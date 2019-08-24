#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int MyPow(int x, int y){
	int tmp = 0;
	int result = 0;
	if (y == 1) return x;
	tmp = MyPow(x, y / 2);
	if (y %2 == 0) result = tmp*tmp;
	else result = x*tmp*tmp;
	return result;
}

void SumK(int *arr, int len,int target, int *num1, int *num2){
	int i = 0;
	int j = len - 1;
	while (i<j)
		if (arr[i] + arr[j] > target) j--;
		else if (arr[i] + arr[j] < target) i++;
		else {
			*num1 = i; *num2 = j; break;
		}
}


int main(){
	int arr[] = {5,6,7,9,10,15};
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = -1;
	int j = -1;
	SumK(arr, len, 20, &i, &j);
	printf("%d,%d\n", i, j);
	printf("%d", MyPow(2, 6));
	system("pause");
	return 0;
}


