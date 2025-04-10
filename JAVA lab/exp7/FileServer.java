
import java.io.*;
import java.net.*;

public class FileServer {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(8000);
            System.out.println("Server is waiting for client...");
            Socket socket = serverSocket.accept(); // Accept client connection
            System.out.println("Client connected!");

            System.out.println("Connected to server!");
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            String filePath = in.readLine();

            File file = new File(filePath);
            if (file.exists()) {
                System.out.println("File found");
                out.println("File Found");
                out.println("Printing file contents...");
                BufferedReader fileReader = new BufferedReader(new FileReader(file));
                String line;
                while ((line = fileReader.readLine()) != null) {
                    out.println(line);
                }
                out.println("\n---------End of file---------\n");
                fileReader.close();
            } else {
                System.out.println("File not found");
                out.println("File not found");
            }

            out.close();
            in.close();
            serverSocket.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
