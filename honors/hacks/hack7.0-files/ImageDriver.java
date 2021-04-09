package unl.cse;

public class ImageDriver {

	public static void main(String args[]) {

		RGB original[][] = ImageUtils.loadImage("images/pointers.png");

		// TODO: perform any method calls here; example:
		RGB rotated[][] = ImageUtils.rotateClockwise(original);
		ImageUtils.saveImage("images/rotated.jpg", rotated);

	}
}
