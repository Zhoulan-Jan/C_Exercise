#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>

using namespace std;

string countAndSay(int n){
	if(n==1) return "1";
	else {
		string cur_str=countAndSay(n-1);
		string new_str;
		int i=0;
		int cnt=1;
		while(i<new_str.size()){
			if(cur_str[i]==cur_str[i+1]){
				cnt++;
			}else{
				new_str=new_str+(char)(cnt+'0')+cur_str[i];
				cnt=1;
			}
			i++;
		}
		return new_str;
	}
}

int main(){
	string p=countAndSay(5);
	cout<<p;
	cout<<"happy";
	printf("\n");
	return 0;
}
