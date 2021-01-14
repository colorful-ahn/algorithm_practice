#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N,M;
	int th;
	vector<int> tree;
	
	cin >> N >> M;
	
	if(N<1 || N>1000000 || M<1 || M>2000000000){
		return 0;
	}else{
		for(int i=0; i<N; i++){
			cin >> th;
			tree.push_back(th);		
		}
		sort(tree.begin(),tree.end());
		
		
		int low=0;
		int hi=tree.at(N-1);
		int ans=0;
		int jigsaw=0;
		
		
		while(low<=hi){
			// half great tree
			long long sum = 0;
        	jigsaw = (low + hi) / 2;
        for (int i = 0; i < N; i++) {
            if (jigsaw < tree.at(i)){
			
				sum += tree.at(i) - jigsaw;
        		}
		}
        if (sum < M) {
            hi = jigsaw - 1;
        }
        else if (sum >= M) {
            ans = jigsaw;
            low = jigsaw + 1;
		}
		
	}
	cout << ans;
}
	return 0;
}
