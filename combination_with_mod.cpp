#include<cassert>
#include<vector>
#include<cstdio>
#include<map>
#include<set>
#include<cstring>
#include<cstring>
#include<memory>
#include<algorithm>
#include<string>
#include<iostream>
#include<queue>
 
using namespace std;
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define pb push_back
typedef long long ll;
 
using namespace std;

const int maxn = 2*100*1000+100;
const ll MOD = 1000000000+7;

ll fact[maxn], inv[maxn];
 
ll pw(ll x, ll e) {
    if(e == 0) return 1;
    if(e == 1) return x;
    ll y = pw(x, e/2);
    y = (y * y) % MOD;
    if(e % 2 == 0) return y;
    return (y * x) % MOD;
}

ll nCrCombination(ll n, ll k) {
    ll v1 = fact[n];
    ll v2 = inv[k];
    ll v3 = inv[n-k];
    return (((v1 * v2) % MOD) * v3) % MOD;
}

void prepareFact(){
    fact[0] = 1;
    for(int i=1;i<maxn;i++) {
      fact[i] = fact[i-1] * i;
      fact[i] %= MOD;
    }
    inv[0] = 1;
    for(int i = 1; i < maxn; i++) {
      ll unit = pw(i, MOD-2);
      inv[i] = inv[i-1] * unit;
      inv[i] %= MOD;
    }    
}
int main()
{
    prepareFact();
    cout<<nCrCombination(23, 9)<<endl;
    return 0;
}
