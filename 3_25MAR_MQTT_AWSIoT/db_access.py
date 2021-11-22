import pymysql 

# Create a connection object 
# IP address of the MySQL database server 
Host = "192.168.4.115" # "localhost"

# User name of the database server 
User = "corona"	

# Password for the database user 
Password = "mask"		 

database = "iot_db"
tableName = "iot"

conn = pymysql.connect(host=Host, user=User, password=Password, db= database) 

# Create a cursor object 
cur = conn.cursor() 


query = f"SELECT * FROM "+tableName

cur.execute(query) 

rows = cur.fetchall() 
conn.close() 

for row in rows : 
	print(row)