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

        WiFi.hostname(deviceName);      // DHCP Hostname (digunakan untuk mencari wifi static lease)
        WiFi.config(staticIP, subnet, gateway); //memasukan ip address, subnet, dan gateway
        WiFi.begin(ssid, password); //memasukan SSID dan password wifi
       
        WiFi.mode(WIFI_STA); // modul yang terhubung dengan WiFi lain (hanya terhubung dengan router wifi )

        while (WiFi.status() != WL_CONNECTED){ // ketika wifi status tidak terhubung maka akan memberikan tanda "titik" secara terus menerus
                delay(500); //dengan waktu delay 500ms
                Serial.print("."); //huruf "titik" yang di tampilkan
        }
      
        Serial.println("WiFi connected"); //jika terhubung akan menampilkan sever wifi connect
        server.begin();  // Starts the Server //kemudian server akan di mulai
        Serial.println("Server started"); //menampilkan server started

        Serial.print("IP Address of network: "); //
        Serial.println(WiFi.localIP());
        Serial.print("Copy and paste the following URL: http://");
        Serial.print(WiFi.localIP());
        Serial.println("/");
}

void loop() { //program akan mengulang terus hingga alat tercabut atau berhenti
        WiFiClient client = server.available(); //
        if (!client) { //jika ridak ada client makan akan di loop
                return;
        }
        Serial.println("Waiting for new client"); //menunggu perintah dari cliet
        
        while(!client.available()) { //ketika cient tersedia makan akan di beri delay
                delay(1);
        }
        
        String request = client.readStringUntil('\r');
        Serial.println(request);
        client.flush();


        int value = LOW; //
        if(request.indexOf("/LED=ON") != -1){ //perintah untuk menyalakan lampu
                digitalWrite(LED, LOW); // Turn LED ON
                value = HIGH;
        }
        
        if(request.indexOf("/LED=OFF") != -1){ // Turn LED OFF //perintah untuk mematikan lampu
                digitalWrite(LED, HIGH); //turn LED OFF
                value = LOW;
        }


        //*------------------HTML Page Code---------------------*//

          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("");
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.print(" CONTROL LED: ");

          if(value == HIGH) 
          {
            client.print("ON");      
          } else{
            client.print("OFF");
          }
          client.println("<br><br>");
          client.println("<a href=\"/LED=ON\"\"><button>ON</button></a>");
          client.println("<a href=\"/LED=OFF\"\"><button>OFF</button></a><br />");
          client.println("</html>");
  
          delay(1);
          Serial.println("Client disonnected");
          Serial.println("");

}