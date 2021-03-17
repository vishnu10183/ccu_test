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
 11cm | 28 'C | 44.00 | 2 | 17.1 | 6.1 | 17.95 | 6.95 
 12cm | 26 'C | 42.00 | 1 | 16.3 | 4.3 | 16.8 | 4.8 
 11cm | 25 'C | 40.50 | 2 | 18.0 | 7.0 | 18.85 | 7.85 
 11cm | 25 'C | 42.60 | 2 | 17.1 | 6.1 | 17.95 | 6.95 
 12cm | 25 'C | 42.60 | 1 | 17.0 | 5.0 | 17.5 | 5.5 
 13cm | 25 'C | 40.40 | 2 | 17.2 | 4.2 | 17.7 | 4.7 
 14cm | 25 'C | 40.50 | 2 | 14.2 | 0.2 | 14.7 | 0.7 
 15cm | 25 'C | 40.10 | 2 | 15.5 | 0.5 | 16.1 | 1.1 
 16cm | 25 'C | 39.80 | 3 | 16.9 | 0.9 | 17.46 | 1.46 
 17cm | 25 'C | 39.60 | 2 | 17.8 | 0.8 | 18.35 | 1.35 
 