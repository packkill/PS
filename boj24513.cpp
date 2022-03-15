/*
    좀비 바이러스
    단순 bfs
    3번 바이러스 처리가 관건
    {바이러스 종류, 퍼진 시간대} 를 저장하는 배열로
    퍼진 시간대가 같으면 그 바이러스는 3번 바이러스로 바꾼다.
*/
#include <iostream>
#include <queue>
using namespace std;

typedef struct Virus{
    int x;
    int y;
    int type;
    int InfectTime;
}Virus;


int N,M;
int VirusType[1000][1000];
int InfectionTime[1000][1000];
bool visited[1000][1000];
int kx[] = {0,0,-1,1};
int ky[] = {-1,1,0,0};
queue <Virus> q;


bool IsInside(int x, int y);
void bfs();
void checkNum(int cnt[]);


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++){
            cin >> VirusType[i][j];
            
            if (VirusType[i][j] == -1) {
                visited[i][j] = true;
                InfectionTime[i][j] = -1;
            }

            if (VirusType[i][j] == 1 || VirusType[i][j] == 2) {
                q.push({i,j,VirusType[i][j],0});
            }
        }
    }

    bfs();

    int cnt[4] = {0};
    checkNum(cnt);
    cout << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3];

    return 0;
}
bool IsInside(int x, int y) {
    return (0<=x && x<N) && (0<=y && y<M);
}
void bfs() {

    while (!q.empty()) {
        Virus curV = q.front();
        q.pop();
        if (VirusType[curV.x][curV.y] == 3) continue;

        for (int i:{0,1,2,3}) {
            int dx = curV.x + kx[i];
            int dy = curV.y + ky[i];
            
            if (IsInside(dx,dy)) {
                if (visited[dx][dy] && (VirusType[dx][dy] == 1 || VirusType[dx][dy] == 2) ) {
                    if (VirusType[dx][dy] != curV.type && InfectionTime[dx][dy] == curV.InfectTime+1) {
                        VirusType[dx][dy] = 3;
                    }
                }
                if (!visited[dx][dy]) {
                    VirusType[dx][dy] = curV.type;
                    InfectionTime[dx][dy] = curV.InfectTime + 1;
                    visited[dx][dy] = true;
                    q.push({dx,dy,curV.type,curV.InfectTime+1});
                }
            }
        }
    }
}

void checkNum(int cnt[]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int x = VirusType[i][j];
            if (x == 1) cnt[1]++;
            if (x == 2) cnt[2]++;
            if (x == 3) cnt[3]++;
        }
    }
}