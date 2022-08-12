

#include <Servo.h>
Servo servoDroite ;
Servo servoGauche ;
const int analogInPin [] = { A0 , A1 , A2 , A3 ,
                             A4 , A5 , A6
                           } ;
int sensorValue = 0;
int outputValue = 0;
void setup ( )
{
  servoDroite.attach ( 8 ) ;
  servoGauche.attach ( 9 ) ;
  Serial.begin ( 115200 ) ;
}

void loop ( )
{
  for ( byte boucle = 0 ; boucle <= 6 ; boucle ++ )
  {
    Serial.print ( analogRead ( analogInPin [ boucle ] ) ) ;
    // Serial.print ( "," ) ;
    Serial.print ( "\t" ) ;
  }
  servoDroite.write ( map ( analogRead ( A1 ) , 0 , 1023 , 0 , 180 ) ) ;
  servoGauche.write ( map ( analogRead ( A0 ) , 0 , 1023 , 0 , 180 ) ) ;
  Serial.println ( "" ) ;
  delay( 100 ) ;
}
