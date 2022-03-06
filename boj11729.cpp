/*
    하노이 탑 이동 순서
    위치 a,b,c 가 있고 n개의 하노이 탑이 a에 있다고 하면 a에서 c로 갈때 가는 방법은
    1.a->b로 n-1개의 탑을 놓고,
    2.가장 큰 원판을 c로 한번 놓고,
    3.b->c로 n-1개의 탑을 다시 옮긴다.
    함수 f(n,st,ed,mid)는 n개의 하노이 탑이 st에서 mid를 거쳐 ed로 가는 이동 경로라고 할 때,
    f(n,st,ed,mid) = f(n-1,st,mid,ed) + move(st,ed) + f(n-1,mid,ed,st)가 될 것이다.
    이동 횟수를 세는 수열 A(n)에 대해서 위 점화식에 따라서 A(n) = 2*A(n-1) + 1이고 A(1) = 1이다.
    A(n) + 1 = 2*A(n-1) + 2 이고 B(n) = A(n) + 1이라고  하면 B(n)은 공비가 2이고 첫째항이 2인 등비수열이다.
    B(n) = 2**n 이므로 A(n) = 2**n - 1이다.
    
*/
#include <iostream>
#include <cmath>
using namespace std;
void move(int st, int ed) {
    cout << st << ' ' << ed << '\n';
}
void f(int n, int st, int ed, int mid) {
    if (n==0) return;
    f(n-1,st,mid,ed);
    move(st,ed);
    f(n-1,mid,ed,st);
}
int main() {
    int N;
    cin >> N;
    cout << (int) pow(2,N)-1 << '\n';
    f(N,1,3,2);
    return 0;
}