#include <detail/RequestHandlersImpl.h>
#include <list>

const char HELPER[] PROGMEM = R"(<form method="POST" action="/upload" enctype="multipart/form-data">
<input type="file" name="[]" multiple><button>Upload</button></form>Lade die spiffs.html hoch.)";

void spiffs() {                                                                             // Funktionsaufruf "spiffs();" muss im Setup eingebunden werden
  SPIFFS.begin(true);
  webServer.on("/list", handleList);
  webServer.on("/format", formatFS);
  webServer.on("/upload", HTTP_POST, sendResponce, handleFileUpload);
  webServer.onNotFound([]() {
     Serial.printf(" WebRequest File: %s\n", webServer.urlDecode(webServer.uri()).c_str()); 
    if (!handleFile(webServer.urlDecode(webServer.uri())))
    {
      if ( !captivePortal(webServer.uri())) webServer.send(404, "text/plain", "FileNotFound");
    }
  });
}


void handleList() {                                                                         // Senden aller Daten an den Client
  File root = SPIFFS.open("/");
  typedef std::pair<String, int> prop;
  std::list<prop> dirList;                                                                  // Liste anlegen
  while (File f = root.openNextFile()) dirList.emplace_back(f.name(), f.size());            // Liste füllen
  dirList.sort([](const prop & f, const prop & l) {                                         // Liste sortieren
    if (webServer.arg(0) == "1") {
      return f.second > l.second;
    } else {
      for (uint8_t i = 0; i < 31; i++) {
        if (tolower(f.first[i]) < tolower(l.first[i])) return true;
        else if (tolower(f.first[i]) > tolower(l.first[i])) return false;
      }
      return false;
    }
  });
  String temp = "[";
  for (auto& p : dirList) {
    if (temp != "[") temp += ',';
    temp += "{\"name\":\"" + p.first.substring(1) + "\",\"size\":\"" + formatBytes(p.second) + "\"}";
  }
  temp += R"(,{"usedBytes":")" + formatBytes(SPIFFS.usedBytes() * 1.05) + R"(",)" +         // Berechnet den verwendeten Speicherplatz + 5% Sicherheitsaufschlag
          R"("totalBytes":")" + formatBytes(SPIFFS.totalBytes()) + R"(","freeBytes":")" +   // Zeigt die Größe des Speichers
          (SPIFFS.totalBytes() - (SPIFFS.usedBytes() * 1.05)) + R"("}])";                   // Berechnet den freien Speicherplatz + 5% Sicherheitsaufschlag
  webServer.send(200, "application/json", temp);
}

bool handleFile(String&& path) {
//    Serial.printf("Web File: %s\n", path.c_str()); 
  if (webServer.hasArg("delete")) {
    SPIFFS.remove(webServer.arg("delete"));                                                    // Datei löschen
    sendResponce();
    return true;
  }
  if (!SPIFFS.exists("/spiffs.html") && WiFi.getMode() == WIFI_STA )webServer.send(200, "text/html", HELPER);                 // ermöglicht das hochladen der spiffs.html
  if (path.endsWith("/")) path += "index.html";
  return SPIFFS.exists(path) ? ({File f = SPIFFS.open(path); webServer.streamFile(f, StaticRequestHandler::getContentType(path)); f.close(); true;}) : false;
}

void handleFileUpload() {                                  // Dateien vom Rechnenknecht oder Klingelkasten ins FS schreiben
  static File fsUploadFile;
  HTTPUpload& upload = webServer.upload();
  if (upload.status == UPLOAD_FILE_START) {
    if (upload.filename.length() > 30) {
      upload.filename = upload.filename.substring(upload.filename.length() - 30, upload.filename.length());  // Dateinamen auf 30 Zeichen kürzen
    }
    printf(PSTR("handleFileUpload Name: /%s\n"), upload.filename.c_str());
    fsUploadFile = SPIFFS.open("/" + webServer.urlDecode(upload.filename), "w");
  } else if (upload.status == UPLOAD_FILE_WRITE) {
     printf(PSTR("handleFileUpload Data: %u\n"), upload.currentSize);
    if (fsUploadFile)
      fsUploadFile.write(upload.buf, upload.currentSize);
  } else if (upload.status == UPLOAD_FILE_END) {
    if (fsUploadFile)
      fsUploadFile.close();
    printf(PSTR("handleFileUpload Size: %u\n"), upload.totalSize);
  }
}

void formatFS() {       //Formatiert den Speicher
  SPIFFS.format();
  sendResponce();
}

void sendResponce() {
  webServer.sendHeader("Location", "spiffs.html");
  webServer.send(303, "message/http");
}

const String formatBytes(size_t const& bytes) {            // lesbare Anzeige der Speichergrößen
  return bytes < 1024 ? static_cast<String>(bytes) + " Byte" : bytes < 1048576 ? static_cast<String>(bytes / 1024.0) + " KB" : static_cast<String>(bytes / 1048576.0) + " MB";
}

bool freeSpace(uint16_t const& printsize) {               // Funktion um beim speichern in Logdateien zu prüfen ob noch genügend freier Platz verfügbar ist.
  //Serial.printf("Funktion: %s meldet in Zeile: %d FreeSpace: %s\n", __PRETTY_FUNCTION__, __LINE__, formatBytes(fs_info.totalBytes - (fs_info.usedBytes * 1.05)).c_str());
  return (SPIFFS.totalBytes() - (SPIFFS.usedBytes() * 1.05) > printsize) ? true : false;
}
