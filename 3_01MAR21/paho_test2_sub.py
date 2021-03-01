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


def onMessage( client, userdata, message ):
    topic = str(message.topic)
    message_data = str(message.payload.decode("utf-8"))
    print( topic + ' : ' + message_data )


if __name__ == '__main__':
    ourClient = mqtt.Client( "Pi4-MQTT" ) # Create MQTT Client Object
    
    ourClient.on_connect = onConnect # Connection call-back function
    ourClient.connect( "192.168.4.114"  ) # Broker IP address

    # Publish a Message to "test-Pi" Topic
    # ourClient.publish( "test-Pi" , " Paho..." )

    # Subscribing to "test-Pi" Topic
    ourClient.subscribe( "test-Pi" )
    
    ourClient.on_message = onMessage # Subscription call-back function
    ourClient.loop_start()
    
    time.sleep(20) # Just delaying before program ends
    ourClient.loop_stop() # If not stopped, keeps on listening
