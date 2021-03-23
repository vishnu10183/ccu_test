import pymysql 

# Create a connection object 
# IP address of the MySQL database server 
Host = "96.125.163.12" # "localhost"

# User name of the database server 
User = "acufol6j_iot_db"	

# Password for the database user 
Password = "iottest"		 

database = "acufol6j_iot_db"
tableName = "iot"

conn = pymysql.connect(host=Host, user=User, password=Password, db= database) 

# Create a cursor object 
cur = conn.cursor() 


#query = f"SELECT * FROM "+tableName
query = f'INSERT INTO {tableName} (time_stamp, xcord, ycord, temprature, humidity) VALUES("2021-03-17 13:02:10", 24, 12, 11.12, 123.45 )'

cur.execute(query) 

rows = cur.fetchall() 
conn.close() 

for row in rows : 
	print(row)
