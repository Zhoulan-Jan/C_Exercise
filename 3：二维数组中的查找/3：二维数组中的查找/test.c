#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//��ά�����еĲ���
void FindinArray(int *nums, int rows, int cols,int target){
	int row = 0;
	int col = cols - 1;
	while (row < rows && col >= 0){
		if (nums[row*cols + col] == target){
			printf("�ҵ���");
			break;
		}
		else if (nums[row*cols + col]>target){
			col--;
		}
		else row++;
	}
	if (row == rows || col < 0){
		printf("û�ҵ�");
	}
}

int main(){
	int arr[][4] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15};
	//��ά�����е���
	int rows = sizeof(arr) / sizeof(arr[0]);
	int cols = sizeof(arr[0]) / sizeof(arr[0][0]);
	/*printf("%d ", rows);
	printf("%d ", cols);*/
	FindinArray(arr, rows, cols,14);
	system("pause");
	return 0;
}