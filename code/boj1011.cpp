/*
    Fly me to the Alpha Centauri
    이전에 k광년을 이동했을 경우 k-1, k, k+1 광년 이동 가능
    처음에는 bfs문제 같았지만 숫자가 2**31까지 있으므로 시간 초과가 남.
    이동 횟수에 따른 최대 이동거리
    이동 횟수 총거리 이동 방법  
    1          1       1
    2          2       11
    3          4       121
    4          6       1221
    5          9       12321
    6          12      123321
    7          16      1234321
    총거리가 제곱수일 때 이동횟수가 바뀜
    i*i와 (i+1)*(i+1) 사이의 거리에서 i*i + i 의 거리일 때 이동 횟수가 바뀜
    
    i를 1에서부터 늘려가면서  d<= i*i 이면 2*i-1,  i*i < d <= i*i + i 이면 2*i

    d가 최대일 때의 i 값은 92681이므로 for문에서 i를 93000까지 설정한다.
*/
#include <iostream>

using namespace std;
long long f(long long n) { 
    for (long long i=1; i<93000;i++) {
        if (n <= i*i) return 2*i-1;
        else if (n <=i*i + i) return 2*i;
    }
    return 0;
}
int main() {
    long long T,x,y;
    cin >> T;
    while (T--) {
        cin >> x >> y;
        cout << f(y-x) << '\n';
    }
    return 0;
}