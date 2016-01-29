/*
 * dump.c
 *
 * Author: Shichao Hu
 * Date Created: 1/28/2016
 * Last Modified by: Shichao Hu
 * Date Last Modified: 1/28/2016
 * Assignment: dump
 * Part of: Lab3
 * Partner: Bradley Vine
 */

void dump_memory(void *p, int len){
      	int i;

	printf("address        char  hexCh  short    integer     float        doubleFloat\n");
	// title for each category, and space for necessary alignment
	
      	for (i = 0; i < len; i++) { // for loop 
		printf("%p", p + i);

		if(*(unsigned char *)(p + i) < 32 || *(unsigned char *)(p + i) > 127)
		{ // if the char is out of range, we just print "?"
			printf("  ?");
		}
		else
		{ // else, we will print the char out
			printf("%3c", *(unsigned char *)(p + i));
		}
		
		printf("    0x%02x", *(unsigned char *)(p + i)); // this is hexCh
		if(i % 2 == 0) printf("%8d", *(short *)(p + i)); // this is short
		if(i % 4 == 0) printf("%12d", *(int *)(p + i)); // this is int
		if(i % 4 == 0) printf("%15e", *(float *)(p + i)); // this is float
		if(i % 8 == 0) printf("%15e", *(double *)(p + i)); // double
		printf("\n"); // new line
      	}
}
