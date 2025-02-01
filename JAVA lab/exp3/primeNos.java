import java.util.Scanner;

public class primeNos {
    public static boolean checkPrime(int n) {
        if (n <= 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;

        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner num = new Scanner(System.in);
        System.out.print("Enter start : ");
        int start = num.nextInt();
        System.out.print("Enter end : ");
        int end = num.nextInt();

        System.out.print("Prime numbers between " + start + " and " + end + " are : ");
        for (int i = start; i <= end; i++) {
            if (checkPrime(i)) {
                System.out.print(i + " ");
            }
        }
        num.close();
    }
}