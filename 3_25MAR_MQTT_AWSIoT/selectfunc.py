import RPi.GPIO as io

f1 = 4
f2 = 17
I1 = 27 # pull-up LED
I2 = 22 # pull-up LED

Fsw = 11 #9
Isw = 8 #25


io.setmode( io.BCM )


io.setup( f1, io.OUT )
io.output( f1, 0 )
io.setup( f2, io.OUT )
io.output( f2, 0 )
io.setup( I1, io.OUT )
io.output( I1, 1 )
io.setup( I2, io.OUT )
io.output( I2, 1 )

io.setup( Fsw, io.IN )
io.setup( Isw, io.IN )


prev_Fsw = 0
prev_Isw = 0

Fsw_flag = 0
Isw_flag = 0

from time import perf_counter
Fsw_init = perf_counter()
repeat_init = perf_counter()
Isw_init = perf_counter()
led_init = perf_counter()

startFlag = False

def startstop():
	global Fsw, f1, f2
	global prev_Fsw
	global Fsw_flag, startFlag
	global Fsw_init, led_init
	pres_Fsw = io.input( Fsw )
	if pres_Fsw == 1 and prev_Fsw == 0:
		Fsw_init = perf_counter()
	if pres_Fsw == 1 and prev_Fsw == 1 and ( (perf_counter()-Fsw_init) >= 2.0 ) :
		startFlag = not startFlag
		print( "----------------->PRESSED START/STOP : ", startFlag )
		if startFlag:
			io.output( f1 , 1 )
			io.output( f2 , 1 )
		else:
			io.output( f1 , 0 )
			io.output( f2 , 0 )
		while io.input(Fsw):
			pass
		if Fsw_flag == 1:
			io.output( f1, 1 )
			io.output( f2, 0 )
		elif Fsw_flag == 2:
			io.output( f2, 1 )
			io.output( f1, 0 )
		Fsw_init = perf_counter()
	'''
	if (perf_counter() - led_init) > 0.5:
		led_init = perf_counter()
		if startFlag:
			if Fsw_flag == 0:
				io.output( f1, not io.input(f1) )
				io.output( f2, not io.input(f2) )
			elif Fsw_flag == 1:
				io.output( f1, not io.input(f1) )
			elif Fsw_flag == 2:
				io.output( f2, not io.input(f2) )
		else:
			if Fsw_flag == 0:
				io.output( f1, 0 )
				io.output( f2, 0 )
			elif Fsw_flag == 1:
				io.output( f1, io.input(f1) )
			elif Fsw_flag == 2:
				io.output( f2, io.input(f2) )
	'''
	prev_Fsw = pres_Fsw
	return startFlag

def fieldselect():
	global Fsw, f1, f2
	global prev_Fsw
	global Fsw_flag, startFlag
	global Fsw_init, repeat_init, led_init
	pres_Fsw = io.input( Fsw )
	if pres_Fsw == 1 and prev_Fsw == 0:
		Fsw_init = perf_counter()
	if not startFlag:
		if pres_Fsw == 0 and prev_Fsw == 1 and ( (perf_counter()-Fsw_init) <2.5 ) and ( (perf_counter()-repeat_init) >0.25  )  :
			Fsw_flag += 1
			Fsw_init = perf_counter()
			repeat_init = perf_counter()
			if Fsw_flag == 3:
				Fsw_flag = 0
			if Fsw_flag == 0:
				io.output( f1 , 0 )
				io.output( f2 , 0 )
			if Fsw_flag == 1 : # or Fsw_flag ==2:
				io.output( f1 , 1 )
				io.output( f2 , 0 )
			if Fsw_flag == 2:
				io.output( f1 , 0 )
				io.output( f2 , 1 )
			print( "----------------->PRESSED FIELD SELECT : ", Fsw_flag )
	
	if pres_Fsw == 1 and prev_Fsw == 1 and ( (perf_counter()-Fsw_init) >= 3.0 ) :
		startFlag = not startFlag
		print( "----------------->PRESSED START/STOP : ", startFlag )
		if startFlag:
			io.output( f1 , 1 )
			io.output( f2 , 1 )
		else:
			io.output( f1 , 0 )
			io.output( f2 , 0 )
		while io.input(Fsw):
			pass
		if not startFlag:
			if Fsw_flag == 1:
				io.output( f1, 1 )
				io.output( f2, 0 )
			elif Fsw_flag == 2:
				io.output( f2, 1 )
				io.output( f1, 0 )
		Fsw_init = perf_counter()
		repeat_init = perf_counter() # to avoid field selection change after stop

	'''
	if (perf_counter() - led_init) > 0.25:
		led_init = perf_counter()
		if startFlag:
			if Fsw_flag == 0:
				io.output( f1, not io.input(f1) )
				io.output( f2, not io.input(f2) )
			elif Fsw_flag == 1:
				io.output( f1, not io.input(f1) )
			elif Fsw_flag == 2:
				io.output( f2, not io.input(f2) )
		else:
			if Fsw_flag == 0:
				io.output( f1, 0 )
				io.output( f2, 0 )
			elif Fsw_flag == 1:
				io.output( f1, 1 )
			elif Fsw_flag == 2:
				io.output( f2, 1 )
	'''
	prev_Fsw = pres_Fsw
	return startFlag, Fsw_flag

def implselect():
	global Isw, I1, I2
	global prev_Isw
	global Isw_flag
	global Isw_init
	pres_Isw = io.input( Isw )
	if pres_Isw == 1 and prev_Isw == 0 and ( (perf_counter()-Isw_init) >0.5  ) :
		Isw_flag += 1
		Isw_init = perf_counter()
		if Isw_flag == 4:
			Isw_flag = 0
		if Isw_flag == 0:
			io.output( I1 , 1 )
			io.output( I2 , 1 )
		if Isw_flag == 1:
			io.output( I1 , 0 )
			io.output( I2 , 1 )
		if Isw_flag == 2:
			io.output( I1 , 1 )
			io.output( I2 , 0 )
		if Isw_flag == 3:
			io.output( I1 , 0 )
			io.output( I2 , 0 )
		print( "----------------->PRESSED IMPLEMENT SELECT : ", Isw_flag )
	prev_Isw = pres_Isw
	return Isw_flag


if __name__ == '__main__':
	while True:
		st, fflag = fieldselect()
		if not st:
			#fflag = fieldselect()
			iflag = implselect()
