/*
    이항 계수 4
    뤼카 정리 사용
    https://ko.wikipedia.org/wiki/뤼카의_정리
    자연수 N,M, 소수 p에 대해서 comb(N,M) = N과 M의 p진 전개의 comb곱과 같다.
    ex) comb(1432,342)mod 7을 구해보자
    1432 = 4*7^3 + 1*7^2 + 1*7^1 + 4
    342 = 0*7^3 + 6*7^2 + 6*7 + 6
    따라서 comb(1432,342) = comb(4,0)*comb(1,6)*comb(1,6)*(4,6) mod 7
    물론 이때 comb(a,b)에 대해서 a < b이면 comb(a,b) = 0 으로 취급함.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, K ,M;
ll dp[2001][2001];

ll comb(ll n, ll r) {
    
    if (n < r) return 0;
    if (dp[n][r] != -1) return dp[n][r];

    if (r == 0) return 1;
    if (r == 1) return n;

    return dp[n][r] = ( comb(n-1,r) + comb(n-1,r-1) ) % M;
}

vector <ll> ll_To_P_base(ll num, ll mod) { // long long 을 P진법으로 바꿔서 vector에 저장
    vector <ll> ret;

    while (num > 0) {
        ret.push_back(num%mod);
        num /= mod;
    }
    return ret;
}



int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> N >> K >> M;
    memset(dp,-1,sizeof(dp));

    ll ans = 1;

    vector <ll> LucasN, LucasK;
    LucasN = ll_To_P_base(N,M);
    LucasK = ll_To_P_base(K,M);

    int minIdx = min(LucasN.size(),LucasK.size());

    for (int i=0; i<minIdx; i++) {
        int n = LucasN[i];
        int k = LucasK[i];

        ans = (ans*comb(n,k))%M;
    }
    cout << ans;
    return 0;
}