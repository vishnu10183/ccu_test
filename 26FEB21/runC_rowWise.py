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


import subprocess
print("OUTPUT:")

tmp=subprocess.check_output( ["sudo", "./ultraS_dht22_1"]) # build file name

#print(tmp)
#tmp=2
val = str(tmp).split('\\n')
val[0] = val[0].split('"')[1]



print(f'Temperature: {val[0]} , {val[1]}')

print('Writing to file....')

actual_val = 20

def insertData( fileName, values ):
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
    data[ lastLine ] = data[lastLine].split('\n')[0] + "{:.3f} ".format(float(each)- actual_val) + '\n '
    

    with open( fileName , 'w' ) as fw:
        fw.writelines( data )
    


insertData( 'ultraS_14cm_10ms.md', val ) # data starts @ 12th Line

print("Program Completed.")


# Committing to GIT
#tmp=subprocess.call( ["cd", "/home/pi/VishnuM/Aurora-CCU/TestCodes"])
tmp=subprocess.call( ["git", "add", "."], cwd="/home/pi/VishnuM/Aurora-CCU/TestCodes")
print(tmp)
tmp=subprocess.call( ["git", "commit", "-m", '"Updated 25FEB"'], cwd="/home/pi/VishnuM/Aurora-CCU/TestCodes")
print(tmp)
tmp=subprocess.call( ["git", "push", "-u", "origin", "RPi4", "--force"], cwd="/home/pi/VishnuM/Aurora-CCU/TestCodes")
print(tmp)
