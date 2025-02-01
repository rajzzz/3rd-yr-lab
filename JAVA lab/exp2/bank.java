abstract class BankAccount {
	protected String accountNumber;
	protected double balance;

	public BankAccount(String accountNumber, double balance) {
		this.accountNumber = accountNumber;
		this.balance = balance;
	}

	public abstract void deposit(double amount);

	public abstract void withdraw(double amount);

	public void displayDetails() {
		System.out.println("Account Number: " + this.accountNumber);
		System.out.println("Balance: " + balance);
	}
}

class SavingsAccount extends BankAccount {
	private double interestRate;

	public SavingsAccount(String accountNumber, double balance, double interestRate) {
		super(accountNumber, balance);
		this.interestRate = interestRate;
	}

	@Override
	public void deposit(double amount) {
		balance += amount + (amount * interestRate / 100);
		System.out.println("Deposited with interest: " + amount);
	}

	@Override
	public void withdraw(double amount) {
		if (balance - amount >= 500) {
			balance -= amount;
			System.out.println("Withdrawn amount: " + amount);
		} else {
			System.out.println("Withdrawal denied. Minimum balance must remain 500.");
		}
	}
}

class CurrentAccount extends BankAccount {
	public double overdraftLimit;

	public CurrentAccount(String accountNumber, double balance, double overdraftLimit) {
		super(accountNumber, balance);
		this.overdraftLimit = overdraftLimit;
	}

	@Override
	public void deposit(double amount) {
		balance += amount;
		System.out.println("Deposited: " + amount);
	}

	@Override
	public void withdraw(double amount) {
		if (balance - amount >= -overdraftLimit) {
			balance -= amount;
			System.out.println("Withdrawn amount: " + amount);
		} else {
			System.out.println("Withdrawal denied. Exceeds overdraft limit.");
		}
	}
}
public class bank {
    public static void main(String[] args) {
		SavingsAccount savings_account = new SavingsAccount("A9201", 1000, 5);	
		CurrentAccount current_account = new CurrentAccount("C4303", 2000, 1000);

		System.out.println("Savings Account:");
        savings_account.displayDetails();
		savings_account.deposit(500);
		savings_account.withdraw(800);
		savings_account.displayDetails();
        System.out.println("");
		System.out.println("Current Account:");
        current_account.displayDetails();
		current_account.deposit(1000);
		current_account.withdraw(3500);
		current_account.displayDetails();
	}
}
