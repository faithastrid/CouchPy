#include <Sabertooth.h>
//Packet serial
Sabertooth STL(128);
Sabertooth STR(129);
//STL and STR refer to the different motor controllers

//later, we can comdense both motor controllers to one class such as
//Sabertooth ST [2] = { Sabertooth(128), Sabertooth(129) };

// Connections to make:
//   Arduino TX->1  ->  Sabertooth S1
//   Arduino GND    ->  Sabertooth 0V
//   Arduino VIN    ->  Sabertooth 5V (OPTIONAL, if you want the Sabertooth to power the Arduino)
// baud rate 9600
//dip switches for address 128
// 1 on
// 2 off
// 3 on
// 4 off
// 5 on
// 6 off

//dip switches for address 129
// 1 off
// 2 off
// 3 on
// 4 off
// 5 on
// 6 on
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SabertoothTXPinSerial.begin(9600);// start communication
  STL.setTimeout(10000); // this will cause the motor controls to stop all motors if a new input is not received in this timeframe
  STR.setTimeout(10000);
  //only works in increments of 100 milliseconds
  //this will stop motors on 10 seconds without new input

//  ST.setDeadband(20); //this will create a deadspot from -20 to 20
  //this will stop the motor if the incoming input is in the deadspot for one second
  //will help later to fine tune controller

    STL.setRamping(14); //this makes sure the motors dont burn themselves out when changing speed suddenly
    STR.setRamping(14);


   // STL.setMinVoltage(30);//will turn off motors if the voltage gets too low, such as low battery
   // STR.setMinVoltage(30);//Value = (desired volts-6) x 5 
 
    //ST.setMaxVoltage(71);//this will stop regenerative braking if they start producing more power than the battery can accept at a time
    //ST.setMaxVoltage(71);//Value = Desired Volts*5.12
    //according to the documentation this should not matter since we are using a battery, we can leave at default
}

void loop() {
  // put your main code here, to run repeatedly:    
    
      STL.motor(1, 50); //turn on motor 1
      delay(5000); //wait 5 sec
      STL.motor(1, 0); // turn off motor 1
      STL.motor(2, 50); // turn on motor 2
      delay(5000);//wait 5 sec
      STL.motor(2, 0); // turn off motor 2
      delay (5000);

      
      STR.motor(1, 50); //turn on motor 1
      delay(5000); //wait 5 sec
      STR.motor(1, 0); // turn off motor 1
      STR.motor(2, 50); // turn on motor 2
      delay(5000);//wait 5 sec
      STR.motor(2, 0); // turn off motor 2
    
  }
