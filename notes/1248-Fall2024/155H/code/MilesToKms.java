package unl.soc;

import java.util.Scanner;

public class MilesToKms {
	
	public static void main(String args[]) {

		double miles, kms;
		
		//prompt the user for the input
	    System.out.println("Please enter miles: ");

	    //read in the input
	    Scanner s = new Scanner(System.in);
	    miles = s.nextDouble();

	    kms = 1.609 * miles;

	    System.out.printf("%f miles is equal to %f kilometers\n", miles);

	}

}
