import java.util.Scanner;

public class fizzBuzz {
  public static void main(String[] args) {

    Scanner num = new Scanner(System.in);
    System.out.print("Enter the total number of elements : ");
    int n = num.nextInt();

    for (int i = 1; i < n + 1; i++) {
      if (i % 3 == 0 && i % 5 == 0) {
        System.out.println(" FizzBuzz");
      } else if (i % 3 == 0) {
        System.out.println(" Fizz");
      } else if (i % 5 == 0) {
        System.out.println(" Buzz");
      }

      else {
        System.out.println(" " + i);
      }
    }
    num.close();
  }
}
