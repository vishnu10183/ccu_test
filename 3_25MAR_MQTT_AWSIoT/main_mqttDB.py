'''
==============================================================================
Program Modified on 17-MAR-2021

-> Subprocess to read C build file
-> Read output from C source file and split values
-> Send JSON string via MQTT publishing

===============================================================================
'''


# File Names
us_c_build_file = "us2_dht22"
temp_c_build_file = "read_dht22"

import subprocess
from time import sleep
import paho_mqtt # paho_mqtt.py

# ------------------------------------------------------------------
# ---------------------------------------------------- MAIN BODY ---
# ------------------------------------------------------------------

consecutive_interval = 10 # in seconds

if __name__ == '__main__':
   print("Begin...")
   while True:
        print( "Waiting...", end= " " )
        sleep(consecutive_interval)
        print( "DONE" )
        try:
            print("Running DHT22 C-file...", end= " ")
            tmp=subprocess.check_output( ["sudo", "./"+temp_c_build_file]) # build file name
            print("...DONE")
            
            print("Running HCSR04 C-file...", end= " ")
            tmp=subprocess.check_output( ["sudo", "./"+us_c_build_file]) # build file name
            print("...DONE")
	    
            print(str(tmp))
            val = str(tmp).split('\\n')
            val[0] = val[0].split('"')[1]
            val[-1] = val[-1].split('"')[0]
            
            
            print(f'Temperature: {val[0]} , Humidity: {val[1]}')
            print( "Sending MQTT JSON....", end= " " )
	    
            #xc, yc, temp, humd
            val[0] = val[0].split(' ')[0]
            paho_mqtt.mqttPublish( int(float(val[3])), \
                               int(float(val[5])), \
                               val[0],\
                               val[1] )
            print("...Done")

        except:
           print ("ERROR!")
           pass
    
   print("Program Completed.")


