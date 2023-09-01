## Circuit Design

I decided to use the Arduino platform and as my 2 outputs, I used a 5V DC motor and active buzzer. And my input device was an ultrasonic sensor.

![](REF-Images/Parts.png)

The idea of the project was to provide a handheld device for the blind, that would help them avoid physical obstacles. The system consisted of using the ultrasonic sensor to detect objects at certain ranges. At certain ranges, the DC motor will start spinning with an attached offset weight that will induce a vibration in the device.

This is the 3D-printed offset weight:
![](<img width="582" alt="image" src="https://github.com/UdhayanDherman17/Prototype-Sensor-For-Blind/assets/65906258/25db6689-58f5-4c79-9803-0dcec4f846c1">
)

This will alert the user and the closer the user approaches the obstacle the more aggressive the vibration. If the user is at an extremely unsafe distance the buzzer will alarm alerting others nearby for assistance.
