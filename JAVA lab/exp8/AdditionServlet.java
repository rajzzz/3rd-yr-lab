// Q: Design a servlet and html page for addition of 2 numbers

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.ServletException;

@WebServlet("/AdditionServlet")  // URL mapping

public class AdditionServlet extends HttpServlet {
   @Override
   protected void doPost(HttpServletRequest request, HttpServletResponse response)
           throws ServletException, IOException {
       // Set response content type
       response.setContentType("text/html");
             // Get numbers from the request
       int num1 = Integer.parseInt(request.getParameter("num1"));
       int num2 = Integer.parseInt(request.getParameter("num2"));
     
       // Calculate sum
       int sum = num1 + num2;
       // Display result
       PrintWriter out = response.getWriter();
       out.println("<html><body>");
       out.println("<h2>Result</h2>");
       out.println("<p>Number 1: " + num1 + "</p>");
       out.println("<p>Number 2: " + num2 + "</p>");
       out.println("<p><b>Sum: " + sum + "</b></p>");
       out.println("</body></html>");
   }
}
