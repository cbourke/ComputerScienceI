package unl.cse;

/**
 * An RGB (Red-Green-Blue) color object.  
 *
 */
public class RGB {

	private int red;
	private int green;
	private int blue;
	
	public RGB(int red, int green, int blue) {
		this.red = red;
		this.green = green;
		this.blue = blue;
	}

	public int getRed() {
		return red;
	}

	public int getGreen() {
		return green;
	}

	public int getBlue() {
		return blue;
	}
	
	public String toString() {
		return "(" + this.red + ", " + this.green + ", " + this.blue + ")";
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + blue;
		result = prime * result + green;
		result = prime * result + red;
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
		RGB other = (RGB) obj;
		if (blue != other.blue)
			return false;
		if (green != other.green)
			return false;
		if (red != other.red)
			return false;
		return true;
	}
	
	public static void main(String args[]) {
		//create a new color object:
		RGB myColor = new RGB(100, 125, 25);
		RGB red = new RGB(255, 0, 0);
		
		// you can get the individual red, green and blue values
		// using the .get methods:
		System.out.println("red   = " + myColor.getRed());
		System.out.println("green = " + myColor.getGreen());
		System.out.println("blue  = " + myColor.getBlue());
	}
	
}
