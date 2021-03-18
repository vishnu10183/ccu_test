from flask import Flask, render_template, request, redirect, url_for

webApp = Flask(__name__)


import rover

@webApp.route('/')
def rootPage():
    return redirect( url_for('brakePage') )

@webApp.route('/brake')
def brakePage():
    rover.brake()
    return render_template( 'app.html', rover_status = 'BRAKE' )

@webApp.route('/forward')
def forwardPage():
    rover.forward()
    return render_template( 'app.html', rover_status = 'FORWARD' )

@webApp.route('/left')
def leftPage():
    rover.left()
    return render_template( 'app.html', rover_status = 'LEFT' )

@webApp.route('/right')
def rightPage():
    rover.right()
    return render_template( 'app.html', rover_status = 'RIGHT' )

@webApp.route('/rev')
def revPage():
    rover.rev()
    return render_template( 'app.html', rover_status = 'REVERSE' )





if __name__ == '__main__':
    webApp.run( host= '0.0.0.0', port=80, debug= True )


