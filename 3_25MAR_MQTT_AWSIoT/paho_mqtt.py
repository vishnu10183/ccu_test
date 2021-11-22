import paho.mqtt.client as mqtt
import time

broker_IPaddr = "192.168.4.35"
Topic = "test-Pi"

def onConnect( client, userdata, flags, rc ):
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
from datetime import datetime

def mqttPublish( xc, yc, temp, humd, field_id, imp_id, resetVar ):
    ourClient = mqtt.Client( "Pi4-MQTT" ) # Create MQTT Client Object
    
    ourClient.on_connect = onConnect # Connection call-back function
    ourClient.username_pw_set(username="vishnu",password="password")
    ourClient.connect( broker_IPaddr  ) # Broker IP address

    now = datetime.now()
    date_str = now.strftime( "%Y-%m-%d %H:%M:%S" )

    json_msg ={
        "Time" : date_str,
        "X" : xc,
        "Y" : yc,
        "Temp" : temp,
        "Humidity": humd,
        "Field_ID" : field_id,
        "Impl_ID" : imp_id,
        "resetVar" : resetVar
        }
    json_str = json.dumps( json_msg ) # Convert dictionary to JSON string
    
    # Publish a Message to "test-Pi" Topic
    ourClient.publish( Topic , json_str )

    time.sleep(1)


if __name__ == '__main__':
    mqttPublish( 24, 12, 25.11, 10.24, 1, 1 )
    
