package unl.soc;

public class Cheer {

	public static void main(String args[]) {

		if (args.length != 3) {
			System.err.println("ERROR: provide a b n");
			System.exit(1);
		}

		int a = Integer.parseInt(args[0]);
		int b = Integer.parseInt(args[1]);
		int n = Integer.parseInt(args[2]);

		if (a < 2 || b < 2 || n <= 0) {
			System.err.println("ERROR: provide valid inputs");
			System.exit(2);
		}

		for (int i = 1; i <= n; i++) {
			if (i % (a * b) == 0) {
				System.out.println("Go Nebraska!");
			} else if (i % a == 0) {
				System.out.println("Go Huskers!");
			} else if (i % b == 0) {
				System.out.println("Go Mavs!");
			} else {
				System.out.println(i);

			}
		}

	}

}
