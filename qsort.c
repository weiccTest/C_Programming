/*
	快速排序
	先开发一个名为quicksort的递归函数，此函数的所有元素采用快速排序算法对数组元素进行排序。
	
*/

#include <stdio.h>

#define N 10

void quicksort(int a[] ,int low ,int high);
int spit(int a[] , int low , int high);

int main(void){
	int a[N], i;
	printf("Enter %d number to be sorted:",N);
	
	for(i = 0; i < N; i++){
		scanf("%d",&a[i]);
	}
	
	quicksort(a, 0 , N-1);
	
	printf("In sorted order:");
	for(i = 0; i < N; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}

void quicksort(int a[] , int low ,int high){
	int middle;
	if(low >= high){
		return;
	}
	middle = split(a, low,high);
	quicksort(a , low,middle - 1);
	quicksort(a, middle + 1, high);
}

int split(int a[], int low , int high){
	int part_element = a[low];

	for(;;){
		while(low < high && part_element <= a[high]){
			high--;
		}
		
		if(low >= high){
			break;
		}
		a[low++] = a[high];
		
		while(low < high && a[low] <= part_element){
			low++;
		}
		
		if(low >= high){
			break;
		}
		a[high--] = a[low];
	}
	a[high] = part_element;
	return high;
}
