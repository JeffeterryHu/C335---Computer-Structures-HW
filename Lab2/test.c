/* test.c
 * 
 * Author: Shichao Hu
 * Date Created: 1/23/2016
 * Last Modified by: Shichao Hu
 * Date Last Modified: 1/28/2016
 * Assignment: testing case
 * Part of: Lab2
 */

#include<stdio.h>

extern void myprintf(const char *, ...);

int main(){
	myprintf("%s myprintf %s\n", "$", "$"); // myprintf will start with $
	printf("%s printf %s\n", "-", "-"); // printf will start with -
	myprintf("$ prints a string %s\n", "wow");
	printf("- prints a string %s\n", "wow");
	myprintf("$ number 10 in decimal %d\n", 10);
	printf("- number 10 in decimal %d\n", 10);
	myprintf("$ hex a in binary is %d\n", 1010);
	printf("- hex a in binary is %d\n", 1010);
}
