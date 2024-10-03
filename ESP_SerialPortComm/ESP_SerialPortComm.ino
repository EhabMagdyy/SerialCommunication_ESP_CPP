/*****************************************************************************************************************************
**********************************    Author  : Ehab Magdy Abdullah                      *************************************
**********************************    Linkedin: https://www.linkedin.com/in/ehabmagdyy/  *************************************
**********************************    Youtube : https://www.youtube.com/@EhabMagdyy      *************************************
******************************************************************************************************************************/

// Define the Serial2 pins
#define RX2 16 // GPIO16
#define TX2 17 // GPIO17

// to send & receive 3 times when stops
unsigned char counter = 0;

void setup()
{
    Serial.begin(115200);                             // Initialize the Serial monitor
    
    Serial2.begin(115200, SERIAL_8N1, RX2, TX2);      // Initialize Serial2 with a baud rate of 115200
}

void loop()
{
    while(counter < 3)
    {
        delay(1000);

        // Receving - Check if there is data available on Serial2
        while(!Serial2.available()){}
        if(Serial2.available())
        {
            // Read data on Serial Port
            String receivedData = Serial2.readStringUntil('\n');

            // Print the received data on Serial Monitor
            Serial.print("Received: ");
            Serial.println(receivedData);
        }

        delay(3000);

        // Send data to Serial2
        String dataToSend1 = "I'm good, Thanks C++!";
        Serial2.print(dataToSend1);
        // Print the sent data on the serial monitor
        Serial.print("Sent: ");
        Serial.println(dataToSend1);

        delay(3000);

        // Send data to Serial2
        String dataToSend2 = "See you later!";
        Serial2.print(dataToSend2);
        // Print the sent data on the serial monitor
        Serial.print("Sent: ");
        Serial.println(dataToSend2);

        // Checks if loop happend 3 times
        counter++;
        if(counter == 3){ Serial.println("Communication Ends"); }
        else{ Serial.println("Sending & Receiving loop ends\n"); }
    }
}
