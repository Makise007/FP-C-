#include <ESP8266WiFi.h> //memasukan liblary

const char* ssid = "bypek";   //memasukan nama wifi/ssid
const char* password = "lupekkkk"; //memasukan password pada wifi

WiFiServer server(80); //port server 80(HTTP)

int LED = LED_BUILTIN; //led bawaan

void setup() { //untuk menyetting
        Serial.begin(115200); //Default Baudrate
        pinMode(LED, OUTPUT); //lampu yang menyala
        digitalWrite(LED, HIGH); 
        
        Serial.print("Connecting to the Newtork");
        
        //Static IP address configuration
        IPAddress staticIP(192, 168, 43, 2); //menggunakan static ip
        IPAddress gateway(192, 168, 43, 1);   //IP Address of your WiFi Router (Gateway)
        IPAddress subnet(255, 255, 255, 0);  //Subnetmask
        const char* deviceName = "Team Sixteen";