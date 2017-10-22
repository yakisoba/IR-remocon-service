#include <IRsend.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <IRremoteESP8266.h>

const char *ssid = "";
const char *password = "";

ESP8266WebServer server ( 80 );
IRsend irsend(14);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  irsend.begin();
  Serial.println("");

  //wait for connection
  while( WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/",handleRoot);

  // system api
  server.on("/tv/power", handlePower);
  server.on("/tv/ok", handleOk);
  server.on("/tv/back", handleBack);
  server.on("/tv/end", handleEnd);
  server.on("/tv/input", handleInput);
  server.on("/tv/data", handleData);
  server.on("/tv/tool", handleTool);
  server.on("/tv/search", handleSearch);

  // channel api
  server.on("/tv/channel", handleChannel);

  // direction
  server.on("/tv/up", handleUp);
  server.on("/tv/down", handleDown);
  server.on("/tv/left", handleLeft);
  server.on("/tv/right", handleRight);

  // color api
  server.on("/tv/blue", handleBlue);
  server.on("/tv/red", handleRed);
  server.on("/tv/green", handleGreen);
  server.on("/tv/yellow", handleYellow);

  // vol api
  server.on("/tv/volup", handleVolUp);
  server.on("/tv/voldown", handleVolDown);
  server.on("/tv/mute", handleVolMute);

  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

void handlePower() {
  Serial.println("Power");
  irsend.sendPanasonic(0x555A,0xF148688B); delay(10);
  irsend.sendPanasonic(0x555A,0xF148688B);
  server.send(204);
}

void handleOk() {
  Serial.println("Ok");
  irsend.sendPanasonic(0x555A,0xF1484A8B);
  server.send(204);
}

void handleBack() {
  Serial.println("Back");
  irsend.sendPanasonic(0x555A,0xF1482780);
  server.send(204);
}

void handleEnd() {
  Serial.println("End");
  irsend.sendPanasonic(0x555A,0xF148AF80);
  server.send(204);
}

void handleInput() {
  Serial.println("Input");
  irsend.sendPanasonic(0x555A,0xF148C881);
  server.send(204);
}

void handleData() {
  Serial.println("Data");
  irsend.sendPanasonic(0x555A,0xF1487A44);
  server.send(204);
}

void handleTool() {
  Serial.println("Tool");
  irsend.sendPanasonic(0x555A,0xF1483D47);
  server.send(204);
}

void handleSearch() {
  Serial.println("Search");
  irsend.sendPanasonic(0x555A,0xF148D94D);
  server.send(204);
}

void handleChannel() {
  String type = server.arg("ch");
  Serial.println("Channel " + type);
  if (type.equals("1ch")) {
    irsend.sendPanasonic(0x555A,0xF148724C);
  } else if (type.equals("2ch")) {
    irsend.sendPanasonic(0x555A,0xF148F244);
  } else if (type.equals("3ch")) {
    irsend.sendPanasonic(0x555A,0xF1480A43);
  } else if (type.equals("4ch")) {
    irsend.sendPanasonic(0x555A,0xF1488A4B);
  } else if (type.equals("5ch")) {
    irsend.sendPanasonic(0x555A,0xF1484A47);
  } else if (type.equals("6ch")) {
    irsend.sendPanasonic(0x555A,0xF148CA4F);
  } else if (type.equals("7ch")) {
    irsend.sendPanasonic(0x555A,0xF1482A41);
  } else if (type.equals("8ch")) {
    irsend.sendPanasonic(0x555A,0xF148AA49);
  } else if (type.equals("9ch")) {
    irsend.sendPanasonic(0x555A,0xF1486A45);
  } else if (type.equals("10ch")) {
    irsend.sendPanasonic(0x555A,0xF148EA4D);
  } else if (type.equals("11ch")) {
    irsend.sendPanasonic(0x555A,0xF1481A42);
  } else if (type.equals("12ch")) {
    irsend.sendPanasonic(0x555A,0xF1489A4A);
  }
  server.send(204);
}

// direction
void handleUp() {
  Serial.println("Up");
  irsend.sendPanasonic(0x555A,0xF148EA81);
  server.send(204);
}
void handleDown() {
  Serial.println("Down");
  irsend.sendPanasonic(0x555A,0xF1480481);
  server.send(204);
}
void handleLeft() {
  Serial.println("Left");
  irsend.sendPanasonic(0x555A,0xF148EB80);
  server.send(204);
}
void handleRight() {
  Serial.println("Right");
  irsend.sendPanasonic(0x555A,0xF1481B8F);
  server.send(204);
}

// color
void handleBlue() {
  Serial.println("Blue");
  irsend.sendPanasonic(0x555A,0xF1480148);
  server.send(204);
}
void handleRed() {
  Serial.println("Red");
  irsend.sendPanasonic(0x555A,0xF1488140);
  server.send(204);
}
void handleGreen() {
  Serial.println("Green");
  irsend.sendPanasonic(0x555A,0xF148414C);
  server.send(204);
}
void handleYellow() {
  Serial.println("Yellow");
  irsend.sendPanasonic(0x555A,0xF148C144);
  server.send(204);
}

// vol
void handleVolUp() {
  Serial.println("VolUp");
  irsend.sendPanasonic(0x555A,0xF148288F);
  server.send(204);
}
void handleVolDown() {
  Serial.println("VolDown");
  irsend.sendPanasonic(0x555A,0xF148A887);
  server.send(204);
}
void handleVolMute() {
  Serial.println("Mute");
  irsend.sendPanasonic(0x555A,0xF148E883);
  server.send(204);
}

void handleRoot() {
  char temp[2048];
  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;

  char message[20];
  String(server.arg(0)).toCharArray(message,20);
  String type = String(server.arg(0));
  Serial.println(type);

  // system
  if (type.equals("Power")) {
    irsend.sendPanasonic(0x555A,0xF148688B); delay(10);
    irsend.sendPanasonic(0x555A,0xF148688B);
  } else if (type.equals("Ok")) {
    irsend.sendPanasonic(0x555A,0xF1484A8B);
  } else if (type.equals("Back")) {
    irsend.sendPanasonic(0x555A,0xF1482780);
  } else if (type.equals("End")) {
    irsend.sendPanasonic(0x555A,0xF148AF80);
  } else if (type.equals("Input")) {
    irsend.sendPanasonic(0x555A,0xF148C881);
  } else if (type.equals("Data")) {
    irsend.sendPanasonic(0x555A,0xF1487A44);
  } else if (type.equals("Tool")) {
    irsend.sendPanasonic(0x555A,0xF1483D47);
  } else if (type.equals("Search")) {
    irsend.sendPanasonic(0x555A,0xF148D94D);

  // TV List
  } else if (type.equals("TV List")) {
    irsend.sendPanasonic(0x555A,0xF148064F);
  } else if (type.equals("Comp TV List")) {
    irsend.sendPanasonic(0x555A,0xF148AE4D);

  // channel
  } else if (type.equals("1ch")) {
    irsend.sendPanasonic(0x555A,0xF148724C);
  } else if (type.equals("2ch")) {
    irsend.sendPanasonic(0x555A,0xF148F244);
  } else if (type.equals("3ch")) {
    irsend.sendPanasonic(0x555A,0xF1480A43);
  } else if (type.equals("4ch")) {
    irsend.sendPanasonic(0x555A,0xF1488A4B);
  } else if (type.equals("5ch")) {
    irsend.sendPanasonic(0x555A,0xF1484A47);
  } else if (type.equals("6ch")) {
    irsend.sendPanasonic(0x555A,0xF148CA4F);
  } else if (type.equals("7ch")) {
    irsend.sendPanasonic(0x555A,0xF1482A41);
  } else if (type.equals("8ch")) {
    irsend.sendPanasonic(0x555A,0xF148AA49);
  } else if (type.equals("9ch")) {
    irsend.sendPanasonic(0x555A,0xF1486A45);
  } else if (type.equals("10ch")) {
    irsend.sendPanasonic(0x555A,0xF148EA4D);
  } else if (type.equals("11ch")) {
    irsend.sendPanasonic(0x555A,0xF1481A42);
  } else if (type.equals("12ch")) {
    irsend.sendPanasonic(0x555A,0xF1489A4A);

  // direction
  } else if (type.equals("Up")) {
    irsend.sendPanasonic(0x555A,0xF148EA81);
  } else if (type.equals("Down")) {
    irsend.sendPanasonic(0x555A,0xF1480481);
  } else if (type.equals("Left")) {
    irsend.sendPanasonic(0x555A,0xF148EB80);
  } else if (type.equals("Right")) {
    irsend.sendPanasonic(0x555A,0xF1481B8F);

  // color
  } else if (type.equals("Blue")) {
    irsend.sendPanasonic(0x555A,0xF1480148);
  } else if (type.equals("Red")) {
    irsend.sendPanasonic(0x555A,0xF1488140);
  } else if (type.equals("Green")) {
    irsend.sendPanasonic(0x555A,0xF148414C);
  } else if (type.equals("Yellow")) {
    irsend.sendPanasonic(0x555A,0xF148C144);

  // volume
  } else if (type.equals("Vol UP")) {
    irsend.sendPanasonic(0x555A,0xF148288F);
  } else if (type.equals("Vol Down")) {
    irsend.sendPanasonic(0x555A,0xF148A887);
  } else if (type.equals("Mute")) {
    irsend.sendPanasonic(0x555A,0xF148E883);
  }

  snprintf ( temp, 800,

"<html>\
  <head>\
    <title>Home IR-Remocon</title>\
    <style>\
      body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
      form { display: flex; flex-flow: row wrap; }\
      input[type=submit] { flex: 0 100px; padding: 15px 40px; }\
    </style>\
  </head>\
  <body>\
    <h1>Home IR-Remocon</h1>\
    <p>Uptime: %02d:%02d:%02d</p>\
    <p>BUTTON :%s</p>\
    <h3>TV Remocon</h3>\
    <h4>system</h4>\
    <form action=\"/\" method=\"post\">\
      <input type=\"submit\" name=\"button_power\" value=\"Power\">\
      <input type=\"submit\" name=\"button_ok\" value=\"Ok\">\
      <input type=\"submit\" name=\"button_input\" value=\"Input\">\
      <input type=\"submit\" name=\"button_back\" value=\"Back\">\
      <input type=\"submit\" name=\"button_end\" value=\"End\">\
      <input type=\"submit\" name=\"button_data\" value=\"Data\">\
      <input type=\"submit\" name=\"button_tool\" value=\"Tool\">\
      <input type=\"submit\" name=\"button_search\" value=\"Search\">\
    </form>\
    <h4>channel</h4>\
    <form action=\"/\" method=\"post\">\
      <input type=\"submit\" name=\"button_1ch\" value=\"1ch\">\
      <input type=\"submit\" name=\"button_2ch\" value=\"2ch\">\
      <input type=\"submit\" name=\"button_3ch\" value=\"3ch\">\
      <input type=\"submit\" name=\"button_4ch\" value=\"4ch\">\
      <input type=\"submit\" name=\"button_5ch\" value=\"5ch\">\
      <input type=\"submit\" name=\"button_6ch\" value=\"6ch\">\
      <input type=\"submit\" name=\"button_7ch\" value=\"7ch\">\
      <input type=\"submit\" name=\"button_8ch\" value=\"8ch\">\
      <input type=\"submit\" name=\"button_9ch\" value=\"9ch\">\
      <input type=\"submit\" name=\"button_10ch\" value=\"10ch\">\
      <input type=\"submit\" name=\"button_11ch\" value=\"11ch\">\
      <input type=\"submit\" name=\"button_12ch\" value=\"12ch\">\
    </form>\
    <h4>color</h4>\
    <form action=\"/\" method=\"post\">\
      <input type=\"submit\" name=\"button_blue\" value=\"Blue\">\
      <input type=\"submit\" name=\"button_red\" value=\"Red\">\
      <input type=\"submit\" name=\"button_green\" value=\"Green\">\
      <input type=\"submit\" name=\"button_yellow\" value=\"Yellow\">\
    </form>\
    <h4>direction</h4>\
    <form action=\"/\" method=\"post\">\
      <input type=\"submit\" name=\"button_up\" value=\"Up\">\
      <input type=\"submit\" name=\"button_down\" value=\"Down\">\
      <input type=\"submit\" name=\"button_left\" value=\"Left\">\
      <input type=\"submit\" name=\"button_right\" value=\"Right\">\
    </form>\
  </body>\
</html>",
    hr, min % 60, sec % 60, message);

  server.send ( 200, "text/html", temp );
}

void handleNotFound() {

  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += ( server.method() == HTTP_GET ) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for ( uint8_t i = 0; i < server.args(); i++ ) {
    message += " " + server.argName ( i ) + ": " + server.arg ( i ) + "\n";
  }
  server.send ( 404, "text/plain", message );

}
