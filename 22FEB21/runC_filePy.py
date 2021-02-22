import subprocess
tmp=subprocess.check_output("./ultraS_dht22_1") # build file name
#tmp=2
val = str(tmp).split('\\n')
val[0] = val[0].split('"')[1]

print("OUTPUT:")
#print(tmp)
print(f'Temperature: {val[0]} , {val[1]}')

print('Writing to file....')



def insertData( fileName, values, startLine ):
    data = []
    with open( fileName , 'r' ) as fr:
        data = fr.readlines()


    for indx, each in enumerate(data):
        if indx in range(0,startLine): # first n lines are headings
            continue
        data[indx] = data[indx].split('\n')[0] +  ' | ' + values[indx-startLine+2] +'\n'
        

    with open( fileName , 'w' ) as fw:
        fw.writelines( data )



insertData( 'ultraS_height_6cm.md', val, 11 ) # data starts @ 12th Line
