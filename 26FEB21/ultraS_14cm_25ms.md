# **Ultrasonic Sensor Measurement - VNC Server : OFF**
### *- C code (WiringPi) including Threading(pThread)*
### *- Set Priority(-20), Set Affinity to Core 2*
### *- DHT22 for Temperature Factor (Avg. of 2 readings)*
### *- Material Used : Metal*
### *- No. of Observations = 5 @ 25ms interval*
### *- Height of HC-SR04 from test floor = 14.5 cm*
### *- Python Code to automate storing & finding error rate.*

Actual | Temp. 1 | Temp. 2 | Obs. 1 | Obs. 2 | Obs. 3 | Obs. 4 | Obs. 5 | Repeat Count | Repeat Value | Error Rate
---- | ---- | ---- | ---- | ---- | ---- | ---- | ----| ---- | ---- | ---- 
 10cm | 30.00 'C | 29.90 'C | 9.434 | 9.557 | 9.557 | 9.557 | 9.539 | 3 | 9.556 | -0.444
 15cm | 29.80 'C | 29.90 'C | 13.977 | 7.023 | 14.274 | 14.082 | 14.064 | 1 | 13.976 | -1.024
 20cm | 29.90 'C | 29.90 'C | 19.375 | 19.463 | 19.445 | 19.445 | 19.463 | 2 | 19.445 | -0.555
 