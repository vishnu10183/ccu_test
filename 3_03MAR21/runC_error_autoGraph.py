'''
==============================================================================
Program Created on 22-FEB-2021 & Updated on 03-MAR-2021

-> Subprocess to read C build file
-> Read output from C source file and split values
-> Insert actual value & observed values (Row-wise) to a MD file
-> Calculate error rate and insert to MD file
-> Commit the changes to Github Repository

Updated:
-> GIT commit function from separate Python file.
-> Edited insertData( ) of splitting last dataLine.
-> For each range of distance, Average errors from files in data directory.
-> Insert corrected value and current error rate
===============================================================================
'''


actual_val_list = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
error_list = []
error_terms = [ -0.2, -0.72, -0.80, -0.82, -0.84, -0.85, -0.85, -0.85, -0.85,
                -0.80, -0.75, -0.70, -0.65, -0.60, -0.56, -0.55, -0.54, -0.54, -0.54 ]



# File Names
c_build_file = "ultraS_dht22_1"
md_file = 'ultraS_14cm_25ms_1.md'
new_md_file = 'ultraS_newError_1.md'
graph_file = 'error_1.png'

def insertData( fileName, values, actual_val ):
        data = []
        with open( fileName , 'r' ) as fr:
            data = fr.readlines()

        lastLine = len(data)-1
        #print( 'No. of lines in MD file:', len(data) )
        #print( 'no. of output values:', len(values) )

        # 1st column is actual value in cm
        data[ lastLine ] = data[lastLine].split('\n')[0] + str(actual_val) + 'cm | '

        # Next columns are TEMP, 5 observations, repeat count, Most-repeated Value
        for indx,each in enumerate(values):
            
            if indx == (len(values)-1): # last value is double quote
                each = values[len(values)-2] # Rewrite each to calculate error-rate
                break
        
            #print(indx ,'<--->',each)
            data[lastLine] += each + ' | '
        

        # Final column is Error rate of Most-repeated value ( i.e, each )
        err = round( float(each)- actual_val, 3)
        data[ lastLine ] +=  str( err ) + '\n '

        with open( fileName , 'w' ) as fw:
            fw.writelines( data )


def insertNewData( fileName, values, actual_val ):
        data = []
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
        

        # Next column is Error rate of Most-repeated value ( i.e, each )
        err = round( repeat_val - actual_val, 3)
        data[ lastLine ] +=  str( err ) + ' | '

       
        # Add error term to Most-repeated value ( i.e, each )
        new_val = repeat_val + error_terms.pop(0)
        
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


if __name__ == '__main__':
    print("OUTPUT:")

    
    for actual_val in actual_val_list:
        nxt = input(f"Ready {actual_val}cm ?: ")
        
        tmp=subprocess.check_output( ["sudo", "./"+c_build_file]) # build file name

        val = str(tmp).split('\\n')
        val[0] = val[0].split('"')[1]


        print(f'Temperature: {val[0]} , {val[1]}')

        print('Writing to file.....', end= ' ')


        insertData( md_file, val, actual_val ) # Insert observation datas
        insertNewData( new_md_file, val, actual_val ) # Insert Error-Corrected Values
        print("Done")
        
    
    print("Program Completed.")

    print( "Creating Graph.....", end= ' ' )
    matplotlib.use('Agg')
    
    plt.plot( actual_val_list, error_list  )
    plt.xlabel('Actual distance (cm) ')
    plt.ylabel( 'Error (%)' )
    plt.title( 'Actual Distance Vs Error' )
    plt.savefig( graph_file )

    print( 'DONE' )
    
    # Committing to GIT
    git_commit()
