# **Ultrasonic Sensor Measurement - VNC Server : OFF**
### *- C code (WiringPi) including Threading(pThread)*
### *- Set Priority(-20), Set Affinity to Core 2*
### *- DHT22 for Temperature Factor (Any of 2 readings)*
### *- Material Used : Metal*
### *- No. of Observations = 5 @ 25ms interval*
### *- Height of HC-SR04 from test floor = 14.5 cm*
### *- Python Code to automate storing & finding error rate.*
### *- Updated code to use error term, and calculate new value and new error rate.*

Actual | Temp. 1 | Temp. 2 | Repeat Count | Repeat Value | Error Rate | New Value | New Error Rate
---- | ---- | ---- | ---- | ---- | ---- | ---- | ----
 11cm | 26 'C | 40.60 | 4 | 12.9 | 1.9 | 13.75 | 2.75 
 11cm | 26 'C | 43.00 | 4 | 10.8 | -0.2 | 11.65 | 0.65 
 12cm | 26 'C | 42.80 | 3 | 11.0 | -1.0 | 11.5 | -0.5 
 