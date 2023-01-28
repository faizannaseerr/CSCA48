////////////////////////////////////////////////////////////
// CSC A48 - DNA alignment Pt. 1
//
// The goal of this assignment is to write a function that
// translates tripled (sets of 3) DNA nucleotide bases to
// the corresponding aminoacid.
//
// As a brief review of your Biology lessons, DNA is a double
// stranded chain of nucleic-acids, there are 4 types of
// nucleotides denoted by the letters:
//
// A, C, T, G
//
// The sequence of these nucleotides specifies the sequence
// in which aminoacids (the building blocks of proteins)
// are assembled into every single one of the proteins that
// make up the cells of most licing things (there are a 
// few that do not use DNA, opting instead to use the single
// stranded version called RNA, viruses tend to be sneaky
// that way!)
//
// Each set of 3 nucleotides specifies one aminoacid in
// a protein's specification.
//
// The goal of this exercise is for you to write a small
// function that takes in a DNA sequence (a string made up
// of letters ATCG in some sequence) and determines the
// corresponding sequence of aminoacids. Below, you will
// find a table listing each aminoacid, and the sequences
// of DNA nucleotides that specify that aminoacid.
// 
// Note that many aminoacids can be specified by more than
// one triplet!
//
//  Aminoacid   Single letter name	Triplets
//  Isoleucine 		I 		ATT, ATC, ATA
//  Leucine 		L 		CTT, CTC, CTA, CTG, TTA, TTG
//  Valine 		V 		GTT, GTC, GTA, GTG
//  Phenylalanine 	F 		TTT, TTC
//  Methionine 		M 		ATG
//  Cysteine 		C 		TGT, TGC
//  Alanine 		A 		GCT, GCC, GCA, GCG
//  Glycine 		G 		GGT, GGC, GGA, GGG
//  Proline 		P 		CCT, CCC, CCA, CCG
//  Threonine 		T		ACT, ACC, ACA, ACG
//  Serine 		S 		TCT, TCC, TCA, TCG, AGT, AGC
//  Tyrosine 		Y 		TAT, TAC
//  Tryptophan 		W 		TGG
//  Glutamine 		Q 		CAA, CAG
//  Asparagine 		N 		AAT, AAC
//  Histidine 		H 		CAT, CAC
//  Glutamic acid 	E 		GAA, GAG
//  Aspartic acid 	D 		GAT, GAC
//  Lysine 		K 		AAA, AAG
//  Arginine 		R 		CGT, CGC, CGA, CGG, AGA, AGG
//
//  Your task is to determine whether two DNA sequences use the
//  same number of each type of aminoacid (the order of the
//  amino-acids doesn't matter here).
//  To that end, you need to write a function that
//  takes a DNA sequence and converts it to the corresponding
//  sequence of aminoacids, for instance if the input sequence is:
//
//  AAGGAGTGTTTT
//
//  Your function must return
//
//  KECF
//
//  Then you need to write a function that takes in two DNA
//  sequences and determines whether they produce the same
//  numbers of each aminoacid. For example, if the sequence
//  of aminoacids for each of the input DNA sequences is
//
//  AATVKFAA    and    TAAVKAAF
//
//  The function must return 1 (they produce the same number
//  of each aminoacid). However, if the aminoacid sequences
//  are
//
//  TVFAAKVV    and    ECVAATFK
//
//  the function will return 0 (not the same number of each
//  aminoacid).
//
// (c) F. Estrada, March, 2022
///////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

////////////////////////////////////helper function///////////////////////////////////

int inArray(char AminoAcid[7][4], char temp[4])
{
	int i = 0;

	while (strcmp(AminoAcid[i], "") != 0){
		if (strcmp(temp, AminoAcid[i]) == 0){
			return 1;
		}
		i += 1;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////

void DNA_sequencing(char inputDNA[1024], char outputAminoAcids[1024])
{
    // This function receives two strings, one that contains a sequence
    // of DNA nucleotides (which MUST be composed of the letters
    // ACGT, no spaces or other symbols can appear here!), and
    // updates an initially empty string 'outputAminoAcids' with the
    // sequence of aminoacids corresponding to the input DNA sequence
    //
    // Try to make this function as compact (fewer lines of code, more
    // elegant, easier to read code) as possible. APply what you've
    // learned in Exercises 6-8, all of which helped you practice
    // using strings!

    // To Do:
    // Complete this function
    
	char I[7][4] = {"ATT", "ATC", "ATA", "", "", "", ""};
	char L[7][4] = {"CTT", "CTC", "CTA", "CTG", "TTA", "TTG", ""};
	char V[7][4] = {"GTT", "GTC", "GTA", "GTG", "", "", ""};
	char F[7][4] = {"TTT", "TTC", "", "", "", "", ""};
	char M[7][4] = {"ATG", "", "", "", "", "", ""};
	char C[7][4] = {"TGT", "TGC", "", "", "", "", ""};
	char A[7][4] = {"GCT", "GCC", "GCA", "GCG", "", "", ""};
	char G[7][4] = {"GGT", "GGC", "GGA", "GGG", "", "", ""};
	char P[7][4] = {"CCT", "CCA", "CCC", "CCG", "", "", ""};
	char T[7][4] = {"ACT", "ACC", "ACA", "ACG", "", "", ""};
	char S[7][4] = {"TCT", "TCC", "TCA", "TCG", "AGT", "AGC", ""};
	char Y[7][4] = {"TAT", "TAC", "", "", "", "", ""};
	char W[7][4] = {"TGG", "", "", "", "", "", ""};
	char Q[7][4] = {"CAA", "CAG", "", "", "", "", ""};
	char N[7][4] = {"AAT", "AAC", "", "", "", "", ""};
	char H[7][4] = {"CAT", "CAC", "", "", "", "", ""};
	char E[7][4] = {"GAA", "GAG", "", "", "", "", ""};
	char D[7][4] = {"GAT", "GAC", "", "", "", "", ""};
	char K[7][4] = {"AAA", "AAG", "", "", "", "", ""};
	char R[7][4] = {"CGT", "CGC", "CGA", "CGG", "AGA", "AGG", ""};

   	int DNAcounter = 0;
    int AAcounter = 0;
    while (inputDNA[DNAcounter] != '\0'){
    	char temp[4];
    	strncpy(temp, &inputDNA[DNAcounter], 3);
    	temp[3] = '\0';
    	// if & else if statements - increment AAcounter by 1 in each if statement
    	if (inArray(I, temp) == 1){
    		outputAminoAcids[AAcounter] = 'I';
    		AAcounter += 1;
    	}

    	else if (inArray(L, temp) == 1){
    		outputAminoAcids[AAcounter] = 'L';
    		AAcounter += 1;
    	}

    	else if (inArray(V, temp) == 1){
    		outputAminoAcids[AAcounter] = 'V';
    		AAcounter += 1;
    	}

    	else if (inArray(F, temp) == 1){
    		outputAminoAcids[AAcounter] = 'F';
    		AAcounter += 1;
    	}

    	else if (inArray(M, temp) == 1){
    		outputAminoAcids[AAcounter] = 'M';
    		AAcounter += 1;
    	}

    	else if (inArray(C, temp) == 1){
    		outputAminoAcids[AAcounter] = 'C';
    		AAcounter += 1;
    	}

    	else if (inArray(A, temp) == 1){
    		outputAminoAcids[AAcounter] = 'A';
    		AAcounter += 1;
    	}

    	else if (inArray(G, temp) == 1){
    		outputAminoAcids[AAcounter] = 'G';
    		AAcounter += 1;
    	}

    	else if (inArray(P, temp) == 1){
    		outputAminoAcids[AAcounter] = 'P';
    		AAcounter += 1;
    	}

    	else if (inArray(T, temp) == 1){
    		outputAminoAcids[AAcounter] = 'T';
    		AAcounter += 1;
    	}

    	else if (inArray(S, temp) == 1){
    		outputAminoAcids[AAcounter] = 'S';
    		AAcounter += 1;
    	}

    	else if (inArray(Y, temp) == 1){
    		outputAminoAcids[AAcounter] = 'Y';
    		AAcounter += 1;
    	}

    	else if (inArray(W, temp) == 1){
    		outputAminoAcids[AAcounter] = 'W';
    		AAcounter += 1;
    	}

    	else if (inArray(Q, temp) == 1){
    		outputAminoAcids[AAcounter] = 'Q';
    		AAcounter += 1;
    	}

    	else if (inArray(N, temp) == 1){
    		outputAminoAcids[AAcounter] = 'N';
    		AAcounter += 1;
    	}

    	else if (inArray(H, temp) == 1){
    		outputAminoAcids[AAcounter] = 'H';
    		AAcounter += 1;
    	}

    	else if (inArray(E, temp) == 1){
    		outputAminoAcids[AAcounter] = 'E';
    		AAcounter += 1;
    	}

    	else if (inArray(D, temp) == 1){
    		outputAminoAcids[AAcounter] = 'D';
    		AAcounter += 1;
    	}

    	else if (inArray(I, temp) == 1){
    		outputAminoAcids[AAcounter] = 'K';
    		AAcounter += 1;
    	}

    	else {
    		outputAminoAcids[AAcounter] = 'R';
    		AAcounter += 1;
    	}
    	DNAcounter += 3;
    }
    outputAminoAcids[AAcounter] = '\0';
}

////////////////////////////////////helper function///////////////////////////////////

void insertion_sort(char outputAA[1024])
{
	int i;
	int j;
	char temp;
	for (i = 1; outputAA[i] != '\0'; i++){
		temp = outputAA[i];
		j = i - 1;
		while (j >= 0 && outputAA[j] > temp){
			outputAA[j + 1] = outputAA[j];
			j = j - 1;
		}
		outputAA[j + 1] = temp;
	}
}

//////////////////////////////////////////////////////////////////////////////////////

int amino_matching(char inputDNA1[1024], char inputDNA2[1024])
{
    // This function receives two strings representing DNA
    // sequences. It returns 1 if the sequences produce the
    // same number of each type of aminoacid. Think carefully
    // about the best (simplest?) way to to this.

    // To Do:
    // Complete this function

    int AAcounter = 0;
    char outputAA1[1024];
    char outputAA2[1024];
    DNA_sequencing(inputDNA1, outputAA1);
    DNA_sequencing(inputDNA2, outputAA2);
    insertion_sort(outputAA1);
    insertion_sort(outputAA2);
    if (strcmp(outputAA1, outputAA2) == 0){
    	return 1;
    }
    else {
    	return 0;
    }
}

#ifndef __testing

int main()
{
	char DNAseq1[1024]="ATTCTTGTT";
	char DNAseq2[1024]="CTTATTGTT";
        char DNAseq3[1024]="GTGCTTGTT";
	char aminoAcids[1024]="";

	printf("Input DNA sequence 1: %s\n",DNAseq1);
	DNA_sequencing(DNAseq1,aminoAcids);
	printf("Output aminoacid sequence 1: %s\n",aminoAcids);

	printf("Input DNA sequence 2: %s\n",DNAseq2);
	DNA_sequencing(DNAseq2,aminoAcids);
	printf("Output aminoacid sequence 2: %s\n",aminoAcids);

	printf("Input DNA sequence 3: %s\n",DNAseq3);
	DNA_sequencing(DNAseq3,aminoAcids);
	printf("Output aminoacid sequence 3: %s\n",aminoAcids);

	if (amino_matching(DNAseq1,DNAseq2)==1)
	{
		printf("Sequence 1 matches sequence 2 in aminoacids\n");
	}
	else
	{
		printf("Sequence 1 does not match sequence 2 in aminoacids\n");
	}

	if (amino_matching(DNAseq1,DNAseq3)==1)
	{
		printf("Sequence 1 matches sequence 3 in aminoacids\n");
	}
	else
	{
		printf("Sequence 1 does not match sequence 3 in aminoacids\n");
	}

	if (amino_matching(DNAseq2,DNAseq3)==1)
	{
		printf("Sequence 2 matches sequence 3 in aminoacids\n");
	}
	else
	{
		printf("Sequence 2 does not match sequence 3 in aminoacids\n");
	}

	return 0;
}

#endif
