import java.io.*;
import java.net.*;

public class AdditionClient {
    public static void main(String[] args) {
        try {
            // Connect to server on localhost, port 5000
            Socket socket = new Socket("localhost", 5001);
            System.out.println("Connected to server!");
            // Input and Output streams
            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new

            InputStreamReader(socket.getInputStream()));

            System.out.print("Enter first number: "); // Get two numbers from user
            int num1 = Integer.parseInt(userInput.readLine());
            System.out.print("Enter second number: ");
            int num2 = Integer.parseInt(userInput.readLine());
            // Send numbers to server
            out.println(num1);
            out.println(num2);
            int sum = Integer.parseInt(in.readLine()); // Receive result from server
            System.out.println("Sum received from server: " + sum);
            // Close resources
            userInput.close();
            out.close();
            in.close();
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}