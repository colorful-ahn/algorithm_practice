#include <bits/stdc++>


struct Info{
	int r,c;
	Info(){
	}
};


int n,dp[501][501];
Info arr[501];

int getmin(int a,int b){
	return a<b?a:b;
}

int calc(int s, int e){
	if(e-s==1){
		return arr[s].r * arr[s].c * arr[e].c;
	}if(e==s){
		return 0;
	}
	//적절한 처리를 통한 계산량 줄이기
	if() 
	//부분부분 전부 다 
	int min = -1;
	for(int mid = s; mid<=e-1;mid++){
		int tmp = calc(s,mid) + calc(mid+1,e) + arr[s].r * arr[mid].c * arr[e].c;
		if(min==-1||tmp<min){
			min = tmp;
		}
	}
	return min;
}


int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d%d",&arr[i].r,&arr[i].c);
	}
	printf("%d",calc(1,n));
}
