/*
    로또
    list에 있는 값들의 모든 조합 구하기
    백트래킹
    파이썬은 쉬울거 같은디...
*/
#include <iostream>
#include <vector>
using namespace std;

void backtrack_dfs(int N, int len, int idx, vector <int> v, int arr[]) {
    if (len == 6) {
        for (int k: v) cout << k << ' ';
        cout << '\n';
    }
    else {
        for (int i=idx; i<N; i++) {

            v.push_back(arr[i]);
            backtrack_dfs(N,len+1,i+1,v,arr);
            v.pop_back();

        }
    }
}

int main() {
    while (true) {

        int N,arr[14];
        vector <int> S;

        cin >> N;
        if (N == 0) break;
        for (int i=0; i<N; i++) cin >> arr[i];

        backtrack_dfs(N,0,0,S,arr);

        cout << '\n';
    }
    return 0;
}