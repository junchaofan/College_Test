package database;

import java.sql.Connection;
import java.sql.DriverManager;

public class DatabaseTools {
	public Connection getConn() {
		Connection myCon = null;
		try {
			myCon =(Connection) DriverManager.getConnection(
					"jdbc:mysql://localhost:3306/mysql?characterEncoding=utf8&useSSL=false&serverTimezone=UTC","root","306015");
			
			if(myCon != null)
			{
				System.out.println("Successfully connected!");
			}
			return myCon;
		}catch(Exception e)
		{
			System.out.print("Connection failed!");
		}
		return myCon;
	}
}
