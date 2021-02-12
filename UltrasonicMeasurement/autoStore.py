

def insertData( fileName, values ):
    data = []
    with open( fileName , 'r' ) as fr:
        data = fr.readlines()


    for indx, each in enumerate(data):
        if indx == 0 or indx == 1:
            continue
        data[indx] = data[indx].split('\n')[0] +  ' | ' + values[indx] +'\n'
        

    with open( fileName , 'w' ) as fw:
        fw.writelines( data )

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
    while count<35:
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
        distanceVal.append( str( round(((final_time - init_time)*170*100),3)) )
        
        count+=1
        sleep(0.1) # delay to view the distance

    print( distanceVal )
    insertData( 'rpi3_powerBank.md', distanceVal )

