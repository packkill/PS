/*
    Four Squares
    dp[i] = i가 제곱수들의 합이 되는 최소의 개수
    dp[i] = min(dp[i-1],dp[i-4],dp[i-9], .... dp[i-k*k] ) i-k*k > 0
*/

#include <iostream>
using namespace std;
#define INF 10
int dp[50001];


int main() {
    int N;
    cin >> N;
    for (int i=0; i<=N; i++) {
        dp[i] = INF;
    }
    for (int i=1; i*i <=N; i++) {
        dp[i*i] = 1;
    }

    for (int i=1; i<=N; i++) {
        if (dp[i] != INF) continue;

        for (int j=1; i - j*j > 0; j++) {
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }
    cout << dp[N];
    return 0;
}