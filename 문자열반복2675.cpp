#include<bits/stdc++.h>

using namespace std;

int t;

int main(){
	scanf("%d",&t);
	while(t-->0){
		int r;
		string str;
		vector<char> v;
		cin >> r >> str;
		for(int i=0; i<str.size(); i++){
			for(int j=0; j<r;j++){
				v.push_back(str[i]);
			}
		}
		for(int i=0; i<v.size();i++){
			printf("%c",v[i]);
		}
		printf("\n"); 
	}
}
