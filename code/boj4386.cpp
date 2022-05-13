/*
    별자리 만들기
    노드가 주어지면 그래프 만들기 -> 최소 스패닝 트리
*/

#include <bits/stdc++.h>
using namespace std;

struct vertax {
    double x;
    double y;
};

struct Edge {
    double dist;
    int st;
    int ed;
};

bool cmp(Edge a, Edge b) {
    return a.dist < b.dist;
}

double d(vertax a, vertax b) { //평면좌표 두 정점사이의 거리
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

vector <Edge> makeGraph(int N, vector <vertax> vList) { // 정점이 주어지면 그래프 만들기
    vector <Edge> graph;

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i == j) continue;
            else {
                double dist = d(vList[i],vList[j]);
                graph.push_back({dist,i,j});
            }
        }
    }

    return graph;
}

class UnionFind { // 유니온파인드 클래스 , MST에서 사용
    int size;
    vector <int> findParents;
public:
    UnionFind(int size) {
        this->size = size;
        findParents.resize(size);
        for (int i=0; i<size; i++) findParents[i] = i;
    }
    int find(int x) {
        if (findParents[x] == x) return x;
        return findParents[x] = find(findParents[x]);
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        findParents[b] = a;
    }
};

double MST(int N, vector <Edge> graph) { //graph의 MST 비용 계산
    double ret = 0;
    UnionFind U(N);

    sort(graph.begin(), graph.end(),cmp);
    for (int i=0; i<graph.size(); i++) {
        if (U.find(graph[i].st) != U.find(graph[i].ed)) {
            ret += graph[i].dist;
            U.merge(graph[i].st,graph[i].ed);
        }
    }
    return ret;
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int N;
    cin >> N;
    vector <vertax> vertaxList(N);
    for (int i=0; i<N; i++) {
        cin >> vertaxList[i].x >> vertaxList[i].y;
    }
    vector <Edge> graph = makeGraph(N, vertaxList);
    
    double ans = MST(N,graph);
    cout << ans;
    return 0;
}