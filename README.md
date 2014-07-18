![GoodHands Logo](https://raw.githubusercontent.com/sbyrnes/goodhands/master/images/goodhands.png)


A prototype glove for controlling mobile applications via finger movements. Currently in prototyping stages.

Project Goals
-----
The goal of the GoodHands project is to create a glove which, using multiple sensors, allows the user to communicate with their phone using various finger positions and movements.

There are various applications of this kind of wearable:
 1. Allow for robust phone control without looking at a screen (phone or watch).
 2. Enable your phone to act as a speech generator for sign language.
 3. Observation and recording of finger movements when performing a task.

Of these, the sign language application is the major motivation as it could provide meaningful quality of life improvements for some people. Part of the GoodHands project will include a simple Android Application to teach the American Sign Language alphabet.

Note that while some of these applications can be achieve with remote motion sensors (such as Kinect) or through gesture detectors, this is designed to be used in an arbitrary location and be sensitive to very detailed finger configurations.
As such, the glove needs to be entirely self contained and work in any orientation or environment, making the use of external cameras impractical.

Technical Components
-----
While the design of the prototype is still underway, it will be based on an Arduino Uno microcontroller.

You can find both the Arduino software and the circuit schematics in the respective subdirectories of this project.
To view the circuit diagrams, you will need to download Fritzing (http://fritzing.org/home/), a free schematics tool for Arduino projects.

Challenges
-----
Challenges are significant for any hardware project. In this particular case, major challenges that need to be investigated and overcome include:
 * Finding a sensor type that is small enough and cheap enough to create a sensor matrix throughout a glove. Initial investigation has centered on capacitive sensors which are promising but may not work in real world applications.
 * Enabling Bluetooth Low Energy (BLE) communication between the glove and the phone at a reasonable price point. There is a lack of well supported BLE shields for Arduino (at least as identified so far).
 * Ensuring that the glove, when done, does not meaningfully impede normal behavior and/or feeling.
