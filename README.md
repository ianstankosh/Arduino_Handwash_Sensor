# Arduino_Handwash_Sensor
This hardware/software project ensures you wash your hands for 20 seconds.

This project was inspired by: https://create.arduino.cc/projecthub/the-tech-lab/fight-coronavirus-simple-handwash-timer-4dc8ac?ref=tag&ref_id=beginner&offset=0

I used the above idea and added an active buzzer and 1 digit 7 segement LED for countdown. I then took the project a step further by creating an Arduino shield by soldering the components to prototyping board.

The following files are included in this repository:

**handwash_timer.ino** - the original code used to run the breadboard version of this project

**handwash_timer_schem.pdf** - the schematic for the breadboard version of this project

**handwash_timer_pcb.ino** - the code for the prototype board version of this project. Note that I did not use the timer in this shield, as the 1 digit display requires 10 inputs/outputs and I was trying to save space on the board. Also note that some of the pin assignments have changed due componenet position on shield.

See included images for reference.
