#include<bits/stdc++.h>

using namespace std;

vector<int> v; 
vector<int> tree;
int N;
int S;


void makeTree(int N, int S){
	
	for(int i=0; i<N; i++){
		tree[S+i] = v[i+1];
	}
	for(int i= S-1; i>0; i--){
		tree[i] = tree[i*2] + tree[i*2+1];
	}
}
int query(int left,int right,int S){
	int result=0;
	left +=S-1;
	right +=S-1;
	while(left<=right){
		if (left%2==1){
			result += tree[left++];
		}
		if(right%2==0){
			result+=tree[right--];
		}
		left/=2;
		right/=2;
	}
	return result;
}


int main(){
	
	scanf("%d",&N); //숫자 갯수
	 
	 

	
	 
	 int x;
	 int sum=0;
	 int result=0;
	 int min=0;
	 int count=0;
	 
	  v.assign(N*2,0);
	 for(int i=0; i<N; i++){
		if(i==N-1){
			scanf("%d",&x);
			result = x;
		}else{
			scanf("%d",&x);
	 		v[i+1]=x;
			sum+=x;//숫자 저장
		}
		; 				 			
	 }
	// 모두 더하는 경우
	S=1;
	while(S<N){
		S*=2;
	}
	tree.assign(S*2+1,0);
		 
	makeTree(N-1,S); 
	//sum에서 query뺀것이 result가 되면 됑 

	for(int i=1; i<N; i++){
		for(int j=1; j<N;j++){
			if(j>=i){
				min = query(i,j,S);
				printf("min : %d\n",min);
				if(sum-min==result){
					count++;
				}
			}
			
		}
	}
	printf("%d",count);
	
	
	} 

