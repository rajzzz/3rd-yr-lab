import java.util.Scanner;

public class exp4 {

    public static int josephus(int n, int k) {
        if (n == 1) {
            return 1;
        } else {
            return (josephus(n - 1, k) + k - 1) % n + 1;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of soldiers: ");
        int n = scanner.nextInt();
        int k = 2; // Every 2nd person is killed
        
        int safePosition = josephus(n, k);
        System.out.println("The safe position is: " + safePosition);
        scanner.close();
    }

}
