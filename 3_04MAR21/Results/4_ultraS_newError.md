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
 2cm | 30.00 'C | 30.00 'C | 4 | 2.219 | 0.219 | 2.019 | 0.019 
 3cm | 30.00 'C | 30.00 'C | 3 | 3.075 | 0.075 | 3.795 | 0.795 
 4cm | 29.90 'C | 29.90 'C | 2 | 3.610 | -0.39 | 4.41 | 0.41 
 5cm | 30.00 'C | 30.00 'C | 3 | 4.106 | -0.894 | 4.926 | -0.074 
 6cm | 30.00 'C | 30.00 'C | 2 | 5.102 | -0.898 | 5.942 | -0.058 
 7cm | 30.00 'C | 30.00 'C | 3 | 6.558 | -0.442 | 7.408 | 0.408 
 8cm | 30.00 'C | 30.00 'C | 2 | 7.059 | -0.941 | 7.909 | -0.091 
 9cm | 30.00 'C | 30.00 'C | 3 | 8.509 | -0.491 | 9.359 | 0.359 
 10cm | 30.00 'C | 30.10 'C | 2 | 8.999 | -1.001 | 9.849 | -0.151 
 11cm | 30.10 'C | 30.10 'C | 3 | 10.466 | -0.534 | 11.316 | 0.316 
 12cm | 30.10 'C | 30.10 'C | 3 | 11.445 | -0.555 | 11.945 | -0.055 
 13cm | 30.10 'C | 30.10 'C | 4 | 12.493 | -0.507 | 12.993 | -0.007 
 14cm | 30.10 'C | 30.10 'C | 3 | 13.524 | -0.476 | 14.024 | 0.024 
 15cm | 30.10 'C | 30.10 'C | 2 | 14.468 | -0.532 | 15.068 | 0.068 
 16cm | 30.10 'C | 30.10 'C | 3 | 15.429 | -0.571 | 15.989 | -0.011 
 17cm | 30.10 'C | 30.10 'C | 3 | 16.041 | -0.959 | 16.591 | -0.409 
 18cm | 30.10 'C | 30.10 'C | 3 | 17.439 | -0.561 | 17.979 | -0.021 
 19cm | 30.10 'C | 30.10 'C | 4 | 18.050 | -0.95 | 18.59 | -0.41 
 20cm | 30.10 'C | 30.10 'C | 2 | 19.396 | -0.604 | 19.936 | -0.064 
 