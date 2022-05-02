/*
    암호 만들기
    문자 정렬 후 단순 백트래킹
    조건: 적어도 1개의 모음 + 적어도 2개의 자음
*/

#include <bits/stdc++.h>
using namespace std;

int MAX_L, C;
vector <char> v;

bool IsPossible(string S) {
    int Vcnt = 0;
    for (int i=0; i<S.size(); i++) {
        if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u' ) Vcnt++;
    }
    int Ccnt = MAX_L - Vcnt;
    return Vcnt >= 1 && Ccnt >= 2;
}

void backtrack_dfs(int idx, string ret) {
    if (ret.length() == MAX_L) {
        if (IsPossible(ret)) {
            cout << ret << '\n';
        }
        return;
    }
    else if (idx < C) {
        ret.push_back(v[idx]);
        backtrack_dfs(idx+1, ret);
        ret.pop_back();
        backtrack_dfs(idx+1, ret);
        
    }
}

int main() {
    cin >> MAX_L >> C;
    for (int i=0; i<C; i++) {
        char a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    string ans = "";
    backtrack_dfs(0,ans);
    return 0;
}