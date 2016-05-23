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

void merge(char *in1, char *in2, char *out, int first1, last1, int first2, int last2){
	FILE *input1, *input2, *output;
	int value1, value2;
	input1 = fopen(in1,"rt");
	input2 = fopen(in2,"rt");
	while((last1 >= first1) && (last2 >= first2)){
		output = fopen(out, "w");
		fseek (output, 0, SEEK_END);
		int count = 250000;
		while(count < 1){
			fscanf(input1, "%d\n", &input1);
			fscanf(input2, "%d\n", &input2);
			if(value1 < value2){
				fprintf(output, "%d\n", input1);
				++first1;
				--count;
			}else{
				fprintf(output, "%d\n", input2);
				++first2;
				--count;
			}
		}
		fclose(output);
	}
	
	while(last1 >= first1){
		output = fopen(out, "w");
		fseek (output, 0, SEEK_END);
		while(count > 1)
		{
			int count = 250000;
			fscanf(input1, "%d\n", &input1);
			fprintf(output, "%d\n", input1);
			++first1;
			--count;
		}
		fclose(output);
	}
	
	while(last2 >= first2){
		output = fopen(out, "w");
		fseek (output, 0, SEEK_END);
		while(count > 1)
		{
			int count = 250000;
			fscanf(input2, "%d\n", &input2);
			fprintf(output, "%d\n", input2);
			++first2;
			--count;
		}
		fclose(output);
	}
	
}

int main(){
	
	clock_t begin = clock();
	
    int array[250001];
    char input1[] = "test1.txt",
    input2[] = "test2.txt",
    input3[] = "test3.txt",
    input4[] = "test4.txt",
    ans1[] = "ans1.txt";
    ans2[] = "ans2.txt";
    output[] = "ans.txt";
    
    
    FILE *f;
    f = fopen("test.txt", "rt");
    
    FILE *w;
    int temp, i, j;
	for(i = 1; i <= 4; ++i){
		for(j = 1; j <= 250000; ++j){
			fscanf(f, "%d\n", &temp);
			array[j] = temp;
		}
		
		heap_sort(array, 1, 250000);
		
		switch(i){
			case 1: w = fopen(input1, "wt"); break;
			case 2: w = fopen(input2, "wt"); break;
			case 3: w = fopen(input3, "wt"); break;
			case 4: w = fopen(input4, "wt"); break;
		}
		
		for(j = 1; j <= 250000; ++j){
			fprintf(w, "%d\n", array[j]);
		}
		
		fclose(w);
	}
	
	merge(input1, input2, ans1, 1, 250000, 1, 250000);
	merge(input3, input4, ans2, 1, 250000, 1, 250000);
	merge(ans1, ans2, output, 1, 500000, 1, 500000);
	
	
	
    
    clock_t end = clock();
	printf("\n\n\ntime run: %f",(double)(end-begin)/(double)CLOCKS_PER_SEC);
    
    return 0;    
}
