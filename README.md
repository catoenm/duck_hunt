# Duck-Hunt-Game

![](https://cloud.githubusercontent.com/assets/10454251/22278612/d9a8df90-e292-11e6-8721-14b62564cc96.gif)

## Hardware

This game was made on the [Keil MCB1700 board](http://www.keil.com/mcb1700), using many of it's available peripheral. In order to access these peripherals, _interrupts_ and _polling_ were used. 

### Peripherals

* __LCD Screen__: The LCD screen will display the images and graphics for the game.
* __Potentiometer__ : The potentiometer is used to adjust the flying speed of the ducks.
* __Joystick__: The joystick acts as a cursor that will be used to aim the crosshair at the target. In addition, the push down button for the joystick is used as the "shoot" button. 
* __LED Array__: The LED array (8 lights) will be used to keep track of the number of ducks that the user has successfully hit each round.

## Software and Tasks

The game uses _multithreading_ to split various functionalities of the game. 

__Examples of tasks__
* Task that polls for the joystick input
* Another task updates the scoreboard and other text on the screen. 

In addition, _semaphores_ were used to control access to variables that multiple tasks were dependent on.
