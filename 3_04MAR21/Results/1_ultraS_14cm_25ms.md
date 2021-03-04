# **Ultrasonic Sensor Measurement - VNC Server : OFF**
### *- C code (WiringPi) including Threading(pThread)*
### *- Set Priority(-20), Set Affinity to Core 2*
### *- DHT22 for Temperature Factor (Any of 2 readings)*
### *- Material Used : Metal*
### *- No. of Observations = 5 @ 25ms interval*
### *- Height of HC-SR04 from test floor = 14.5 cm*
### *- Python Code to automate storing & finding error rate.*

Actual | Temp. 1 | Temp. 2 | Obs. 1 | Obs. 2 | Obs. 3 | Obs. 4 | Obs. 5 | Repeat Count | Repeat Value | Error Rate
---- | ---- | ---- | ---- | ---- | ---- | ---- | ----| ---- | ---- | ---- 
 2cm | 29.90 'C | 30.10 'C | 2.569 | 2.639 | 2.219 | 2.219 | 2.639 | 2 | 2.219 | 0.219
 3cm | 30.10 'C | 30.20 'C | 2.639 | 3.128 | 2.708 | 2.708 | 2.708 | 3 | 2.708 | -0.292
 4cm | 30.20 'C | 30.20 'C | 3.565 | 3.617 | 3.617 | 3.617 | 3.635 | 3 | 3.617 | -0.383
 5cm | 30.20 'C | 30.20 'C | 4.089 | 4.176 | 4.176 | 4.194 | 4.176 | 3 | 4.176 | -0.824
 6cm | 30.20 'C | 30.20 'C | 4.998 | 5.102 | 5.085 | 5.085 | 5.085 | 3 | 5.084 | -0.916
 7cm | 30.20 'C | 30.20 'C | 5.976 | 6.063 | 6.081 | 6.081 | 6.081 | 3 | 6.080 | -0.92
 8cm | 30.20 'C | 30.20 'C | 6.972 | 7.042 | 7.059 | 7.059 | 7.042 | 2 | 7.059 | -0.941
 9cm | 30.20 'C | 30.10 'C | 8.003 | 8.090 | 8.090 | 8.527 | 8.090 | 3 | 8.090 | -0.91
 10cm | 30.20 'C | 30.10 'C | 8.964 | 9.052 | 9.069 | 9.069 | 9.069 | 3 | 9.069 | -0.931
 11cm | 30.10 'C | 30.10 'C | 9.943 | 10.048 | 10.048 | 10.048 | 10.048 | 4 | 10.047 | -0.953
 12cm | 30.10 'C | 30.10 'C | 11.411 | 11.498 | 11.498 | 11.515 | 11.498 | 3 | 11.497 | -0.503
 13cm | 30.10 'C | 30.20 'C | 12.407 | 12.476 | 12.476 | 12.476 | 12.476 | 4 | 12.476 | -0.524
 14cm | 30.20 'C | 30.20 'C | 13.403 | 13.472 | 13.472 | 13.472 | 13.455 | 3 | 13.472 | -0.528
 15cm | 30.20 'C | 30.10 'C | 14.346 | 14.451 | 14.451 | 14.451 | 14.451 | 4 | 14.450 | -0.55
 16cm | 30.10 'C | 30.10 'C | 14.958 | 15.063 | 15.063 | 15.063 | 15.063 | 4 | 15.062 | -0.938
 17cm | 30.10 'C | 30.10 'C | 15.919 | 15.971 | 15.989 | 15.989 | 15.971 | 2 | 15.988 | -1.012
 18cm | 30.10 'C | 30.10 'C | 17.334 | 17.439 | 17.002 | 17.439 | 17.020 | 2 | 17.439 | -0.561
 19cm | 30.10 'C | 30.10 'C | 18.365 | 18.487 | 18.487 | 18.487 | 18.487 | 4 | 18.487 | -0.513
 20cm | 30.10 'C | 30.10 'C | 19.379 | 19.466 | 19.449 | 19.449 | 19.466 | 2 | 19.448 | -0.552
 