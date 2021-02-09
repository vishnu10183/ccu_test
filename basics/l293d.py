import RPi.GPIO as io

io.setmode( io.BCM )
io.setwarnings(False)

class L293D:
    

    def __init__(self):
        self.EN12 = 12
        self.EN34 = 13

        self.IN1= 26
        self.IN2= 16
        self.IN4= 5
        self.IN3= 6
        
        io.setup( self.EN12, io.OUT )
        io.output( self.EN12, 0 )
        io.setup( self.EN34, io.OUT )
        io.output( self.EN34, 0 )

        io.setup( self.IN1, io.OUT )
        io.output( self.IN1, 0 )
        io.setup( self.IN2, io.OUT )
        io.output( self.IN2, 0 )
        io.setup( self.IN3, io.OUT )
        io.output( self.IN3, 0 )
        io.setup( self.IN4, io.OUT )
        io.output( self.IN4, 0 )

    def move_fw(self):
        print("Move FW")
        io.output( self.IN2, 0 )
        io.output( self.IN4, 0 )
        io.output( self.IN1, 1 )
        io.output( self.IN3, 1 )

    def move_rev(self):
        io.output( self.IN1, 0 )
        io.output( self.IN3, 0 )
        io.output( self.IN2, 1 )
        io.output( self.IN4, 1 )

    def brake(self):
        print("BRAKE!!!")
        io.output( self.IN1, 0 )
        io.output( self.IN3, 0 )
        io.output( self.IN2, 0 )
        io.output( self.IN4, 0 )

from time import sleep

if __name__ == '__main__':
    print("TEST!")
    mtr= L293D()
    #io.output( mtr.EN12, 1 )
    #io.output( mtr.EN34, 1 )
    mtr.brake()
    #mtr.move_fw()
    #move_rev()
    sleep(1)

    
