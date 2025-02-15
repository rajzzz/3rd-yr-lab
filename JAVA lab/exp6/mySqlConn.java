/* WAP in java to 
 * 1. Fetch all the records from the employee table
 * 2. Insert a new employee record
 * 3. Search employee with empid
 * 4. Update specific employee details
 * 5. Delete a particualr employee record
 * 
 * Employee table has fields in mysql
 *      EmpId
 *      EmpName 
 *      EmpCity
 *      EmpSalary
 */

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

public class mySqlConn {

    static void fetchAllRecords(Statement statement, ResultSet resultSet) throws SQLException {
        resultSet = statement.executeQuery("SELECT * FROM Employees");
        // Get the metadata for the result set (column labels)
        ResultSetMetaData metaData = resultSet.getMetaData();
        // int columnCount = metaData.getColumnCount();

        System.out.println("Employee Details:");
        // using print formating to print the result on terminal in prettier way
        System.out.printf("%-10s %-20s %-20s %-10s\n",
                metaData.getColumnLabel(1),
                metaData.getColumnLabel(2),
                metaData.getColumnLabel(3),
                metaData.getColumnLabel(4));

        while (resultSet.next()) {
            System.out.printf("%-10d %-20s %-20s %-10d\n",
                    resultSet.getInt("Empid"),
                    resultSet.getString("EmpName"),
                    resultSet.getString("EmpCity"),
                    resultSet.getInt("EmpSalary"));
        }
        System.out.println("_________________________________");
    }

    static void insertRecord(Statement statement, Scanner scanner) throws SQLException {
        System.out.println("Inserting a new employee record...");
        System.out.println("Enter employee id: ");
        int id = scanner.nextInt();
        scanner.nextLine();  
        System.out.println("Enter employee name: ");
        String name = scanner.nextLine();
        System.out.println("Enter employee city: ");
        String city = scanner.nextLine();
        System.out.println("Enter employee salary: ");
        int salary = scanner.nextInt();

        int rowsAffected = statement.executeUpdate(
                "INSERT INTO Employees VALUES (" + id + ", '" + name + "', '" + city + "', " + salary + ")");
        if (rowsAffected > 0) {
            System.out.println("Record inserted successfully!");
        } else {
            System.out.println("Record insertion failed!");
        }
        System.out.println("_________________________________");
    }

    static void searchRecord(Scanner scanner, Statement statement, ResultSet resultSet) throws SQLException {
        System.out.println("Enter employee id to search for employee: ");
        int id = scanner.nextInt();
        resultSet = statement.executeQuery("Select * from Employees where Empid = " + id);
        if (resultSet.next()) {
            System.out.println("Employee found with id: " + id);
            System.out.println("Employee Name: " + resultSet.getString("EmpName"));
            System.out.println("Employee City: " + resultSet.getString("EmpCity"));
            System.out.println("Employee Salary: " + resultSet.getInt("EmpSalary"));
        } else {
            System.out.println("Employee with id " + id + " not found!");
        }
        System.out.println("_________________________________");
    }

    static void updateRecord(Statement statement, Scanner scanner) throws SQLException {
        System.out.println("Enter employee id to update employee record: ");
        int id = scanner.nextInt();
        scanner.nextLine();
        System.out.println("Enter employee name: ");
        String name = scanner.nextLine();
        System.out.println("Enter employee city: ");
        String city = scanner.nextLine();
        System.out.println("Enter employee salary: ");
        int salary = scanner.nextInt();
        int rowsAffected = statement.executeUpdate("Update Employees set EmpName = '" + name + "', EmpCity = '" + city
                + "', EmpSalary = " + salary + " where Empid = " + id);
        if (rowsAffected > 0) {
            System.out.println("Employee with id " + id + " updated successfully!");
        } else {
            System.out.println("Employee with id " + id + " not found!");
        }
        System.out.println("_________________________________");
    }

    static void deleteRecord(Statement statement, Scanner scanner) throws SQLException {
        System.out.println("Enter employee id to delete employee record: ");
        int id = scanner.nextInt();
        int rowsAffected = statement.executeUpdate("Delete from Employees where Empid = " + id);
        if (rowsAffected > 0) {
            System.out.println("Employee with id " + id + " deleted successfully!");
        } else {
            System.out.println("Employee with id " + id + " not found!");
        }
        System.out.println("_________________________________");
    }

    public static void main(String[] args) {
        // Database credentials
        String url = "jdbc:mysql://localhost/pulkit";
        String username = "root";
        String password = "";

        // Establishing the connection
        try {
            // Registering the JDBC driver (Optional for newer versions of JDBC)
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Creating a connection to the database
            Connection connection = DriverManager.getConnection(url, username, password);

            // Checking if the connection is successful
            if (connection != null) {
                System.out.println("Connection successful!");
                System.out.println("_____________________________");
            } else {
                System.out.println("Connection failed!");
            }

            Statement statement = connection.createStatement();
            ResultSet resultSet;
            // 1. Fetch all the records from the employee table
            resultSet = statement.executeQuery("SELECT * FROM Employees");
            fetchAllRecords(statement, resultSet);

            // 2. Insert a new employee record
            Scanner scanner = new Scanner(System.in);
            insertRecord(statement, scanner);

            // 3. Search employee with empid
            searchRecord(scanner, statement, resultSet);

            // 4. Update specific employee details
            updateRecord(statement, scanner);

            // 5. Delete a particualr employee record
            deleteRecord(statement, scanner);

            scanner.close();
            connection.close();
        } catch (ClassNotFoundException e) {
            System.out.println("JDBC Driver not found!");
            e.printStackTrace();
        } catch (SQLException e) {
            System.out.println("SQL Exception: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
