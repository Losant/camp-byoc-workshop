# Workshop 2 - LED Button

In this workshop, you'll learn how to wire and write a program to toggle an LED with a button through an Arduino MKR WIFI 1010.

[Wiring Diagram](https://files.onlosant.com/60db883643a55500077c070a/camp-byoc/wiring-diagram.png) | [Finished Project](https://files.onlosant.com/60db883643a55500077c070a/camp-byoc/finished-project.jpeg)
------ | ------
<img src="https://files.onlosant.com/60db883643a55500077c070a/camp-byoc/wiring-diagram.png" alt="Wiring Diagram" width="200"/>| <img src="https://files.onlosant.com/60db883643a55500077c070a/camp-byoc/finished-project.jpeg" alt="Finished Project" width="275"/>

## Wiring the Project

1. Push the Aruindo board into terminals 1–14 on either side of the center line, which are rows “C” and “J.” The USB port should be facing away from the breadboard.
2. Connect the Arduino's ground pin (GND) to the far right blue (negative) rail.
3. Connect GPIO 1 (1) to terminal A22 on the breadboard.
4. Connect the resistor from terminal B22 to terminal G22.
5. Connect the long end (positive) of the LED to terminal I22, and the short end (negative) to the blue (negative) rail.
6. Connect GPIO 2 (~2) to terminal A27 on the breadboard.
7. Connect the button to the breadboard. The pins in the button should connect to terminals E27, E29, F27, and F29.
8. Connect terminal J29 to the blue (negative) rail.

## Uploading and Running the Code

Plug the Arduino into the USB. In the Arduino code editor, go to the Tools menu. The following should be selected:

- Under the "Board" menu, "Arduino MKR WIFI 1010" should be selected.
- Under the "Port" menu, the port your Arduino is plugged into should be selected.

Once that's done, select File -> New. This will open a new file for you. Copy [the code for this workshop](https://github.com/Losant/camp-byoc-workshop/blob/main/workshop-2/sketch/sketch.ino) and paste it into the new file. Then, select Sketch -> Upload. This will put the code on the Arduino. Wait a few seconds for the upload to complete, then use the button on the breadboard to see your program in action!
