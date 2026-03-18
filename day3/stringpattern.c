#include <stdio.h>
int main(){
//	char str[] = "Guru";
	char str[100];
	int len;
	scanf("%s%n", str, &len);
	for (int i = 1; i<=len; i++)
		printf("%-*.*s%*.*s\n",len, i, str,len, i, str);
	
	for (int i = len; i>=1; i--)
		printf("%-*.*s%*.*s\n",len, i, str,len, i, str);
//	printf("%5.2s\n", str);
//	printf("%5.3s\n", str);
//	printf("%5.4s\n", str);
//	printf("%5.5s\n", str);
	return 0;
}
//Raman
//R       R
// a     a
//  m   m
//   a a
//    n
//   a a
//  m   m
// a     a
//R       R
