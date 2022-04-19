#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_valid(char dna[]);

void check_codons(char dna[]);

int main() {
	char dna[10000];

	printf("Enter the DNA sequecen: ");
	//read up to 9999 characters
	scanf("%9999s", dna);

	/*
	TODO: add your code here (or in the additional
	functions that are called from here).
	*/

	//Calls check_valid to check the initial sequence
	check_valid(dna);

	//Calls check_codons to see if the codons of Theronine were present
	check_codons(dna);

	return 0;
}


/*This functions checks whether the sequence is initally valid. If any lower cases or wrong capital letters were added to the string it would return -1. I decided to use pointers for this
because it would be easier to declare a pointer and compare it to the array that is prompted as "dna" in the main function. I had made a pointer for each base that could exist and made
them const char * baseNUMBER so that I can call the command strchr which compares the characters of the array to the bases. The rest is a basic while loop which allows us to continously
check the sequence while incrementing it by one base*/
void check_valid(char dna[]){
	const char * base1 = "A";
	const char * base2 = "T";
	const char * base3 = "G";
	const char * base4 = "C";
	char * sequence = dna;
	char * bases = sequence;
	while(*bases){
		if(strchr(base1, *bases) || strchr(base2, *bases) || strchr(base3, *bases) || strchr(base4, *bases));
		else {
			printf("%s", "-1\n");
			exit(1);
		}
		bases++;
	}
}

	/*similar to the previous function, check_valid, I made const char * codonNUMBER for each Theronine codon in order to compare the sequence to the array in main. Because I needed
	to retrieve the indexes of the codons I had to create a for loop inside of while loop which increments for every base and skips the next two once a codon is found. The if statements
	allowed me to use the command line strcmp to compare the string of codons to the array of characters. When all of this is run we are able to print out the indexes of where the codons
	were present.*/
void check_codons(char dna[]){
	int count = 0;
	int x;
	int length = strlen(dna);
	char codons[4];
	const char * codon1 = "ACT";
	const char * codon2 = "ACC";
	const char * codon3 = "ACA";
	const char * codon4 = "ACG";
	for(int i = 0; i < length; (i = i + 3)){
		x = 0;
		while (x < 3){
			codons[x] = dna[x + i];
			x++;
		}
		codons[3] = '\0';

		if(strcmp(codons, codon1) == 0){
			printf("%d\n", i);
			count++;
		}
		else if(strcmp(codons, codon2) == 0){
			printf("%d\n", i);
			count++;
		}
		else if(strcmp(codons, codon3) == 0){
			printf("%d\n", i);
			count++;
		}
		else if(strcmp(codons, codon4) == 0){
			printf("%d\n", i);
			count++;
		}
	}
	if (count == 0){
		printf("%d", -2);
		exit(1);
	}
}