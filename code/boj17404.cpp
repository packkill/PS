/*
    RGB거리 2
    다이나믹 프로그래밍
    RGB거리 문제처럼 하되,case를 나눠서 첫번째를 R,G,B로 각각 칠한다고 가정하고
    최소비용을 구한다.
*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int N;
int cost[3][1001];
int dp[3][1001];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> cost[0][i] >> cost[1][i] >> cost[2][i];
    }
    //0번째 start 고정
    int ans = INF;
    
    dp[0][1] = cost[0][1];
    dp[1][1] = INF;
    dp[2][1] = INF;
    for (int i=2; i<=N; i++) {
        dp[0][i] = min(dp[1][i-1],dp[2][i-1]) + cost[0][i];
        dp[1][i] = min(dp[2][i-1],dp[0][i-1]) + cost[1][i];
        dp[2][i] = min(dp[0][i-1],dp[1][i-1]) + cost[2][i];
    }
    ans = min({ans, dp[1][N], dp[2][N]});
    
    //1번째 start 고정
    dp[0][1] = INF;
    dp[1][1] = cost[1][1];
    dp[2][1] = INF;
    for (int i=2; i<=N; i++) {
        dp[0][i] = min(dp[1][i-1],dp[2][i-1]) + cost[0][i];
        dp[1][i] = min(dp[2][i-1],dp[0][i-1]) + cost[1][i];
        dp[2][i] = min(dp[0][i-1],dp[1][i-1]) + cost[2][i];
    }
    ans = min({ans, dp[2][N], dp[0][N]});
    
    //2번째 start 고정
    dp[0][1] = INF;
    dp[1][1] = INF;
    dp[2][1] = cost[2][1];
    for (int i=2; i<=N; i++) {
        dp[0][i] = min(dp[1][i-1],dp[2][i-1]) + cost[0][i];
        dp[1][i] = min(dp[2][i-1],dp[0][i-1]) + cost[1][i];
        dp[2][i] = min(dp[0][i-1],dp[1][i-1]) + cost[2][i];
    }
    ans = min({ans, dp[0][N], dp[1][N]});

    cout << ans << '\n';
    return 0;
}