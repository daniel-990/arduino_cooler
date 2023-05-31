#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(5, 6);  // RX, TX
int ventilador = 2;

void setup() {
  Serial.begin(9600);
  bluetoothSerial.begin(9600);  // Establece la velocidad de comunicación para el módulo HC-05
  pinMode(ventilador, OUTPUT); // Configura el pin del ventilador como salida 
}

void loop() {

  if (bluetoothSerial.available()) {
    char data = bluetoothSerial.read();
    if (data == '1') { // Compara con un carácter en lugar de una cadena
      digitalWrite(ventilador, HIGH);
      Serial.println("ventilador On"); 
    } else {
      digitalWrite(ventilador, LOW);
      Serial.println("ventilador Off"); 
    }
    Serial.print(data);  // Muestra los datos recibidos desde el módulo HC-05 en el Monitor Serie
  }

  //para enviar datos desde el monitor serial
  if (Serial.available()) {
    char data = Serial.read();
    bluetoothSerial.print(data);  // Envía los datos desde el Monitor Serie al módulo HC-05
  }
}
