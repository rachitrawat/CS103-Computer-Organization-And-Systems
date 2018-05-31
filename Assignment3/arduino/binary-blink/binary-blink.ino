int val;

void setup() {

  // set val (8 bit value)
  val = 5;

  // open the serial port at 9600 bps
  Serial.begin(9600);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

}

void binary(int num)
{
    int rem;
 
    if (num <= 1)
    {
     LED_BLINK_1();
     Serial.print(num);
      return;
    }
    rem = num % 2;
    
    binary(num / 2);

     delay(500);          //gap b/w bits 500ms
     if(rem == 1){
        LED_BLINK_1();
    }
    else{
        LED_BLINK_0();
    }

    Serial.print(rem);

}


void LED_BLINK_1(){
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(150);                        // wait for 150 ms
        digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
        delay(150);
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(150);
        digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}

void LED_BLINK_0(){
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);                       // wait for 1 sec
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
}

void loop() {
  // at the beginning of every 10 secs, 
  // blink out the 8 bits of "val" using the built in LED
  // bit 1 - two quick short blinks
  // bit 0 - one long blink
  // gap between bits - 500 ms

    delay(10000);                       // wait for 10 second
    binary(val);
    Serial.print("\n");

}

