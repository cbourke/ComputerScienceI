#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the ProteinMap struct
typedef struct {
    char trigram[4];
    char protein;
} ProteinMap;

// Define the array of ProteinMap entries
ProteinMap pMap[] = {
    { "UUU", 'F' },
    { "UUC", 'F' },
    // Add more entries as needed
};

// Function to compare ProteinMap entries for binary search
int proteinMapComp(const void *a, const void *b) {
    const ProteinMap *x = (const ProteinMap *)a;
    const ProteinMap *y = (const ProteinMap *)b;
    return strcmp(x->trigram, y->trigram);
}

// Function to convert RNA trigram to protein
char rnaToProtein(const char *rna) {
    if (rna == NULL || strlen(rna) != 3) {
        return 0;
    }
    ProteinMap key = { "", '\0' };
    strcpy(key.trigram, rna);
    ProteinMap *match = bsearch(&key, pMap, sizeof(pMap) / sizeof(ProteinMap), sizeof(ProteinMap), proteinMapComp);
    return (match == NULL) ? 0 : match->protein;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s RNATrigram\n", argv[0]);
        exit(1);
    }

    char prot = rnaToProtein(argv[1]);

    if (prot == '\0') {
        printf("\"%s\" is an invalid RNA trigram\n", argv[1]);
    } else {
        printf("%s -> %c\n", argv[1], prot);
    }

    return 0;
}





  
