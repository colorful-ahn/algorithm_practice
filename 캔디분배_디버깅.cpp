#include<bits/stdc++.h>

using namespace std;
typedef long long ll;



struct Ex_gcd{
	ll s;
	ll t;
	ll r;
};




Ex_gcd eGCD(ll a, ll b){
	ll s0=1, t0=0, r0=a;
	ll s1=0, t1=1, r1=b;
	
	
	ll temp;
	while(r1 !=0){
		ll q= r0/r1;    
		
		temp = r0 - q * r1;   
		r0 = r1;
		r1 = temp;
		
		temp = s0 - q *s1;
		s0 = s1;
		s1 = temp;
		
		temp = t0 - q*t1;
		t0 = t1;
		t1 = temp;
		
	}	
	Ex_gcd result = {s0,t0,r0};
	return result;

	
}

ll A,B;
int N;


int main(){
	
	
	scanf("%d",&N); //테스트 케이스 
	
	
	for(int i=0;i<N;i++){
		scanf("%lld %lld",&A,&B);
		
		Ex_gcd result = eGCD(-A,B);   // -x
		
		
		if(abs(result.r)!=1){
			printf("IMPOSSIBLE\n");
			
		}
		else{
			ll x = result.s*1/result.r; // general sun
			ll y = result.t*1/result.r;
			
			
			while(y<=0 || x<=0){
				x+=B;
				y-=-A;
				if(y > 1000000000){
					break;
				}
			}
			if(y>1000000000){
				printf("IMPOSSIBLE\n");
			}else{
				printf("%lld\n",y);
			}
		}
	}
	
	return 0;	
}
