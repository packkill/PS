/*
    본대 산책 2
    주어진 그림을 인접행렬로 표현한 후 제곱하는 문제
    왜 제곱하는지는 여백이 부족해 남기지 않는다...
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

struct Matrix {
    int N;
    vector<vector<ll>> A;
    Matrix(int N) {
        this->N = N;
        this->A = vector <vector<ll>> (N,vector <ll> (N));
    }
    Matrix operator *(const Matrix& X){
        Matrix ret(N);
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                for (int k=0; k<N; k++) {
                    ret.A[i][j] += (A[i][k]*X.A[k][j]);
                }
                ret.A[i][j] %= mod;
            }
        }
        return ret; 
    }
};

Matrix pow(Matrix M, ll exp) {
    if (exp == 1) return M;
    Matrix ret = pow(M,exp/2);
    if (exp % 2) return ret*ret*M;
    else return ret*ret;
}

int main() {
    ll N;
    cin >> N;
    Matrix mat(8);
    mat.A = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0},
    };
    Matrix ret = pow(mat,N);
    cout << ret.A[0][0]%mod << '\n';
    return 0;
}