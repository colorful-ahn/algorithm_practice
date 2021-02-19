#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<long long> answer;
void find_answer()
{	
	answer.push_back(0);
	answer.push_back(1);
	answer.push_back(2);
	
    long long tmp;
    for(int i = 3; i <= N; i++)
    {
        tmp = 0;
        tmp = answer[i - 1] + answer[i - 2];
        answer.push_back(tmp%15746);
    }
}
int main() {
    scanf("%d",&N);
    find_answer();
    printf("%lld",answer[N]%15746);
}
