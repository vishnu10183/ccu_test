import RPi.GPIO as io
from time import sleep

left_fn = 19
left_fp = 26
left_bn = 6
left_bp = 13

right_fp = 16
right_fn = 12
right_bp = 20
right_bn = 21

io.setmode( io.BCM )

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


def forward():
    io.output( left_fn, 0 )
    io.output( right_fp, 0 )
    io.output( left_bn, 0 )
    io.output( right_bp, 0 )

    io.output( left_fp, 1 )
    io.output( right_fn, 1 )
    io.output( left_bp, 1 )
    io.output( right_bn, 1 )


def rev():
    io.output( left_fp, 0 )
    io.output( right_fn, 0 )
    io.output( left_bp, 0 )
    io.output( right_bn, 0 )
    
    io.output( left_fn, 1 )
    io.output( right_fp, 1 )
    io.output( left_bn, 1 )
    io.output( right_bp, 1 )


def right():
    io.output( left_fn, 0 )
    io.output( right_fp, 0 )
    io.output( left_bn, 0 )
    io.output( right_bp, 0 )

    io.output( right_fn, 0 )
    io.output( right_bn, 0 )
    io.output( left_fp, 1 )
    io.output( left_bp, 1 )
    
def left():
    io.output( left_fn, 0 )
    io.output( right_fp, 0 )
    io.output( left_bn, 0 )
    io.output( right_bp, 0 )

    io.output( left_fp, 0 )
    io.output( left_bp, 0 )   
    io.output( right_fn, 1 )
    io.output( right_bn, 1 ) 

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
    #forward()
    brake()
    #left()
    #right()
