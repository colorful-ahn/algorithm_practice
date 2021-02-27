#include<bits/stdc++.h>

using namespace std;

stack<char> s;

int main(){
	while(1){
		string str;
		getline(cin,str);
		
		if(str[0]=='.') break;
		
			for(int i=0; i<str.size(); i++){
			if(str[i]=='(') s.push(str[i]);
			if(str[i]=='[') s.push(str[i]);
			if(str[i]==')'){
				if(!s.empty()&&s.top()=='(') s.pop();
				else { printf("no\n"); break; }
			}
			if(str[i]==']'){
				if(!s.empty()&&s.top()=='[') s.pop();
				else { printf("no\n"); break; }
			}
			if(s.empty()&&i==str.size()-2) printf("yes\n");
			else if(!s.empty()&&i==str.size()-2) printf("no\n");
		} 
		
		while(!s.empty()){
			s.pop();
		}	
		
		
	}
}
