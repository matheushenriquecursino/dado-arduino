int button = 2;
int bottomleft = 3;
int middleleft = 4;
int upperleft = 5;
int middle = 6;
int bottomright = 7;
int middleright = 8;
int upperright = 9;
int state = 0;
long randNumber;

void setup() {
 
  pinMode (bottomleft, OUTPUT);
  pinMode (middleleft, OUTPUT);
  pinMode (upperleft, OUTPUT);
  pinMode (middle, OUTPUT);
  pinMode (bottomright, OUTPUT);
  pinMode (middleright, OUTPUT);
  pinMode (upperright, OUTPUT);
  pinMode (button, INPUT);
  
  Serial.begin (9600);
  
  randomSeed (analogRead(0));
}

void loop (){
  
  if(digitalRead(button) ==HIGH && state ==0){
    state = 1;
    randNumber = random (1,7);
    delay (100);
	Serial.println(randNumber);
    
    if(randNumber == 6){
      six();
    }
    if(randNumber == 5){
      five();
    }
    if(randNumber == 4){
      four();
    }
    if(randNumber == 3){
      three();
    }
    if(randNumber == 2){
      two();
    }
    if(randNumber == 1){
      one();
    }
    
    delay (1000);
    clearAll();
    state = 0;
  }
}

void six (){
  digitalWrite (bottomleft, HIGH);
  digitalWrite (middleleft, HIGH);
  digitalWrite (upperleft, HIGH);
  digitalWrite (bottomright, HIGH);
  digitalWrite (middleright, HIGH);
  digitalWrite (upperright, HIGH);
}

void five(){
  
  digitalWrite (bottomleft, HIGH);
  digitalWrite (middle, HIGH);
  digitalWrite (upperleft, HIGH);
  digitalWrite (bottomright, HIGH);
  digitalWrite (upperright, HIGH);
}

void four (){
  digitalWrite (bottomleft, HIGH);
  digitalWrite (upperleft, HIGH);
  digitalWrite (bottomright, HIGH);
  digitalWrite (upperright, HIGH);
}

void three (){
  digitalWrite (middle, HIGH);
  digitalWrite (upperleft, HIGH);
  digitalWrite (bottomright, HIGH);
}

void two(){
  digitalWrite (bottomleft, HIGH);
  digitalWrite (upperright, HIGH);
}

void one(){
  digitalWrite (middle, HIGH);
}

void clearAll (){
  digitalWrite (bottomleft,  LOW);
  digitalWrite (middleleft, LOW);
  digitalWrite (middle, LOW);
  digitalWrite (upperleft, LOW);
  digitalWrite (bottomright, LOW);
  digitalWrite (middleright, LOW);
  digitalWrite (upperright, LOW);
}
