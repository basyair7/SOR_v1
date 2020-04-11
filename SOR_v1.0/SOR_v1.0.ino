/* NAME PROJECT : SWITCH ON ALL REMOTE IR
 * Creator      : PRD GROUP 2019
 * powered by arduino
 */
/*sebelum di compiler, jangan lupa add library IRremote.h yang sudah di download, 
 * klik ke sketch >> Include Library >> Add .ZIP File >> Select the Downloaded ZIP yang telah didownload
 */

#include<IRremote.h>

int all_remote = A0;
int saklar1 = 4;
int saklar2 = 2;
int saklar3 = 5;

IRrecv tombol_remote(all_remote);
decode_results kode_remote;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  tombol_remote.enableIRIn();
  
  pinMode(saklar1,OUTPUT); 
  pinMode(saklar2,OUTPUT);
  pinMode(saklar3,OUTPUT);

  digitalWrite(saklar1,HIGH); 
  digitalWrite(saklar2,HIGH);
  digitalWrite(saklar3,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (tombol_remote.decode(&kode_remote))
  {
    remote1();
    remote2();
    remote3();

    Serial.println(kode_remote.value, HEX);
    tombol_remote.resume();
    
  }
}

void remote1(){
  //untuk remote tv LG
    switch (kode_remote.value){
      case 0x20DF10EF :
        digitalWrite(saklar1, !digitalRead(saklar1));
        digitalWrite(saklar2, !digitalRead(saklar2));
        digitalWrite(saklar3, !digitalRead(saklar3));
        break;
        
      case 0x20DF8877 :
        digitalWrite(saklar1, !digitalRead(saklar1));
        break;

      case 0x20DF48B7 :
        digitalWrite(saklar2, !digitalRead(saklar2));
        break;
        
      case 0x20DFC837 :
        digitalWrite(saklar3, !digitalRead(saklar3));
        break;
        default:
        break;
    }
    
    delay(50);
}

void remote2(){
  //untuk remote dvd polytron
    switch (kode_remote.value){
      case 0x5173760C :
        digitalWrite(saklar1, !digitalRead(saklar1));
        digitalWrite(saklar2, !digitalRead(saklar2));
        digitalWrite(saklar3, !digitalRead(saklar3));
        break;
        
      case 0x60C110A8 :
        digitalWrite(saklar1, !digitalRead(saklar1));
        break;

      case 0xA0884347 :
        digitalWrite(saklar2, !digitalRead(saklar2));
        break;
        
      case 0x2993106E :
        digitalWrite(saklar3, !digitalRead(saklar3));
        break;
        default:
        break;
    }
    
    delay(50);
}

void remote3(){
  //untuk remote tv receiver
    switch (kode_remote.value){
      case 0x200850AF :
        digitalWrite(saklar1, !digitalRead(saklar1));
        digitalWrite(saklar2, !digitalRead(saklar2));
        digitalWrite(saklar3, !digitalRead(saklar3));
        break;
        
      case 0x2008807F :
        digitalWrite(saklar1, !digitalRead(saklar1));
        break;

      case 0x200840BF :
        digitalWrite(saklar2, !digitalRead(saklar2));
        break;
        
      case 0x2008C03F :
        digitalWrite(saklar3, !digitalRead(saklar3));
        break;
        default:
        break;
    }
    
    delay(50);
}
