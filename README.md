#  :fire: Fire Alarm :fire:

## :clipboard: Description
### What is it?
This is an application with nextion tft display.

Simulate a conventional fire alarm panel.

![Fire](https://github.com/vinimyls/Fire_Panel/blob/main/pic/smoke.gif)

### How this work?

If the smoke detector found smoke, it goes into alarm.

This event will increase the current over the resistors 1k and 220R, generating a digital signal at arduino's input.

the Nextion display will warm about the fire, allowing the system to be reset.


## :computer: Code

- [Code](https://github.com/vinimyls/Fire_Panel/blob/main/fire_panel/fire_panel.ino)
- [HMI file for nextion editor](https://github.com/vinimyls/Fire_Panel/blob/main/smoke.HMI)
## :electric_plug: Hardware
- ![Diagram](https://github.com/vinimyls/Fire_Panel/blob/main/pic/diagram.png)
## :warning: Prerequisites
- Arduino
- Nextion display (in this example model NX8048T050)
- Relay model 5Vcc
- [Nextion official library for arduino](https://github.com/itead/ITEADLIB_Arduino_Nextion)
- [Nextion Editor for HMI](https://nextion.tech/nextion-editor/)


A subtle modification in NexConfig.h

    add '//' in line  #define DEBUG_SERIAL_ENABLE 
    modify the "nexSerial Serial2" for "nexSerial Serial" 
![Modify](https://github.com/vinimyls/Fire_Panel/blob/main/pic/modify.png)
