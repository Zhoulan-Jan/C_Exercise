#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 500000

//字符串翻转
char *strev(char *s){
	char *p1, *p2;
	if (!s || !*s){
		return s;
	}
	for (p1 = s, p2 = s + strlen(s) - 1; p2 > p1; ++p1, --p2){
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	return s;
}


//大数相乘
int ans3[MAX];
char num[MAX];
char *BigMul(char *a, char *b){
	memset(ans3, 0, sizeof(ans3));
	memset(num, 0, sizeof(num));
	int lena = strlen(a);
	int lenb = strlen(b);
	//翻转
	strev(a);
	strev(b);
	//大数与b的每一位数相称
	for (int i = 0; i < lena; i++){
		for (int j = 0; j < lenb; j++){
			ans3[i + j] += (a[i] - '0')*(b[j] - '0');
		}
	}
	//分解
	int i;
	int yu=0;
	int len = lena + lenb - 1;
	for (i = 0;; i++){
		if (i < len || yu != 0){
			yu = ans3[i] + yu;
			ans3[i] = yu% 10;
			yu = yu / 10;
		}
		else break;
	}
	//将ans的数字转化为字符串
	int nu = 0;
	//char *as = num;
	while (i--){
		num[nu++] = ans3[i] + '0';
	}
	//num[nu] = '\0';
	return num;
}

//大数相减
char ans2[MAX];
//比较两数大小
int compare(char *a, char *b){
	int lena = strlen(a);
	int lenb = strlen(b);
	if (lena > lenb) return 1;
	if (lena < lenb) return -1;
	return strcmp(a, b);
}

char *NumSub(char *a, char *b){
	char aa[MAX];
	char bb[MAX];
	int flag = 0;//bool bo = true;
	memset(aa, 0, sizeof(aa));
	memset(bb, 0, sizeof(bb));
	memset(ans2, 0, sizeof(ans2));
	char *as = ans2;
	//比较两个数大小 -
	if (compare(a, b) > 0){
		strcpy(aa, a);
		strcpy(bb, b);
		flag = 1;
	}
	else if (compare(a, b) < 0){
		strcpy(aa, b);
		strcpy(bb, a);
		flag = -1;
	}
	else if (compare(a, b) == 0){
		ans2[0] = '0';
		return as;
	}
	//翻转
	strev(aa);
	strev(bb);
	/*printf("aa:%s\n",aa);
	printf("bb:%s\n", bb);*/
	//相减 可能借位
	int lena = strlen(aa);
	int lenb = strlen(bb);
	int i;
	for (i = 0;; i++){
		if (i < lena&&i < lenb){
			if (aa[i]>=bb[i]){
				ans2[i] = aa[i] - bb[i] +'0';
			}
			else {
				ans2[i] = aa[i] - bb[i] + 10 + '0'; //加的是数字10呀
				for (int j = i + 1;; j++){
					if (aa[j] == '0') aa[j] = '9';
					else{
						aa[j]--;
						break;
					}
				}
			}
		}
		else if (i < lena){
			ans2[i] = aa[i];
		}
		else if (i < lenb){
			ans2[i] = bb[i];
		}
		else break;
	}
	//去掉ans前置零
	while (i--){
		ans2[i + 1] = '\0';
		if (ans2[i] - '0'>0) { break; }
	}
	//添-
	if (flag == -1){
		ans2[i + 1] = '-';
	}
	strev(ans2);
	return as;
}


//大数相加 
char a[MAX], b[MAX];
char ans1[MAX];

char *NumAdd(char *a, char *b){ //*
	memset(ans1, 0, sizeof(ans1));
	int lena = strlen(a);
	int lenb = strlen(b);
	int ci = 0; //进位标志

	//翻转
	strev(a);
	strev(b);
	//相加：考虑进位
	for (int i = 0;; i++){
		if (i < lena&&i < lenb){
			ans1[i] = (ci + a[i] - '0' + b[i] - '0') % 10 + '0';
			ci = (ci + a[i] - '0' + b[i] - '0') / 10;
		}
		else if(i<lena){
			ans1[i] = (ci + a[i] - '0') % 10 + '0';
			ci = (ci + a[i] - '0') / 10;
		}
		else if (i < lenb){
			ans1[i] = (ci + b[i] - '0') % 10 + '0';
			ci = (ci + b[i] - '0') / 10;
		}
		else if (ci != 0){
			ans1[i] = ci % 10 + '0';
			ci = ci / 10;
		}
		else break;
	}
	strev(ans1);
	return ans1;
}


char a[MAX];
char b[MAX];
char n[MAX];
int main(){
	while (scanf("%s%s", a, b) != EOF){
		//printf("%s\n",NumSub(a,b));
		//printf("%s\n",NumAdd(a,b));
		if (strcmp(a, "0") == 0 || strcmp(b, "0") == 0) printf("0\n"); //为什么时双引号啊
		else printf("%s\n", BigMul(a, b));
	}
	while (scanf("%s", n) != EOF){
		printf("%s", fac(n));
	}
	system("pause");
	return 0;
}