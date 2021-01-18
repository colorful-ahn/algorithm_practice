#include<bits/stdc++.h>

#define MAX 100000+1

using namespace std;

int N,M;
int pr[MAX];
long long weight[MAX];


int find(int a){
	if(pr[a]==a) return a;
		pr[a] = find(pr[a]);
		weight[a] +=weight[pr[a]];
		return pr[a];
	
}

void unionf(int a, int b, int c){
	
	if(a>b){
		int tmp;
		tmp =a;
		a = b;
		b = tmp;
		c = -c;
	}
	find(a);
	find(b);
	pr[b]=a;
	weight[b] = c+weight[a] - weight[b];
}

int main(){
	
	while(true){
		cin >> N >> M;
		if(N==0 && M==0) break;
		for(int i=1; i<=N; i++){
		pr[i]=i;
		weight[i]=0;
		}
		for(int i=1; i<=M; i++){
			char ch;
			int a,b,c;
			cin >> ch;
			if(ch == '!'){
				cin >> a >> b >> c;	
				unionf(a,b,c);
			}
			else{
				cin >> a >> b;
				if(find(a)!=find(b)){
					cout << "UNKNOWN\n";
				}
				else{	
						cout << weight[b] - weight[a] << "\n";					
				}
			}
		}
	}
	return 0;
} 
