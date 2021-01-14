#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)

{

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int T;
        cin >> T;


        int N;
        cin >> N;

        vector<long long> A(N);

        for (int i = 0; i < N; i++){
        	cin >> A[i];
		}
                 

        int M;
        cin >> M;
        vector<long long> B(M);

        for (int i = 0; i < M; i++){
        	cin >> B[i];
		}

        vector<long long> a_sub, b_sub;

        //sub fill
        for (int i = 0; i < N; i++)
        {
                 long long sum = A[i];
                 a_sub.push_back(sum);
                 for (int j = i + 1; j < N; j++)
                 {
				   sum += A[j];
                	a_sub.push_back(sum);
                 }
        }
        for (int i = 0; i < M; i++)
        {
                 long long sum = B[i];
                 b_sub.push_back(sum);
                 for (int j = i + 1; j < M; j++)
                 {
                         sum += B[j];
                         b_sub.push_back(sum);
                 }
        }

 
		//sort
        sort(a_sub.begin(), a_sub.end());
        sort(b_sub.begin(), b_sub.end());

        long long result = 0;
        int ptA =0;
        int ptB =b_sub.size()-1;

        for(int i=0; i<a_sub.size();i++){	//time out
        	if(a_sub.at(i)+b_sub.at(b_sub.size()-1)<T){
        		continue;
			}
        	for(int j=b_sub.size()-1;j>=0;j--){
        		if(a_sub.at(i)+b_sub.at(j)>T){
        			b_sub.pop_back();
        			continue;
				}
				else if(a_sub.at(i)+b_sub.at(j) == T){
					result ++;
				}
			}
		}
		
		while(ptA < a_sub.size() && ptB >0){
			
		}

        cout << result << "\n";

        return 0;

}



