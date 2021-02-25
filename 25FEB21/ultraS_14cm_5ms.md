# **Ultrasonic Sensor Measurement - VNC Server : OFF**
### *- C code (WiringPi) including Threading(pThread)*
### *- Set Priority(-20), Set Affinity to Core 2*
### *- DHT22 for Temperature Factor (Avg. of 2 readings)*
### *- Material Used : Metal*
### *- No. of Observations = 10 @ 5ms interval*
### *- Height of HC-SR04 from test floor = 14.5 cm*
### *- Python Code to automate storing & finding error rate.*

Actual | Temp. 1 | Temp. 2 | Obs. 1 | Obs. 2 | Obs. 3 | Obs. 4 | Obs. 5 | Obs. 6 | Obs. 7 | Obs. 8 | Obs. 9 | Obs. 10 | Repeat Value | Error Rate
---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ----
 75cm | 29.00 'C | 29.20 'C | 73.302 | 73.441 | 73.424 | 73.494 | 73.441 | 73.424 | 73.441 | 73.389 | 73.441 | 73.808 | 73.441 | -1.559 
 75cm | 29.20 'C | 29.20 'C | 73.272 | 73.376 | 73.376 | 73.376 | 73.376 | 73.743 | 73.376 | 73.376 | 73.376 | 73.376 | 73.376 | -1.624 
 75cm | 29.20 'C | 29.20 'C | 73.306 | 73.411 | 73.429 | 73.411 | 73.429 | 73.830 | 73.411 | 73.429 | 73.429 | 73.429 | 73.428 | -1.572 
 