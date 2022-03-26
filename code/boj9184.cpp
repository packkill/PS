/*
    신나는 함수 실행
    문제에 재귀함수가 주어짐.
    재귀함수 -> DP
*/

#include <iostream>
using namespace std;

int a,b,c;
int dp[101][101][101];

int solve(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) 
        return 1;
    if (dp[a][b][c]) return dp[a][b][c];

    if (a > 20 || b > 20 || c > 20) 
        return dp[a][b][c] = solve(20,20,20);
    if (a < b && b < c) 
        return dp[a][b][c] = solve(a,b,c-1) + solve(a,b-1,c-1) - solve(a,b-1,c);
    else
        return dp[a][b][c] = solve(a-1,b,c) + solve(a-1,b-1,c) + solve(a-1,b,c-1) -solve(a-1,b-1,c-1);
}
int main() {
    int a,b,c;
    while (1) {
        scanf("%d %d %d",&a,&b,&c);
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n",a,b,c,solve(a,b,c));
    }
    return 0;
}