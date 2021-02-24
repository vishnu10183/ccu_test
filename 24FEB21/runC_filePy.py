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

actual_val = 50

def insertData( fileName, values, startLine ):
    data = []
    with open( fileName , 'r' ) as fr:
        data = fr.readlines()


    for indx, each in enumerate(data):
        if indx in range(0,startLine): # first n lines are headings
            continue
        if indx-startLine != 13 :
            data[indx] = data[indx].split('\n')[0] +  ' | ' + values[indx-startLine] +'\n'
        else:
            data[indx] = data[indx].split('\n')[0] + " | {:.3f} ".format(float(values[indx-startLine-1]) - actual_val)
        

    with open( fileName , 'w' ) as fw:
        fw.writelines( data )



insertData( 'ultraS_height_6cm.md', val, 11 ) # data starts @ 12th Line

print("Program Completed.")
