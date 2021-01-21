#include <bits/stdc++.h>

int t,n;
int card[1010],subsum[1010];
int k_dp[1010][1010], m_dp[1010][1010]; 
//memorization...

int kp(int,int);
int mp(int,int);

int getsum(int s, int e){
	return subsum[e] - subsum[s-1];
} 

int getmax(int a,int b){
	return a>b?a:b;
}

int kp(int s, int e){
	if(s==e){
		return card[s];
	}
	if(k_dp[s][e]!= -1){
		return k_dp[s][e];
	}
	int left=0,right=0;
	//left
	// 근우가 지금 가져가는 카드로 얻는 값 card[s]
	// 명우가 최선을 다해서 얻는 점수 mp(s+1,e)
	// 근우가 나머지 플레이에서 얻는 점수 : [s+1~e]까지의 합 - "명우가 최선을 다해서 얻는 점수" 
	left = card[s]+getsum(s+1,e) - mp(s+1,e);
	right = card[e] + getsum(s,e-1) - mp(s,e-1);
	//right
	k_dp[s][e] = getmax(left,right);
	return k_dp[s][e];
}

int mp(int s, int e){
	if(s==e){
		return card[s];
	}
	if(m_dp[s][e]!=-1){
		return m_dp[s][e];
	}
		int left = 0, right = 0;
		left = card[s] + getsum(s+1,e) - kp(s+1,e);
		right = card[e] + getsum(s,e-1) - kp(s,e-1);
		
		m_dp[s][e] = getmax(left,right);
		return m_dp[s][e];
	
}


int main(){
	scanf("%d",&t);
	for(int i=1; i<=t; i++){
		scanf("%d",&n);
		memset(k_dp,0xff,sizeof(k_dp));
		memset(m_dp,0xff,sizeof(m_dp));
		
		for(int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			card[j]=x;
			subsum[j]=x;
		}
		kp(1,n);
		printf("%d\n",k_dp[1][n]);
	}
}
