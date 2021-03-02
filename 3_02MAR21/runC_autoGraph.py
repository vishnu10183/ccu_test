'''
==================================================================
Program Created on 22-FEB-2021 & Updated on 25-FEB-2021

-> Subprocess to read C build file
-> Read output from C source file and split values
-> Insert actual value & observed values (Row-wise) to a MD file
-> Calculate error rate and insert to MD file
-> Commit the changes to Github Repository
==================================================================
'''


actual_val_list = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
error_list = []

# File Names
c_build_file = "ultraS_dht22_1"
md_file = 'ultraS_14cm_25ms_6.md'
graph_file = 'error_6.png'

def insertData( fileName, values, actual_val ):
        data = []
        with open( fileName , 'r' ) as fr:
            data = fr.readlines()

        lastLine = len(data)-1
        #print( 'No. of lines in MD file:', len(data) )
        #print( 'no. of output values:', len(values) )

        # 1st column is actual value in cm
        data[ lastLine ] = data[lastLine].split('\n')[0] + str(actual_val) + 'cm | \n'

        # Next columns are TEMP, 10 observations, Most-repeated Value
        for indx,each in enumerate(values):
            
            if indx == (len(values)-1): # last value is double quote
                each = values[len(values)-2] # Rewrite each to calculate error-rate
                break
            #print(indx ,'<--->',each)
            data[ lastLine ] = data[lastLine].split('\n')[0] + each + ' | \n'

        # Final column is Error rate
        err = round( float(each)- actual_val, 3)
        #data[ lastLine ] = data[lastLine].split('\n')[0] + "{:.3f} ".format( err ) + '\n '
        data[ lastLine ] = data[lastLine].split('\n')[0] + str( err ) + '\n '

        error_list.append( 100 * abs( err ) / actual_val )

        with open( fileName , 'w' ) as fw:
            fw.writelines( data )

        
def git_commit():
        #tmp=subprocess.call( ["cd", "/home/pi/VishnuM/Aurora-CCU/TestCodes"])
        tmp=subprocess.call( ["git", "add", "."], cwd="/home/pi/VishnuM/Aurora-CCU/TestCodes")
        print(tmp)
        tmp=subprocess.call( ["git", "commit", "-m", '"Updated 25FEB"'], cwd="/home/pi/VishnuM/Aurora-CCU/TestCodes")
        print(tmp)
        tmp=subprocess.call( ["git", "push", "-u", "origin", "RPi4", "--force"], cwd="/home/pi/VishnuM/Aurora-CCU/TestCodes")
        print(tmp)




# ------------------------------------
# ---------------------- MAIN BODY ---
# ------------------------------------

import subprocess
import matplotlib
import matplotlib.pyplot as plt


if __name__ == '__main__':
    print("OUTPUT:")

    
    for actual_val in actual_val_list:
        nxt = input(f"Ready {actual_val}cm ?: ")
        
        tmp=subprocess.check_output( ["sudo", "./"+c_build_file]) # build file name

        val = str(tmp).split('\\n')
        val[0] = val[0].split('"')[1]


        print(f'Temperature: {val[0]} , {val[1]}')

        print('Writing to file.....', end= ' ')


        insertData( md_file, val, actual_val ) # data starts @ 12th Line
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
