package jdbcmysql;
import java.io.*;
import java.sql.*;
import java.util.*;

public class JDBCMysql {

    public static void main(String[] args) {
        try {
            Class.forName ("com.mysql.jdbc.Driver") ;
        }
        catch(Exception e) {
                System.out.println(e) ;
        }    

        try {
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/dummy", "root", "") ;

            PreparedStatement pst = con.prepareStatement("insert into itmast values(?,?,?,?)") ;
            pst.setInt(1, itmid) ;
            pst.setString(2, itmname) ;
            pst.setInt(3, qty) ;
            pst.setInt(4, price) ;
            pst.batchUpdate() ;
            
            pst.executeUpdate() ;
 
            
            Statement stmt = con.createStatement() ;

            ResultSet rs = stmt.executeQuery("Select * from itmmast;") ;

            while (rs.next()) {
                System.out.println(rs.getInt(1) + " " + rs.getString(2) + " " + rs.getInt(3) + " " + rs.getInt(4)) ;
            }
            
            
            con.close() ;
        }
        catch(Exception e) {
                System.out.println(e) ;
        }    
    }
}