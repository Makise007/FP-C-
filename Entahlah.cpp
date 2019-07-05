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

        Serial.print("IP Address of network: "); //print serial IP address
        Serial.println(WiFi.localIP()); //print ip local
        Serial.print("Copy and paste the following URL: http://"); //menampilkan string copy ...
        Serial.print(WiFi.localIP()); //http local ip
        Serial.println("/");