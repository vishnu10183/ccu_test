# **Ultrasonic Sensor Measurement**
### *- C code (WiringPi) including Threading(pThread)*
### *- Set Priority(-20), Set Affinity to Core 2*
### *- DHT22 for Temperature Factor (Avg. of 2 readings)*
### *- Material Used : Metal*
### *- No. of Observations = 20*
### *- Height of HC-SR04 from test floor = 6.4 cm*


Obs. No.|2cm (27.80'C)|6cm(27.80'C)|10cm (27.85'C)|30cm(27.90'C)|60cm (27.80'C)|90cm (27.80'C)|120cm (27.80'C)
----| ----| ----| ----| ----| ---- | ---- | ---- 
1  | 2.681 | 5.118 | 9.454 | 29.180 | 58.088 | 88.429 | 118.760
2  | 2.750 | 5.187 | 9.523 | 29.267 | 58.210 | 88.569 | 118.864
3  | 2.733 | 5.187 | 9.523 | 29.232 | 58.175 | 88.516 | 118.969
4  | 2.750 | 5.187 | 9.506 | 29.284 | 58.175 | 88.551 | 118.917
5  | 2.750 | 5.205 | 9.541 | 29.284 | 58.175 | 88.499 | 118.934
6  | 2.768 | 5.187 | 9.506 | 29.302 | 58.175 | 88.569 | 122.694
7  | 2.750 | 5.170 | 9.471 | 29.284 | 58.193 | 88.551 | 118.917
8  | 2.750 | 5.187 | 9.523 | 29.284 | 58.158 | 88.551 | 57.370
9  | 2.750 | 5.205 | 9.506 | 28.779 | 58.228 | 88.551 | 118.951
10  | 2.750 | 5.187 | 9.506 | 29.232 | 58.193 | 88.534 | 118.951
11  | 2.750 | 5.187 | 9.506 | 29.284 | 57.862 | 88.482 | 109.291
12  | 1.410 | 5.205 | 9.523 | 29.284 | 58.141 | 88.569 | 118.917
13  | 2.768 | 5.187 | 9.523 | 29.284 | 58.158 | 88.551 | 118.917
14  | 2.733 | 5.187 | 9.523 | 29.215 | 58.175 | 88.569 | 118.847
15  | 2.750 | 5.187 | 9.523 | 29.720 | 58.210 | 88.551 | 118.882
16  | 2.750 | 5.205 | 9.106 | 29.284 | 58.193 | 88.534 | 118.864
17  | 2.733 | 5.187 | 9.088 | 29.284 | 58.193 | 88.499 | 118.917
18  | 2.750 | 5.135 | 9.088 | 29.789 | 58.036 | 88.551 | 118.917
19  | 2.716 | 5.153 | 9.523 | 29.302 | 58.210 | 88.499 | 118.917
20  | 2.716 | 5.187 | 9.506 | 29.284 | 58.193 | 88.482 | 118.986