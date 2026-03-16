#include <stdio.h>

int main(){
	struct F {
		int x;
		int y;
	}s1;
	int x = 12;
	float f = 3.6;
	char c = 'A';
	void* ptr;
	ptr = &x; //ptr is pointing an integer
	printf("%d\n", *(int*)ptr);
	ptr = &c; //ptr is pointing a character
	printf("%c\n", *(char*)ptr);
	ptr = &f; //ptr is pointing a float
	printf("%g\n", *(float*)ptr);	
	s1.x = 10; s1.y = 200;
	ptr = &s1;
	printf("%d %d", (struct F*)s1.x, (struct F*)s1.y);
	return 0;
}