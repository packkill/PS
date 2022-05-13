/*
    본대 산책 3
    본대 산책 2는 정점과 간선이 고정이였다면 이 문제는 입력으로 주어진다.
    나머지는 똑같다. 객꿀
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
                    ret.A[i][j] %= mod;
                }
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
    int N,M;
    cin >> N >> M;
    Matrix mat(N);
    while (M--) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        mat.A[a][b] = 1;
        mat.A[b][a] = 1;
    }
    ll D;
    cin >> D;
    Matrix ret = pow(mat,D);
    cout << ret.A[0][0]%mod << '\n';
    return 0;
}