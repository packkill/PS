/*
    큰 수 만들기
    플5급인가?하게 되는 쉬웠다고 생각되는 문제
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int N;

    cin >> N;
    vector <string> v(N);
    for (int i=0; i<N; i++) cin >> v[i];

    sort(v.begin(),v.end(),[](string a,string b){return a+b>b+a;});
    if (v[0][0] == '0') cout << '0';
    else for (int i=0; i<N; i++) cout << v[i];
    return 0;
}