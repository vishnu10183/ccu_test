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
 2cm | 26.80 'C | 26.70 'C | 3 | 2.255 | 0.255 | 2.055 | 0.055 
 3cm | 26.70 'C | 26.80 'C | 3 | 2.672 | -0.328 | 3.392 | 0.392 
 4cm | 26.70 'C | 26.80 'C | 2 | 3.644 | -0.356 | 4.444 | 0.444 
 5cm | 26.80 'C | 26.80 'C | 3 | 4.598 | -0.402 | 5.418 | 0.418 
 6cm | 26.80 'C | 26.80 'C | 3 | 5.639 | -0.361 | 6.479 | 0.479 
 7cm | 26.80 'C | 26.80 'C | 2 | 6.090 | -0.91 | 6.94 | -0.06 
 8cm | 26.80 'C | 26.70 'C | 1 | 7.062 | -0.938 | 7.912 | -0.088 
 9cm | 26.80 'C | 26.80 'C | 2 | 8.069 | -0.931 | 8.919 | -0.081 
 10cm | 26.80 'C | 26.80 'C | 3 | 9.544 | -0.456 | 10.394 | 0.394 
 11cm | 26.80 'C | 26.80 'C | 3 | 9.960 | -1.04 | 10.81 | -0.19 
 12cm | 26.80 'C | 26.80 'C | 2 | 11.487 | -0.513 | 11.987 | -0.013 
 13cm | 26.70 'C | 26.80 'C | 2 | 12.528 | -0.472 | 13.028 | 0.028 
 14cm | 26.70 'C | 26.70 'C | 2 | 13.465 | -0.535 | 13.965 | -0.035 
 15cm | 26.70 'C | 26.70 'C | 1 | 14.420 | -0.58 | 15.02 | 0.02 
 16cm | 26.70 'C | 26.70 'C | 2 | 15.496 | -0.504 | 16.056 | 0.056 
 17cm | 26.60 'C | 26.60 'C | 2 | 16.467 | -0.533 | 17.017 | 0.017 
 18cm | 26.60 'C | 26.60 'C | 3 | 17.491 | -0.509 | 18.031 | 0.031 
 19cm | 26.60 'C | 26.60 'C | 3 | 18.480 | -0.52 | 19.02 | 0.02 
 20cm | 26.60 'C | 26.60 'C | 2 | 19.018 | -0.982 | 19.558 | -0.442 
 