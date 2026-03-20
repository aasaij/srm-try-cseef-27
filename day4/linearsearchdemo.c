//Program to implement linear search algorithm
#include <stdio.h>
#include <string.h>
int linearSearch(int row, int col,char list[row][col], char s[]){
	for (int i = 0; i<row; i++){
		if (!strcmp(list[i], s))
			return i;
	}
	return -1;
}
int main(){
	char names[][15] = {"Keerthika", "Preethi","Guru", "Srivarshan", "Rasin", "Amit"};
	int size = sizeof(names)/sizeof(names[0]);
	char search[15];
	scanf("%s", search);
	int index = linearSearch(size, 15, names, search);
	if (index==-1)
		printf("Not found");
	else
		printf("Found @ %d", index+1);
	return 0;
}