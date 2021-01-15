#include<bits/stdc++.h>

using namespace std;

vector<long long> v;
// as+bt=r s,t,r 조합을 찾기 , r이 gcd일때를 찾는 것. 
vector<long long> Av,Bv,Dv;
vector<long long> x,y;
//vector<int> K;

int GCD(long long a, long long b){
		while(b>0){
			long long r;
			r= a%b;
			a = b;
			b = r;
		}
	return a;
}


void eGCD(long long a, long long b){
	long long s0=1, t0=0, r0=a;
	long long s1=0, t1=1, r1=b;
	
	
	long long temp;
	while(r1 !=0){
		int q= r0/r1;    // 나눠 
		
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
	
	
	//X : 인당 나눠줄 사탕의 수 
	// Y : 사탕 봉지의 수
	// A * X + 1 = B * y
	// Ax + By = C 형태로
	// -Ax + By = 1
	// A(-x) + By =1
	
	// A,B 입력 받고
	int N;
	scanf("%d",&N); //테스트 케이스 
	long long A,B;
	
	//v.assign(N*3+1,0);
	Av.assign(N,0);
	Bv.assign(N,0);
	Dv.assign(N,0);
	//K.assign(N+1,0);
	x.assign(N,0);
	y.assign(N,0);
	
	
	for(int i=0; i<N; i++){
		scanf("%d",&A); // K명 참가 
		scanf("%d",&B); // 한봉지에 몇개 들었는지.
		Av[i]=A;
		Bv[i]=B;
		Dv[i]=GCD(A,B); 
	} 

	// A and B GCD
	
	
	
	
	for(int i=0; i<N; i++){
		eGCD(Av[i],Bv[i]);
	}  
	
	
	
	// v를 3씩 끊어서 사용할까? 
	
	// D = GCD(A,B)
	// D * K = C ==> C % D ==0 이어야만 해를 가질 수 있다 : 베주 항등식
	
	// 확장 유클리드 호제법을 이용하여 s,t,r을 찾아낸다.
	
	
	// v에 3칸씩 s,t,r 들어감. 
	
	// x0 =s* C/D
	// y0  = t * C/D
	
	
	int j=0;
	for(int i=0; i<v.size(); ){
		x[j] = v[i];   //각 입력들에 대한 s의 값이 쌓임 
		y[j] = v[i+1];  // 각 입력들에 대한 t의 값이 쌓임 
		i+=3;
		j+=1;
	}
	// 요까지 됐엉
	
//	int i=0;
//	int max=0;
	
	// 무한루프?! 
	//
//	printf("z : %d,%d,%d",x[0],y[0],Dv[0]); 
//	while(i<Av.size()){
//		
//		K[i]=max;
//		if(K[i]>=(y[i]-1000000000)*(Dv[i]/Av[i]) && K[i]<y[0]*(Dv[i]/Av[i]) && K[i]<(x[i]*-1)*(Dv[i]/Bv[i])){	
//			max=0;
//			i++;
//		}
//		max+=1;
//		
//	}  // K값 도출 
//	
//	
//	
//	for(int i=0; i<K.size();i++){
//		printf("C : %d",K[i]);
//	}
	
	// 일반해 공식  x= x0+B/D*K        y= y0-A/D*K
	 
	 //  x < 0
	// 0< y <= 1e9 
	
	// x0 + B/D*K <0
	// 0 < y0 - A/D * K < 1e9
	
	// k < -x0 / B*D
	// -y0 < - A/D * K < 1e9 -y0
	
	// (y0 - 1e9) / A*D < k < y0/A*D
	
	
//	for(int i=0; i<x.size(); i++){
//		x[i] +=Bv[i]/Dv[i]*K[i];
//		y[i] -=Bv[i]/Dv[i]*K[i];
//	}
	for(int i=0; i<y.size();i++){
		if(y[i]>=1000000000 || y[i]<0){
			cout << "Impossible" << "\n";
		}else if(Dv[i]==Av[i] || Dv[i]==Bv[i]){			//1일때;; 
			if(Av[i]==1){
				cout << "1" <<"\n";
			}else{
				cout << "Impossible" << "\n";
			}
				
		}
	
		else{
			cout << y[i] << "\n";
		}
	}
	// k의 max를 구한 후 그 k를 이용해서 y값을 구해냄
	// 구한 y값이 1e9 보다 작다면 가능한 답. 
		
	
}
