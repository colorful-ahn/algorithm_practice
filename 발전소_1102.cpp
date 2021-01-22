#include <bits/stdc++.h>

#define INF 10000
int n,cost[16][16],p;
bool onoff[16];
char buf[20];
int dp[(1<<16)];  // 상태를 만들기 위한 최소비용 



int bitcount(int x){
	int count=0;
	while(x){
		if(x&1) count++;
		x/=2;
	}
	
	return count;
}

int bitcheck(int b,int pos){
	return b & (1<<pos);
} 
int bitset(int b, int pos){
	return b | (1<<pos);
}


int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d",&cost[i][j]);
		}
	}
	scanf("%s",buf);
	
	for(int i=0; buf[i];i++){
		if(buf[i]=='Y'){
			onoff[i]=true;
		}
	}
	scanf("%d",&p);
	for(int i=0; i<(1<<16);i++){
		dp[i] = INF;
	}
	
	//최초시작은 어떻게 진행해야 할까??
	// 힌트는 최초에 커져있는 발전소를 아니까, 상태를 만들어서, 그 상태의 dp[]=0으로... 
	int first_state = 0;
	for(int i=0; i<n;i++){
		if(onoff[i]){
			first_state = bitset(first_state,i);
		}
	}
	dp[first_state] = 0;
	
	
	// start
	for(int state=0; state< (1<<n);state++){
		for(int i=0; i<n; i++){
		//state인 상태에서 i발전소를 켤 수 있을까??
		// 켜게되면 비용은 어떻게 될까?
		//그때 state는어떤 모양일까? : nxt_state
		//nxt_state에는 어떤 값이 있었을까?? 
		int nxt_state,nxt_cost;
		if(bitcheck(state,i)){		// state : 발전소가 켜져있는것 , i 가 있다는 것은 이미 켜져있는것 
			continue;
		}
		nxt_state = bitset(state,i);
		for(int j=0;j<n;j++){			// j번째 발전소를 이용해서 i를 켜자 
			if(bitcheck(state,j)){
				nxt_cost = dp[state] + cost[j][i];
				if(nxt_cost < dp[nxt_state]){
					dp[nxt_state] = nxt_cost;
				}
			}
		}
		}
	}
	
	
	
	//printf 는 p를 고려해서 p보다 큰 가를 확인해야 함. 
	int answer = INF;
	for(int i=0; i<(1<<n);i++){
		if(bitcount(i) >= p){
			//작업 
			if(dp[i]<answer){
				answer = dp[i];
			}
		}
	}
	if(answer == INF) answer = -1;
	printf("%d",answer);
}
