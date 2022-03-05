/*
    영역 구하기
    주어진 좌표 내의 칸을 체크한후 bfs or dfs로 개수 구하기.
    그림에서는 왼쪽아래가 (0,0)이고 오른쪽위가 (M,N)이지만 상관없다.
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int bfs(int x, int y);
bool IsInside(int x, int y);
int N,M,K;
int arr[100][100];
int kx[] = {0,0,-1,1};
int ky[] = {-1,1,0,0};

int main() {
    cin >> N >> M >> K;

    while (K--) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i=x1; i<=x2-1; i++) {
            for (int j=y1; j<=y2-1; j++) {
                arr[j][i] = 1;
            }
        }
    }
    vector <int> area;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (!arr[i][j]) {
                int cnt = bfs(i,j);
                area.push_back(cnt);
            }
        }
    }
    sort(area.begin(),area.end());

    cout << area.size() << '\n';
    for (auto i:area) {
        cout << i << ' ';
    }
    return 0;
}
bool IsInside(int x, int y) {
    return 0<=x && x<N && 0<=y && y<M;
}
int bfs(int x, int y) {
    queue <pair<int,int>> q;
    q.push({x,y});
    int cnt = 1;
    arr[x][y] = 1;
    while (!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int dx = now_x + kx[i];
            int dy = now_y + ky[i];
            if (IsInside(dx,dy) && !arr[dx][dy]) {
                cnt++;
                arr[dx][dy] = 1;
                q.push({dx,dy});
            }
        }
    }
    return cnt;
}