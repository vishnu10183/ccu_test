# **Ultrasonic Sensor Measurement - VNC Server : OFF**
### *- C code (WiringPi) including Threading(pThread)*
### *- Set Priority(-20), Set Affinity to Core 2*
### *- DHT22 for Temperature Factor (Avg. of 2 readings)*
### *- Material Used : Metal*
### *- No. of Observations = 5 @ 25ms interval*
### *- Height of HC-SR04 from test floor = 14.5 cm*
### *- Python Code to automate storing & finding error rate.*
### *- Updated code to use error term, and calculate new value and new error rate.*

Actual | Temp. 1 | Temp. 2 | Repeat Count | Repeat Value | Error Rate | New Value | New Error Rate
---- | ---- | ---- | ---- | ---- | ---- | ---- | ----
 2cm | 30.90 'C | 30.90 'C | 2 | 2.170 | 0.17 | 1.97 | -0.03 
 3cm | 31.00 'C | 30.90 'C | 4 | 2.712 | -0.288 | 3.4320000000000004 | 0.432 
 4cm | 30.90 'C | 30.90 'C | 3 | 3.692 | -0.308 | 4.492 | 0.492 
 5cm | 30.90 'C | 30.90 'C | 2 | 4.183 | -0.817 | 5.003 | 0.003 
 6cm | 31.00 'C | 30.90 'C | 2 | 5.162 | -0.838 | 6.002 | 0.002 
 7cm | 30.90 'C | 30.90 'C | 3 | 6.142 | -0.858 | 6.992 | -0.008 
 8cm | 30.90 'C | 30.80 'C | 3 | 7.053 | -0.947 | 7.903 | -0.097 
 9cm | 30.90 'C | 30.90 'C | 1 | 8.033 | -0.967 | 8.883 | -0.117 
 10cm | 30.90 'C | 30.90 'C | 2 | 9.083 | -0.917 | 9.933 | -0.067 
 11cm | 30.90 'C | 30.80 'C | 2 | 10.551 | -0.449 | 11.351 | 0.351 
 12cm | 30.90 'C | 30.80 'C | 3 | 11.513 | -0.487 | 12.263 | 0.263 
 13cm | 30.90 'C | 30.90 'C | 3 | 12.073 | -0.927 | 12.773 | -0.227 
 14cm | 30.90 'C | 30.90 'C | 3 | 13.475 | -0.525 | 14.125 | 0.125 
 15cm | 30.90 'C | 30.90 'C | 2 | 14.473 | -0.527 | 15.073 | 0.073 
 16cm | 30.90 'C | 30.90 'C | 4 | 15.506 | -0.494 | 16.066 | 0.066 
 17cm | 30.90 'C | 30.80 'C | 2 | 15.993 | -1.007 | 16.543 | -0.457 
 18cm | 30.80 'C | 30.90 'C | 1 | 17.396 | -0.604 | 17.936 | -0.064 
 19cm | 30.90 'C | 30.90 'C | 3 | 18.516 | -0.484 | 19.055999999999997 | 0.056 
 20cm | 30.90 'C | 30.90 'C | 3 | 19.478 | -0.522 | 20.018 | 0.018 
 