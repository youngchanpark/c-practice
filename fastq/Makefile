CC=gcc


read_gzipped_fastq:
	$(CC) -I/opt/local/include -L/opt/local/lib -lz read_gzipped_fastq.c
# -I/opt/local/include: Add this directory to the include directory
# because zlib.h is in here
	
# -L/opt/local/lib: This is for adding the libz.a static library as a linker

# -lz: This actually adds the linker libz.a for compiling this script

