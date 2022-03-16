/*
    연산자 끼워넣기
    백트래킹
    재귀함수 파라미터로 연산자의 개수(a,b,c,d)를 주고 
    모든 연산자를 다 사용하면(a+b+c+d==0) ret값을 max min과 비교하면서 return
*/
#include <iostream>
using namespace std;
int max_ret = -1000000000;
int min_ret = 1000000000;
int arr[11];
void dfs(int ret, int idx, int a, int b, int c, int d) {
    if (a + b + c + d == 0) {
        max_ret = max(ret,max_ret);
        min_ret = min(ret,min_ret);
        return;
    }
    if (a) dfs(ret+arr[idx],idx+1,a-1,b,c,d);
    if (b) dfs(ret-arr[idx],idx+1,a,b-1,c,d);
    if (c) dfs(ret*arr[idx],idx+1,a,b,c-1,d);
    if (d) dfs(ret/arr[idx],idx+1,a,b,c,d-1);
}
int main() {
    int N;
    cin >> N;
    for (int i=0; i<N;i++) cin >> arr[i];
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    dfs(arr[0],1,a,b,c,d);
    cout << max_ret << '\n' << min_ret;
    return 0;
}