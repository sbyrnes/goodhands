Circuit Schematic
=====
Current circuit design for only finger tip sensing. 

Note that the finger capacitors are not actually part of the circuit, as they are the element being estimated. Instead, the wires terminate into a large conducting surface that is covered with a dielectric so that when your finger touches the dielectric it forms a capacitor. 

Notes:
 * 1 M Ohm resistors seem to work well for requiring a close touch for detection. 
 * 220 Ohm resistors required for LEDs as per specs.
 * Some small (10 ohm) resistors between the pad and the sensor pins would be a good idea in case of accidental circult closure.
 * 

![Circuit Diagram](https://raw.githubusercontent.com/sbyrnes/goodhands/master/circuit/goodhands.png)
