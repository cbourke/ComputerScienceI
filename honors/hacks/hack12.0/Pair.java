package unl.cse;

import java.util.Comparator;

/**
 * The Pair<X,Y> class is a generic class which wraps 2 object instances (of
 * types X and Y) in a single object. Either or both of the values contained in
 * the Pair can be NULL (the hashCode() of a Pair containing two NULL values is
 * 0, as is the case with other classes in the JDK).
 *
 * @param <X>
 * @param <Y>
 */
public class Pair<X, Y> {
	protected final X first;
	protected final Y second;

	public static <A, B> Comparator<Pair<A, B>> orderByFirst(final Comparator<A> firstComp,
			final Comparator<B> secondComp) {
		return new Comparator<Pair<A, B>>() {
			public int compare(Pair<A, B> p1, Pair<A, B> p2) {
				int result = firstComp.compare(p1.getFirst(), p2.getFirst());
				if (result == 0) {
					result = secondComp.compare(p1.getSecond(), p2.getSecond());
				}
				return result;
			}
		};
	}

	public static <A extends Comparable<A>, B extends Comparable<B>> Comparator<Pair<A, B>> orderByFirst() {
		return new Comparator<Pair<A, B>>() {
			public int compare(Pair<A, B> p1, Pair<A, B> p2) {
				int result = p1.getFirst().compareTo(p2.getFirst());
				if (result == 0) {
					result = p1.getSecond().compareTo(p2.getSecond());
				}
				return result;
			}
		};
	}

	public static <A, B> Comparator<Pair<A, B>> orderBySecond(final Comparator<A> firstComp,
			final Comparator<B> secondComp) {
		return new Comparator<Pair<A, B>>() {
			public int compare(Pair<A, B> p1, Pair<A, B> p2) {
				int result = secondComp.compare(p1.getSecond(), p2.getSecond());
				if (result == 0) {
					result = firstComp.compare(p1.getFirst(), p2.getFirst());
				}
				return result;
			}
		};
	}

	public static <A extends Comparable<A>, B extends Comparable<B>> Comparator<Pair<A, B>> orderBySecond() {
		return new Comparator<Pair<A, B>>() {
			public int compare(Pair<A, B> p1, Pair<A, B> p2) {
				int result = p1.getSecond().compareTo(p2.getSecond());
				if (result == 0) {
					result = p1.getFirst().compareTo(p2.getFirst());
				}
				return result;
			}
		};
	}

	public static <A, B> Pair<A, B> make(A a, B b) {
		return new Pair<A, B>(a, b);
	}

	public Pair(X first, Y second) {
		this.first = first;
		this.second = second;
	}

	public X getFirst() {
		return first;
	}

	public Y getSecond() {
		return second;
	}

	public Pair<Y, X> reverse() {
		return Pair.make(second, first);
	}

	@Override
	public int hashCode() {
		int firstHash = first == null ? 0 : first.hashCode();
		int secondHash = second == null ? 0 : second.hashCode();
		return firstHash * 31 + secondHash;
	}

	@Override
	public String toString() {
		return new StringBuffer().append('<').append(first).append(',').append(second).append('>').toString();
	}

	@SuppressWarnings("unchecked")
	@Override
	public boolean equals(Object o) {
		// if the references point to the same object (same memory location), return
		// true
		if (this == o)
			return true;

		// if the parameter is null, return false
		if (o == null)
			return false;

		// if the parameter is not of the same type, return false
		if (!(this.getClass().equals(o.getClass())))
			return false;

		// return true iff the first and second values are equal to those of the
		// parameter
		// (nulls are valid and explicitly checked for)
		Pair<X, Y> p = (Pair<X, Y>) o;
		boolean firstsEqual = this.first == null ? p.first == null : this.first.equals(p.first);
		boolean secondsEqual = this.second == null ? p.second == null : this.second.equals(p.second);

		return firstsEqual && secondsEqual;
	}

}