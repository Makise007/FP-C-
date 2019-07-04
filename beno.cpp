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