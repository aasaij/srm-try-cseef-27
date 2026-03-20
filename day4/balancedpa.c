#include <stdio.h>
//Program to check whether the paranthesis are balanced or not
int main(){
	char expr[100], *c;
	char st[100];
	int top = -1;
	scanf("%s", &expr[0]);
	c = expr;
	while(*c!='\0'){
		if (*c =='{' || *c =='[' || *c =='(')
			st[++top]= *c;
		else if (*c ==']' && st[top]=='[' || *c ==')' && st[top]=='(' || 
				*c =='}' && st[top]=='{')
				top--;
		else{
			printf("Invalid!");
			return 0;
		}
		c++;
	}
//	if (*c=='\0' && top == -1)
//		printf("Valid!");
//	else
//		printf("Invalid!");
	printf("%s", (*c=='\0' && top == -1)?"Valid":"Invalid");
	return 0;
}