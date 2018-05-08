const int Last = 100;// sets a limit
const int last = 4;

const int buttonPin= 13;  // the number of the pushbutton pin 13
const int buttonPin2 = 12; // the number of the pushbutton pin 12
const int buttonPin3 = 11;  // the number of the pushbutton pin 11

const int ledPin =  1;// first LED connected to digital pin 1
const int ledPin2 =  2; // second LED connected to digital pin 2
const int ledPin3 =  3;// third LED connected to digital pin 3

const int buzzer = 9; //the number of the buzzer pin 9
int buttonState = 0; // variable for reading the pushbutton status
int level = 1; // the game level
int speedd = 1000; // the game velocity
int sequence[Last];//generated array by computer
int input[Last];//user entry array




void setup(){
  // initializing the three LEDs and the buzzer pins as outputs:
  // initializing the three pushbutton pins as inputs:
  pinMode(ledPin3, OUTPUT);  // sets the digital pin 3 as output
  pinMode(ledPin2, OUTPUT);  // sets the digital pin 2 as output
  pinMode(ledPin, OUTPUT);  // sets the digital pin 1 as output
  
  pinMode(buttonPin, INPUT); // sets the digital pin 13 as an input
  pinMode(buttonPin2, INPUT); // sets the digital pin 12 as an input
  pinMode(buttonPin3, INPUT); // sets the digital pin 11 as an input

  pinMode(buzzer, OUTPUT); // Set buzzer pin 9 as an output
}

void loop(){ // a function to keep the game going by caliing all the function togather
  pattern(); // calling the patteern function
     display(); // calling the diplay function
  GetInput();  // calling the obtaininput function 
}

void pattern(){ // a function to randomize the pattern 
randomSeed(millis()); // using random funnction to randomize the pattern
for(int i = 0; i < Last; i++){
   sequence[i] = random(1,4);
}
}

void display(){
  digitalWrite(ledPin, LOW); // sets the LED on digital pin 1 off
   digitalWrite(ledPin2, LOW); // sets the LED on digital pin 2 off
    digitalWrite(ledPin3, LOW); // sets the LED on digital pin 3 off
for (int i = 0; i < level; i++){ // a loop to randomly turn on one of the LEDs 
digitalWrite(sequence[i], HIGH); // sets the random digital pin on 
   delay(speedd);
digitalWrite(sequence[i], LOW); // // sets the random digital pin off 
   delay(200); // waits for a 0.2 second
}
}

void GetInput(){ // a function to check the user's input sequence 
  
int flag = 0; //this flag indicates if the sequence is correct
for (int i = 0; i < level; i++){
flag = 0;
while(flag == 0){
if (digitalRead(buttonPin) == LOW){ // if the button is being pressed 
      digitalWrite(ledPin2, HIGH); // sets the LED on digital pin 2 on
input[i] = 2;
flag = 1;
delay(200);
if (input[i] != sequence[i]){ // if the user press the wrong button
wrong(); // it will return to the incorrect function
return;
}
digitalWrite(ledPin2, LOW); // sets the LED on digital pin 2 off
}
  if (digitalRead(buttonPin2) == LOW){ // if the button is being pressed
        digitalWrite(ledPin3, HIGH); // sets the LED on digital pin 3 on
input[i] = 3;
flag = 1;
delay(200);
if (input[i] != sequence[i]){ // if the user press the wrong button
wrong(); // it will return to the incorrect function
return;
}
digitalWrite(ledPin3, LOW); // sets the LED on digital pin 3 off
}
if (digitalRead(buttonPin3) == LOW){ // if the button is being pressed 
digitalWrite(ledPin, HIGH); // sets the LED on digital pin 1 on
input[i] = 1;
flag = 1;
delay(200);
if (input[i] != sequence[i]){ // if the user press the wrong button
wrong();// it will return to the incorrect function
return;
}
digitalWrite(ledPin, LOW); // sets the LED on digital pin 1 off
}
}
}
right(); // otherwise it will return to the correct function
}


void wrong(){ // when the user inputs an incorrect sequence
  for (int i = 0; i < 3; i++){
  digitalWrite(ledPin, HIGH); // sets the LED on digital pin 1 on
    digitalWrite(ledPin2, HIGH); // sets the LED on digital pin 2 on
      digitalWrite(ledPin3, HIGH); // sets the LED on digital pin 2 on
  tone(buzzer, 261, 1000); 
 delay(1000); // waits for a second
  tone(buzzer, 196, 200);
 delay(200); // waits for 0.2 second
  tone(buzzer, 185, 200);
 delay(200); // waits for 0.2 second
  tone(buzzer, 175, 200);
 delay(200); // waits for 0.2 second
  tone(buzzer, 165, 200);
 delay(200); // waits for 0.2 second
  tone(buzzer, 155, 200);
 delay(200); // waits for 0.2 second
  digitalWrite(ledPin, LOW); /// sets the LED on digital pin 1 off
   digitalWrite(ledPin2, LOW); // sets the LED on digital pin 2 off
    digitalWrite(ledPin3, LOW); // sets the LED on digital pin 3 off
} //all the LEDs turn on making a special sound 
level = 1; // the game starts all over again from level one 
speedd = 1000; 
}
void right(){ //when the user inputs a correct sequence, all the LEDs turn On indicating that the sequence is correct
  
digitalWrite(ledPin, LOW); /// sets the LED on digital pin 1 off
   digitalWrite(ledPin2, LOW); // sets the LED on digital pin 2 off
      digitalWrite(ledPin3, LOW); // sets the LED on digital pin 3 off
delay(250); // waits for 0.25 second
digitalWrite(ledPin, HIGH); // sets the LED on digital pin 1 on
  digitalWrite(ledPin2, HIGH); // sets the LED on digital pin 2 on
    digitalWrite(ledPin3, HIGH); // sets the LED on digital pin 3 on
delay(1000);  // waits for a second
if (level < last){ // the game starts again and it increases the level 
level++;
}
}
