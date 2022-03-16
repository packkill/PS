/*
    스타트와 링크
    브루트포스 and 백트래킹
    첫 시도 시간초과 -> 왜? 아마도 백트래킹 최적화를 안해서인거같음 
    백트래킹 함수 파라미터로 idx 넣어주면서 이미 탐색한 경우는 제외
*/
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int N;
int result = 1000000000;
int stats[21][21];

int splitHalf(bool vst[21]) { //절반이 나누어졌는지 구하는 함수
    int cnt = 0;
    for (int i=1; i<=N; i++) {
        cnt += vst[i];
    }
    return (cnt == N/2);
}

int sumOfStats(vector <int> v) {// 그룹의 능력치합을 구하는 함수
    int sum = 0;
    for (int i:v)
        for (int j:v) 
            sum += stats[i][j];
    return sum;
}
int getDiff(bool vst[21]) { // 절반씩 팀을 정했을 때 각 팀끼리의 차이를 구하는 함수
    vector <int> Start;
    vector <int> Link;
    for (int i=1; i<=N; i++) {
        if (vst[i]) Start.push_back(i);
        else Link.push_back(i);
    }
    return abs(sumOfStats(Start) - sumOfStats(Link));
}


void backtrack_dfs(int idx, bool vst[21]) {
     
    if (splitHalf(vst)) {
        result = min(result,getDiff(vst));
        return;
    } 
    else {
        for (int i=idx; i<=N; i++) {
            if (!vst[i]) {
                vst[i] = true;
                backtrack_dfs(i, vst);
                vst[i] = false;
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            cin >> stats[i][j];
        }
    }
    bool visited[21] = {0};
    backtrack_dfs(1,visited);
    cout << result;
    return 0;
}