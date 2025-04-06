import java.io.Serializable;

public class SavingsAccount implements Serializable {
    private int accountNumber;
    private String accountHolder;
    private double balance;

    // Constructor
    public SavingsAccount(int accountNumber, String accountHolder, double balance) {
        this.accountNumber = accountNumber;
        this.accountHolder = accountHolder;
        this.balance = balance;
    }

    // Getter and Setter Methods
    public int getAccountNumber() {
        return accountNumber;
    }

    public void setAccountNumber(int accountNumber) {
        this.accountNumber = accountNumber;
    }

    public String getAccountHolder() {
        return accountHolder;
    }

    public void setAccountHolder(String accountHolder) {
        this.accountHolder = accountHolder;
    }

    public double getBalance() {
        return balance;
    }

    // Method to deposit money
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposit Successful! New Balance: " + balance);
        } else {
            System.out.println("Invalid Deposit Amount.");
        }
    }

    // Method to withdraw money
    public boolean withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawal Successful! New Balance: " + balance);
            return true;
        } else {
            System.out.println("Insufficient Balance or Invalid Amount!");
            return false;
        }
    }
}
