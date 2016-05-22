#include<stdio.h>

int main(){
	FILE *f;
	f = fopen("ans.txt","rt");
	
	int qk, temp, count = 0;
	fscanf(f, "%d\n", &qk);	
	while(!feof(f)){
		//printf("%d\n",count++);
    	fscanf(f, "%d\n", &temp);
        if(qk > temp){
			printf("false %d %d", qk, temp);
			break;
        }else{
        	qk = temp;
		}
    }
    return 0;
}
