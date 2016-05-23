#include<stdio.h>
#include<time.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert_sort(int *A, int first, int last){
	int i, qk, j;
	for(i = first + 1; i <= last; ++i){
		qk = A[i];
		j = i;
		while((j > first)&&(A[j -1] > qk)){
			A[j] = A[j -1];
			--j;
		}
		A[j] = qk;
	}
}

int partition(int *A, int first, int last){
	int pivot = A[first], i = first, j = last + 1;
	while(i < j){
		i++;
		while((i <= last ) && (pivot > A[i])) i++;
		--j;
		while((j >= first) && (pivot < A[j])) j--;
		swap(&A[i], &A[j]);
	}
	swap(&A[i], &A[j]);
	swap(&A[j], &A[first]);
	return j;
}

void quick_sort(int *A, int first, int last){
	if(last - first < 9){
		insert_sort(A, first, last);
	}else{
		int pivot = partition(A, first, last);
		quick_sort(A, first, pivot - 1);
		quick_sort(A, pivot + 1, last);
	}
}

void merge(char *in1, char *in2, char *out, int first1, int last1, int first2, int last2){
	FILE *input1, *input2, *output;
	int value1, value2;
	int st1 = first1, st2 = first2;
	input1 = fopen(in1,"rt");
	input2 = fopen(in2,"rt");
	while((last1 >= st1) && (last2 >= st2)){
		output = fopen(out, "w");
		fseek (output, 0, SEEK_END);
		int count = 250000;
		while((count > 1) && (last1 >= st1) && (last2 >= st2))
		{
			fscanf(input1, "%d\n", &value1);
			fscanf(input2, "%d\n", &value2);
			if(value1 < value2){
				fprintf(output, "%d\n", value1);
				++st1;
				--count;
			}else{
				fprintf(output, "%d\n", value2);
				++st2;
				--count;
			}
		}	
		fclose(output);
	}
	
	while(last1 >= st1){
		int count = 250000;
		output = fopen(out, "w");
		fseek (output, 0, SEEK_END);
		while((count > 1) && (last1 >= st1))
		{
			fscanf(input1, "%d\n", &value1);
			fprintf(output, "%d\n", value2);
			++st1;
			--count;
		}
		fclose(output);
	}
	
	while(last2 >= st2){
		output = fopen(out, "w");
		fseek (output, 0, SEEK_END);
		int count = 250000;
		while((count > 1) && (last2 >= st2))
		{
			fscanf(input2, "%d\n", &value2);
			fprintf(output, "%d\n", value2);
			++st2;
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
    ans1[] = "ans1.txt",
    ans2[] = "ans2.txt",
    output[] = "output.txt";
    
    
    FILE *f;
    f = fopen("test.txt", "rt");
    
    FILE *w;
    int temp, i, j;
	for(i = 1; i <= 4; ++i){
		for(j = 1; j <= 250000; ++j){
			fscanf(f, "%d\n", &temp);
			array[j] = temp;
		}
		
		quick_sort(array, 1, 250000);
		
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
