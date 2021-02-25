'''
===================================================
Program Created on 15th FEB 2021

-> Subprocess to read C build file
-> Read output from C source file and split values
-> Insert actual value & observed values (Row-wise) to a MD file
-> Calculate error rate and insert to MD file
-> Commit the changes to Github Repository
===================================================
'''


import subprocess
print("OUTPUT:")

tmp=subprocess.check_output( ["sudo", "./ultraS_dht22_1"]) # build file name
'''
try:
    subprocess.check_output("./ultraS_piGPIO_1",shell=True,stderr=subprocess.STDOUT)
except subprocess.CalledProcessError as e:
    raise RuntimeError("command '{}' return with error (code {}): {}".format(e.cmd, e.returncode, e.output))
'''
#print(tmp)
#tmp=2
val = str(tmp).split('\\n')
val[0] = val[0].split('"')[1]



print(f'Temperature: {val[0]} , {val[1]}')

print('Writing to file....')

actual_val = 125

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
        
        if indx == 13:
            each = values[12]
            break
        #print(indx ,'<--->',each)
        data[ lastLine ] = data[lastLine].split('\n')[0] + each + ' | \n'

    # Final column is Error rate    
    data[ lastLine ] = data[lastLine].split('\n')[0] + "{:.3f} ".format(float(each)- actual_val) + '\n '
    
    '''
    for indx, each in enumerate(data):
        if indx in range(0,startLine): # first n lines are headings
            continue
        if indx-startLine != 13 :
            data[indx] = data[indx].split('\n')[0] +  ' | ' + values[indx-startLine] +'\n'
        else:
            data[indx] = data[indx].split('\n')[0] + " | {:.3f} ".format(float(values[indx-startLine-1]) - actual_val)
        
    '''
    with open( fileName , 'w' ) as fw:
        fw.writelines( data )
    


insertData( 'ultraS_14cm_5ms.md', val ) # data starts @ 12th Line

print("Program Completed.")

# Committing to GIT
#tmp=subprocess.call( ["cd", "/home/pi/VishnuM/Aurora-CCU/TestCodes"])
tmp=subprocess.call( ["git", "add", "."], cwd="/home/pi/VishnuM/Aurora-CCU/TestCodes")
print(tmp)
tmp=subprocess.call( ["git", "commit", "-m", '"Updated 25FEB"'], cwd="/home/pi/VishnuM/Aurora-CCU/TestCodes")
print(tmp)
tmp=subprocess.call( ["git", "push", "-u", "origin", "RPi4", "--force"], cwd="/home/pi/VishnuM/Aurora-CCU/TestCodes")
print(tmp)
