#include <SoftwareSerial.h>
#define LimiteQuadro 6
#define EnderecoXbee '2'

//Quadro de envio de dados: Destinatário | Remetente | Tkn | Mensagem 
//Ponto de exclamação inicia a transmissão (!)

SoftwareSerial xbee(2, 3); // RX, TX
char data[LimiteQuadro];
char data2[LimiteQuadro];

bool enviado = false;

int  i = 0;

void setup()
{
    Serial.begin(9600);

    //Set the data rate for the SoftwareSerial port
    xbee.begin(9600);

    delay( 3000 );
}

void loop() {

    for(i = 0; i < LimiteQuadro; i++){
       data2[i] = xbee.read();
    }

    Serial.println("Aguardando Mensagem");
    delay(2500);

    if (data2[0] == '2'){

      Serial.print(" ");
      Serial.print("Mensagem Recebida : ");
       
      for(i = 0; i < LimiteQuadro; i++){
        Serial.print(data2[i]);
      } 
      Serial.println(" ");
      Serial.println("Transmissão da mensagem começará em 3 ...");
      delay(1000);
      Serial.println("Transmissão da mensagem começará em 2 ...");
      delay(1000);
      Serial.println("Transmissão da mensagem começará em 1 ...");
      delay(1000);

      Serial.print("Nova Mensagem Enviada : ");
      
      data[0] = '3';
      xbee.write(data[0]);
      Serial.print(data[0]);

      data[1] = data2[1];
      xbee.write(data[1]);
      Serial.print(data[1]);
      
      data[2] = 'B';
      xbee.write(data[2]);
      Serial.print(data[2]);
      
      for(i = 3; i < LimiteQuadro; i++){
         data[i] = data2[i];
         xbee.write(data[i]);
         Serial.print(data[i]);
       }
      Serial.println(" ");

    }
  }
