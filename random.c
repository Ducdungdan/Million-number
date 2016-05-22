#include<stdio.h>
#include<stdlib.h>

int main()
{
	srand(time(NULL));

    FILE *w;
 	w=fopen("D:\\Million number\\New folder\\test.txt","wt");
 	
	
	int h, k,i=1,n;
	do
	{   
		h=rand()*4000000000u%4000000000u - 2000000000u;
		fprintf(w,"%d\n",h);
		++i;
	}while(i<=1000000);
	fclose(w);
	
	return 0;
}
