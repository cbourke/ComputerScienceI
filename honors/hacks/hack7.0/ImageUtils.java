package unl.cse;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

/**
 * This is a collection of utility methods for manipulating images in a variety
 * of formats (jpg, bmp, gif, png, etc.).
 * 
 * For the purposes of these utilities, images are represented by a
 * 2-dimensional array of {@link RGB} elements (pixels).
 * 
 * The dimensions are assumed to be height x width (h x w). The first dimension
 * is considered to be the height (number of rows of pixels) and the second is
 * considered to be the width (number of columns of pixels). It is assumed that
 * all rows and all columns are uniform in their length.
 *
 */
public class ImageUtils {

	/**
	 * Loads an image from the file specified by the given <code>filePath</code>.
	 * 
	 * @param filePath
	 * @return
	 */
	public static RGB[][] loadImage(String filePath) {
		File file = new File(filePath);
		BufferedImage img = null;
		try {
			img = ImageIO.read(file);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		RGB pixels[][] = new RGB[img.getHeight()][img.getWidth()];
		for (int y = 0; y < img.getHeight(); y++) {
			for (int x = 0; x < img.getWidth(); x++) {
				int p = img.getRGB(x, y);
				int r = (p >> 16) & 0xff;
				int g = (p >> 8) & 0xff;
				int b = p & 0xff;
				pixels[y][x] = new RGB(r, g, b);
			}
		}
		return pixels;
	}

	/**
	 * Saves the given image to the file specified by the given
	 * <code>filePath</code>
	 * 
	 * @param filePath
	 * @param image
	 */
	public static void saveImage(String filePath, RGB image[][]) {
		String extension = filePath.substring(filePath.lastIndexOf(".") + 1);
		BufferedImage newImg = new BufferedImage(image[0].length, image.length, BufferedImage.TYPE_INT_RGB);
		for (int y = 0; y < newImg.getHeight(); y++) {
			for (int x = 0; x < newImg.getWidth(); x++) {
				int p = (image[y][x].getRed() << 16) + (image[y][x].getGreen() << 8) + image[y][x].getBlue();
				newImg.setRGB(x, y, p);
			}
		}

		File f = new File(filePath);
		try {
			ImageIO.write(newImg, extension, f);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

	/**
	 * TODO: add documentation
	 */
	public static RGB[][] copyImage(RGB image[][]) {
		// TODO: implement; we only return null so it will compile
		return null;
	}

	/**
	 * TODO: add documentation
	 */
	public static void flipHorizontal(RGB image[][]) {
		// TODO: implement
	}

	/**
	 * TODO: add documentation
	 */
	public static void flipVertical(RGB image[][]) {
		// TODO: implement
	}

	/**
	 * TODO: add documentation
	 */
	public static RGB[][] rotateClockwise(RGB image[][]) {
		// TODO: implement; we only return null so it will compile
		return null;
	}

}
