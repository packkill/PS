/*
    별 찍기 - 19
    2n+1 크기의 정사각형
    파이썬으로 숏코딩 1등먹었다 ㅎㅎ
*/

#include <iostream>
using namespace std;

int N, arr[201][201];

int main() {
    cin >> N;
    int MAX = 4*N-3;
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++)  {
            char c = (max(abs(i-MAX/2),abs(j-MAX/2))%2)? ' ':'*';
            cout << c;
        }
        cout << '\n';
    }
}