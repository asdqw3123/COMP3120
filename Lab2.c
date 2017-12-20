#include<stdio.h>

int main() {
	FILE* f, *f2;
	char ch[100]={0,};

	f = fopen("input.txt","r+");
	f2 = fopen("output.txt","w+");
	
	fgets(ch,sizeof(ch),f);
	
	fprintf(f2,"test : %s",ch);

	fclose(f);
	fclose(f2);

	return 0;
}
