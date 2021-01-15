#include <bits/stdc++.h> 


using namespace std; 

vector<int> v;
vector<int> vL;
vector<int> vR;



// gcd(a,b) == gcd(b,a%b) r==0 exit
int GCD(int a, int b){
	if(a>b){
		while(b!=0){
		int r;
		r= a%b;
		a = b;
		b =r;
	}
	return a;
	}else{
		while(a!=0){
		int r;
		r= b%a;
		b = a;
		a =r;
	}
	return b;
	}
}


int main(){
	int N;
	int x;
	int gcd=0;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	
	cin >> N;
	
	v.assign(N,0);
	vL.assign(N,0);
	vR.assign(N,0);
	
	for(int i=0; i<N; i++){
		cin >> x;
		v[i]=x;
	}
	
	vL[0] = v[0];
	vR[N-1] = v[N-1];
	
	for(int i=1; i<N; i++){
		vL[i] = GCD(vL[i-1],v[i]);
	}
	for(int i=N-2; i>=0; i--){
		vR[i] = GCD(vR[i+1],v[i]);
	}
	
	int max=0;
	int maxIndex =0;
	for(int i=0; i<N; i++){
		
		if(i==0){
			gcd = vR[1];
		}
		else if(i==N-1){
			gcd = vL[N-2];
		}else{
			gcd = GCD(vL[i-1],vR[i+1]);
		}
		if(v[i]%gcd != 0&& gcd > max){
			max =gcd;
			maxIndex = v[i];
		}
	}
	if(max == 0){
		cout << "-1";
	}else{
		cout << max << " " <<maxIndex;
	}
	
}
