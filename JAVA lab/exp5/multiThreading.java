/* Write a two thread based program in java, where thread 1 adds all the even numbers and thread2 adds all the odd numbers from a given file whihc has large number of positive integers */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Random;
import java.util.Scanner;

class EvenThread implements Runnable {

    @Override
    public void run() {
        try {
            int sum = 0;
            BufferedReader br = new BufferedReader(new FileReader("numbers.txt"));
            String line;
            while ((line = br.readLine()) != null) {
                int num = Integer.parseInt(line);
                if (num % 2 == 0) {
                    System.out.println("Even: " + num);
                    sum += num;
                }
            }
            br.close();
            System.out.println("Sum of even numbers from the file is: " + sum);

        } catch (Exception e) {
            System.out.println("ERROR: " + e.getMessage());
        }
    }
}

class OddThread implements Runnable {

    @Override
    public void run() {
        try {
            int sum = 0;
            BufferedReader br = new BufferedReader(new FileReader("numbers.txt"));
            String line;
            while ((line = br.readLine()) != null) {
                int num = Integer.parseInt(line);
                if (num % 2 != 0) {
                    System.out.println("Odd: " + num);
                    sum += num;
                }
            }
            br.close();
            System.out.println("Sum of odd numbers from the file is: " + sum);

        } catch (Exception e) {
            System.out.println("ERROR: " + e.getMessage());
        }
    }
}

public class multiThreading {

    public static void main(String[] args) {
        try {
            Scanner scan = new Scanner(System.in);
            System.out.println("Enter the number of random integers that you want to generate:");
            int n = scan.nextInt();
            Random r = new Random();
            BufferedWriter bw = new BufferedWriter(new FileWriter("numbers.txt"));
            for (int i = 0; i < n; i++) {
                int randomNo = r.nextInt(100) + 1;
                bw.write(randomNo + "\n");
            }
            bw.close();

            EvenThread t1 = new EvenThread();
            OddThread t2 = new OddThread();
            Thread thread1 = new Thread(t1);
            Thread thread2 = new Thread(t2);
            thread1.start();
            thread2.start();
            scan.close();

        } catch (Exception e) {
            System.out.println("ERROR: " + e.getMessage());
        }

    }
}
