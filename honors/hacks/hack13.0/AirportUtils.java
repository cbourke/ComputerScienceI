package unl.soc;

import java.util.Comparator;
import java.util.List;

/**
 * TODO: documentation
 *
 */
public class AirportUtils {

	/**
	 * A comparator function that orders the two Airport structures by their GPS IDs
	 * in lexicographic order.
	 */
	public static final Comparator<Airport> CMP_GPS_ID = new Comparator<>() {
		@Override
		public int compare(Airport a1, Airport a2) {
			// TODO: modify this if necessary
			return a1.getGpsId().compareTo(a2.getGpsId());
		}
	};

	/**
	 * A comparator function that orders the two Airport structures by their type.
	 */
	//TODO: implement
	public static final Comparator<Airport> CMP_TYPE = null;

	/**
	 * A comparator function that orders the two Airport structures by their name in
	 * lexicographic order.
	 */
	//TODO: implement
	public static final Comparator<Airport> CMP_NAME = null;

	/**
	 * A comparator function that orders the two Airport structures by their name in
	 * reverse lexicographic order.
	 */
	//TODO: implement
	public static final Comparator<Airport> CMP_NAME_DESC = null;

	/**
	 * A comparator function that orders the two Airport structures first by
	 * country, then by city
	 */
	//TODO: implement
	public static final Comparator<Airport> CMP_COUNTRY_CITY = null;

	/**
	 * A comparator function that orders the given Airport structures by their
	 * latitudes north to south
	 */
	//TODO: implement
	public static final Comparator<Airport> CMP_LATITUDE = null;

	/**
	 * A comparator function that orders the given Airport structures by their
	 * longitudes west to east
	 */
	//TODO: implement
	public static final Comparator<Airport> CMP_LONGITUDE = null;

	/**
	 * A comparator function that orders the two Airport structures by their
	 * relative distance from Lincoln Municipal Airport (0R2, 40.846176, -96.75471)
	 * in ascending order according (closest to Lincoln would come first)
	 */
	//TODO: implement
	public static final Comparator<Airport> CMP_LINCOLN_DISTANCE = null;

	/**
	 * A function that generates and prints several reports on the given list of
	 * Airports.
	 */
	public static void generateReports(List<Airport> airports) {

		  //TODO: implement

		  System.out.printf("Airports (original): \n");
		  System.out.printf("==============================\n");
			//TODO: print the airports

		  System.out.printf("\nAirports By GPS ID: \n");
		  System.out.printf("==============================\n");

		  System.out.printf("\nAirports By Type: \n");
		  System.out.printf("==============================\n");

		  System.out.printf("\nAirports By Name: \n");
		  System.out.printf("==============================\n");

		  System.out.printf("\nAirports By Name - Reversed: \n");
		  System.out.printf("==============================\n");

		  System.out.printf("\nAirports By Country/City: \n");
		  System.out.printf("==============================\n");

		  System.out.printf("\nAirports By Latitude: \n");
		  System.out.printf("==============================\n");

		  System.out.printf("\nAirports By Longitude: \n");
		  System.out.printf("==============================\n");

		  System.out.printf("\nAirports By Distance from Lincoln: \n");
		  System.out.printf("==============================\n");

		  System.out.printf("\nClosest Airport to Lincoln: \n");
		  System.out.printf("==============================\n");

		  System.out.printf("\nFurthest Airport from Lincoln: \n");
		  System.out.printf("==============================\n");

		  System.out.printf("\nEast-West Geographic Center: \n");
		  System.out.printf("==============================\n");

		  System.out.printf("\nNew York, NY airport: \n");
		  System.out.printf("==============================\n");
		  //if none found, print: "No New York airport found!\n"

		  System.out.printf("\nLarge airport: \n");
		  System.out.printf("==============================\n");
		  //if none found, print: "No large airport found!\n"

	}

}
