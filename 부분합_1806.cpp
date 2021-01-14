#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, S;


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> S;
	vector<int> v(N);
	for (int i = 0; i < N; i++)	
		cin >> v.at(i);
	
	int start = 0, end = 0, sum = 0, minLen = 100000000;
	while (start <= end) {
		if (sum >= S) {	
			minLen = min(minLen,end - start);	
			sum -= v.at(start++);
		}
		else if (end == N) break;
		else sum += v.at(end++);	
	}

	if (minLen == 100000000) cout << 0 << endl;	
	else cout << minLen << endl;
	return 0;
}
