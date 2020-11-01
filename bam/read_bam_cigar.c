#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <htslib/sam.h>


int main(int argc, char *argv[]) {
	samFile *fp = hts_open(argv[1],"r"); // Open BAM file
	bam_hdr_t *bam_header = sam_hdr_read(fp); // Read header
	bam1_t *alignment = bam_init1(); // initialize an alignment

	uint32_t n_cig, *cigar;
	uint32_t cigar_length;
	uint8_t cigar_operation;


	int read_num = 1;

	while (sam_read1(fp, bam_header, alignment) > 0){
		int i;
		// Extract number of CIGAR for read
		n_cig = alignment->core.n_cigar;

		cigar = bam_get_cigar(alignment);
		printf("Read %i\n", read_num);
		printf("N_CIGAR: %" PRIu32 "\n", n_cig);
		// Loop each CIGAR
		for (i = 0 ; i < n_cig ; i++) {
			
			printf("CIGAR: %" PRIu32 "\n", cigar[i]);
			
			// Extract current CIGAR operation	
			cigar_operation = BAM_CIGAR_MASK & cigar[i];
			/*
			cigar_operation = 15 & cigar[i];
			cigar_operation = 0xF & cigar[i];
			cigar_operation = 0b00001111 & cigar[i];
			*/

			// Extract current CIGAR length
			cigar_length = bam_cigar_oplen(cigar[i]);
			/*
			cigar_length = cigar[i] >> 4;
			cigar_length = cigar[i] >> BAM_CIGAR_SHIFT;
			*/
			
			printf("Length: %" PRIu32 "\n", cigar_length);
			printf("Operation: %" PRIu8 "\n", cigar_operation);
			printf("Operation: %c\n", bam_cigar_opchr(cigar[i]));
		}
		printf("\n");
		read_num++;

	}

	bam_destroy1(alignment);
	sam_close(fp);
	return 0;
}
