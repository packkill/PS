/*
    선 긋기
    스위핑이라는데 잘 모르겠다 아직.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

int N;
vector <pii> Point;

bool IsConnected(pii a, pii b) {
    return (b.first <= a.second);
}
int dist(pii a) {
    return a.second - a.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N--) {
        int x,y;
        cin >> x >> y;
        Point.push_back({x,y});
    }

    sort(Point.begin(),Point.end());

    pii tmp = Point[0];
    int ret = 0;

    for (int i=1; i<Point.size(); i++) {
        if (IsConnected(tmp,Point[i])) {
            //연결되어있으면 tmp를 계속 잇는다.
            tmp = {min(tmp.first,Point[i].first),max(tmp.second,Point[i].second)};
        } 
        else {
            //연결되어있지 않으면 tmp의 길이를 ret에 더하고, tmp를 새거로 바꾼다.
            ret += dist(tmp);
            tmp = Point[i];
        }
    }//마지막 tmp의 길이도 ret에 더한다.
    ret += dist(tmp);
    cout << ret;
    return 0;
}