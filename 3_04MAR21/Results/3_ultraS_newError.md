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
 2cm | 30.10 'C | 30.00 'C | 3 | 2.586 | 0.586 | 2.386 | 0.386 
 3cm | 30.00 'C | 30.00 'C | 2 | 2.656 | -0.344 | 3.376 | 0.376 
 4cm | 30.00 'C | 30.00 'C | 3 | 3.617 | -0.383 | 4.417 | 0.417 
 5cm | 30.10 'C | 30.00 'C | 4 | 4.176 | -0.824 | 4.996 | -0.004 
 6cm | 30.10 'C | 30.10 'C | 3 | 5.574 | -0.426 | 6.414 | 0.414 
 7cm | 30.10 'C | 30.10 'C | 2 | 6.063 | -0.937 | 6.913 | -0.087 
 8cm | 30.10 'C | 30.10 'C | 3 | 7.478 | -0.522 | 8.328 | 0.328 
 9cm | 30.10 'C | 30.10 'C | 3 | 8.509 | -0.491 | 9.359 | 0.359 
 10cm | 30.10 'C | 30.10 'C | 3 | 9.488 | -0.512 | 10.338 | 0.338 
 11cm | 30.10 'C | 30.10 'C | 3 | 10.484 | -0.516 | 11.334 | 0.334 
 12cm | 30.10 'C | 30.10 'C | 2 | 11.445 | -0.555 | 11.945 | -0.055 
 13cm | 30.10 'C | 30.10 'C | 2 | 12.476 | -0.524 | 12.976 | -0.024 
 14cm | 30.10 'C | 30.10 'C | 3 | 13.472 | -0.528 | 13.972 | -0.028 
 15cm | 30.10 'C | 30.10 'C | 4 | 14.450 | -0.55 | 15.05 | 0.05 
 16cm | 30.10 'C | 30.10 'C | 3 | 15.481 | -0.519 | 16.041 | 0.041 
 17cm | 30.10 'C | 30.10 'C | 4 | 16.460 | -0.54 | 17.01 | 0.01 
 18cm | 30.10 'C | 30.10 'C | 4 | 17.439 | -0.561 | 17.979 | -0.021 
 19cm | 30.20 'C | 30.10 'C | 3 | 18.470 | -0.53 | 19.01 | 0.01 
 20cm | 30.10 'C | 30.10 'C | 2 | 19.466 | -0.534 | 20.006 | 0.006 
 