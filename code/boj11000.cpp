/*
    강의실 배정
    그리디
    *구하고자 하는 것을 그리디로*
    강의실의 개수를 구해야 하므로 강의실에 대한 그리디를 진행
    어떤 수업이 있을 때, 이 수업을 어느 강의실에 할당하는것이 가장 좋을까?
    -> 수업이 가장 빨리 끝나는 강의실에 할당해야함.
    수업이 가장 빨리 끝나는 강의실을 어떻게 알것인가?
    -> 값을 넣을때마다 최대나 최소를 log만에
    -> 우선순위 큐
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int N;
int cnt = 0;
priority_queue <int, vector<int>, greater<int> > room;
vector <pii> Class;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int st, ed;
    for (int i=0; i<N; i++) {
        cin >> st >> ed;
        Class.push_back({st,ed});
    }
    sort(Class.begin(),Class.end());
    room.push(0);
    for (pii c : Class) {
        //가장 끝난시간이 이른 강의실에 수업을 넣을 수 있는 경우
        if (room.top() <= c.first) {
            //그 강의실에 수업을 추가
            //강의실의 끝나는 시간을 갱신
            room.pop();
            room.push(c.first);
        }
        //가장 빨리 끝나는 강의실과 겹친다면 나머지도 모두 겹치게 된다.
        else {
            room.push(c.first);
        }
    }

    cout << room.size() << '\n';
    return 0;
}