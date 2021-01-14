#include <bits/stdc++.h>

using namespace std;


vector<pair <int,int> > jewel;
vector<int> bags;

struct cmp { bool operator()(pair<int,int> &j1, pair<int,int> &j2) { return j1.second < j2.second; } };

int main(){
	
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
	
	int N,K;
	int M,V;
	int C;
	
	
	priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> pq;
	//priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,less<pair<long long,long long> > > pq;
	
	cin >> N >> K;
	
	
	jewel.assign(N,{0,0});
	bags.assign(K,0);
	
	//q jewelry
	for(int i=0; i<N;i++){
		cin >> M >> V;
		
			jewel[i].first = M; // weight
			jewel[i].second = V;	//price
		
		
		//pq.push({M,V});
	}
	// bag
	for(int i=0; i<K; i++){
		cin >> C;	
			bags[i]=C;				
	}
	
	sort(bags.begin(),bags.end());
	sort(jewel.begin(),jewel.end());
	
	int jIndex =0;
	long long result = 0;
	
	for (int i=0; i<bags.size();i++){
		while(jIndex < N && jewel[jIndex].first <= bags[i]){
			pq.push(jewel[jIndex++]);
		}
		if(!pq.empty()){
			result += pq.top().second;
			pq.pop();
		}
	} 
	cout << result;
	
return 0;	
}
