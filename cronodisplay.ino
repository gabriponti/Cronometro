#include <ezButton.h>

unsigned long timestart;

int LED0 = 11111100;
int LED1 = 01100000;
int LED2 = 11011010;
int LED3 = 11110010;
int LED4 = 01100110;
int LED5 = 10110110;
int LED6 = 10111110;
int LED7 = 11100000;
int LED8 = 11111110;
int LED9 = 11100110;

int SRCLK = 2;                                   //clock di mandata per numero da arduino a sipo
int RCLK = 3;                                    //clock di mandata per numero binario da sipo a display
int SER = 4;                                     //pin mandata dati

ezButton button (12);
int tempo[6];

void setup() {
  Serial.begin(9600);
  button.setDebounceTime (3000);

  pinMode (SER, OUTPUT);
  pinMode (SRCLK, OUTPUT);
  pinMode (RCLK, OUTPUT);
}

void loop() {
button.loop(); 

  if( button.isPressed() ){
    timestart = millis();
    Serial.println(1);
    count();
    trasmissione();
}
}

void count(){
  unsigned long timenow = millis() - timestart;  
    float time1 = timenow / 60000;        // calcolo minuti
    int time2 = time1;                    // minuti interi
    int Dm = time2 /10;                   //decine di minuti
    int Um = time2 - (Dm*10);             //unità di minuti
    tempo[5] = Dm;
    tempo[4] = Um;
    (float)time2;                          
    float time3 = time1 - time2;         // resto calcolo minuti
    float time4 = time3 * 60;             // calcolo secondi
    int time5 = time4;                    //secondi interi
    int Ds = time2 /10;                   //decine di secondi
    int Us = time2 - (Ds*10);             //unità di secondi
    tempo[3] = Ds;
    tempo[2] = Us;
    (float)time5;
    float time6 = time4 - time5;         // resto calcolo secondi
    float time7 = time6 * 100;            // calcolo centesimi di secondo
    int time8 = time7;                    // centesimi di secondo interi
    int Dcs = time2 /10;                   //decine di centesimi di secondo
    int Ucs = time2 - (Dcs*10);             //unità di centesimi di secondo
    tempo[1] = Dcs;
    tempo[0] = Ucs;
}

void trasmissione(){
 
  for (int a=0; a<=5; a++){
 
    switch (tempo[a]) {
     
      case 0:
   
    digitalWrite (SRCLK, LOW);   // teniamo a livello basso il latchPin per tutto il tempo in cui stiamo trasmettendo
    shiftOut (SER, RCLK, LSBFIRST, LED0);
    digitalWrite (SRCLK, HIGH);  // mettiamo il latch pin alto quando non serve più trasmettere al 74HC595
    break;
   
      case 1:
     digitalWrite (SRCLK, LOW);
    shiftOut (SER, RCLK, LSBFIRST, LED1);
    digitalWrite (SRCLK, HIGH);
    break;
   
      case 2:
    digitalWrite(SRCLK, LOW);
    shiftOut (SER, RCLK, LSBFIRST, LED2);
    digitalWrite(SRCLK, HIGH);
    break;
   
      case 3:
    digitalWrite (SRCLK, LOW);
    shiftOut (SER, RCLK, LSBFIRST, LED3);
    digitalWrite (SRCLK, HIGH);
    break;
   
      case 4:
    digitalWrite (SRCLK, LOW);
    shiftOut (SER, RCLK, LSBFIRST, LED4);
    digitalWrite (SRCLK, HIGH);
    break;
   
      case 5:
    digitalWrite (SRCLK, LOW);
    shiftOut (SER, RCLK, LSBFIRST, LED5);
    digitalWrite (SRCLK, HIGH);
    break;
   
      case 6:
    digitalWrite (SRCLK, LOW);
    shiftOut (SER, RCLK, LSBFIRST, LED6);
    digitalWrite (SRCLK, HIGH);
    break;
   
      case 7:
    digitalWrite (SRCLK, LOW);
    shiftOut (SER, RCLK, LSBFIRST, LED7);
    digitalWrite (SRCLK, HIGH);
    break;
   
      case 8:
    digitalWrite (SRCLK, LOW);
    shiftOut (SER, RCLK, LSBFIRST, LED8);
    digitalWrite (SRCLK, HIGH);
    break;
   
      case 9:
    digitalWrite (SRCLK, LOW);
    shiftOut (SER, RCLK, LSBFIRST, LED9);
    digitalWrite (SRCLK, HIGH);
    break;
    }
  }  
}
