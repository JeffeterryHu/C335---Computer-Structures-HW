/* main.c --- 
 * 
 * Filename: main.c
 * Description: HW4
 * Author: Bryce Himebaugh
 * Maintainer: Shichao Hu
 * Created: 3/23/2016
 * Last-Updated: 3/24/2016
 *           By: Shichao Hu
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change log:
 * 
 * 
 */

/* Copyright (c) 2015 The Trustees of Indiana University and 
 * Indiana University Research and Technology Corporation.  
 * 
 * All rights reserved. 
 * 
 * Additional copyrights may follow 
 */

/* Code: */
#include <stdio.h> 
#include <stddef.h> 
#include <stdint.h> 
#include "testvector.h"
#include "machine.h"
#include "flags.h"

uint32_t reg[16];
uint32_t psr;

int main(int argc, char *argv[]) {
  // Argument to test_instructions can be ALL to run all of tests or a specific
  // instruction can be tested by passing the name. 
  // ADCS, ADDS, SUBS, ANDS, BICS, LSLS, ASRS
  // To run the instruction tests for all of the instructions, pass ALL
  
  //****************** my code ********************//
  char *temp;
  int i;
  uint32_t x1, x2, x3, x4;
  uint32_t p;

  // first element ( long 1)
  temp = argv[1];

  x1 = 0;

  for(i=9;i>1;i--){
  	if(i==9){
		p = 1;
	}
	else{
		p *= 16;
	}

	if(temp[i]<='9'){
		x1 += p * (temp[i] - '0');
	}
	else{
		x1 += p * (temp[i] - 'A' + 10);
	}
  }

  x2 = 0;

  for(i=17;i>9;i--){
  	if(i==17){
		p = 1;
	}
	else{
		p *= 16;
	}
	
	if(temp[i]<='9'){
		x2 += p * (temp[i] - '0');
	}
	else{
		x2 += p * (temp[i] - 'A' + 10);
	}
  }

  //long 2
  temp = argv[2];

  x3 = 0;

  for(i=9;i>1;i--){
  	if(i==9){
		p = 1;
	}
	else{
		p *= 16;
	}

	if(temp[i]<='9'){
		x3 += p * (temp[i] - '0');
	}
	else{
		x3 += p * (temp[i] - 'A' + 10);
	}
  }

  x4 = 0;

  for(i=17;i>9;i--){
  	if(i==17){
		p = 1;
	}
	else{
		p *= 16;
	}

	if(temp[i]<='9'){
		x4 += p * (temp[i] - '0');
	}
	else{
		x4 += p * (temp[i] - 'A' + 10);
	}
  }

  //register

  reg[1] = x1;
  reg[3] = x3;
  adcs(1,3);
  reg[2] = x2;
  reg[4] = x4;
  adds(2,4);

  printf("0x%08x%08x\n",reg[1],reg[2]);

  //test_instructions(ANDS);
  //each of them has test instruction
  return (0);
}

void ands(int rn, int rm) {
  // Include your code to emulate the "and" instruction:
  // subs rn, rm
  // rn = index where operand1 is located in reg[], also destination for result
  // rm = index where operand2 is located in reg[]

  reg[rn] &= reg[rm];

  // Negative Flag 
  if (reg[rn]&0x80000000) SET_N;
  else CLEAR_N;
 
  // Zero Flag 
  if (!reg[rn]) SET_Z;
  else CLEAR_Z;
}

void adcs(int rn, int rm) {
  // Include your code to emulate the "adc" instruction:
  // adcs rn, rm
  // rn = index where operand1 is located in reg[], also destination for result
  // rm = index where operand2 is located in reg[]

  //*********************** my code *****************//

  uint32_t backup = reg[rn];
  uint32_t carry = (psr >> 29) & 1;
  reg[rn] += reg[rm] + carry;

  // flag: Carry, Zero, Overflow, Negative
  // Carry
  if((reg[rn] < backup) || (reg[rn] < reg[rm])){
  	SET_C;	
  }
  else{
  	CLEAR_C;
  }
  // Zero
  if(reg[rn] == 0x00){
  	SET_Z;
  }
  else{
  	CLEAR_Z;
  }
  // Overflow
  if(((reg[rn] >> 31) == 1) && ((backup >> 31) == 0) && ((reg[rm] >> 31) == 0))
     ||
     (((reg[rn] >> 31 == 0) && ((backup >> 31) == 1) && ((reg[rm] >> 31) == 1))){
     	SET_V;
  }
  else{
  	CLEAR_V;
  }

  // Negative
  if(reg[rn]&0x80000000){
  	SET_N;
  }
  else{
  	CLEAR_N;
  }
}

void adds(int rn, int rm) {
  // Include your code to emulate the "add" instruction:
  // adds rn, rm
  // rn = index where operand1 is located in reg[], also destination for result
  // rm = index where operand2 is located in reg[]

  //******************* my code *******************//

  uint32_t backup = reg[rn];
  reg[rn] += reg[rm];

  // Carry
  if((reg[rn]<reg[rm]) || (reg[rn]<backup)){
  	SET_C;
  }
  else{
  	CLEAR_C;
  }

  // Zero
  if(reg[rn] == 0x00){
  	SET_Z;
  }
  else{
  	CLEAR_Z;
  }

  // Overflow
  if ((((reg[rn] >> 31) == 1) && ((backup >> 31) == 0) && ((reg[rm] >> 31) == 0))
       ||
       (((reg[rn] >> 31) == 0) && ((backup >> 31) == 1) && ((reg[rm] >> 31) == 1))){
  	SET_V;     
  }
  else{
  	CLEAR_V;
  }

  // Negative
  if(reg[rn]&0x80000000){
  	SET_N;
  }
  else{
  	CLEAR_N;
  }
}

void bics(int rn, int rm) {
  // Include your code to emulate the "bics" instruction:
  // subs rn, rm
  // rn = index where operand1 is located in reg[], also destination for result
  // rm = index where operand2 is located in reg[]

  //************************* my code *******************//

  reg[rn] = reg[rn] & (~reg[rm]);

  // Zero
  if(reg[rn] == 0x00){
  	SET_Z;
  }
  else{
  	CLEAR_Z;
  }

  // Negative
  if(reg[rn]&0x80000000){
  	SET_N;
  }
  else{
  	CLEAR_N;
  }
}

void lsls(int rn, int rm) {
  // Include your code to emulate the "lsls" instruction:
  // subs rn, rm
  // rn = index where operand1 is located in reg[], also destination for result
  // rm = index where operand2 is located in reg[]

  //********************* my code ***************************//

  uint32_t carry;

  if(reg[rm] == 0){
  	if(reg[rn] == 0x00){
		SET_Z;
		}
	else{
		CLEAR_Z;
		}
	if(reg[rn]&0x80000000){
		SET_N;
		}
	else{
		CLEAR_N;
		}
  else if(reg[rm] == 32){
  	carry = reg[rn] & 1;
	reg[rn] = 0;
	SET_Z;
	CLEAR_N;
  	}
  else if(reg[rm] > 32){
  	reg[rn] = 0;
	SET_Z;
	CLEAR_N;
	CLEAR_C;
  	}
  else{
  	carry = (reg[rn] & (1 << (32 - reg[rm]))) >> (32 - reg[rm]);
	reg[rn] = reg[rn] << reg[rm];
	if(reg[rn]&0x80000000){
		SET_N;
		}
	else{
		CLEAR_N;
		}	
	if(reg[rn] == 0x00){
		SET_Z;
		}
	else{
		CLEAR_Z;
		}
	if(carry){
		SET_C;
		}
	else{
		CLEAR_C;
		}
  	}
  }
}

void asrs(int rn, int rm) {
  // Include your code to emulate the "asrs" instruction:
  // subs rn, rm
  // rn = index where operand1 is located in reg[], also destination for result
  // rm = index where operand2 is located in reg[]

  //************************* my code **********************//

  uint32_t bit_l = (reg[rn]&0x80000000) >> 31;
  uint32_t bit_n;

  if(reg[rm]>31){
  	if(bit_l==1){
		reg[rn] = 0xffffffff;
		SET_C;
	}
	else{
		reg[rn] = 0x00000000;
		CLEAR_C;
	}
  }
  else{
  	bit_n = (reg[rn] & (1 << (reg[rm]-1))) >> (reg[rm] - 1);
	if(bit_l == 1){
		reg[rn] = reg[rn] >> reg[rm];
		reg[rn] = reg[rn] | (0xffffffff << (32 - reg[rm]));
		if(bit_n==1){
			SET_C;
		}
		else{
			CLEAR_C;
		}
	}
	else{
		reg[rn] = reg[rn] >> reg[rm];
		if(bit_n==1){
			SET_C;
		}
		else{
			CLEAR_C;
		}
	}
  }

  if(reg[rn]&0x80000000){
  	SET_N;
  }
  else{
  	CLEAR_N;
  }

  if(reg[rn] == 0x00){
  	SET_Z;
  }
  else{
  	CLEAR_Z;
  }
}

/* main.c ends here */
