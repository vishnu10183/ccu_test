import RPi.GPIO as io
from l293d import L293D

pwm_fw= 50
brakeInterval = -5

motor = L293D()

io.output( motor.EN12, 0 )
io.output( motor.EN34, 0 )

pwm12= io.PWM(motor.EN12, 1000 ) # frequency =1000
pwm34= io.PWM(motor.EN34, 1000 ) # frequency =1000

pwm12.start(100)
pwm34.start(100)

motor.move_fw()

from time import sleep
sleep(1)


def brake():
        print("BRAKE!!!...")
        for dc in range( pwm_fw, 0 , brakeInterval ):
            pwm34.ChangeDutyCycle( dc )
            pwm12.ChangeDutyCycle( dc )
            sleep(.25)
brake()

