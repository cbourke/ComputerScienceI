package unl.soc;

public class Loan {
	
	/**
	 * Returns the given value rounded to the nearest
	 * cent (100th spot).
	 * 
	 * @param x
	 * @return
	 */
	public static double roundToCents(double x) {
		return Math.round(x * 100.0) / 100.0;
	}

	public static void main(String args[]) {

		double principle = 10000;
		int numYears = 5;
		double annualRate = 0.05;

		double monthlyRate = annualRate / 12;
		int numTerms = numYears * 12;
		double monthlyPayment = (monthlyRate * principle) / 
				(1 - Math.pow(1 + monthlyRate, -numTerms));
		monthlyPayment = roundToCents(monthlyPayment);
				
		double balance = principle;
		for(int month=1; month<numTerms; month++) {
			double monthInterest = roundToCents(monthlyRate * balance);
			double monthPrinciple = roundToCents(monthlyPayment - monthInterest);
			double newBalance = roundToCents(balance - monthPrinciple);
			System.out.printf("%d $%.2f $%.2f $%.2f $%.2f\n", month, balance, monthInterest, monthPrinciple, newBalance);
			balance = newBalance;
		}
		
		//TODO: you may need to handle the final month separately

	}

}
