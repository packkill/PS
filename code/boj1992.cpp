/*
    쿼드트리
    분할정복
*/

#include <iostream>
#include <string>
using namespace std;
int N;
char arr[65][65];
bool AllSame(int x, int y, int N) {
    for (int i=x; i<x+N; i++) {
        for (int j=y; j<y+N; j++) {
            if (arr[i][j] != arr[x][y]) {
                return false;
            }
        }
    }
    return true;
}
string solve(int x, int y, int N) {
    string ret;
    if (N == 1 || AllSame(x,y,N)) {
        ret = arr[x][y];
    }
    else {
        string a = solve(x, y, N/2);
        string b = solve(x, y+N/2, N/2);
        string c = solve(x+N/2, y, N/2);
        string d = solve(x+N/2, y+N/2, N/2);
        ret = "(" + a + b + c + d + ")";
    }
    return ret;
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    cout << solve(0,0,N);


    return 0;
}