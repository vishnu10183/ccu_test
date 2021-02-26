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
 2cm | 29.80 'C | 29.90 'C | 2.254 | 2.341 | 2.341 | 2.778 | 2.324 | 2 | 2.341 | 0.341 
 2cm | 29.90 'C | 29.80 'C | 2.253 | 2.341 | 2.341 | 2.341 | 2.341 | 4 | 2.340 | 0.340 
 5cm | 29.80 'C | 29.90 'C | 4.577 | 4.664 | 4.664 | 4.664 | 4.664 | 4 | 4.663 | -0.337 
 5cm | 29.80 'C | 29.80 'C | 4.175 | 4.227 | 4.227 | 4.227 | 4.245 | 3 | 4.227 | -0.773 
 5cm | 29.80 'C | 29.80 'C | 4.594 | 4.664 | 4.664 | 4.664 | 4.664 | 4 | 4.663 | -0.337 
 10cm | 29.80 'C | 29.80 'C | 8.944 | 8.996 | 8.996 | 8.996 | 8.996 | 4 | 8.995 | -1.005 
 10cm | 29.80 'C | 29.80 'C | 8.909 | 9.013 | 8.979 | 8.996 | 8.996 | 2 | 8.995 | -1.005 
 10cm | 29.80 'C | 29.80 'C | 8.909 | 8.996 | 9.013 | 9.013 | 9.013 | 3 | 9.013 | -0.987 
 15cm | 29.80 'C | 29.80 'C | 14.376 | 14.446 | 14.463 | 14.429 | 14.446 | 2 | 14.445 | -0.555 
 