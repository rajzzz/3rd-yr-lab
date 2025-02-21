
import java.io.*;
import java.net.*;

public class AdditionServer {
    public static void main(String[] args) {
        try {
            // Create server socket on port 5000
            ServerSocket serverSocket = new ServerSocket(5001);
            System.out.println("Server is waiting for client...");
            Socket socket = serverSocket.accept(); // Accept client connection
            System.out.println("Client connected!");
            // Input and Output streams
            BufferedReader in = new BufferedReader(new

            InputStreamReader(socket.getInputStream()));

            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            int num1 = Integer.parseInt(in.readLine()); // Read two numbers from client
            int num2 = Integer.parseInt(in.readLine());
            int sum = num1 + num2; // Calculate sum
            out.println(sum); // Send result back to client
            // Close resources
            in.close();
            out.close();
            socket.close();
            serverSocket.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}