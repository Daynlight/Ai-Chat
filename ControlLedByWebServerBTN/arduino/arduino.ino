#include <ESP8266WiFi.h>

// Replace with your network credentials
const char* ssid = "SSID";
const char* password = "PASSWORD";
IPAddress local_IP(192,168,0,210);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,0,0);

int ledPin = D1;
bool ledState = LOW;

WiFiServer server(80);

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
  
  Serial.begin(115200);
  delay(10);

  // Configures static IP address
  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Once connected, print the IP address
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Start the server
  server.begin();
  Serial.println("Server started");
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("New client");
  while(!client.available()){
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Send the response to the client
  if (request.indexOf("/led/switch") != -1)
    ledState = !ledState;


  client.print("HTTP/1.1 200 OK\r\n");
  client.print("Content-Type: text/html\r\n\r\n");
  client.print("<!DOCTYPE HTML>\r\n");
  client.print("<html>\r\n");
  client.print("<body>\r\n"); 
  client.print("<h1>Pin State: "+ String(ledState) +"</h1>\r\n");
  client.print("<a href=\"/led/switch\"><button>Change</button></a>\r\n");
  client.print("</body>\r\n");
  client.print("</html>\r\n");

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}
