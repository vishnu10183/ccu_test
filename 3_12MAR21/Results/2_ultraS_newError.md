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
 2cm | 26.00 'C | 26.00 'C | 3 | 1.336 | -0.664 | 1.136 | -0.864 
 3cm | 25.90 'C | 26.00 'C | 2 | 2.654 | -0.346 | 3.374 | 0.374 
 4cm | 25.90 'C | 26.00 'C | 3 | 3.574 | -0.426 | 4.374 | 0.374 
 5cm | 26.00 'C | 26.00 'C | 3 | 4.667 | -0.333 | 5.487 | 0.487 
 6cm | 26.00 'C | 26.00 'C | 3 | 5.084 | -0.916 | 5.924 | -0.076 
 7cm | 26.00 'C | 26.00 'C | 2 | 6.489 | -0.511 | 7.339 | 0.339 
 8cm | 26.00 'C | 26.00 'C | 4 | 7.531 | -0.469 | 8.381 | 0.381 
 9cm | 26.00 'C | 26.10 'C | 2 | 8.554 | -0.446 | 9.404 | 0.404 
 10cm | 26.00 'C | 26.10 'C | 3 | 9.544 | -0.456 | 10.394 | 0.394 
 11cm | 26.10 'C | 26.10 'C | 2 | 9.995 | -1.005 | 10.845 | -0.155 
 12cm | 26.00 'C | 26.00 'C | 2 | 11.487 | -0.513 | 11.987 | -0.013 
 13cm | 26.00 'C | 26.10 'C | 2 | 12.528 | -0.472 | 13.028 | 0.028 
 14cm | 26.10 'C | 26.10 'C | 1 | 13.431 | -0.569 | 13.931 | -0.069 
 15cm | 26.10 'C | 26.10 'C | 2 | 14.472 | -0.528 | 15.072 | 0.072 
 16cm | 26.10 'C | 26.10 'C | 4 | 14.454 | -1.546 | 15.014 | -0.986 
 17cm | 26.10 'C | 26.10 'C | 1 | 15.461 | -1.539 | 16.011 | -0.989 
 18cm | 26.10 'C | 26.20 'C | 2 | 17.474 | -0.526 | 18.014 | 0.014 
 19cm | 26.10 'C | 26.20 'C | 2 | 17.977 | -1.023 | 18.517 | -0.483 
 20cm | 26.20 'C | 26.20 'C | 2 | 19.400 | -0.6 | 19.94 | -0.06 
 