#include<stdio.h>
#include<time.h>

inline void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heap_ify(int *A, int i, int n){
	int L = 2*i,
	R = 2*i + 1,
	max = i;
	if((A[max] < A[R]) && (R <= n)) max = R;
	if((A[max] < A[L]) && (L <= n)) max = L;
	if(max != i){
		swap(&A[max], &A[i]);
		heap_ify(A, max, n);
	}
}

void build_heap(int *A, int first, int last){
	int i = last/2;
	for(; i >= 1; --i){
		heap_ify(A, i, last);
	}
}

void heap_sort(int *A, int first, int last){ // bat dau tu 1
	build_heap(A, first, last);
	int i;
	for(i = last; i > 1; --i){
		swap(&A[i], &A[1]);
		heap_ify(A, 1, i -1);
	}
}

void merge(FILE *input1, FILE *input2, FILE *output, int first1, last1, int first2, int last2){
	
}

int main(){
	
	clock_t begin = clock();
	
    int array[25001];
    
    FILE *f;
    f = fopen("test.txt", "rt");
    
    FILE *w;
    int temp, i, j;
	for(i = 1; i <= 5; ++i){
		for(j = 1; j <= 250000; ++j){
			fscanf(f, "%d\n", &temp);
			array[j] = temp;
		}
		
		heap_sort(array, 1, 25000);
		
		switch(i){
			case 1: w = fopen("temp1.txt", "wt"); break;
			case 2: w = fopen("temp2.txt", "wt"); break;
			case 3: w = fopen("temp3.txt", "wt"); break;
			case 4: w = fopen("temp4.txt", "wt"); break;
		}
		
		for(j = 1; j <= 25000; ++j){
			fprintf(w, "%d\n", array[j]);
		}
		
		fclose(w);
	}
	
	FILE *ans;
	
	FILE *t1, *t2, *t3, *t4;
	
	int count;
	int first1 = 1, first2 = 1, first3 = 1, first4 = 1, first5 = 1;
	int last1 = 20000, last2 = 20000, last3 = 20000, last4 = 20000, last5 = 20000;
	int temp1, temp2, temp3, temp4, temp5;
	int min;
	
	
    
    clock_t end = clock();
	printf("\n\n\ntime run: %f",(double)(end-begin)/(double)CLOCKS_PER_SEC);
    
    return 0;    
}
