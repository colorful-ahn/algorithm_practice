#include<bits/stdc++.h>

#define MAX 100000+1

using namespace std;

int N,M;
int pr[MAX];
long long weight[MAX];


int find(int a){
	if(pr[a]==a) return a;
		int x = pr[a];
		pr[a] = find(pr[a]);
		weight[a] +=weight[x];
		return pr[a];
	
}

void unionf(int a, int b, int c){
	if(a>b){
		int tmp;
		tmp = a;
		a = b;
		b = tmp;
		c = -c;
	}
	int Ra = find(a);
	int Rb = find(b);
	if(Ra == Rb ) return ;
	pr[Rb]=Ra;
	weight[Rb] += c+weight[a] - weight[b];
}

int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
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
