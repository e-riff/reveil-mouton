#define HEURE_SEMAINE 6
#define MINUTE_SEMAINE 55
#define HEURE_WE 7
#define MINUTE_WE 45
#define PIN_JOUR 3
#define PIN_NUIT 4
#define HEURE_COUCHE 20
#define MINUTE_COUCHE 15


#include <RTClib.h>
#include "verif_heure.h"

RTC_DS3231 rev_mout;
DateTime now;



bool couche = false;

void setup () {
  pinMode(PIN_JOUR, OUTPUT);
  pinMode(PIN_NUIT, OUTPUT);

  Serial.begin(19200);

        digitalWrite(PIN_JOUR, HIGH);
      digitalWrite(PIN_NUIT, HIGH);
      delay(200);
      digitalWrite(PIN_JOUR, LOW);
      digitalWrite(PIN_NUIT, LOW);

  while (!rev_mout.begin()) {
    for (int i = 0 ; i < 10 ; i++) {
      digitalWrite(PIN_JOUR, HIGH);
      digitalWrite(PIN_NUIT, HIGH);
      delay(200);
      digitalWrite(PIN_JOUR, LOW);
      digitalWrite(PIN_NUIT, LOW);
      delay(200);
    }
    Serial.flush();
  }

  if (rev_mout.lostPower()) {
    Serial.println("rev_mout lost power, let's set the time!");
    for ( int i = 0 ; i < 10 ; i++) {
      digitalWrite(PIN_JOUR, HIGH);
      digitalWrite(PIN_NUIT, HIGH);
      delay(200);
      digitalWrite(PIN_JOUR, LOW);
      digitalWrite(PIN_NUIT, LOW);
      delay(200);
    }
    Serial.println("Couldn't find rev_mout");
    Serial.flush();
        
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the rev_mout to the date & time this sketch was compiled
    //rev_mout.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the rev_mout with an explicit date & time, for example to set
    // 2 Février 2022, 21, 2014 at 3am you would call:
    //rev_mout.adjust(DateTime(2022, 2, 2, 3, 00, 00));
  }

  //Pour test :
  //rev_mout.adjust(DateTime(2022, 2, 2, 3, 00, 00));
  //rev_mout.adjust(DateTime(F(__DATE__), F(__TIME__)));

  digitalWrite(PIN_JOUR, HIGH);
  digitalWrite(PIN_NUIT, LOW);


}

void loop () {
  DateTime now = rev_mout.now();
  
  Serial.print(now.year());
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.println(now.day(), DEC);
  Serial.print("Jour de la semaine : ");
  Serial.println(now.dayOfTheWeek());
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);
  Serial.println();

  couche = test_changement(couche, now.dayOfTheWeek(), now.hour(), now.minute());
  
  delay(30000);


}
