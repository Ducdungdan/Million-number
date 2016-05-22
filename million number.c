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

int main(){
	
	clock_t begin = clock();
	
    long long min = 0, max = 0, temp;
    int array[10000];
    FILE *f;
    f = fopen("test.txt", "rt");
    fscanf(f, "%d\n", &min);
    max = min;
    
    //L?y giá tr? 2 mút c?a dãy
    while(!feof(f)){
    	fscanf(f, "%lld\n", &temp);
        if(min > temp) min = temp;
        if(max < temp) max = temp;
    }
    fclose(f);
    //printf("%lld %lld", min, max);
    FILE *w; // M? file ans
    w = fopen("ans.txt","wt");
    
    long long value = (max - min)/500;
    //printf("\n %lld", value);
    long long tempmax, tempmin;
    tempmax = min;
    int i, count, j;
    for(i = 1; i <= 500; ++i){
    //	printf("%d \n",i);
        f = fopen("test.txt", "rt");
        tempmin = tempmax;
        if(i != 500){
			tempmax = i*value + min;
		}else{
			tempmax = max + 1;
		}
	//	printf("%d %d\n",tempmin, tempmax);
        count = 1;
        while(!feof(f)){
        	fscanf(f, "%lld\n", &temp);
            if((temp >= tempmin) && (temp < tempmax)){
				array[count] = temp;
                ++count;
            }
        }
        --count;
        heap_sort(array, 1, count);
        for(j = 1; j <= count; ++j){
            fprintf(w, "%d\n", array[j]);
        }
        fclose(f);
    }
    
	fclose(w);
    
    clock_t end = clock();
	printf("\n\n\ntime run: %f",(double)(end-begin)/(double)CLOCKS_PER_SEC);
    
    return 0;    
}

