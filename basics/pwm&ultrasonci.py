import RPi.GPIO as io
from l293d import L293D

pwm_fw= 20
brakeInterval = -4

motor = L293D()

io.output( motor.EN12, 0 )
io.output( motor.EN34, 0 )

pwm12= io.PWM(motor.EN12, 1000 ) # frequency =1000
pwm34= io.PWM(motor.EN34, 1000 ) # frequency =1000

pwm12.start(pwm_fw)
pwm34.start(pwm_fw)
current_pwm= pwm_fw


from time import sleep, time



def brake():
        global current_pwm
        print("BRAKE!!!...")
        for dc in range( current_pwm, 0 , brakeInterval ):
            pwm34.ChangeDutyCycle( dc )
            pwm12.ChangeDutyCycle( dc )
            sleep(.05)
        current_pwm= 0


#def ultrasonic_init():    
TRIG = 18
ECHO = 23

io.setup( TRIG, io.OUT )
io.output( TRIG, 0)

io.setup( ECHO, io.IN )

sleep( 0.5)

def proximity( unit ):
    global TRIG
    global ECHO
    io.output( TRIG, 1 )
    sleep( 0.00001 )
    io.output( TRIG,0 )

    while io.input( ECHO ) == 0:
        pass

    init_time = time()

    while io.input( ECHO ) == 1:
        pass

    final_time = time()

    if unit.lower() == 'm':
        return ((final_time - init_time)*170)
    elif unit.lower() == 'cm':
        return ((final_time - init_time)*170*100)
        
    # multiplied by 100 for cm
    
    
    

if __name__ == '__main__':
    #ultrasonic_init()
    motor.move_fw()
    sleep(1)

    while True:
        print("LOOOOOOP")
        dist= proximity('cm')
        print( "Distance = ", dist)
        if dist <=3.5: 
            brake()
        #else:
            #motor.move_fw()
        sleep(0.5)

