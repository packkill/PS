/*
    행렬 제곱
    제곱을 분할 정복으로 풀면 될거같다.
    Matrix라는 struct를 선언해서 *연산자 오버로딩을 써보았다.
*/

#include <iostream>
#include <vector>
using namespace std;
#define mod 1000
struct Matrix {
    int size;
    vector <vector <long long> > m;
    
    Matrix (int N) {
        size = N;
        m = vector <vector <long long>> (N,vector <long long> (N));
    }

    Matrix operator *(const Matrix& A) {
        Matrix ret(size);

        for (int i=0; i<size; i++) {
            for (int j=0; j<size; j++) {
                for (int k=0; k<size; k++) {
                    ret.m[i][j] += (m[i][k]*A.m[k][j]);
                    //파이썬으로 적음.
                    //C[i][j] = sum(A[i][k]*B[k][j] for k in range(N))
                }
                ret.m[i][j] %= mod;
            }
        }
        return ret;
    }
};

Matrix pow(Matrix M, long long exp) {
    if (exp == 1) return M;
    Matrix ret = pow(M,exp/2);
    if (exp % 2) return ret*ret*M;
    else return ret*ret;
}
int main() {
    int N;
    long long M;
    cin >> N >> M;
    Matrix arr(N);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            long long x;
            cin >> x;
            arr.m[i][j] = x%mod;
        }
    }

    Matrix ret = pow(arr,M);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << ret.m[i][j]%mod << ' ';
        }
        cout << '\n';
    }


    return 0;
}