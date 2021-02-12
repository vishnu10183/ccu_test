import RPi.GPIO as io
from time import sleep, time

io.setmode( io.BCM )


TRIG = 18
ECHO = 23

io.setup( TRIG, io.OUT )
io.output( TRIG, 0)

io.setup( ECHO, io.IN )

sleep( 0.5)

print( "Beginning...." )

minVal = 0
maxVal = 0

count =0
while count<20:
    io.output( TRIG, 1 )
    sleep( 0.00001 )
    io.output( TRIG,0 )

    while io.input( ECHO ) == 0:
        pass

    init_time = time()

    while io.input( ECHO ) == 1:
        pass

    final_time = time()

    # multiplied by 100 for metre to cm
    val= (final_time - init_time)*170*100

    if count ==3: # skipping first value, as it can be error value
        minVal = val
        maxVal = val
        
    if val < minVal:
        minVal = val
    if val > maxVal:
        maxVal = val
    
    #print( "Distance = ",  ) 

    sleep(0.1) # delay to view the distance
    count+=1

io.output(TRIG,0)
print(f"Max Value: {maxVal} \n Min Value: {minVal}")
