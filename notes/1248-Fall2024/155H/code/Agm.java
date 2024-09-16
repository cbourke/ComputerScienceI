package unl.soc;

/**
 * Chris Bourke
 * 2024-09-13
 *
 * This program reads command line arguments for two numbers
 * and computes and outputs their arithmetic–geometric.  See
 *
 * <a href="https://en.wikipedia.org/wiki/Arithmetic%E2%80%93geometric_mean">here</a>
 *
 */
public class Agm {

	public static void main(String args[]) {

		final double TOLERANCE = 0.0000001;

		if(args.length != 2) {
			System.err.printf("ERROR: expected 2 numbers\n");
			System.exit(1);
	    }
	    double x = Double.parseDouble(args[0]);
	    double y = Double.parseDouble(args[1]);

	    if(x < 0 || y < 0) {
	    	System.err.printf("ERROR: both values should be non-negative\n");
	    	System.exit(2);
	    } else if( Math.abs(x - y) < TOLERANCE) {
	    	System.err.printf("agm(%f, %f) = %.20f\n", x, y, x);
	        System.exit(0);
	    }

	    double a_mean_prev = x, a_mean_curr = 0;
	    double g_mean_prev = y, g_mean_curr = 0;

	    while( Math.abs(a_mean_prev - g_mean_prev) > TOLERANCE ) {
	        a_mean_curr = (a_mean_prev + g_mean_prev) / 2;
	        g_mean_curr = Math.sqrt(a_mean_prev * g_mean_prev);
	        a_mean_prev = a_mean_curr;
	        g_mean_prev = g_mean_curr;
	    }
	    System.out.printf("agm(%f, %f) = %.20f\n", x, y, a_mean_curr);



	}

}
