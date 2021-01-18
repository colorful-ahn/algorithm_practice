#include<bits/stdc++.h>

using namespace std;

int n,m,ans;
int pr[1001];

typedef struct com {
	int a,b,c;
}com;


bool cmp(com a , com b){
	return a.c < b.c;
}


int findf(int a){
	if ( a == pr[a] ) return a;
	//return findf(p[a]);
	pr[a] = findf(pr[a]);		// 시간초과 해결하기 위한 방법 
	return pr[a];
}

void unionf(int a, int b){
	a = findf(a);
	b = findf(b);
	pr[a] = b;
}

int main(){
	// computer
	
	scanf("%d",&n);
	// edge
	scanf("%d",&m);
	
	vector<com> v(m);
	
	for(int i=1; i<=n; i++){
		pr[i]=i;
	}
	//v.resize(n);
	for(int i=0; i<m; i++){
		int a,b,c;
		
		scanf("%d %d %d",&a,&b,&c);
		v[i].a=a;
		v[i].b=b;
		v[i].c=c;
		
				
	}	
	sort(v.begin(),v.end(),cmp);
	
	for(int i=0; i<m;i++){
		int a,b,c;
		a = v[i].a;
		b = v[i].b;
		c = v[i].c;
		if(findf(a)!=findf(b)){
			unionf(a,b);
			ans +=c;
		}
	}
	printf("%d",ans);
}
