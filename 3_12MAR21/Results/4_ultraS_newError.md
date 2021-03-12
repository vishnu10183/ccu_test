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
 2cm | 26.60 'C | 26.30 'C | 4 | 1.752 | -0.248 | 1.552 | -0.448 
 3cm | 26.30 'C | 26.20 'C | 3 | 3.140 | 0.14 | 3.86 | 0.86 
 4cm | 26.20 'C | 26.20 'C | 3 | 3.626 | -0.374 | 4.426 | 0.426 
 5cm | 26.20 'C | 26.20 'C | 2 | 4.182 | -0.818 | 5.002 | 0.002 
 6cm | 26.20 'C | 26.00 'C | 4 | 5.171 | -0.829 | 6.011 | 0.011 
 7cm | 26.10 'C | 26.10 'C | 1 | 6.507 | -0.493 | 7.357 | 0.357 
 8cm | 26.20 'C | 26.20 'C | 1 | 7.114 | -0.886 | 7.964 | -0.036 
 9cm | 26.10 'C | 26.20 'C | 1 | 8.086 | -0.914 | 8.936 | -0.064 
 10cm | 26.20 'C | 26.20 'C | 2 | 9.110 | -0.89 | 9.96 | -0.04 
 11cm | 26.20 'C | 26.30 'C | 2 | 10.463 | -0.537 | 11.313 | 0.313 
 12cm | 26.20 'C | 26.30 'C | 2 | 10.966 | -1.034 | 11.466 | -0.534 
 13cm | 26.30 'C | 26.30 'C | 2 | 12.563 | -0.437 | 13.063 | 0.063 
 14cm | 26.30 'C | 26.40 'C | 3 | 13.483 | -0.517 | 13.983 | -0.017 
 15cm | 26.40 'C | 26.40 'C | 4 | 14.524 | -0.476 | 15.124 | 0.124 
 16cm | 26.40 'C | 26.50 'C | 2 | 15.409 | -0.591 | 15.969 | -0.031 
 17cm | 26.50 'C | 26.50 'C | 2 | 16.467 | -0.533 | 17.017 | 0.017 
 18cm | 26.60 'C | 26.60 'C | 1 | 16.971 | -1.029 | 17.511 | -0.489 
 19cm | 26.50 'C | 26.60 'C | 1 | 18.359 | -0.641 | 18.899 | -0.101 
 20cm | 26.60 'C | 26.60 'C | 2 | 19.487 | -0.513 | 20.027 | 0.027 
 