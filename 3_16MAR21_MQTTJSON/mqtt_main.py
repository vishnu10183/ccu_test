'''
==============================================================================
Program Created on 22-FEB-2021 & Updated on 16-MAR-2021

-> Subprocess to read C build file
-> Read output from C source file and split values
-> Insert actual value & observed values (Row-wise) to a MD file
-> Calculate error rate and insert to MD file
-> Commit the changes to Github Repository
-> GIT commit function from separate Python file.
-> Insert corrected value and current error rate in another file.

Updated:
-> Resulting Graph & MD files in Results folder.
-> Copy from MD files template if file does not exist.
-> Change temperature and readings to integer

===============================================================================
'''


actual_val_list = [ 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
error_list = []
error_terms = [ -0.85, -0.5, -0.50, -0.5, -0.60, -0.56, -0.55, -0.54, -0.54, -0.54 ]



# File Names
c_build_file = "us2_dht22"
template_dir = 'Templates/'
result_dir = 'Results/'
md_file = 'ultraS_14cm_25ms.md'
new_md_file = 'ultraS_newError.md'
graph_file = 'error.png'

exp_count = input("Experiment No.? ") + '_'

import os
from os.path import exists as file_exists
def copy_template( fileName ):
        data = []
        with open( os.path.join(template_dir , fileName) , 'r' ) as fr:
                data = fr.readlines()
        with open( os.path.join(result_dir , exp_count + fileName) , 'w' ) as fw:
                fw.writelines( data )
                

def insertNewData( fileName, values, actual_val ):
        data = []

        if not file_exists( os.path.join(result_dir , exp_count + fileName) ):
                copy_template( fileName )
                
        fileName = os.path.join(result_dir , exp_count + fileName)
        
        with open( fileName , 'r' ) as fr:
            data = fr.readlines()

        lastLine = len(data)-1

        # 1st column is actual value in cm
        # Next columns are TEMP, repeat count, Most-repeated Value
        data[ lastLine ] = data[lastLine].split('\n')[0]                \
                                + str(actual_val) + 'cm | '             \
                                + values[0] + ' | ' + values[1] + ' | ' \
                                + values[len(values)-3] + ' | '         \
                                + values[len(values)-2] + ' | '

        
        repeat_val = float( values[len(values)-2] )
        

        # Next column is Error rate of Most-repeated value 
        err = round( repeat_val - actual_val, 3)
        data[ lastLine ] +=  str( err ) + ' | '

       
        # Add error term to Most-repeated value
        new_val = round( repeat_val - error_terms.pop(0), 3)
        
        
        err = round( new_val- actual_val, 3)

        data[ lastLine ] +=  str( new_val ) + ' | '     # New Value
        data[ lastLine ] +=  str( err ) + ' \n '        # New Error Rate


        with open( fileName , 'w' ) as fw:
            fw.writelines( data )            


        # Error list to plot graph
        error_list.append( 100 * abs( err ) / actual_val )

        



# ------------------------------------------------------------------
# ---------------------------------------------------- MAIN BODY ---
# ------------------------------------------------------------------

import subprocess
import matplotlib
import matplotlib.pyplot as plt
from GIT_commit import git_commit

import paho_mqtt

if __name__ == '__main__':
    print("OUTPUT:")

    
    for actual_val in actual_val_list:
        nxt = input(f"Ready {actual_val}cm ?: ")
        
        tmp=subprocess.check_output( ["sudo", "./"+c_build_file]) # build file name

        val = str(tmp).split('\\n')
        val[0] = val[0].split('"')[1]
        val[-1] = val[-1].split('"')[0]


        print(f'Temperature: {val[0]} , {val[1]}')

        print('Writing to file.....', end= ' ')


        
        insertNewData( new_md_file, val, actual_val ) # Insert Error-Corrected Values
        print("Done")

        print( "Sending MQTT JSON...." )

        #xc, yc, temp, humd
        paho_mqtt.mqttPublish( val[3], val[5], val[0], val[1] )
        print("Done")
    
    print("Program Completed.")

    print( "Creating Graph.....", end= ' ' )
    matplotlib.use('Agg')
    
    plt.plot( actual_val_list, error_list  )
    plt.xlabel('Actual distance (cm) ')
    plt.ylabel( 'Error (%)' )
    plt.title( 'Actual Distance Vs Error' )
    plt.savefig( result_dir + exp_count + graph_file )

    print( 'DONE' )
    
    # Committing to GIT
    git_commit()
