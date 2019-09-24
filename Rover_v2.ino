//Orientation Motor side Down, Battery Side up
int E1 = 6 ; //Right track spreed controller
int E2 = 5 ; //Left track speed controller
int M1 = 8 ; //Right track direction controller
int M2 = 7 ; //Left track direction controller
int flag = 0 ;//Continuous flag
void setup() {
  // put your setup code here, to run once:
  int i ;
  for ( i = 5 ; i <= 8 ; i++ )
  pinMode ( i, OUTPUT ) ;
  Serial.begin ( 9600 ) ;
}

void loop() {
  // put your main code here, to run repeatedly:
  while ( Serial.available() < 1 ) {} //Do nothing to wait for received char
  char key = Serial.read() ;
  int track_l_spd = 255 ;
  int track_r_spd = 255 ;
  switch( key )
  {
    case 'w' :
      up ( track_l_spd, track_r_spd , flag ) ; //Move forwards
      break ;
    case 's' :
      down ( track_l_spd, track_r_spd , flag ) ;//Move backwards
      break ;
    case 'a' :
      left ( track_l_spd, track_r_spd , flag ) ;//Turn and move left
      break ;
    case 'd' :
      right ( track_l_spd, track_r_spd , flag ) ;//Turn and move right
      break ;
    case 'c' :
      if ( flag == 0 )
      {
        flag = 1 ;
      }
      else
      {
        flag = 0 ;
      }
    default :
      stop() ;
      break ;
  }
}

void stop ( void )
{
  digitalWrite ( E1, LOW ) ;//Stop power to right track
  digitalWrite ( E2, LOW ) ;//Stop power to left track
}
void up ( char x , char y , int flag )
{
  analogWrite ( E1, x ) ;//Write 255 to right track
  digitalWrite ( M1, LOW ) ;//Power to right track
  analogWrite ( E2, y ) ;//Write 255 to left track
  digitalWrite ( M2, LOW ) ;//Power to left track
  if ( flag == 0 )//If not continuous
  {
    delay( 1000 ) ;
    digitalWrite ( E1, LOW ) ;
    digitalWrite ( E2, LOW ) ;
  }
  
}
void down ( char x , char y , int flag )
{
  analogWrite ( E1, x ) ;//Write 255 to right track
  digitalWrite ( M1, HIGH ) ;//Reverse Power to right track
  analogWrite ( E2, y ) ;//Write 255 to left track
  digitalWrite ( M2, HIGH ) ;//Reverse Power to left track
  if ( flag == 0 )//If not continuous
  {
    delay( 1000 ) ;
    digitalWrite ( E1, LOW ) ;
    digitalWrite ( E2, LOW ) ;
  }
}
void left ( char x , char y , int flag )
{
  analogWrite ( E1, x ) ;//Write 255 to right track
  digitalWrite ( M1, HIGH ) ;//High Power to right track
  analogWrite ( E2, y ) ;//Write 255 to left track
  digitalWrite ( M2, LOW ) ;//Low Power to left track
  if ( flag == 0 )//If not continuous
  {
    delay( 1000 ) ;
    digitalWrite ( E1, LOW ) ;
    digitalWrite ( E2, LOW ) ;
  }
}
void right ( char x , char y , int flag )
{
  analogWrite ( E1, x ) ;//Write 255 to right track
  digitalWrite ( M1, LOW ) ;//Low power to right track
  analogWrite ( E2, y ) ;//Write 255 to left track
  digitalWrite ( M2, HIGH ) ;//High power to left track
  if ( flag == 0 )//If not continuous
  {
    delay( 1000 ) ;
    digitalWrite ( E1, LOW ) ;
    digitalWrite ( E2, LOW ) ;
  }
}
