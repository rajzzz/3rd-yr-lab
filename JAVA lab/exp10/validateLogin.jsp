<%@ page import="java.sql.*" %>
<%@ include file="dbConnection.jsp" %>

<%
    String username = request.getParameter("username");
    String password = request.getParameter("password");
    boolean isValid = false;

    if (conn != null) {
        String query = "SELECT * FROM users WHERE username=? AND password=?";
        PreparedStatement stmt = conn.prepareStatement(query);
        stmt.setString(1, username);
        stmt.setString(2, password);
        ResultSet rs = stmt.executeQuery();
        
        if (rs.next()) {
            isValid = true;
        }
        
        rs.close();
        stmt.close();
        conn.close();
    }

    if (isValid) {
        session.setAttribute("username", username);
        response.sendRedirect("welcome.jsp");
    } else {
        out.println("<div class='error'>Invalid username or password. <a href='login.jsp'>Try Again</a></div>");
    }
%>
