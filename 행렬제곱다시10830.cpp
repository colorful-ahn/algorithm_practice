#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
int n;
ll b;
ll a[6][6],hang[6][6];
void cal(ll a[6][6], ll b[6][6])
{	
	ll temp[6][6]={0,};
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] %= 1000;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = temp[i][j];
    }
    

int main() {
    scanf("%lld%lld",&n,&b); 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            scanf("%d",&a[i][j]);
        }
        hang[i][i] = 1;
    }
 
    while (b > 0)
    {
        if (b % 2 == 1) cal(hang, a);
        cal(a, a);
        b /= 2;
    }
    for (int i = 1; i <= n; i++){
	for (int j = 1; j <= n; j++) printf("%lld ",hang[i][j]);
	printf("\n");
    }
}

