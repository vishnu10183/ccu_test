import pymysql 

# Create a connection object 
# IP address of the MySQL database server 
Host = "0.0.0.0" # "localhost"

# User name of the database server 
User = "AFuser"	

# Password for the database user 
Password = "secret"		 

database = "mqtt_sql"
tableName = "roughdata"

conn = pymysql.connect(host=Host, user=User, password=Password, db= database) 

# Create a cursor object 
cur = conn.cursor() 


query = f"SELECT * FROM "+tableName

cur.execute(query) 

rows = cur.fetchall() 
conn.close() 

for row in rows : 
	print(row)
