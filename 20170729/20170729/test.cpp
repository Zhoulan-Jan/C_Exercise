#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>

using namespace std;

#if 1
//并查集 畅通工程
#define MX 1000
int pre[MX];
int find(int x){
	int son,t;
	son = x;
	while(x != pre[x]){
		x = pre[x];
	}
	while (son != x){
		t = pre[son];
		pre[son] = x;
		son = t;
	}
	return x;
}

void _union(int x, int y){
	int r1 = find(x);
	int r2 = find(y);
	if (r1 != r2){
		pre[r1] = r2;
	}
}

int main(){
	int n, m;
	int a, b;
	while (scanf("%d%d", &n, &m) != EOF){
		for (int i = 0; i <= n; i++){
			pre[i] = i;
		}
		n--;
		for (int i = 0; i < m; i++){
			scanf("%d%d", &a, &b); 
			if (find(a) != find(b)){
				_union(a, b);
				n--;
			}
		}
		printf("%d\n", n);
	}
	system("pause");
	return 0;
}
#endif