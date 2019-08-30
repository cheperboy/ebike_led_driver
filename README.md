![](https://github.com/cheperboy/ebike_led_driver/blob/master/pictures/rear_light.jpg)

# Motivation
Find it so weird to recharge almost every day a dedicated battery for the rear light of my cargo e-bike while a there is a huge battery onboard available on this bike to power the motor!

Power leds (3W) became so cheap and come with optics, it is perfect for any project needing efficient light system.
 
# Objective
The goal of this project is to realize a e-bike front/rear led lamp with following constraints:
1. Powered from dedicated 6v/2A power from the motor’s controller (Brose motor). No power bank or other battery than the e-bike battery!
2. Visibility / Efficiency as much as possible
3. As far as possible, a gentle design for led housing, well integrated to the bike frame (Douze Cycle cargo bike)
 
# Main design choices
* Use of Cree XP-E2 Led (front light: neutral white. Rear light: red)
* Led driver based on MOSFET and BJT transistor : cheap, versatile  
* Led housing made of 3/4" copper pipe (fits perfectly for XP-E2 leds)
 
# Circuit design
The available power from Brose motor is 14.6 W whose 3.6 W already used by a manufactured front lamp installed on the bike -> 11 W available for this project

## Schematic
See [constant current instructable led driver circuit](https://www.instructables.com/id/Power-LED-s---simplest-light-with-constant-current/) : Cheap and efficient, could work with input voltage up to 60 V. Low drop out voltage between input and output so it can drive two led in series from 6 volt input.

The value of R_sense limit the current through the led to 1A.

Dimming the led is achieved with pwm from Attiny85.

Rear light
The rear light has two modes:

Constant low power
Blink: alternate low power / high power light (best approach for visibility purpose)
Constant low power: pwm ratio is 10/255 -> about 0,25W

Blink: ​pwm ratio is 10/255 during 500 ms and 60/255 during 50 ms. -> about 0,35 W​ ​

Then about 10W still available for the front light (more than enough!)

Front light
The front light has two modes: OFF / ON (pwm dimmed to every available amps)

Below the general principle of the schematic.
![CircuitLab](https://github.com/cheperboy/ebike_led_driver/blob/master/hardware/led-driver-design.png)

## PCB / stripboard design
Components are soldered on a stripboard. it was intended to be a prototype but became the final circuit because works well and perfectly fits in the box.
Below the design of PCB including two drivers (front and rear lights).
![fritzing design](https://github.com/cheperboy/ebike_led_driver/blob/master/hardware/fritzing_img.png)

## PCB soldered
![PCB soldered](https://github.com/cheperboy/ebike_led_driver/blob/master/pictures/pcb_box.jpg)

# Led Housing
| ![cree_xpe2](https://github.com/cheperboy/ebike_led_driver/blob/master/pictures/cree_xpe2.jpg) | ![cree_xpe2_optic](https://github.com/cheperboy/ebike_led_driver/blob/master/pictures/cree_xpe2_optic.jpg)  |
|---|---|

Cree Led XP-E2 mounted on a 20 mm diameter pcb.
3/4" copper pipe has exactly enough room to hold it.
Led pcb is glued inside the tube.
The tube is mounted on a twisted aluminum plate.

| ![led_housing_before](https://github.com/cheperboy/ebike_led_driver/blob/master/pictures/led_housing_before.jpg) | ![led_housing_after](https://github.com/cheperboy/ebike_led_driver/blob/master/pictures/led_housing_after.jpg)  |
|---|---|

