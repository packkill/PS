/*
    객실 배치
    dp, 분할 정복, 10^18승
    A[i] = i01호에 사람이 있는 경우의수
    B[i] = i02호에 사람이 있는 경우의수
    C[i] = i층에 사람이 없는 경우의 수
    S[i] = i층까지의 모든 경우의수
    라고 하자.

    그렇다면 이때,
    (i-1)층에 사람이 없다면,
    A[i] = C[i-1], B[i] = C[i-1], C[i] = C[i-1]이다.
    i층에 사람이 있다면,
    A[i] = B[i-1], B[i] = A[i-1], C[i] = A[i-1] + B[i-1]이 된다.
    i층의 모든 경우의 수는 두 경우를 모두 고려한 것이므로,
    결국
    A[i] = B[i-1] + C[i-1]
    B[i] = A[i-1] + C[i-1]
    C[i] = A[i-1] + B[i-1] + C[i-1] = S[i-1]이다. (∵S = A+B+C)
    따라서 S[i] 
                = A[i] + B[i] + C[i] 
                = A[i-1] + B[i-1] + 2*C[i-1] + S[i-1] 
                = 2*S[i-1] + C[i-1] 
                = 2*S[i-1] + S[i-2]
    이다.
    점화식: S[i] = 2*S[i-1] + S[i-2]
    
    점화식을 구하고 Berlekamp-Massey(벌레켐프 매시) 알고리즘이니 키타마사법이니를 사용한다는데 잘 모르겠다 ㅠㅠ
    여기서 2가지 방식으로 갈 수 있다고 한다... 고수들이 그렇다고 한다. 나한테 조금 더 와닿는건 행렬.
    1. 행렬 거듭제곱
    위 점화식에 따라서

    A[i]   (0  1  1)   A[i-1]
    B[i] = (1  0  1) * B[i-1]
    C[i]   (1  1  1)   C[i-1]
    로 행렬 곱셈처럼 표현될 수 있다.
    즉
    A[N]   (0  1  1) ^(N-1)   A[1]
    B[N] = (1  0  1)        * B[1]
    C[N]   (1  1  1)          C[1]
    이다.

*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

struct Matrix {
    int size;
    vector <vector <long long> > A;

    Matrix(int N) {
        size = N;
        A = vector< vector <long long> > (N, vector<long long> (N));
    }
    long long sum() {
        long long ret = 0;
        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                ret = (ret + A[i][j]) % mod;
            }
        }
        return ret;
    }
    Matrix operator *(const Matrix& X) {
        Matrix ret(size);

        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                for (int k=0; k<size; k++) {
                    ret.A[i][j] += (A[i][k] * X.A[k][j]);
                    ret.A[i][j] %= mod;
                }
            }
        }
        return ret;
    }
};

Matrix power(Matrix m, long long exp) {
    if (exp == 1) return m;
    Matrix ret = power(m,exp/2);
    if (exp%2) return ret*ret*m;
    else return ret*ret;
}


int main() {
    long long N;
    cin >> N;

    Matrix ans(3);
    ans.A[0] = {0, 1, 1};
    ans.A[1] = {1, 0, 1};
    ans.A[2] = {1, 1, 1};
    if (N == 1) 
        cout << 3;
    else {
        Matrix ret = power(ans,N-1);
        cout << ret.sum();
    }

    return 0;
}