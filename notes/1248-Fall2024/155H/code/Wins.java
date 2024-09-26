package unl.soc;

/**
 * TODO:
 */
public class Wins {

	public static final double EXPONENT = 2.37;

	public static void main(String args[]) {
		// TODO: basic error checking

		int pointsFor = Integer.parseInt(args[0]);
		int pointsAgainst = Integer.parseInt(args[1]);

		double winPercentage = Math.pow(pointsFor, EXPONENT)
				/ (Math.pow(pointsFor, EXPONENT) + Math.pow(pointsAgainst, EXPONENT));

		int wins = (int) Math.round(winPercentage * 12);
		int loss = 12 - wins;

		System.out.printf("Win Percentage: %f%%\n", winPercentage * 100);
		System.out.printf("Win/Loss: %d/%d\n", wins, loss);

		String format = """
				Win Percentage: %f%%
				Win/Loss: %d/%d
				""";
		System.out.printf(format, winPercentage * 100, wins, loss);

	}

}
