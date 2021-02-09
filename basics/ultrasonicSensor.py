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

while True:
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
    print( "Distance = ", (final_time - init_time)*170 ) 

    sleep(0.5) # delay to view the distance

