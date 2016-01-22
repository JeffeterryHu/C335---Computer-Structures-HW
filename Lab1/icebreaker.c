/* icebreaker.c
 * Author: Shichao Hu
 * Date Created: 1/14/2016
 * Last Modified by: Shichao Hu
 * Date Last Modified: 1/14/2016
 * Partner: Yangjun Liu
 * Lab1
 */

#include<stdio.h>
#include<unistd.h>

void main(){
	int i = 1;
	while(1){ //while it is true, keep looping
		printf("Hello world\n");
		char name[100];
		FILE *f;

		sprintf(name, "../../Desktop/%d.txt", i);  
		//convert the number to char using sprintf

		f = fopen(name,"w");
		fclose(f);

		i++;
		sleep(3);
	}
}
