#include <SoftwareSerial.h>
SoftwareSerial mySerial(7, 8);
char incoming_char=0;

//sd y musica
#include <SD.h>  
#include <SPI.h>
#include <TMRpcm.h>  
TMRpcm bocina;   //Se crea un objeto de la librería TMRpcm
int cancionactual = 1;

String sendData(String command, const int timeout, boolean debug)
{
    String cadena = "";
    mySerial.print(command); // enviar el carácter leído al modulo
    long int time = millis();    
    while( (time+timeout) > millis())
    {
      while(mySerial.available())
      {        
        // Muestra los Datos de salida del modulo por el seguimiento de la serie
        char c = mySerial.read(); //Lee el proximo caracter
        cadena+=c;
      }  
    }   
    if(debug)
    {
      Serial.print(cadena);
    }    
    return cadena;
}

void setup()
{
  Serial.begin(9600); // for serial monitor
  mySerial.begin(9600); // for GSM shield
  sendData("AT+CMGF=1\r\n",2000,true);  // set SMS mode to text
  delay(1000);
  sendData("AT+CNMI=2,2,0,0,0\r\n",2000,true);
  // blurt out contents of new SMS upon receipt to the GSM shield's serial out
  delay(1000);
  
  Serial.print(F("Iniciando SD ..."));
  bocina.speakerPin = 9;
  if (!SD.begin(10))
  {
    Serial.println(F("Error al iniciar"));
    return;
  }
  Serial.println(F("Iniciado correctamente"));
  
}
int accion = 0;
bool activado = false;
void loop()
{
  // Now we simply display any text that the GSM shield sends out on the serial monitor
  if(mySerial.available() >0)
  {
    incoming_char=mySerial.read(); //Get the character from the cellular serial port.
    //Serial.print(incoming_char);
    //prender y apagar
    if (incoming_char=='$')  // toda clave va seguido del carácter #
    {
      
      if(bocina.isPlaying()==1)
      {
        Serial.println("apagar");
        acciones(10);
      }
      else
      {
        Serial.println("prender");
        acciones(11);
      }
    }
    if(incoming_char == 's')
    {
      Serial.println("play");
      acciones(14);
    }
    if(incoming_char == 'h')
    {
      Serial.println("pause");
      acciones(15);
    }
    if(incoming_char == 'x')
    {
      Serial.println("stop");
      acciones(16);
    }
    if(incoming_char == '#')
    {
      cancionactual = random(1,10);
      Serial.println("adelante");
      acciones(13);
    }
    if(incoming_char == 'z')
    {
      cancionactual = random(1,10);
      Serial.println("atras");
      acciones(12);
    }
  }
  aumento();
}
void aumento()
{
  if(bocina.isPlaying()==1 && activado==true)
      {
        cancionactual = random(1,10);
      }
}
