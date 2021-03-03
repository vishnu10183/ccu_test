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
 2cm | 30.90 'C | 30.90 'C | 2 | 2.292 | 0.292 | 2.492 | 0.492 
 3cm | 30.90 'C | 31.00 'C | 4 | 2.275 | -0.725 | 2.995 | -0.005 
 4cm | 31.00 'C | 30.90 'C | 3 | 3.202 | -0.798 | 4.002 | 0.002 
 5cm | 30.90 'C | 30.90 'C | 4 | 4.235 | -0.765 | 5.055000000000001 | 0.055 
 6cm | 30.90 'C | 30.90 'C | 3 | 5.652 | -0.348 | 6.492 | 0.492 
 7cm | 30.90 'C | 31.00 'C | 3 | 6.618 | -0.382 | 7.468 | 0.468 
 8cm | 30.90 'C | 31.00 'C | 3 | 7.124 | -0.876 | 7.973999999999999 | -0.026 
 9cm | 31.00 'C | 31.00 'C | 2 | 8.157 | -0.843 | 9.007 | 0.007 
 10cm | 31.00 'C | 30.90 'C | 3 | 9.573 | -0.427 | 10.423 | 0.423 
 11cm | 31.00 'C | 31.00 'C | 3 | 10.045 | -0.955 | 10.845 | -0.155 
 12cm | 30.90 'C | 30.90 'C | 3 | 11.025 | -0.975 | 11.775 | -0.225 
 13cm | 30.90 'C | 30.90 'C | 2 | 12.077 | -0.923 | 12.777 | -0.223 
 14cm | 31.00 'C | 30.90 'C | 2 | 13.548 | -0.452 | 14.198 | 0.198 
 15cm | 30.90 'C | 30.90 'C | 3 | 14.036 | -0.964 | 14.636 | -0.364 
 16cm | 30.90 'C | 30.90 'C | 4 | 15.506 | -0.494 | 16.066 | 0.066 
 17cm | 30.90 'C | 30.90 'C | 2 | 16.538 | -0.462 | 17.088 | 0.088 
 18cm | 30.90 'C | 31.00 'C | 3 | 17.466 | -0.534 | 18.006 | 0.006 
 19cm | 30.90 'C | 31.00 'C | 3 | 18.498 | -0.502 | 19.038 | 0.038 
 20cm | 30.90 'C | 30.90 'C | 4 | 19.058 | -0.942 | 19.598 | -0.402 
 