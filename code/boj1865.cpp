/*
    웜홀
    벨만포드
    사이클 탐색
*/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int TC, N, M, W;
struct Edge {
    int st,ed,weight;
};
vector <Edge> graph;
int dist[501];


void init() {
    cin >> N >> M >> W;
    graph.clear();
    
    while (M--) {
        int st, ed, t;
        cin >> st >> ed >> t;
        graph.push_back({st,ed,t});
        graph.push_back({ed,st,t});
    }
    while (W--) {
        int st, ed, t;
        cin >> st >> ed >> t;
        graph.push_back({st,ed,-t});
    }
}


bool BellmanFord(int st) {
    fill(&dist[0],&dist[N+1],0); //https://www.acmicpc.net/board/view/72995
    //dist를 0으로 초기화하고 BellmanFord(1)만 해도 AC인 이유 위 링크에 있음.
    
    dist[st] = 0;

    for (int loop=1; loop<=N; loop++) {
        for (auto edge: graph) {
            int u = edge.st;
            int v = edge.ed;
            int w = edge.weight;

            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                if (loop == N) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool IsPossible() {//시간여행이 가능한가? 벨만포드가 하나라도 false인가?
    
    if (!BellmanFord(1)) return true;
    
    return false;
} 


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> TC;
    while (TC--) {
        init();
        if (IsPossible()) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}