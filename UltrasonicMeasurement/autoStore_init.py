
import RPi.GPIO as io
from time import sleep, time
    
if __name__ == '__main__':

    io.setmode( io.BCM )


    TRIG = 18
    ECHO = 23

    io.setup( TRIG, io.OUT )
    io.output( TRIG, 0)

    io.setup( ECHO, io.IN )

    sleep( 0.25)

    print( "Beginning...." )

    distanceVal = []
    count =0
    while count<32:
        io.output( TRIG, 1 )
        sleep( 0.00001 )
        io.output( TRIG,0 )

        while io.input( ECHO ) == 0:
            pass

        init_time = time()

        while io.input( ECHO ) == 1:
            pass

        final_time = time()

        with open( 'rpi3_ERD.md' , 'a' ) as fw:
            fw.write( str( round(((final_time - init_time)*170*100),3)) +'\n' )

        # multiplied by 100 for metre to cm
        
        
        count+=1
        sleep(0.1) # delay to view the distance



