bool test_changement(bool flag_couche, int jour, int heureActu, int minActu);



bool test_changement(bool flag_couche, int jour, int heureActu, int minActu) {
/*  Serial.println(flag_couche);
    Serial.println(heureActu);
    Serial.println(minActu);
    Serial.println(jour);
    delay(500);
*/  

  if (jour <= 5 && jour > 0) { //Si on est la semaine
    if ( (heureActu >  HEURE_SEMAINE && heureActu < HEURE_COUCHE)   ||    (heureActu == HEURE_SEMAINE && minActu >= MINUTE_SEMAINE)    ||   (heureActu == HEURE_COUCHE && minActu < MINUTE_COUCHE )) {
//      Serial.println("journée");
      if (flag_couche) { //Si c'est le premier réveil
        flag_couche = !flag_couche; //Je change les flags
//        Serial.println("on se réveille doucement");
        //Et je change changement des LEDs
        digitalWrite(PIN_JOUR, HIGH);
        digitalWrite(PIN_NUIT, LOW);
      }
    }
    else  { //Si on dans dans la nuit
//      Serial.println("nuit");
      if (!flag_couche) { //Si c'est le premier temps du dodo
//        Serial.println("On s'endort");
        flag_couche = !flag_couche; //Je change les flags en endormi
        digitalWrite(PIN_JOUR, LOW);
        digitalWrite(PIN_NUIT, HIGH);
      }
    }
  }


  else { //Si on est le weekend
    if ( (heureActu >  HEURE_WE && heureActu < HEURE_COUCHE)   ||    (heureActu == HEURE_WE && minActu >= MINUTE_WE)    ||   (heureActu == HEURE_COUCHE && minActu < MINUTE_COUCHE )) {
      if (flag_couche) { //Si c'est le premier réveil
        flag_couche = !flag_couche; //Je change les flags
        //Et je change changement des LEDs
        digitalWrite(PIN_JOUR, HIGH);
        digitalWrite(PIN_NUIT, LOW);
      }
    }
    else  { //Si on dans dans la nuit
      if (!flag_couche) { //Si c'est le premier temps du dodo
        flag_couche = !flag_couche; //Je change les flags en endormi
        digitalWrite(PIN_JOUR, LOW);
        digitalWrite(PIN_NUIT, HIGH);
      }
    }
  }


  return flag_couche;
}
