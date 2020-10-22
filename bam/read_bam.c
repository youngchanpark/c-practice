#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <htslib/sam.h>


int main(int argc, char *argv[]) {


	samFile *fp = hts_open(argv[1],"r"); // Open BAM file
	bam_hdr_t *bam_header = sam_hdr_read(fp); // Read header
	bam1_t *alignment = bam_init1(); //initialize an alignment
	// char cigar_string[100];
	uint32_t n_cig, *cigar;
	uint8_t l_extranul;


	while (sam_read1(fp, bam_header, alignment) > 0){
		n_cig = alignment->core.n_cigar;
		l_extranul = alignment->core.l_extranul;


		/*
		We use format macros (PRIu32, PRIu8) from inttypes.h instead of %ui
		to correctly print uint values.

		See https://stackoverflow.com/a/12120500
		*/
		printf("N_CIGAR: %" PRIu32 "\n", n_cig);
		printf("L_EXTRANUL: %" PRIu8 "\n", l_extranul);

		// cigar_string = bam_get_qname(alignment);
		// printf("CIGAR: %s", cigar_string);

		cigar = bam_get_cigar(alignment);
		printf("CIGAR: %" PRIu32 "\n", *cigar);

		/*
		decimal value of 1600 in binary is 11001000000
		lower 4 bit represents the CIGAR operation,
		and the higher 28 bit represents the length of the remaining array.

		1100100/0000
		CIGAR = 0 = 0000
		Length = 100 = 1100100
		*/
		printf("CIGAR: %" PRIu32 "\n", cigar[0]);
		printf("CIGAR: %" PRIu32 "\n", cigar[1]);
		printf("CIGAR: %" PRIu32 "\n", cigar[2]);
		printf("CIGAR: %" PRIu32 "\n", cigar[99]);
		printf("CIGAR: %" PRIu32 "\n", cigar[100]);
		printf("CIGAR: %" PRIu32 "\n", cigar[101]);
		/*
		>>> bin(336757313)
		'0b10100000100101000001001000001'
		>>> int('0b10100000100101000001001000001', 2)
		336757313
		*/
		break;
	}

	bam_destroy1(alignment);
	sam_close(fp);



	return 0;
}
