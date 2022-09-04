package unl.cse;

import java.util.HashMap;
import java.util.Map;

/**
 * TODO: add class documentation
 */
public class ProteinTranslator {

  /**
	 * Trigram DNA to protein map
	 */
	public static final Map<String, Character> proteinMap = new HashMap<>();

	static {

		proteinMap.put("AAA", 'K');
		proteinMap.put("AAC", 'N');
		proteinMap.put("AAG", 'K');
		proteinMap.put("AAU", 'N');
		proteinMap.put("ACA", 'T');
		proteinMap.put("ACC", 'T');
		proteinMap.put("ACG", 'T');
		proteinMap.put("ACU", 'T');
		proteinMap.put("AGA", 'R');
		proteinMap.put("AGC", 'S');
		proteinMap.put("AGG", 'R');
		proteinMap.put("AGU", 'S');
		proteinMap.put("AUA", 'I');
		proteinMap.put("AUC", 'I');
		proteinMap.put("AUG", 'M');
		proteinMap.put("AUU", 'I');
		proteinMap.put("CAA", 'Q');
		proteinMap.put("CAC", 'H');
		proteinMap.put("CAG", 'Q');
		proteinMap.put("CAU", 'H');
		proteinMap.put("CCA", 'P');
		proteinMap.put("CCC", 'P');
		proteinMap.put("CCG", 'P');
		proteinMap.put("CCU", 'P');
		proteinMap.put("CGA", 'R');
		proteinMap.put("CGC", 'R');
		proteinMap.put("CGG", 'R');
		proteinMap.put("CGU", 'R');
		proteinMap.put("CUA", 'L');
		proteinMap.put("CUC", 'L');
		proteinMap.put("CUG", 'L');
		proteinMap.put("CUU", 'L');
		proteinMap.put("GAA", 'E');
		proteinMap.put("GAC", 'D');
		proteinMap.put("GAG", 'E');
		proteinMap.put("GAU", 'D');
		proteinMap.put("GCA", 'A');
		proteinMap.put("GCC", 'A');
		proteinMap.put("GCG", 'A');
		proteinMap.put("GCU", 'A');
		proteinMap.put("GGA", 'G');
		proteinMap.put("GGC", 'G');
		proteinMap.put("GGG", 'G');
		proteinMap.put("GGU", 'G');
		proteinMap.put("GUA", 'V');
		proteinMap.put("GUC", 'V');
		proteinMap.put("GUG", 'V');
		proteinMap.put("GUU", 'V');
		proteinMap.put("UAA", 'x');
		proteinMap.put("UAC", 'Y');
		proteinMap.put("UAG", 'x');
		proteinMap.put("UAU", 'Y');
		proteinMap.put("UCA", 'S');
		proteinMap.put("UCC", 'S');
		proteinMap.put("UCG", 'S');
		proteinMap.put("UCU", 'S');
		proteinMap.put("UGA", 'x');
		proteinMap.put("UGC", 'C');
		proteinMap.put("UGG", 'W');
		proteinMap.put("UGU", 'C');
		proteinMap.put("UUA", 'L');
		proteinMap.put("UUC", 'F');
		proteinMap.put("UUG", 'L');
		proteinMap.put("UUU", 'F');
	}
	
	public static void main(String args[]) {
		//an example of how to use the map:
		String codon = "GGU";
		String protein = proteinMap.get(codon);
		System.out.println(codon + " translates to " + protein);
		
	}

}
