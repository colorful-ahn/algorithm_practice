#include<bits/stdc++.h>

using namespace std;

getMax(int a,int b){
	return a>b?a:b;
}

int main(){
	string str;
	map<char, int> m;
	char arr[26];
	cin >> str;
	
	for(int i=0; i<str.size(); i++){
		map[str[i]]++;
	}
	for(auto i=m.begin(); i!=m.end(); i++){
		arr[i]++;
	}
}
