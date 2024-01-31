#include <WiFi.h>

const char* ssid = "Tirth.";
const char* password = "12345678";

WiFiServer server(80); // Create a web server on port 80

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();  // Listen for incoming clients

  if (client) {
    String request = client.readStringUntil('\r');  // Read the request
    Serial.println(request);

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println(""); //  Important blank line

    // Send the data you want to transfer (replace with your actual data)
    client.println("Data from Arduino screen:");
    client.println("Sensor value: 123");  // Example data
    client.println("Another value: 456");

    client.println("</html>");
    delay(1);
    client.stop();
  }
}
