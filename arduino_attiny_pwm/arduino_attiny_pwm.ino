/*
Use of timer to blink led
Library fit for Attiny85
https://github.com/PaulStoffregen/TimerOne/blob/master/examples/ATTiny85/ATTiny85.ino	
*/

#include <TimerOne.h>

// PIN assignement
#define out_pwm_rear 	0 	// PB0 Pin5 OUTPUT PWM Front Led
#define out_pwm_front 	1 	// PB1 Pin6 OUTPUT PWM Rear led
#define in_button_rear 	A2 	// A2 Pin3 INPUT_PULLUP button
#define in_button_front A3 	// A3 Pin2 INPUT_PULLUP button

// Brightness PWM values
#define brightness_rear_low 	10
#define brightness_rear_high 	60

// Delay timer values
#define delay_rear_led_low 	500000 // 500 ms
#define delay_rear_led_high 50000 // 50 ms

// State memorisation
int rear_led_state = LOW;
int requested_state = LOW;

void setup() {
	pinMode(out_pwm_rear, 	 OUTPUT);
	pinMode(out_pwm_front,	 OUTPUT);
	pinMode(in_button_rear,  INPUT_PULLUP);
	pinMode(in_button_front, INPUT_PULLUP);
	Timer1.initialize(delay_rear_led_low); // Enable Timer1
	analogWrite(out_pwm_rear, brightness_rear_low);
}

void manage_led_rear(bool requested_state) {
	if (requested_state == LOW) {
		Timer1.detachInterrupt(); // Disable Timer1
		analogWrite(out_pwm_rear, brightness_rear_low); // produces PWM (range 0 to 255) with low brightness
	}
	else {
		blink_rear_led();
	}
}
void blink_rear_led(){
	/* Manage rear led blinking
	low pwm value during delay_rear_led_low
	high pwm value during delay_rear_led_high
	*/
	if (rear_led_state == HIGH)
	{
		analogWrite(out_pwm_rear, brightness_rear_low);
		rear_led_state = LOW;
		Timer1.initialize(delay_rear_led_low);
		Timer1.attachInterrupt(blink_rear_led);	
	}
	else
	{
		analogWrite(out_pwm_rear, brightness_rear_high);
		rear_led_state = HIGH;
		Timer1.initialize(delay_rear_led_high);
		Timer1.attachInterrupt(blink_rear_led);	
	}
}

void loop()
{	
	if (requested_state != digitalRead(in_button_rear)){
		requested_state = !requested_state;
		manage_led_rear(requested_state);
	}
}
