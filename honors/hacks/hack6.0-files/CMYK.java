package unl.cse;

/**
 * A CMYK (Cyan-Magenta-Yellow-Black) color object.
 *
 */
public class CMYK {

	private double cyan;
	private double magenta;
	private double yellow;
	private double k;

	public CMYK(double cyan, double magenta, double yellow, double k) {
		this.cyan = cyan;
		this.magenta = magenta;
		this.yellow = yellow;
		this.k = k;
	}
	
	public double getCyan() {
		return cyan;
	}
	
	public double getMagenta() {
		return magenta;
	}
	
	public double getYellow() {
		return yellow;
	}
	
	public double getK() {
		return k;
	}
	
	public String toString() {
		return "(" + this.cyan + ", " + this.magenta + ", " + this.yellow + ", " + k + ")";
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		long temp;
		temp = Double.doubleToLongBits(cyan);
		result = prime * result + (int) (temp ^ (temp >>> 32));
		temp = Double.doubleToLongBits(k);
		result = prime * result + (int) (temp ^ (temp >>> 32));
		temp = Double.doubleToLongBits(magenta);
		result = prime * result + (int) (temp ^ (temp >>> 32));
		temp = Double.doubleToLongBits(yellow);
		result = prime * result + (int) (temp ^ (temp >>> 32));
		return result;
	}
	
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		CMYK other = (CMYK) obj;
		if (Double.doubleToLongBits(cyan) != Double
				.doubleToLongBits(other.cyan))
			return false;
		if (Double.doubleToLongBits(k) != Double.doubleToLongBits(other.k))
			return false;
		if (Double.doubleToLongBits(magenta) != Double
				.doubleToLongBits(other.magenta))
			return false;
		if (Double.doubleToLongBits(yellow) != Double
				.doubleToLongBits(other.yellow))
			return false;
		return true;
	}
	
	public static void main(String args[]) {
		//create a new color object:
		CMYK myColor = new CMYK(.25, .75, .50, 0.0);
		CMYK red = new CMYK(0.0, .99, 1.0, 0.0);
		
		// you can get the red, green and blue values:
		System.out.println("cyan    = " + myColor.getCyan());
		System.out.println("magenta = " + myColor.getMagenta());
		System.out.println("yellow  = " + myColor.getYellow());
		System.out.println("k       = " + myColor.getK());
	}
	
}

