package unl.cse;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.RepeatedTest;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;
import static org.junit.jupiter.api.Assertions.assertThrows;

import java.util.Random;

/**
 * A JUnit test suite of test cases for the {@link TruckList} linked list
 * implementation.
 *
 */
public class ColorUtilsTests {

	private final static Random r = new Random();

	/**
	 * Tolerance for CMYK values
	 */
	public static final double EPSILON = 0.01;


	/**
	 * Tests both {@link ColorUtils#cmykToRGB(CMYK)} and
	 * {@link ColorUtils#rgbToCMYK(RGB)} methods by randomly generating an RGB
	 * value, converting it to CMYK and then back again to ensure that it is (close
	 * to) the original value.
	 * 
	 * A tolerance of 1 is applied to account for rounding discrepancies.
	 * 
	 */
	@RepeatedTest(100)
	public void cyclicTest() {
		RGB originalRgb = new RGB(r.nextInt(256), r.nextInt(256), r.nextInt(256));
		CMYK cmyk = ColorUtils.rgbToCMYK(originalRgb);
		RGB computedRgb = ColorUtils.cmykToRGB(cmyk);

		assertTrue(originalRgb.getRed() == computedRgb.getRed() || 
				   originalRgb.getRed() == computedRgb.getRed() - 1,
				   "Red value is not as expected.");
		assertTrue(originalRgb.getGreen() == computedRgb.getGreen() || 
				   originalRgb.getGreen() == computedRgb.getGreen() - 1,
				   "Green value is not as expected.");
		assertTrue(originalRgb.getBlue() == computedRgb.getBlue() || 
				   originalRgb.getBlue() == computedRgb.getBlue() - 1,
				   "Blue value is not as expected.");

	}

	/**
	 * Tests that both {@link ColorUtils#cmykToRGB(CMYK)} and
	 * {@link ColorUtils#rgbToCMYK(RGB)} properly throw an {@link IllegalArgumentException}
	 * if given a <code>null</code> input.
	 * 
	 */
	@Test
	public void nullTests() {
		assertThrows(IllegalArgumentException.class, () -> {
			ColorUtils.rgbToCMYK(null);
		});
		assertThrows(IllegalArgumentException.class, () -> {
			ColorUtils.cmykToRGB(null);
		});
	}
	
	/**
	 * Tests that both {@link ColorUtils#cmykToRGB(CMYK)} and
	 * {@link ColorUtils#rgbToCMYK(RGB)} properly throw an {@link IllegalArgumentException}
	 * if given <code>RGB</code>/<code>CMYK</code> instances with
	 * values outside the defined range of [0, 255] and [0, 1] respectively.
	 * 
	 */
	@Test
	public void boundsTests() {
		assertThrows(IllegalArgumentException.class, () -> {
			ColorUtils.rgbToCMYK(new RGB(-1, 127, 127));
		});
		assertThrows(IllegalArgumentException.class, () -> {
			ColorUtils.rgbToCMYK(new RGB(127, -1, 127));
		});
		assertThrows(IllegalArgumentException.class, () -> {
			ColorUtils.rgbToCMYK(new RGB(127, 127, -1));
		});
		assertThrows(IllegalArgumentException.class, () -> {
			ColorUtils.rgbToCMYK(new RGB(256, 127, 127));
		});
		assertThrows(IllegalArgumentException.class, () -> {
			ColorUtils.rgbToCMYK(new RGB(127, 256, 127));
		});
		assertThrows(IllegalArgumentException.class, () -> {
			ColorUtils.rgbToCMYK(new RGB(127, 127, 256));
		});
		
		assertThrows(IllegalArgumentException.class, () -> {
			ColorUtils.cmykToRGB(new CMYK(-1, .5, .5, .5));
		});
		
		assertThrows(IllegalArgumentException.class, () -> {
			ColorUtils.cmykToRGB(new CMYK(.5, -1, .5, .5));
		});

		assertThrows(IllegalArgumentException.class, () -> {
			ColorUtils.cmykToRGB(new CMYK(.5, .5, -1, .5));
		});

		assertThrows(IllegalArgumentException.class, () -> {
			ColorUtils.cmykToRGB(new CMYK(.5, .5, .5, -1));
		});
		
		assertThrows(IllegalArgumentException.class, () -> {
			ColorUtils.cmykToRGB(new CMYK(2, .5, .5, .5));
		});
		
		assertThrows(IllegalArgumentException.class, () -> {
			ColorUtils.cmykToRGB(new CMYK(.5, 2, .5, .5));
		});

		assertThrows(IllegalArgumentException.class, () -> {
			ColorUtils.cmykToRGB(new CMYK(.5, .5, 2, .5));
		});

		assertThrows(IllegalArgumentException.class, () -> {
			ColorUtils.cmykToRGB(new CMYK(.5, .5, .5, 2));
		});
	}
	
	/**
	 * Tests both {@link ColorUtils#cmykToRGB(CMYK)} and
	 * {@link ColorUtils#rgbToCMYK(RGB)} methods using the color, "aquamarine" with
	 * rgb = (128, 255, 212) cmyk = (0.5, 0, 0.17, 0)
	 */
	@Test
	public void testAquamarine() {
		RGB rgbExpected = new RGB(128, 255, 212);
		CMYK cmykExpected = new CMYK(0.5, 0, 0.17, 0);

		RGB rgbResult = ColorUtils.cmykToRGB(cmykExpected);
		CMYK cmykResult = ColorUtils.rgbToCMYK(rgbExpected);

		assertEquals(rgbExpected, rgbResult, "RGB values do not match");
		assertEquals(cmykExpected.getCyan(), cmykResult.getCyan(), EPSILON, "Cyan values are not close enough");
		assertEquals(cmykExpected.getMagenta(), cmykResult.getMagenta(), EPSILON,
				"Magenta values are not close enough");
		assertEquals(cmykExpected.getYellow(), cmykResult.getYellow(), EPSILON, "Yellow values are not close enough");
		assertEquals(cmykExpected.getK(), cmykResult.getK(), EPSILON, "K values are not close enough");
	}

	/**
	 * Tests both {@link ColorUtils#cmykToRGB(CMYK)} and
	 * {@link ColorUtils#rgbToCMYK(RGB)} methods using the color, "salmon" with rgb
	 * = (250, 127, 115) cmyk = (0.0, 0.49, 0.54, 0.02)
	 */
	@Test
	public void testSalmon() {
		RGB rgbExpected = new RGB(250, 127, 115);
		CMYK cmykExpected = new CMYK(0.0, 0.49, 0.54, 0.02);

		RGB rgbResult = ColorUtils.cmykToRGB(cmykExpected);
		CMYK cmykResult = ColorUtils.rgbToCMYK(rgbExpected);

		assertEquals(rgbExpected, rgbResult, "RGB values do not match");
		assertEquals(cmykExpected.getCyan(), cmykResult.getCyan(), EPSILON, "Cyan values are not close enough");
		assertEquals(cmykExpected.getMagenta(), cmykResult.getMagenta(), EPSILON,
				"Magenta values are not close enough");
		assertEquals(cmykExpected.getYellow(), cmykResult.getYellow(), EPSILON, "Yellow values are not close enough");
		assertEquals(cmykExpected.getK(), cmykResult.getK(), EPSILON, "K values are not close enough");
	}

	/**
	 * Tests both {@link ColorUtils#cmykToRGB(CMYK)} and
	 * {@link ColorUtils#rgbToCMYK(RGB)} methods using the color, "husker red" with
	 * rgb = (209, 0, 0) cmyk = (0.0, 1, 1, 0.18)
	 */
	@Test
	public void testHuskerRed() {
		RGB rgbExpected = new RGB(209, 0, 0);
		CMYK cmykExpected = new CMYK(0.0, 1, 1, 0.18);

		RGB rgbResult = ColorUtils.cmykToRGB(cmykExpected);
		CMYK cmykResult = ColorUtils.rgbToCMYK(rgbExpected);

		assertEquals(rgbExpected, rgbResult, "RGB values do not match");
		assertEquals(cmykExpected.getCyan(), cmykResult.getCyan(), EPSILON, "Cyan values are not close enough");
		assertEquals(cmykExpected.getMagenta(), cmykResult.getMagenta(), EPSILON,
				"Magenta values are not close enough");
		assertEquals(cmykExpected.getYellow(), cmykResult.getYellow(), EPSILON, "Yellow values are not close enough");
		assertEquals(cmykExpected.getK(), cmykResult.getK(), EPSILON, "K values are not close enough");
	}

	/**
	 * Tests both {@link ColorUtils#cmykToRGB(CMYK)} and
	 * {@link ColorUtils#rgbToCMYK(RGB)} methods using the color, "cycle blue" with
	 * rgb = (40, 159, 209) cmyk = (0.81, 0.24, 0, 0.18)
	 */
	@Test
	public void testCycleBlue() {
		RGB rgbExpected = new RGB(40, 159, 209);
		CMYK cmykExpected = new CMYK(0.81, 0.24, 0, 0.18);

		RGB rgbResult = ColorUtils.cmykToRGB(cmykExpected);
		CMYK cmykResult = ColorUtils.rgbToCMYK(rgbExpected);

		assertEquals(rgbExpected, rgbResult, "RGB values do not match");
		assertEquals(cmykExpected.getCyan(), cmykResult.getCyan(), EPSILON, "Cyan values are not close enough");
		assertEquals(cmykExpected.getMagenta(), cmykResult.getMagenta(), EPSILON,
				"Magenta values are not close enough");
		assertEquals(cmykExpected.getYellow(), cmykResult.getYellow(), EPSILON, "Yellow values are not close enough");
		assertEquals(cmykExpected.getK(), cmykResult.getK(), EPSILON, "K values are not close enough");
	}

	/**
	 * Tests both {@link ColorUtils#cmykToRGB(CMYK)} and
	 * {@link ColorUtils#rgbToCMYK(RGB)} methods using the color, "orange" with rgb
	 * = (255, 158, 33) cmyk = (0, 0.38, 0.87, 0)
	 */
	@Test
	public void testOrange() {
		RGB rgbExpected = new RGB(255, 158, 33);
		CMYK cmykExpected = new CMYK(0, 0.38, 0.87, 0);

		RGB rgbResult = ColorUtils.cmykToRGB(cmykExpected);
		CMYK cmykResult = ColorUtils.rgbToCMYK(rgbExpected);

		assertEquals(rgbExpected, rgbResult, "RGB values do not match");
		assertEquals(cmykExpected.getCyan(), cmykResult.getCyan(), EPSILON, "Cyan values are not close enough");
		assertEquals(cmykExpected.getMagenta(), cmykResult.getMagenta(), EPSILON,
				"Magenta values are not close enough");
		assertEquals(cmykExpected.getYellow(), cmykResult.getYellow(), EPSILON, "Yellow values are not close enough");
		assertEquals(cmykExpected.getK(), cmykResult.getK(), EPSILON, "K values are not close enough");
	}

	/**
	 * Tests both {@link ColorUtils#cmykToRGB(CMYK)} and
	 * {@link ColorUtils#rgbToCMYK(RGB)} methods using the color, "Facebook blue"
	 * with rgb = (60, 90, 153) cmyk = (0.61, 0.41, 0, 0.4)
	 */
	@Test
	public void testFacebookBlue() {
		RGB rgbExpected = new RGB(60, 90, 153);
		CMYK cmykExpected = new CMYK(0.61, 0.41, 0, 0.4);

		RGB rgbResult = ColorUtils.cmykToRGB(cmykExpected);
		CMYK cmykResult = ColorUtils.rgbToCMYK(rgbExpected);

		assertEquals(rgbExpected, rgbResult, "RGB values do not match");
		assertEquals(cmykExpected.getCyan(), cmykResult.getCyan(), EPSILON, "Cyan values are not close enough");
		assertEquals(cmykExpected.getMagenta(), cmykResult.getMagenta(), EPSILON,
				"Magenta values are not close enough");
		assertEquals(cmykExpected.getYellow(), cmykResult.getYellow(), EPSILON, "Yellow values are not close enough");
		assertEquals(cmykExpected.getK(), cmykResult.getK(), EPSILON, "K values are not close enough");
	}

	/**
	 * Tests both {@link ColorUtils#cmykToRGB(CMYK)} and
	 * {@link ColorUtils#rgbToCMYK(RGB)} methods using the color, "Twitter blue"
	 * with rgb = (56, 160, 242) cmyk = (0.77, 0.34, 0, 0.05)
	 */
	@Test
	public void testTwitterBlue() {
		RGB rgbExpected = new RGB(56, 160, 242);
		CMYK cmykExpected = new CMYK(0.77, 0.34, 0, 0.05);

		RGB rgbResult = ColorUtils.cmykToRGB(cmykExpected);
		CMYK cmykResult = ColorUtils.rgbToCMYK(rgbExpected);

		assertEquals(rgbExpected, rgbResult, "RGB values do not match");
		assertEquals(cmykExpected.getCyan(), cmykResult.getCyan(), EPSILON, "Cyan values are not close enough");
		assertEquals(cmykExpected.getMagenta(), cmykResult.getMagenta(), EPSILON,
				"Magenta values are not close enough");
		assertEquals(cmykExpected.getYellow(), cmykResult.getYellow(), EPSILON, "Yellow values are not close enough");
		assertEquals(cmykExpected.getK(), cmykResult.getK(), EPSILON, "K values are not close enough");
	}

	/**
	 * Tests both {@link ColorUtils#cmykToRGB(CMYK)} and
	 * {@link ColorUtils#rgbToCMYK(RGB)} methods using the color, "Instagram pink"
	 * with rgb = (194, 43, 163) cmyk = (0, 0.78, 0.16, 0.24)
	 */
	@Test
	public void testInstagramPink() {
		RGB rgbExpected = new RGB(194, 43, 163);
		CMYK cmykExpected = new CMYK(0, 0.78, 0.16, 0.24);

		RGB rgbResult = ColorUtils.cmykToRGB(cmykExpected);
		CMYK cmykResult = ColorUtils.rgbToCMYK(rgbExpected);

		assertEquals(rgbExpected, rgbResult, "RGB values do not match");
		assertEquals(cmykExpected.getCyan(), cmykResult.getCyan(), EPSILON, "Cyan values are not close enough");
		assertEquals(cmykExpected.getMagenta(), cmykResult.getMagenta(), EPSILON,
				"Magenta values are not close enough");
		assertEquals(cmykExpected.getYellow(), cmykResult.getYellow(), EPSILON, "Yellow values are not close enough");
		assertEquals(cmykExpected.getK(), cmykResult.getK(), EPSILON, "K values are not close enough");
	}

	/**
	 * Tests both {@link ColorUtils#cmykToRGB(CMYK)} and
	 * {@link ColorUtils#rgbToCMYK(RGB)} methods using the color, "Powerpoint
	 * Orange" with rgb = (209, 69, 36) cmyk = (0, 0.67, 0.83, 0.18)
	 */
	@Test
	public void testPowerpointOrange() {
		RGB rgbExpected = new RGB(209, 69, 36);
		CMYK cmykExpected = new CMYK(0, 0.67, 0.83, 0.18);

		RGB rgbResult = ColorUtils.cmykToRGB(cmykExpected);
		CMYK cmykResult = ColorUtils.rgbToCMYK(rgbExpected);

		assertEquals(rgbExpected, rgbResult, "RGB values do not match");
		assertEquals(cmykExpected.getCyan(), cmykResult.getCyan(), EPSILON, "Cyan values are not close enough");
		assertEquals(cmykExpected.getMagenta(), cmykResult.getMagenta(), EPSILON,
				"Magenta values are not close enough");
		assertEquals(cmykExpected.getYellow(), cmykResult.getYellow(), EPSILON, "Yellow values are not close enough");
		assertEquals(cmykExpected.getK(), cmykResult.getK(), EPSILON, "K values are not close enough");
	}

	/**
	 * Tests both {@link ColorUtils#cmykToRGB(CMYK)} and
	 * {@link ColorUtils#rgbToCMYK(RGB)} methods using the color, "Spotify Green"
	 * with rgb = (30, 214, 96) cmyk = (0.86, 0, 0.55, 0.16)
	 */
	@Test
	public void testSpotifyGreen() {
		RGB rgbExpected = new RGB(30, 214, 96);
		CMYK cmykExpected = new CMYK(0.86, 0, 0.55, 0.16);

		RGB rgbResult = ColorUtils.cmykToRGB(cmykExpected);
		CMYK cmykResult = ColorUtils.rgbToCMYK(rgbExpected);

		assertEquals(rgbExpected, rgbResult, "RGB values do not match");
		assertEquals(cmykExpected.getCyan(), cmykResult.getCyan(), EPSILON, "Cyan values are not close enough");
		assertEquals(cmykExpected.getMagenta(), cmykResult.getMagenta(), EPSILON,
				"Magenta values are not close enough");
		assertEquals(cmykExpected.getYellow(), cmykResult.getYellow(), EPSILON, "Yellow values are not close enough");
		assertEquals(cmykExpected.getK(), cmykResult.getK(), EPSILON, "K values are not close enough");
	}

	/**
	 * Tests both {@link ColorUtils#cmykToRGB(CMYK)} and
	 * {@link ColorUtils#rgbToCMYK(RGB)} methods using the color, "white" with rgb =
	 * (255, 255, 255) cmyk = (0, 0, 0, 0)
	 */
	@Test
	public void testWhite() {
		RGB rgbExpected = new RGB(255, 255, 255);
		CMYK cmykExpected = new CMYK(0, 0, 0, 0);

		RGB rgbResult = ColorUtils.cmykToRGB(cmykExpected);
		CMYK cmykResult = ColorUtils.rgbToCMYK(rgbExpected);

		assertEquals(rgbExpected, rgbResult, "RGB values do not match");
		assertEquals(cmykExpected.getCyan(), cmykResult.getCyan(), EPSILON, "Cyan values are not close enough");
		assertEquals(cmykExpected.getMagenta(), cmykResult.getMagenta(), EPSILON,
				"Magenta values are not close enough");
		assertEquals(cmykExpected.getYellow(), cmykResult.getYellow(), EPSILON, "Yellow values are not close enough");
		assertEquals(cmykExpected.getK(), cmykResult.getK(), EPSILON, "K values are not close enough");
	}

	/**
	 * Tests both {@link ColorUtils#cmykToRGB(CMYK)} and
	 * {@link ColorUtils#rgbToCMYK(RGB)} methods using the color, "black" with rgb =
	 * (0, 0, 0) cmyk = (0, 0, 0, 1)
	 */
	@Test
	public void testBlack() {
		RGB rgbExpected = new RGB(0, 0, 0);
		CMYK cmykExpected = new CMYK(0, 0, 0, 1);

		RGB rgbResult = ColorUtils.cmykToRGB(cmykExpected);
		CMYK cmykResult = ColorUtils.rgbToCMYK(rgbExpected);

		assertEquals(rgbExpected, rgbResult, "RGB values do not match");
		assertEquals(cmykExpected.getCyan(), cmykResult.getCyan(), EPSILON, "Cyan values are not close enough");
		assertEquals(cmykExpected.getMagenta(), cmykResult.getMagenta(), EPSILON,
				"Magenta values are not close enough");
		assertEquals(cmykExpected.getYellow(), cmykResult.getYellow(), EPSILON, "Yellow values are not close enough");
		assertEquals(cmykExpected.getK(), cmykResult.getK(), EPSILON, "K values are not close enough");
	}


	//TODO: add your own annotated test cases using the above as examples


}
