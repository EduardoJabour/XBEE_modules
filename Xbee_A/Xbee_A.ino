#include <SoftwareSerial.h>
#define LimiteQuadro 6
#define EnderecoXbee '1'


//Quadro de envio de dados: Destinatário | Remetente | Tkn | Mensagem 
//Ponto de exclamação inicia a transmissão (!)

SoftwareSerial xbee(2, 3); // RX, TX
char data[LimiteQuadro];
char data2[LimiteQuadro];
char aux1;

bool enviado = false;

int  i = 0, j = 0;

void setup()
{
    Serial.begin(9600);

    Serial.println( "Arduino started sending bytes via XBee" );

    //Set the data rate for the SoftwareSerial port
    xbee.begin(9600);

    delay( 3000 );
}

void loop() {

    if(enviado == false){     
  
      Serial.println("Transmissão da mensagem começará em 3 ...");
      delay(1000);
      Serial.println("Transmissão da mensagem começará em 2 ...");
      delay(1000);
      Serial.println("Transmissão da mensagem começará em 1 ...");
      delay(1000);
      Serial.print("Mensagem Enviada : ");
      
      data[0] = '2';
      xbee.write(data[0]);
      Serial.print(data[0]);
      data[1] = 'A';
      xbee.write(data[1]);
      Serial.print(data[1]);
      for(i = 2; i < LimiteQuadro; i++){
         data[i] = 'x';
         xbee.write(data[i]);
         Serial.print(data[i]);
       }

      enviado = true;

      if(data == "2Axxxx"){
          Serial.println("Mensagem Enviada");
      }
    
    }
    else{
      delay(3000);

      for(i = 0; i < LimiteQuadro; i++){
         data2[i] = xbee.read();
       }

      if (data2[0] == '1'){
        Serial.println(" ");
        Serial.print("Mensagem Recebida : ");
        
        for(i = 0; i < LimiteQuadro; i++){
          Serial.print(data2[i]);
        }        
      }     
    }
  }
