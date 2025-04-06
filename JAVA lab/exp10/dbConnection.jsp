<%@ page import="java.sql.*" %>
<%
    String dbURL = "jdbc:mysql://localhost:3306/UserDB";
    String dbUser = "root"; // Change if needed
    String dbPass = "";     // Change if needed

    Connection conn = null;
    try {
        Class.forName("com.mysql.cj.jdbc.Driver");
        conn = DriverManager.getConnection(dbURL, dbUser, dbPass);
    } catch (Exception e) {
        out.println("Database connection error: " + e.getMessage());
        e.printStackTrace();
    }
%>
