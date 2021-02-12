#include<bits/stdc++.h>

#define MOD 1000000007
#define MAX_N 1000000
typedef long long ll;
using namespace std;

ll n, m, k, t, x, y, z;
ll seg[4*MAX_N];


ll update(ll pos, ll val, ll node, ll x, ll y){
    if (y < pos || pos < x)
        return seg[node];
    if (x == y)
        return seg[node] = val;
    ll mid = (x + y) >> 1;
    return seg[node] = (update(pos, val, node * 2, x, mid)*update(pos, val, node * 2 + 1, mid + 1, y)) % MOD;
}
ll query(ll lo, ll hi, ll node, ll x, ll y){
    if (y < lo || hi < x)
        return 1;
    if (lo <= x&&y <= hi)
        return seg[node];
    ll mid = (x + y) >> 1;
    return (query(lo, hi, node * 2, x, mid)*query(lo, hi, node * 2 + 1, mid + 1, y)) % MOD;
}

int main(){
    scanf("%lld%lld%lld", &n, &m, &k);
    for (ll i = 1; i <= n; i++){
        scanf("%lld", &t);
        update(i, t, 1, 1, n);
    }
    for (ll i = 0; i < m + k; i++){
        scanf("%lld%lld%lld", &x, &y, &z);
        if (x == 1)
            update(y, z, 1, 1, n);
        else
            printf("%lld\n", query(y, z, 1, 1, n));
    }
    return 0;
}


