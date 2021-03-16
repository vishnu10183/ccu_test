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
 2cm | 26.80 'C | 26.70 'C | 2.204 | 2.239 | 2.256 | 2.256 | 2.256 | 3 | 2.255 | 0.255
 3cm | 26.70 'C | 26.80 'C | 2.620 | 2.638 | 2.672 | 2.672 | 2.672 | 3 | 2.672 | -0.328
 4cm | 26.70 'C | 26.80 'C | 3.592 | 3.627 | 3.644 | 3.644 | 3.627 | 2 | 3.644 | -0.356
 5cm | 26.80 'C | 26.80 'C | 4.546 | 4.598 | 4.598 | 4.616 | 4.598 | 3 | 4.598 | -0.402
 6cm | 26.80 'C | 26.80 'C | 5.084 | 5.640 | 5.640 | 5.640 | 5.622 | 3 | 5.639 | -0.361
 7cm | 26.80 'C | 26.80 'C | 5.987 | 6.056 | 6.091 | 6.091 | 6.073 | 2 | 6.090 | -0.91
 8cm | 26.80 'C | 26.70 'C | 7.063 | 7.080 | 7.115 | 6.993 | 7.097 | 1 | 7.062 | -0.938
 9cm | 26.80 'C | 26.80 'C | 8.034 | 8.086 | 8.069 | 8.069 | 8.086 | 2 | 8.069 | -0.931
 10cm | 26.80 'C | 26.80 'C | 9.457 | 9.527 | 9.544 | 9.544 | 9.544 | 3 | 9.544 | -0.456
 11cm | 26.80 'C | 26.80 'C | 9.891 | 9.961 | 9.961 | 9.926 | 9.961 | 3 | 9.960 | -1.04
 12cm | 26.80 'C | 26.80 'C | 11.418 | 11.453 | 11.470 | 11.488 | 11.488 | 2 | 11.487 | -0.513
 13cm | 26.70 'C | 26.80 'C | 12.459 | 12.529 | 12.511 | 12.529 | 12.494 | 2 | 12.528 | -0.472
 14cm | 26.70 'C | 26.70 'C | 13.431 | 13.379 | 13.466 | 13.500 | 13.466 | 2 | 13.465 | -0.535
 15cm | 26.70 'C | 26.70 'C | 14.420 | 14.438 | 14.455 | 14.403 | 14.385 | 1 | 14.420 | -0.58
 16cm | 26.70 'C | 26.70 'C | 15.427 | 15.444 | 15.496 | 15.496 | 15.479 | 2 | 15.496 | -0.504
 17cm | 26.60 'C | 26.60 'C | 16.433 | 16.468 | 16.485 | 16.450 | 16.468 | 2 | 16.467 | -0.533
 18cm | 26.60 'C | 26.60 'C | 17.474 | 17.492 | 17.492 | 17.492 | 17.457 | 3 | 17.491 | -0.509
 19cm | 26.60 'C | 26.60 'C | 18.429 | 18.463 | 18.481 | 18.481 | 18.481 | 3 | 18.480 | -0.52
 20cm | 26.60 'C | 26.60 'C | 18.967 | 19.001 | 19.019 | 19.019 | 19.036 | 2 | 19.018 | -0.982
 