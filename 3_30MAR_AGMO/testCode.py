import RPi.GPIO as io

f1 = 4
f2 = 17
I1 = 27 # pull-up LED
I2 = 22 # pull-up LED

Fsw = 9
Isw = 25


io.setmode( io.BCM )


io.setup( f1, io.OUT )
io.output( f1, 0 )
io.setup( f2, io.OUT )
io.output( f2, 0 )
io.setup( I1, io.OUT )
io.output( I1, 1 )
io.setup( I2, io.OUT )
io.output( I2, 1 )




from time import sleep

if __name__ == '__main__':
	while True:
		io.setup( Fsw, io.IN )
		#io.output( Fsw, 0 )
		io.setup( Isw, io.IN )
		#io.output( Isw, 0 )
		print( f'FSW : {io.input(Fsw)} , ISW : {io.input(Isw)}' )
		sleep(1)
