#include<bits/stdc++.h>

using namespace std;

int getmin(int a,int b){
	return a<b?a:b;
}

int main(){
	int n;
	scanf("%d",&n);
	vector<pair<int, int> > v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d",&v[i].second,&v[i].first);
	}
	sort(v.begin(), v.end());
	int time = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (time <= v[i].second) {
			time = v[i].first;
			ans++;
		}
	}
	printf("%d", ans);


}
