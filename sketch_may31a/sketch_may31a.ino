#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(5, 6);  // RX, TX
int ventilador = 2;

//sensor de luz
int sensor = 3;
int Valor_fotocelda = 0;


void setup() {
  Serial.begin(9600);
  bluetoothSerial.begin(9600);  // Establece la velocidad de comunicación para el módulo HC-05
  pinMode(ventilador, OUTPUT); // Configura el pin del ventilador como salida 

  //
  pinMode(sensor, INPUT);//Definir el sensor(pin3) como entrada
}

void loop() {

      //sensor de luz
        Valor_fotocelda = digitalRead(sensor);//Leer y almacenar el valor del sensor
        delay(100);
        if(Valor_fotocelda == 0){
          Serial.print("prende el cooler\n");
          digitalWrite(ventilador, HIGH);
        }else{
          Serial.print("apaga el cooler\n");
          digitalWrite(ventilador, LOW);
        }
      //sensor de luz

  // if (bluetoothSerial.available()) {
  //   char data = bluetoothSerial.read();
  //   if (data == '1') { // Compara con un carácter en lugar de una cadena
  //     digitalWrite(ventilador, HIGH);
  //     Serial.println("ventilador On"); 
  //   }else if(data == '0') {
  //     digitalWrite(ventilador, LOW);
  //     Serial.println("ventilador Off"); 
  //   }
  //   Serial.print(data);  // Muestra los datos recibidos desde el módulo HC-05 en el Monitor Serie
  // }

  // // //para enviar datos desde el monitor serial
  // if (Serial.available()){
  //   char data = Serial.read();
  //   bluetoothSerial.print(data);  // Envía los datos desde el Monitor Serie al módulo HC-05
  // }
}
