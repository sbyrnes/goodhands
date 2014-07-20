Circuit Schematic
=====
Current circuit design for only finger tip sensing. 

Note that the finger capacitors are not actually part of the circuit, as they are the element being estimated. Instead, the wires terminate into a large conducting surface that is covered with a dielectric so that when your finger touches the dielectric it forms a capacitor. 

Notes:
 * 1 M Ohm resistors seem to work well for requiring a close touch for detection. However, the detecting capacitance seems to vary by person, indicating that some auto-calibration might be necessary.
 * 220 Ohm resistors required for LEDs as per specs.
 * Some small (10 ohm) resistors between the pad and the sensor pins would be a good idea in case of accidental circult closure. Not using this in Mark 1 but considering the high variance in detection and degradation over time while using it this should be in Mark 2.

WARNING: There is a mistake in the circuit diagram where the outputs are offset by two pins. So 3 should be 5, 5 should be 7, etc. Either fix it in your circuit or change the code.

![Circuit Diagram](https://raw.githubusercontent.com/sbyrnes/goodhands/master/circuit/goodhands.png)
