#include<stdio.h>
#include<unistd.h>

void main(){
	int i = 1;
	while(1){
		printf("Hello world\n");
		char name[100];
		FILE *f;
		sprintf(name, "../../Desktop/%d.txt", i);
		f = fopen(name,"w");
		fclose(f);
		i++;
		sleep(3);
	}
}
