'''
==============================================================================
Program Modified on 17-MAR-2021

-> Subprocess to read C build file
-> Read output from C source file and split values
-> Send JSON string via MQTT publishing

===============================================================================
'''


# File Names
c_build_file = "us2_dht22"

import subprocess
from time import sleep
import paho_mqtt # paho_mqtt.py

# ------------------------------------------------------------------
# ---------------------------------------------------- MAIN BODY ---
# ------------------------------------------------------------------



if __name__ == '__main__':
   print("Begin...")
   while True:
        print("Running c file...", end" ")
        tmp=subprocess.check_output( ["sudo", "./"+c_build_file]) # build file name
        print("...DONE")

        val = str(tmp).split('\\n')
        val[0] = val[0].split('"')[1]
        val[-1] = val[-1].split('"')[0]
        
        print(val)
        print(f'Temperature: {val[0]} , Humidity: {val[1]}')
        print( "Sending MQTT JSON....", end= " " )

        #xc, yc, temp, humd
        val[0] = val[0].split(' ')[0]
        paho_mqtt.mqttPublish( int(float(val[3])), int(float(val[5])), val[0], val[1] )
        print("...Done")

        sleep(1)
    
   print("Program Completed.")


