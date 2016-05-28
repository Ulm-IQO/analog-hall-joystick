/* Test program to calibrate joystick offset and range */

/* Run with Teensyduino on a Teensy 3.x board */

/* Analog input pins after scaling, before offset stage.
   There is an X axis, Y axis and two Z axes.
*/
int xppin = A1;
int yppin = A2;
int z1ppin = A3;
int z2ppin = A4;

/* Analog input pins after scaling and offset */
int xopin = A5;
int yopin = A6;
int z1opin = A7;
int z2opin = A8;

/* LED */
int ledpin = 13;

void setup() {                
  Serial.begin(38400);

  analogReadResolution(12);

  pinMode(ledpin, OUTPUT); 
  pinMode(xppin,INPUT);
  pinMode(yppin,INPUT);
  pinMode(z1ppin,INPUT);
  pinMode(z2ppin,INPUT);

  pinMode(xopin,INPUT);
  pinMode(yopin,INPUT);
  pinMode(z1opin,INPUT);
  pinMode(z2opin,INPUT);
}

int xpre, ypre, z1pre, z2pre, xpost, ypost, z1post, z2post;

void loop() {
  xpre = analogRead(xppin)*16;
  ypre = analogRead(yppin)*16;
  z1pre = analogRead(z1ppin)*16;
  z2pre = analogRead(z2ppin)*16;
  xpost = analogRead(xopin)*16;
  ypost = analogRead(yopin)*16;
  z1post = analogRead(z1opin)*16;
  z2post = analogRead(z2opin)*16;
  
  Serial.print(xpre);
  Serial.print(" ");
  Serial.print(ypre);
  Serial.print(" ");
  Serial.print(z1pre);
  Serial.print(" ");
  Serial.print(z2pre);
  Serial.print(" ");
  Serial.print(xpost);
  Serial.print(" ");
  Serial.print(ypost);
  Serial.print(" ");
  Serial.print(z1post);
  Serial.print(" ");
  Serial.print(z2post);
  Serial.println();
  
  digitalWrite(ledpin, HIGH);
  delay(250);
  digitalWrite(ledpin, LOW);
  delay(250);
}

