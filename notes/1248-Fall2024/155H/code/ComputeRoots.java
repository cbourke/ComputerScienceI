package unl.soc;

/**
 * Chris Bourke
 * 2024-09-06
 * 
 * TODO: write documentation
 */
public class ComputeRoots {

	public static void main(String args[]) {

	    double a, b, c;

	    if(args.length != 3) {
	        System.out.printf("ERROR: you did not provide the correct number of command line arguments\n");
	        System.exit(1);
	    }

	    a = Double.parseDouble(args[0]);
	    b = Double.parseDouble(args[1]);
	    c = Double.parseDouble(args[2]);

	    if(a == 0) {
	    	System.out.printf("ERROR: a cannot be zero, you have a linear equation, just solve it!\n");
	    	System.exit(2);
	    }

	    double x1 = (-b + Math.sqrt( Math.pow(b, 2) - 4*a*c ) ) / (2*a);
	    double x2 = (-b - Math.sqrt( Math.pow(b, 2) - 4*a*c ) ) / (2*a);

	    System.out.printf("%fx^2 + %fx + %f has roots %f and %f\n", a, b, c, x1, x2);

	}
	
}
