/*
    가장 가까운 두 점
    왼쪽 오른쪽 중간으로 분할 정복
    참고한 사이트: https://cantcoding.tistory.com/32
    중간에서 최적화 -> y기준으로 정렬해서 탐색
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
typedef pair<int,int> pii;


int N;
vector <pii> Point;

int square(int x) {return x*x;}
int dist(pii a, pii b) {
    return square(b.second-a.second)+square(b.first-a.first);
}
bool cmp_y(pii a, pii b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int Solve(int st, int ed) { // [st,ed]의 최소거리

    if (ed-st == 0) return INF;
    else if (ed-st == 1) return dist(Point[st],Point[ed]);

    int mid = (st+ed)/2;
    //분할 정복
    int leftD = Solve(st, mid);
    int rightD = Solve(mid, ed);
    int ret = min(leftD,rightD);

    vector <pii> cand;
    for (int i=st; i<=ed; i++) {
        if (square(Point[i].first-Point[mid].first) <= ret) {
            //(x좌표의 차)**2 < ret -> 후보에 넣기
            cand.push_back(Point[i]);
        }
    }
    //y의 범위가 ret인것만 탐색
    sort(cand.begin(),cand.end(),cmp_y);
    int len = cand.size();
    for (int i=0; i<len; i++) {
        for (int j=i+1; j<len && (square(cand[i].second-cand[j].second) < ret); j++) {
            ret = min(ret, dist(cand[i],cand[j]));
        }
    }
    return ret;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        int x,y;
        cin >> x >> y;
        Point.push_back({x,y});
    }
    sort(Point.begin(),Point.end());
    cout << Solve(0,N-1);
    return 0;
}