/*
    연구소
    https://www.acmicpc.net/problem/14502
    대깨 완전탐색
    임의의 3점을 벽으로 설정 후 각각의 경우마다 bfs로 안전구역의 개수를 센다.
    for문이 너무 많을 것같아서 매크로로 했다. FORFOR은 덤.
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FOR(i,N) for (int i=0;i<N;i++)
#define FORFOR(i,j,N,M) FOR(i,N) FOR(j,M)
int N,M;
int board[9][9];
int kx[] = {0,0,-1,1};
int ky[] = {-1,1,0,0};

bool IsSame(int i1, int j1, int i2, int j2);
bool IsInside(int x, int y);
int test(int i1,int j1,int i2,int j2,int i3,int j3);
void bfs(int x,int y,int tmp[9][9], bool vst[9][9]);

int main() {
    cin >> N >> M;
    fill(&board[0][0], &board[7][8], -1);
    FOR(i,N) FOR(j,M) cin >> board[i][j];
    int ans = 0;
    FORFOR(i1,j1,N,M) {
        FORFOR(i2,j2,N,M) {
            FORFOR(i3,j3,N,M) {
                if (board[i1][j1]==0 && board[i2][j2]==0 && board[i3][j3]==0){
                    if (!IsSame(i1,j1,i2,j2)&&!IsSame(i2,j2,i3,j3)&&!IsSame(i3,j3,i1,j1)){
                        ans = max(ans,test(i1,j1,i2,j2,i3,j3));
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

bool IsSame(int i1, int j1, int i2, int j2) {
    return (i1==i2) &&(j1==j2);
}
bool IsInside(int x, int y) {
    return (0<=x && x<N) && (0<=y && y<M);
}   
int test(int i1,int j1,int i2,int j2,int i3,int j3) {
    int tmp[9][9];
    bool vst[9][9]={false};
    int cnt = 0;
    copy(&board[0][0],&board[0][0]+64,&tmp[0][0]);
    tmp[i1][j1] = tmp[i2][j2] = tmp[i3][j3] = 1;

    FORFOR(i,j,N,M) {
        if (!vst[i][j] && tmp[i][j] == 2) {
            vst[i][j] = true;
            bfs(i,j,tmp,vst);
        } 
    }

    FORFOR(i,j,N,M) {
        if (tmp[i][j]==0) cnt++;
    }
    return cnt;
}
void bfs(int x,int y,int tmp[9][9],bool vst[9][9]) {
    queue <pair <int,int>> q;
    q.push({x,y});

    while (!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        FOR(i,4) {
            int dx = now_x + kx[i];
            int dy = now_y + ky[i];
            if (IsInside(dx,dy) && tmp[dx][dy] == 0 && !vst[dx][dy]) {
                q.push({dx,dy});
                tmp[dx][dy] = 2;
                vst[dx][dy] = true;
            }
        }
    }
}