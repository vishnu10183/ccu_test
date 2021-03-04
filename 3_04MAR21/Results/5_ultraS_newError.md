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
 2cm | 29.80 'C | 29.80 'C | 3 | 2.651 | 0.651 | 2.451 | 0.451 
 3cm | 29.80 'C | 29.80 'C | 3 | 2.651 | -0.349 | 3.371 | 0.371 
 4cm | 29.90 'C | 29.80 'C | 2 | 3.122 | -0.878 | 3.922 | -0.078 
 5cm | 29.80 'C | 29.90 'C | 3 | 4.116 | -0.884 | 4.936 | -0.064 
 6cm | 29.80 'C | 29.80 'C | 3 | 5.093 | -0.907 | 5.933 | -0.067 
 7cm | 29.80 'C | 29.80 'C | 2 | 6.000 | -1.0 | 6.85 | -0.15 
 8cm | 29.80 'C | 29.80 'C | 2 | 7.535 | -0.465 | 8.385 | 0.385 
 9cm | 29.80 'C | 29.80 'C | 3 | 8.024 | -0.976 | 8.874 | -0.126 
 10cm | 29.90 'C | 29.80 'C | 3 | 9.000 | -1.0 | 9.85 | -0.15 
 11cm | 29.90 'C | 29.90 'C | 4 | 9.908 | -1.092 | 10.758 | -0.242 
 12cm | 29.90 'C | 29.80 'C | 4 | 11.425 | -0.575 | 11.925 | -0.075 
 13cm | 29.90 'C | 29.90 'C | 3 | 12.402 | -0.598 | 12.902 | -0.098 
 14cm | 29.90 'C | 29.90 'C | 2 | 13.449 | -0.551 | 13.949 | -0.051 
 15cm | 29.90 'C | 29.90 'C | 3 | 14.425 | -0.575 | 15.025 | 0.025 
 16cm | 29.90 'C | 29.90 'C | 3 | 15.402 | -0.598 | 15.962 | -0.038 
 17cm | 29.90 'C | 29.90 'C | 3 | 16.379 | -0.621 | 16.929 | -0.071 
 18cm | 29.90 'C | 29.90 'C | 2 | 17.426 | -0.574 | 17.966 | -0.034 
 19cm | 29.80 'C | 29.90 'C | 2 | 18.385 | -0.615 | 18.925 | -0.075 
 20cm | 29.90 'C | 29.90 'C | 3 | 19.362 | -0.638 | 19.902 | -0.098 
 