import pymysql 

# Create a connection object 
# IP address of the MySQL database server 
Host = "aws-iot-project.cm3t4elsveqy.us-east-2.rds.amazonaws.com" #"96.125.163.12" #"0.0.0.0" # "localhost"

# Access-Details of the database server 
User = "iot_admin" #"acufol6j_iot_db" #"corona" #"AFuser" #
Password = "Iot1234#"# "iottest" #"mask" #"secret" #

database = "iot_db"#"acufol6j_iot_db" #"iot_db" #"mqtt_sql" #"iot_db" #
tableName = "iot" #"roughdata" #"iot"

connection = pymysql.connect(host=Host, user=User, password=Password, db= database)

def startSQL():
        global connection
        connection = pymysql.connect(host=Host, user=User, password=Password, db= database) 

def closeSQL():
        global connection
        connection.close()

def insertData( time_stamp, xcord, ycord, temp, humidity, distance, field_id, impl_id ):
        global connection
        db_cursor = connection.cursor() 

        query = f"INSERT INTO {tableName} (time_stamp, xcord, ycord, temperature, humidity, distance, field_id, implement_id) VALUES( '{time_stamp}', {xcord}, {ycord}, {temp}, {humidity}, {distance}, {field_id}, {impl_id} )"
        #query = f"INSERT INTO iot( time_stamp, xcord, ycord, temperature, humidity, distance) VALUES('{time_stamp}',15, 15, '25.0', 40.10, 1.5)"
        print( query )
        db_cursor.execute(query)
        connection.commit()
        
        

def updateData( colName, newVal, idNo ):
        connection = pymysql.connect(host=Host, user=User, password=Password, db= database) 
        db_cursor = connection.cursor() 

        query = f"UPDATE {tableName}" +\
                f" SET {colName} = '{newVal}' WHERE id = {idNo}"
                
        db_cursor.execute(query)
        
        connection.close() 

def viewFullData():
        connection = pymysql.connect(host=Host, user=User, password=Password, db= database) 
        db_cursor = connection.cursor()
        
        query = f"SELECT * FROM {tableName}"
        db_cursor.execute(query)
        rows = db_cursor.fetchall()
        
        connection.close() 
        for row in rows : 
                print(row)

def showTable():
        connection = pymysql.connect(host=Host, user=User, password=Password, db= database) 
        db_cursor = connection.cursor()
        
        query = f"SHOW TABLES"
        db_cursor.execute(query)
        print (db_cursor.fetchall() )
        
        connection.close() 

def renameCol( oldName, newName, dtype ):
        connection = pymysql.connect(host=Host, user=User, password=Password, db= database) 
        db_cursor = connection.cursor() 

        query = f'ALTER TABLE {tableName} CHANGE {oldName} {newName} {dtype}'
        db_cursor.execute(query)
        
        connection.close() 

if __name__ == '__main__':
        print( 'Starting...' )
        insertData("2021-03-17 17:20:41", 15, 15, 25, 40.10)
        '''
        updateData( colName= 'timestamp', newVal= '2021-03-16 18:10:24', idNo= 1 )
        renameCol( 'timestamp' , 'time_stamp', 'timestamp' )
        renameCol( 'xc' , 'xcord', 'INT(11)' )
        renameCol( 'yc' , 'ycord', 'INT(11)' )
        renameCol( 'temp' , 'temperature', 'FLOAT(20)' )
        '''
        #viewFullData()
        #showTable()
        print( 'COMPLETED' )
