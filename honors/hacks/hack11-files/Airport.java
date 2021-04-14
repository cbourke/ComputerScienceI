package unl.cse;

import java.util.List;

/**
 * TODO: documentation
 *
 */
public class Airport {

	//TODO: define your member variables and methods

  /**
	 * Required constructor
	 * TODO: add documentation, implement
	 */
	public Airport(String gpsId, String name, double latitude, double longitude, String type, int elevationFeet,
		 String city, String country) {
  }

	/**
	 * Computes the air distance, in kilometers, from <code>this<code>
	 * airport to the given <code>destination</code> using their latitude/longitude
	 * and the
	 * <a href="https://en.wikipedia.org/wiki/Spherical_law_of_cosines">Spherical
	 * Law of Cosines</a>.
	 */
	public double getAirDistance(Airport destination) {
		//TODO: implement
		return -1.0;
	}

	/**
	 * Computes the estimated travel time (in hours) for a flight that involves the
	 * given stops using the average flight speed (kilometers per hour) and average
	 * layover time (in hours)
	 */
	public static double getEstimatedTravelTime(List<Airport> stops, double aveKmsPerHour, double aveLayoverTimeHrs) {
		//TODO: implement
		return -1.0;
	}

}
