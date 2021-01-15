#include<bits/stdc++.h>

using namespace std;

vector<char> str;
long long fact[21];
vector<int> nums;
vector<bool> visited;


int factorial(int n){
	if( n==0 || n==1){
		fact[0]=1;
		fact[1]=1;
		return 1;
	}else if(n==2){
		fact[2]=2;
		return 2;
	}
	else{
		return fact[n] = n * factorial(n-1);
	}
}

int main(){
	
	int N,K;
	int x;
	
	
	scanf("%d",&N);
	scanf("%d",&K);
	
	factorial(N);
	visited.assign(N,false);
	
	
	if(K==1){			// x��° ������ ���� ã�� 
		scanf("%d",&x);
		// ���� ã��
		
		for(int i=0; i<N; i++){				//���� �ϴ� ���� �� 
			for(int j=1; j<=N;j++){				// N ������ 
				if(visited[j]==true){
					continue;
				}else{
					if(x > fact[N-i-1]){
						x-=fact[N-i-1];  	// skip�ϴ� �ڵ� 
					}else{
						str.push_back(j+'0');
						//str.push_back(' ');
						visited[j] = true;
						break;
					}
				}
			}
		}
		
	for(int i=0; i<N; i++){
		printf("%c ",str[i]);
	}
		 
	}else if(K==2){
		nums.assign(N,0);
		for(int i=0; i<N; i++){
			scanf("%d",&x);
			nums[i]=x;
			// ���°���� ã�� 
		}
		long result =0;
		for(int i=0; i<N; i++){
			for(int j=1; j<nums[i];j++){
				if(visited[j] == false){
					result += fact[N-i-1];
				}
			}
			visited[nums[i]] = true;
		}
		printf("%d",result+1);
	}
		
}
