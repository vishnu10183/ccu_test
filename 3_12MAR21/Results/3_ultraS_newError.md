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
 2cm | 26.30 'C | 26.30 'C | 4 | 2.169 | 0.169 | 1.969 | -0.031 
 3cm | 26.30 'C | 26.30 'C | 2 | 3.158 | 0.158 | 3.878 | 0.878 
 4cm | 26.30 'C | 26.40 'C | 2 | 3.609 | -0.391 | 4.409 | 0.409 
 5cm | 26.40 'C | 26.40 'C | 2 | 4.615 | -0.385 | 5.435 | 0.435 
 6cm | 26.40 'C | 26.40 'C | 2 | 5.552 | -0.448 | 6.392 | 0.392 
 7cm | 26.40 'C | 26.40 'C | 3 | 6.073 | -0.927 | 6.923 | -0.077 
 8cm | 26.50 'C | 26.50 'C | 2 | 7.496 | -0.504 | 8.346 | 0.346 
 9cm | 26.50 'C | 26.50 'C | 2 | 8.502 | -0.498 | 9.352 | 0.352 
 10cm | 26.50 'C | 26.50 'C | 2 | 9.509 | -0.491 | 10.359 | 0.359 
 11cm | 26.50 'C | 26.60 'C | 3 | 10.498 | -0.502 | 11.348 | 0.348 
 12cm | 26.60 'C | 26.60 'C | 4 | 11.452 | -0.548 | 11.952 | -0.048 
 13cm | 26.60 'C | 26.60 'C | 2 | 12.528 | -0.472 | 13.028 | 0.028 
 14cm | 26.60 'C | 26.60 'C | 2 | 13.396 | -0.604 | 13.896 | -0.104 
 15cm | 26.60 'C | 26.60 'C | 2 | 14.437 | -0.563 | 15.037 | 0.037 
 16cm | 26.60 'C | 26.60 'C | 2 | 15.496 | -0.504 | 16.056 | 0.056 
 17cm | 26.60 'C | 26.60 'C | 2 | 16.433 | -0.567 | 16.983 | -0.017 
 18cm | 26.60 'C | 26.70 'C | 2 | 17.508 | -0.492 | 18.048 | 0.048 
 19cm | 26.70 'C | 26.70 'C | 3 | 18.463 | -0.537 | 19.003 | 0.003 
 20cm | 26.60 'C | 26.70 'C | 1 | 19.452 | -0.548 | 19.992 | -0.008 
 