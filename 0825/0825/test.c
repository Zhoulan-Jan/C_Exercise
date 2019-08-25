#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//�ж�һ�����Ƿ���2^k
int IsPowTow(int n){
	for (int i = 1; i <= n; i<<=1){
		if (i == n) return 1;
	}
	return 0;
}

//������1�ĸ���ֻ��һ���Ļ�������2^k
int IsPowTow2(int n){
	int cnt = 0;
	while (n){
		n = n&(n - 1);
		cnt++;
	}
	if (cnt == 1) return 1;
	else return 0;
}

//ɾ���ַ����Ŀո� ��βɾ�� �м���һ���ո� 
void DelBlank(char *str){
	int i = 0;
	int j = 0;
	int flg = 0; //δ����
	while (str[i] != '\0'){
		if (str[i] != ' ' && !flg){
			str[j++] = str[i++];
			flg = 1;
		}
		else if (str[i] != ' ' && flg){
			str[j++] = str[i++];
		}
		else if (str[i] == ' '&& !flg){
			i++;
		}
		else if (str[i] == ' ' && flg){
			str[j++] = str[i++];
			flg = 0;
		}
	}
	if (str[j-1] == ' '){
		str[j-1] = '\0';
	}
	else str[j] = '\0';
}

//�ַ���ѹ��

int main(){
	printf("%d\n", IsPowTow(32));
	printf("%d\n", IsPowTow(31));
	printf("%d\n", IsPowTow2(32)); 
	printf("%d\n", IsPowTow2(31)); 
	char string[] = "   asd  rf g     d  ";
	DelBlank(string);
	printf("%s\n", string);
	system("pause");
	return 0;
}

