#include<iostream>
#include<cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include<cmath>



#define NUM 1000000000
using namespace std;

int num(long long a);
int pop();
int inv();
int dup();
int swp();
int add();
int sub();
int mul();
int div();
int mod();


stack<long long>s;
vector<string> v;
vector<long long>number_store;

 
int main(){
	
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	int first;
	int flag;
	int c;
	long long x;
	string str;
 
	while (1) {
		flag = 0;
		while (1) {
			cin >> str;
 
			if (str == "NUM") {
				cin >> x;
				if(x>0 && x<= NUM){
				
				number_store.push_back(x);
			}
				else{
					flag=1;
				}
			}
			if (str == "QUIT") {
				return 0;
			}
			if (str == "END") {
				break;
			}
 
			v.push_back(str);
		}
 
		cin >> n;
 		if(n>=0 && n<=10000){
		int storen = n; 
		while (n--) {
			c = 0;
 			
			cin >> first;
			if(first>= NUM || first <= -NUM || storen * v.size() >= 100000){
				flag = 1;
			}else{
						
			s.push(first);
 
			for (int i = 0; i < v.size(); i++) {
				if (v[i] == "NUM") {
					flag = num(number_store[c]);
					++c;
				}
				else if (v[i] == "POP") {
					flag = pop();
				}
				else if (v[i] == "INV") {
					flag = inv();
				}
				else if (v[i] == "DUP") {
					flag = dup();
				}
				else if (v[i] == "SWP") {
					flag = swp();
				}
				else if (v[i] == "ADD") {
					flag = add();
				}
				else if (v[i] == "SUB") {
					flag = sub();
				}
				else if (v[i] == "MUL") {
					flag = mul();
				}
				else if (v[i] == "DIV") {
					flag = div();
				}
				else if (v[i] == "MOD") {
					flag = mod();
				}
				else{
					flag = 1;
				}
				
 				if(s.empty() || s.size() >=1000){
 					flag =1;
				 }
				if (!s.empty() && (s.top() > NUM || s.top() < -NUM)) {
					flag = 1;
				}
				if (flag == 1) {
					break;
				}
			}
		
		}
 
			if (flag == 1 || s.size() != 1) {
				cout << "ERROR" << "\n";
			}
			else {
				cout << s.top() << "\n";
			}
			while (!s.empty()) {
				s.pop();
			}
		}
	}
	else{
		cout << "ERROR" << "\n";
	}
 
		number_store.clear();
		v.clear();
		cout << endl;
	}
	
	return 0;
}

int num(long long a){
	s.push(a);
	return 0;
}
int pop(){
	if(s.empty()){
		return 1;
	}else{
		s.pop();
		return 0;
	}
}
int inv(){
	if(s.empty()){
		return 1;
	}else{
	
	int a;
	a = s.top();
	s.pop();
	s.push(-a);
	return 0;
}
}
int dup(){
	if(s.empty()){
		return 1;
	}else{
	
	long long a;
	a = s.top();
	if(a >NUM || a< -NUM){
		return 1;
	}else{
	
	s.push(a);
	return 0;
}}}
int swp(){
	if(s.empty()){
		return 1;
	}else{
	
	long long one,two;
	one = s.top();
	s.pop();
	if(s.empty()){
		return 1;
	}else{
	
	two = s.top();
	s.pop();
	s.push(one);
	s.push(two);
	return 0;
}}}
//add condition
int add(){
	if(s.empty()){
		return 1;
	}else{
	
	long long right = s.top();
	s.pop();
	if(s.empty()){
		return 1;
	}else{
	
	long long left = s.top();
	s.pop();
	long long result = left + right;
	if(result > NUM || result < -NUM){
		return 1;
	}else{	
	s.push(result);
	return 0;
}}}}
int sub(){
	if(s.empty()){
		return 1;
	}else{
	
	long long right = s.top();
	s.pop();
	if(s.empty()){
		return 1;
	}else{
	
	long long left = s.top();
	s.pop();
	long long result = left - right;
	if(result > NUM || result < -NUM){
		return 1;
	}else{	
	s.push(result);
	return 0;
}}}}
int mul(){
	if(s.empty()){
		return 1;
	}else{
	
	long long right = s.top();
	s.pop();
	if(s.empty()){
		return 1;
	}else{
	
	long long left = s.top();
	s.pop();
	long long result = left * right;
	if(result > NUM || result < -NUM){
		return 1;
	}else{	
	s.push(result);
	return 0;
}}}}
int div(){
	int count = 0;
	if(s.empty()){
		return 1;
	}else{
	
	long long right = s.top();
	s.pop();
	if(right<0){
		count++;
		
	}
	
	if(s.empty() || right == 0){
		return 1;
	}else{
	
	long long left = s.top();
	s.pop();
	if(left<0){
		count++;
		
	}
	
	
	long long result = abs(left) / abs(right);
	if(result > NUM || result < -NUM){
		return 1;
	}else{
	if(count ==1){
		result *=-1;
	}	
	s.push(result);
	return 0;
}}}}
int mod(){
	int count = 0;
	if(s.empty()){
		return 1;
	}else{
	
	long long right = s.top();
	s.pop();
	
	if(s.empty() || right == 0){
		return 1;
	}else{
	
	long long left = s.top();
	s.pop();
	if(left<0){
		count++;
	}
	
	
	
	long long result = abs(left) % abs(right);
	if(result > NUM || result < -NUM){
		return 1;
	}else{
	if(count ==1){
		result *=-1;
	}	
	s.push(result);
	return 0;
}}}}


