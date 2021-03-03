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
 2cm | 30.90 'C | 30.90 'C | 1.733 | 1.855 | 1.855 | 1.855 | 1.838 | 3 | 1.855 | -0.145
 3cm | 30.80 'C | 30.80 'C | 2.204 | 2.274 | 2.274 | 2.257 | 2.292 | 2 | 2.274 | -0.726
 4cm | 30.70 'C | 30.70 'C | 3.114 | 3.184 | 3.202 | 3.202 | 3.639 | 2 | 3.201 | -0.799
 5cm | 30.70 'C | 30.80 'C | 4.515 | 4.655 | 4.655 | 4.655 | 4.637 | 3 | 4.654 | -0.346
 6cm | 30.80 'C | 30.70 'C | 5.494 | 5.599 | 5.582 | 5.582 | 5.547 | 2 | 5.581 | -0.419
 7cm | 30.80 'C | 30.70 'C | 6.193 | 6.701 | 6.701 | 6.648 | 6.683 | 2 | 6.700 | -0.3
 8cm | 30.70 'C | 30.50 'C | 7.136 | 7.101 | 7.241 | 7.206 | 7.223 | 1 | 7.135 | -0.865
 9cm | 30.50 'C | 30.50 'C | 8.430 | 8.517 | 8.500 | 8.517 | 8.517 | 3 | 8.517 | -0.483
 10cm | 30.50 'C | 30.50 'C | 9.462 | 9.567 | 9.567 | 9.567 | 9.549 | 3 | 9.566 | -0.434
 11cm | 30.50 'C | 30.50 'C | 10.004 | 10.126 | 10.109 | 10.109 | 10.056 | 2 | 10.108 | -0.892
 12cm | 30.50 'C | 30.50 'C | 11.018 | 11.106 | 11.088 | 11.088 | 11.106 | 2 | 11.088 | -0.912
 13cm | 30.50 'C | 30.50 'C | 12.033 | 12.120 | 12.120 | 12.120 | 12.137 | 3 | 12.119 | -0.881
 14cm | 30.50 'C | 30.50 'C | 13.467 | 13.537 | 13.554 | 13.537 | 13.537 | 3 | 13.536 | -0.464
 15cm | 30.50 'C | 30.50 'C | 13.344 | 14.079 | 14.079 | 14.096 | 14.079 | 3 | 14.078 | -0.922
 16cm | 30.60 'C | 30.60 'C | 15.393 | 15.446 | 15.446 | 15.428 | 15.428 | 2 | 15.445 | -0.555
 17cm | 30.60 'C | 30.60 'C | 16.463 | 16.498 | 16.550 | 16.533 | 16.550 | 2 | 16.550 | -0.45
 18cm | 30.60 'C | 30.60 'C | 17.355 | 17.460 | 17.460 | 17.460 | 17.425 | 3 | 17.460 | -0.54
 19cm | 30.60 'C | 30.60 'C | 18.804 | 18.507 | 18.507 | 18.489 | 18.489 | 2 | 18.506 | -0.494
 20cm | 30.60 'C | 30.60 'C | 19.399 | 19.486 | 19.486 | 19.434 | 19.469 | 2 | 19.486 | -0.514
 