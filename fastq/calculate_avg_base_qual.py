#!/usr/bin/env python3



input_file = '/Users/YoungChanPark/projects/deepvariant/deepvariant/third_party/nucleus/testdata/test_reads.fastq'


def phred_score(char: str) -> int:
	return ord(char) - 33

def mean(qual_list) -> float:
	return sum(qual_list) / len(qual_list)


qual_list = list()

with open(input_file, 'r') as file:
	line_counter = 0
	for line in file:
		line_counter+=1
		if line_counter == 4:
			qual_list.extend([phred_score(qual) for qual in line.replace('\n', '')])
			line_counter = 0


print("Mean:", mean(qual_list))
