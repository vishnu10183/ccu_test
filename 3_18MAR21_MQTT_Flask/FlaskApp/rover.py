import RPi.GPIO as io
from time import sleep

io.setmode( io.BCM )

left_fp = 19
left_fn = 26
left_bn = 6
left_bp = 13

right_fp = 16
right_fn = 1
right_bp = 20
right_bn = 21

enb = 12

pwmVal_fb = 15
pwmVal_lr = 60
io.setup( enb, io.OUT )
io.output( enb , 0 )
pwm_enb = io.PWM( enb , 1000 )



io.setup( left_fp, io.OUT )
io.output( left_fp, 0 )
io.setup( left_fn, io.OUT )
io.output( left_fn, 0 )
io.setup( right_fp, io.OUT )
io.output( right_fp, 0 )
io.setup( right_fn, io.OUT )
io.output( right_fn, 0 )

io.setup( left_bp, io.OUT )
io.output( left_bp, 0 )
io.setup( left_bn, io.OUT )
io.output( left_bn, 0 )
io.setup( right_bp, io.OUT )
io.output( right_bp, 0 )
io.setup( right_bn, io.OUT )
io.output( right_bn, 0 )


pwm_enb.start(pwmVal_fb)


'''
pwmleft_fp = io.PWM( left_fp , 1000 )
pwmleft_bp = io.PWM( left_bp , 1000 )
pwmleft_fn = io.PWM( left_fn , 1000 )
pwmleft_bn = io.PWM( left_bn , 1000 )

pwmright_fn = io.PWM( right_fn , 1000 )
pwmright_fn = io.PWM( right_fn , 1000 )
pwmright_fn = io.PWM( right_fn , 1000 )
pwmright_fn = io.PWM( right_fn , 1000 )

pwmleft_fp.start(0)
pwmleft_fn.start(0)
pwmleft_bp.start(0)
pwmleft_bn.start(0)

pwmright_fp.start(0)
pwmright_fn.start(0)
pwmright_bp.start(0)
pwmright_bn.start(0)
'''

def forward():
    pwm_enb.ChangeDutyCycle( pwmVal_fb )	
    io.output( left_fn, 0 )
    io.output( right_fp, 0 )
    io.output( left_bn, 0 )
    io.output( right_bp, 0 )

    io.output( left_fp, 1 )
    io.output( right_fn, 1 )
    io.output( left_bp, 1 )
    io.output( right_bn, 1 )
    #sleep(0.1)
    '''
    pwmleft_fp.ChangeDutyCycle( pwmVal )
    pwmright_fn.ChangeDutyCycle( pwmVal )
    pwmleft_bp.ChangeDutyCycle( pwmVal )
    pwmright_bn.ChangeDutyCycle( pwmVal )
    '''


def rev():
    pwm_enb.ChangeDutyCycle( pwmVal_fb )
    io.output( left_fp, 0 )
    io.output( right_fn, 0 )
    io.output( left_bp, 0 )
    io.output( right_bn, 0 )
    
    io.output( left_fn, 1 )
    io.output( right_fp, 1 )
    io.output( left_bn, 1 )
    io.output( right_bp, 1 )
    #sleep(0.1)
    '''
    pwmleft_fn.ChangeDutyCycle( pwmVal )
    pwmright_fp.ChangeDutyCycle( pwmVal )
    pwmleft_bn.ChangeDutyCycle( pwmVal )
    pwmright_bp.ChangeDutyCycle( pwmVal )
    '''

def right():
    pwm_enb.ChangeDutyCycle( pwmVal_lr )
    io.output( left_fn, 0 )
    io.output( right_fp, 0 )
    io.output( left_bn, 0 )
    io.output( right_bp, 0 )

    io.output( right_fn, 0 )
    io.output( right_bn, 0 )
    io.output( left_fp, 1 )
    io.output( left_bp, 1 )
    #sleep(0.1)
    '''
    pwmleft_fn.ChangeDutyCycle( pwmVal )
    pwmleft_bp.ChangeDutyCycle( pwmVal )
    '''
    
    
def left():
    pwm_enb.ChangeDutyCycle( pwmVal_lr )
    #while True:
    io.output( left_fn, 0 )
    io.output( right_fp, 0 )
    io.output( left_bn, 0 )
    io.output( right_bp, 0 )

    io.output( left_fp, 0 )
    io.output( left_bp, 0 )   
    io.output( right_fn, 1 )
    io.output( right_bn, 1 )
    #sleep(0.1)
    '''
    pwmright_fn.ChangeDutyCycle( pwmVal )
    pwmright_bn.ChangeDutyCycle( pwmVal )
    '''
    

def brake():
    io.output( left_fn, 0 )
    io.output( right_fp, 0 )
    io.output( left_bn, 0 )
    io.output( right_bp, 0 )

    io.output( left_fp, 0 )
    io.output( right_fn, 0 )
    io.output( left_bp, 0 )
    io.output( right_bn, 0 )

if __name__ == '__main__':
    
    brake()
    #left()
    #right()
    forward()
