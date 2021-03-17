import paho.mqtt.client as mqtt
import time

broker_IPaddr = "192.168.4.35"
Topic = "test-Pi"
mqtt_user = "rpi3"
mqtt_pass = "girish"

def onConnect ( client, userdata, flags, rc ):
    if rc == 0:
        print( "Connection Successful!" )
    elif rc == 1:
        print( "[ERROR] Connection Error -", rc, " : Incorrect Protocol Version" )
    elif rc == 2:
        print( "[ERROR] Connection Error -", rc, " : Invalid Client Identifier" )
    elif rc == 3:
        print( "[ERROR] Connection Error -", rc, " : Server Unavailable" )
    elif rc == 4:
        print( "[ERROR] Connection Error -", rc, " : Bad Username/Password" )
    elif rc == 5:
        print( "[ERROR] Connection Error -", rc, " : Unauthorised Access!" )
    else:
        print( "[ERROR] Connection Error -", rc, " : Currently Unused" )

import json
def onMessage ( client, userdata, message ):
    topic = str(message.topic)
    message_data = str( message.payload.decode("utf-8") )
    print( topic + ' :' )#+ message_data )
    data_dict = json.loads( message_data )
    for key, value in data_dict.items():
        print( f" {key} : {value}" )
    
if __name__ == '__main__':

    try:
        
        ourClient = mqtt.Client( "Pi2-MQTT" ) # Create MQTT Client Object
        ourClient.on_connect = onConnect # Connection call-back function
        ourClient.username_pw_set(username= mqtt_user,password= mqtt_pass)
        ourClient.connect( broker_IPaddr ) # Broker IP address
        # Subscribing to "test-Pi" Topic
        ourClient.subscribe( Topic )
        ourClient.on_message = onMessage # Subscription call-back function

        ourClient.loop_start( )
        time.sleep(.5)
        print("MQTT Subscriber listening...")
        #time.sleep(20) # Just delaying before program ends

    except KeyboardInterrupt:
        ourClient.loop_stop( ) # If not stopped, keeps on listening
