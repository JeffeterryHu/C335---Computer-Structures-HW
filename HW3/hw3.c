/* hw3.c
 * Created by: Shichao Hu
 * Created On: 3/1/2016
 * Last Modified: 3/6/16
 * Part of: Homework3
 */

#include <stdio.h>

#define ExtractOpname1(x)(0x1 & x >> 9) //macro of getting opname1
#define ExtractOpname2(x)(0x4 & x >> 6) //macro of getting opname2
#define ExtractRm(x)(0x3 & x >> 6) // Rm
#define ExtractRn(x)(0x3 & x >> 3) // Rn
#define ExtractRd(x)(0x3 & x) // Rd
#define ExtractRdn(x)(0x3 & x) // Rdn

int main() {
	
	char *regnames[] = {"r0","r1","r2","r3","r4","r5","r6","r7","r8","r9","r10","r11","r12","sp","lr","pc"};
	char *opname1[] = {"adds","subs"};
	char *opname2[] = {"ands","eors","lsls","lsrs","asrs","adcs","sbcs","rors","tsts","rsbs","cmps","cmns","orrs","muls","bics","mvns"};

	int inst;
	printf(".text\n.syntax unified\n.thumb\n");

	while(scanf("%x", &inst) == 1)
	{
		switch(inst>>10)
		{
			case 6:
				printf(" %s, %s, %s, %s \n", opname1[ExtractOpname1(inst)], regnames[ExtractRd(inst)], regnames[ExtractRn(inst)], regnames[ExtractRm(inst)]);
				break;
			case 16:
				printf(" %s, %s, %s\n", opname2[ExtractOpname2(inst)], regnames[ExtractRdn(inst)], regnames[ExtractRn(inst)]);
				break;
			default:
				printf("wrong");
				//printf("0x%x\n", inst);
				break;
		}
	}
}
