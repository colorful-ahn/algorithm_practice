#include <bits/stdc++.h>

using namespace std;

vector<int> v;
// as+bt=r s,t,r 조합을 찾기 , r이 gcd일때를 찾는 것. 
void eGCD(int a, int b){
	int s0=1, t0=0, r0=a;
	int s1=0, t1=1, r1=b;
	
	
	int temp;
	while(r1 !=0){
		int q= r0/r1;
		
		temp = r0 - q * r1;   // new R value
		r0 = r1;
		r1 = temp;
		
		temp = s0 - q *s1;
		s0 = s1;
		s1 = temp;
		
		temp = t0 - q*t1;
		t0 = t1;
		t1 = temp;
		
	}
	v.push_back(s0);
	v.push_back(t0);
	v.push_back(r0);
	
}

int main(){
	
	eGCD(71,240);
	for(int i=0; i<v.size();i++){
		cout << v[i] << "\n";
	}
		
	
}
