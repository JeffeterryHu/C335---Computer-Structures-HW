/* mywc.c
 *
 * Author: Shichao Hu
 * Date Created: 1/21/2016
 * Last Modified by: Shichao Hu
 * Date Last Modified: 1/21/2016
 * Assignment: my own word count
 * Part of: Lab2
 */

//#include<stdlib.h>
#include<stdio.h>

int main(){
	int total_char = 0; //total characters in the file
	int total_line = 0; //total lines in the file
	int total_word = 0; //total words in the file
	int boolean;
	int n;

	while((n = getchar()) != EOF){ // EOF means the end of file
		total_char++;
		if(isspace(n) || n=='\n'){
			total_word++;
		//if n is space or n goes another line, word count plus 1
		}
		if(n=='\n'){
			total_line++;
		//if n means new line, line count plus 1
		}
		if(n=='-'){
			total_word--;
		//if n equals -, word count minus 1
		}
	}
	printf("Lines, Words, Characters\n");
	printf("%d %d %d\n",total_line,total_word,total_char);
	return 0;
}
