import paho.mqtt.client as mqtt
import time

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



if __name__ == '__main__':
    ourClient = mqtt.Client( "Pi4-MQTT" ) # Create MQTT Client Object
    
    ourClient.on_connect = onConnect # Connection call-back function
    ourClient.username_pw_set(username="vishnu",password="password")
    ourClient.connect( "192.168.4.35"  ) # Broker IP address

    # Publish a Message to "test-Pi" Topic
    ourClient.publish( "test-PC" , "Checking Paho..." )

    time.sleep(1)
