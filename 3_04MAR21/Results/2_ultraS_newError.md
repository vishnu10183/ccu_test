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
 2cm | 30.00 'C | 29.90 'C | 4 | 2.215 | 0.215 | 2.015 | 0.015 
 3cm | 29.90 'C | 29.90 'C | 4 | 2.215 | -0.785 | 2.935 | -0.065 
 4cm | 29.90 'C | 30.00 'C | 4 | 3.197 | -0.803 | 3.997 | -0.003 
 5cm | 30.00 'C | 30.10 'C | 2 | 4.123 | -0.877 | 4.943 | -0.057 
 6cm | 30.10 'C | 30.10 'C | 3 | 5.591 | -0.409 | 6.431 | 0.431 
 7cm | 30.10 'C | 30.10 'C | 4 | 6.500 | -0.5 | 7.35 | 0.35 
 8cm | 30.10 'C | 30.10 'C | 4 | 7.111 | -0.889 | 7.961 | -0.039 
 9cm | 30.10 'C | 30.20 'C | 3 | 8.527 | -0.473 | 9.377 | 0.377 
 10cm | 30.10 'C | 30.10 'C | 2 | 9.488 | -0.512 | 10.338 | 0.338 
 11cm | 30.10 'C | 30.10 'C | 2 | 10.484 | -0.516 | 11.334 | 0.334 
 12cm | 30.10 'C | 30.20 'C | 2 | 11.008 | -0.992 | 11.508 | -0.492 
 13cm | 30.20 'C | 30.10 'C | 3 | 12.057 | -0.943 | 12.557 | -0.443 
 14cm | 30.10 'C | 30.20 'C | 4 | 12.983 | -1.017 | 13.483 | -0.517 
 15cm | 30.10 'C | 30.10 'C | 2 | 14.433 | -0.567 | 15.033 | 0.033 
 16cm | 30.10 'C | 30.10 'C | 2 | 15.481 | -0.519 | 16.041 | 0.041 
 17cm | 30.10 'C | 30.10 'C | 3 | 16.041 | -0.959 | 16.591 | -0.409 
 18cm | 30.10 'C | 30.10 'C | 3 | 16.967 | -1.033 | 17.507 | -0.493 
 19cm | 30.10 'C | 30.10 'C | 2 | 18.417 | -0.583 | 18.957 | -0.043 
 20cm | 30.10 'C | 30.10 'C | 4 | 19.466 | -0.534 | 20.006 | 0.006 
 