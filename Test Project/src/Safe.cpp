#include <Arduino.h>
#include "safe.h"
#include <time.h>

// put function declarations here:
Safe::Safe(){
  srand( time (NULL));
  int randomNumber = rand() % 1000;
  sprintf(_passcode, "%04d", randomNumber);
}

void Safe::compareCode(int *buf, String entry){
  char entryChars[5];
  entry.toCharArray(entryChars,5,0);
  for(int i=0; i<4; i++){
    if(entryChars[i]==_passcode[i]) buf[i] = -5;
    else{
      buf[i] = buf[i]+1;
    }
  }
}

char Safe::getChar(int i){
  return _passcode[i];
}

