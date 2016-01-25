/* rpn.c
 * Author: Shichao Hu
 * Date Created: 1/23/2016
 * Last Modified by: Shichao Hu
 * Date Last Modified: 1/25/2016
 * HW0
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXOP 100 /* max size of operator */
#define NUMBER '0'
#define BUFSIZE 100

int getop(char []);
void push(double);
double pop(void);

// RPN calculator
int main(void){
	int type;
	double op2;
	char s[MAXOP];
	while((type = getop(s)) != EOF){
		switch(type){
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0){
					push(pop() / op2);
				}else{
					printf("error: don't divide by zero\n");
				}
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("Error: %s\n", s);
				break;
		}
	}
	return 0;
}

int getch(void);
void ungetch(int);

int getop(char s[]){
	int i, c;
	while((s[0] = c = getch()) == ' ' || c == '\t'){
		s[1] = '\0';
	}	
	if(!isdigit(c) && c != '.'){
		return c;  // if c is not a number
		i = 0;
	}
	if(isdigit(c)){ // get the int part out
		while(isdigit(s[++i] = c = getch()));
	}
	if(c == '.'){
		while(isdigit(s[++i] = c = getch()));
		s[i] = '\0';
	}
	if(c != EOF){
		ungetch(c);
	}
	return NUMBER;
}

char buff[BUFSIZE]; // set up the buffer size
int buffp = 0;

int getch(void){
	return (buffp > 0) ? buff[--buffp] : getchar();
}

void ungetch(int c){
	if(buffp >= BUFSIZE){
		printf("reach the quantity of input limit\n");
	}else{
		buff[buffp++] = c;
	}
}

typedef struct list_t {
	double item;
	struct list_t *next;
} list_t;


list_t *st = NULL; // start with empty

// push top value from stack
void push(double f){
	//if(is_full()){
	//	stack_overflow();
	//}else{
	//	...
	//}
}

// pop and return top value from stack
double pop(void)
{

}

