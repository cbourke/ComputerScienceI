package unl.cse;

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
	}

}
