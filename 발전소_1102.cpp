#include <bits/stdc++.h>

#define INF 10000
int n,cost[16][16],p;
bool onoff[16];
char buf[20];
int dp[(1<<16)];  // ���¸� ����� ���� �ּҺ�� 



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
	
	//���ʽ����� ��� �����ؾ� �ұ�??
	// ��Ʈ�� ���ʿ� Ŀ���ִ� �����Ҹ� �ƴϱ�, ���¸� ����, �� ������ dp[]=0����... 
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
		//state�� ���¿��� i�����Ҹ� �� �� ������??
		// �ѰԵǸ� ����� ��� �ɱ�?
		//�׶� state�¾ ����ϱ�? : nxt_state
		//nxt_state���� � ���� �־�����?? 
		int nxt_state,nxt_cost;
		if(bitcheck(state,i)){		// state : �����Ұ� �����ִ°� , i �� �ִٴ� ���� �̹� �����ִ°� 
			continue;
		}
		nxt_state = bitset(state,i);
		for(int j=0;j<n;j++){			// j��° �����Ҹ� �̿��ؼ� i�� ���� 
			if(bitcheck(state,j)){
				nxt_cost = dp[state] + cost[j][i];
				if(nxt_cost < dp[nxt_state]){
					dp[nxt_state] = nxt_cost;
				}
			}
		}
		}
	}
	
	
	
	//printf �� p�� ����ؼ� p���� ū ���� Ȯ���ؾ� ��. 
	int answer = INF;
	for(int i=0; i<(1<<n);i++){
		if(bitcount(i) >= p){
			//�۾� 
			if(dp[i]<answer){
				answer = dp[i];
			}
		}
	}
	if(answer == INF) answer = -1;
	printf("%d",answer);
}
