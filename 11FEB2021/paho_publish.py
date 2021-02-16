import paho.mqtt.client as mqtt # Import the MQTT library

import time # The time library is useful for delays

 

# Our "on message" event

def messageFunction (client, userdata, message):

    topic = str(message.topic)

    message_data = str(message.payload.decode("utf-8"))

    print(topic + message_data)

 

print("Starting....")

ourClient = mqtt.Client("rpi4_mqtt") # Create a MQTT client object

ourClient.connect("192.168.4.38", 1883) # Connect to the test MQTT broker



 

print("Pubishing....")

# Main program loop

#while(1):

ourClient.publish("TEST_unit", "on") # Publish message to MQTT broker

time.sleep(1) # Sleep for a second



print("Subscribing....")

ourClient.subscribe("TEST_unit") # Subscribe to the topic AC_unit

ourClient.on_message = messageFunction # Attach the messageFunction to subscription

ourClient.loop_start() # Start the MQTT client
