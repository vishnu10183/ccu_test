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
 2cm | 29.90 'C | 30.10 'C | 2 | 2.219 | 0.219 | 2.019 | 0.019 
 3cm | 30.10 'C | 30.20 'C | 3 | 2.708 | -0.292 | 3.428 | 0.428 
 4cm | 30.20 'C | 30.20 'C | 3 | 3.617 | -0.383 | 4.417 | 0.417 
 5cm | 30.20 'C | 30.20 'C | 3 | 4.176 | -0.824 | 4.996 | -0.004 
 6cm | 30.20 'C | 30.20 'C | 3 | 5.084 | -0.916 | 5.924 | -0.076 
 7cm | 30.20 'C | 30.20 'C | 3 | 6.080 | -0.92 | 6.93 | -0.07 
 8cm | 30.20 'C | 30.20 'C | 2 | 7.059 | -0.941 | 7.909 | -0.091 
 9cm | 30.20 'C | 30.10 'C | 3 | 8.090 | -0.91 | 8.94 | -0.06 
 10cm | 30.20 'C | 30.10 'C | 3 | 9.069 | -0.931 | 9.919 | -0.081 
 11cm | 30.10 'C | 30.10 'C | 4 | 10.047 | -0.953 | 10.847 | -0.153 
 12cm | 30.10 'C | 30.10 'C | 3 | 11.497 | -0.503 | 12.247 | 0.247 
 13cm | 30.10 'C | 30.20 'C | 4 | 12.476 | -0.524 | 13.176 | 0.176 
 14cm | 30.20 'C | 30.20 'C | 3 | 13.472 | -0.528 | 14.122 | 0.122 
 15cm | 30.20 'C | 30.10 'C | 4 | 14.450 | -0.55 | 15.05 | 0.05 
 16cm | 30.10 'C | 30.10 'C | 4 | 15.062 | -0.938 | 15.622 | -0.378 
 17cm | 30.10 'C | 30.10 'C | 2 | 15.988 | -1.012 | 16.538 | -0.462 
 18cm | 30.10 'C | 30.10 'C | 2 | 17.439 | -0.561 | 17.979 | -0.021 
 19cm | 30.10 'C | 30.10 'C | 4 | 18.487 | -0.513 | 19.027 | 0.027 
 20cm | 30.10 'C | 30.10 'C | 2 | 19.448 | -0.552 | 19.988 | -0.012 
 