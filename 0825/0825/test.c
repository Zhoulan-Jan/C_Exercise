#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//判断一个数是否是2^k
int IsPowTow(int n){
	for (int i = 1; i <= n; i<<=1){
		if (i == n) return 1;
	}
	return 0;
}

//二进制1的个数只有一个的话，就是2^k
int IsPowTow2(int n){
	int cnt = 0;
	while (n){
		n = n&(n - 1);
		cnt++;
	}
	if (cnt == 1) return 1;
	else return 0;
}

int main(){
	printf("%d\n", IsPowTow(32));
	printf("%d\n", IsPowTow(31));
	printf("%d\n", IsPowTow2(32)); 
	printf("%d\n", IsPowTow2(31)); 
	system("pause");
	return 0;
}

