# **Ultrasonic Sensor Measurement - VNC Server : OFF**
### *- C code (WiringPi) including Threading(pThread)*
### *- Set Priority(-20), Set Affinity to Core 2*
### *- DHT22 for Temperature Factor (Avg. of 2 readings)*
### *- Material Used : Metal*
### *- No. of Observations = 5 @ 10ms interval*
### *- Height of HC-SR04 from test floor = 14.5 cm*
### *- Python Code to automate storing & finding error rate.*

Actual | Temp. 1 | Temp. 2 | Obs. 1 | Obs. 2 | Obs. 3 | Obs. 4 | Obs. 5 | Repeat Count | Repeat Value | Error Rate
---- | ---- | ---- | ---- | ---- | ---- | ---- | ----| ---- | ---- | ----
 2cm | 29.80 'C | 29.60 'C | 2.253 | 2.340 | 2.358 | 2.288 | 2.323 | 0 | 0.000 | -2.000 
 2cm | 29.80 'C | 29.90 'C | 2.254 | 2.341 | 2.341 | 2.778 | 2.324 | 1 | 2.341 | 0.341 
 2cm | 29.90 'C | 29.80 'C | 2.253 | 2.341 | 2.341 | 2.341 | 2.341 | 3 | 2.340 | 0.340 
 5cm | 29.80 'C | 29.90 'C | 4.577 | 4.664 | 4.664 | 4.664 | 4.664 | 3 | 4.663 | -0.337 
 5cm | 29.80 'C | 29.80 'C | 4.175 | 4.227 | 4.227 | 4.227 | 4.245 | 2 | 4.227 | -0.773 
 5cm | 29.80 'C | 29.80 'C | 4.594 | 4.664 | 4.664 | 4.664 | 4.664 | 3 | 4.663 | -0.337 
 10cm | 29.90 'C | 29.80 'C | 9.031 | 9.136 | 9.118 | 9.118 | 9.118 | 2 | 9.118 | -0.882 
 10cm | 29.90 'C | 29.80 'C | 9.013 | 9.118 | 9.136 | 9.118 | 9.136 | 1 | 9.118 | -0.882 
 