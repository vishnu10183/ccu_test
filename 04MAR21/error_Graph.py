
import matplotlib
import matplotlib.pyplot as plt

graph_file = 'error_1.png'


actual_val_list = [2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]
error_list = [0.14, -0.43, -0.53, -0.62, -0.60, -1.05, -1.16, -0.28, -0.38, \
                -0.21, -0.36, -1.02, -0.74, -0.71, -0.69, -0.78, -0.76, -0.79, -0.88 ]
error_percent = []

if __name__ == '__main__':
    print( "Creating Graph.....", end= ' ' )
    matplotlib.use('Agg')
    
    for indx, actual_val in enumerate( actual_val_list ) :
        err = round( error_list[indx] - actual_val, 3)
        error_percent.append( 100 * abs( err ) / actual_val )


    plt.plot( actual_val_list, error_percent  )
    plt.xlabel('Actual distance (cm) ')
    plt.ylabel( 'Error (%)' )
    plt.title( 'Actual Distance Vs Error' )
    plt.savefig( graph_file )

    print( 'DONE' )