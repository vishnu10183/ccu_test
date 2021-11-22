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
from time import sleep, perf_counter
import paho_mqtt # paho_mqtt.py
import selectfunc

# ------------------------------------------------------------------
# ---------------------------------------------------- MAIN BODY ---
# ------------------------------------------------------------------

consecutive_interval = 1 # in seconds
interval_init = perf_counter()
resetFlag = 1

if __name__ == '__main__':
   print("Begin...")
   while True:
     sleep(0.01)
     #st = selectfunc.startstop()
     st , Fsw_select = selectfunc.fieldselect()
     if not st:
      resetFlag = 1
      #Fsw_select = selectfunc.fieldselect()
      Isw_select = selectfunc.implselect()
     #print( f"  Field Select : {Fsw_select} ,  Implement Select : {Isw_select}" )
     
     #print( "Waiting...", end= " " )
     #sleep(consecutive_interval)
     #print( "DONE" )
     if st: 
      if ( perf_counter() - interval_init ) > consecutive_interval :
        interval_init = perf_counter()
        try:
            print("Running DHT22 C-file...", end= " ")
            tmp=subprocess.check_output( ["sudo", "./"+temp_c_build_file]) # build file name
            print("...DONE")
            
            print("Running HCSR04 C-file...", end= " ")
            tmp=subprocess.check_output( [ "./"+us_c_build_file], timeout= 1 ) # build file with 2 seconds timeout
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
                               val[1], Fsw_select, Isw_select, resetFlag )
            resetFlag = 0
            print("...Done")

        #except TimeoutExpired:
          #print ( "\n\nTimeout!!!\n" )


        except Exception as e:
           print ( f"\n\nERROR! : {e}\n")
           pass
    
   print("Program Completed.")


