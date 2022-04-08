/*
    두 대표 자연수
    입력되는 배열의 크기는 500만이지만
    배열에 속하는 수들의 범위는 1에서 10000까지 밖에 안된다.
    따라서 숫자의 개수를 세는 배열로 문제를 풀면
    시간초과가 나지 않을 것이다. 
*/

#include <iostream>
using namespace std;
#define INF 1e18
int N;
long long arr[10001],list1[10001],list2[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    //input
    while (N--) {
        int x;
        cin >> x;
        arr[x]++;
    }
    long long min1 = INF, min2 = INF;
    for (int i=1; i<=10000; i++) {
        long long sum1=0, sum2=0;

        for (int j=1; j<=10000; j++) {
            sum1 += arr[j]*abs(j-i);
            sum2 += arr[j]*(j-i)*(j-i);
        }
        list1[i] = sum1;
        list2[i] = sum2;
        min1 = min(min1, sum1);
        min2 = min(min2, sum2);
    }

    for (int i=1; i<=10000; i++) {
        if (list1[i] == min1) {
            cout << i << ' ';
            break;
        }

    }
    for (int i=1; i<=10000; i++) {
        if (list2[i] == min2) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}