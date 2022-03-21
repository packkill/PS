/*
    하이퍼 토마토
    bfs문제
    11차원으로 하다가 실패 -> 1차원 시도 -> 크게 실패
    다시 11차원으로 함.
    11차원이 직관적인 bfs 풀이가 가능함.
    그리고 계속 13퍼센트에서 틀렸습니다가 떴는데, 
    입력에서만 for문을 거꾸로하는게 아니라
    max값을 찾을때나 다를때도 for문을 거꾸로 해야했다...
*/
#include <iostream>
#include <queue>
using namespace std;
#define FOR(i,N) for (int i=0; i<N; i++)

typedef struct T11{
    int M,N,O,P,Q,R,S,T,U,V,W;
}T11;

T11 dt[22] = {
    {1,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,1},

    {-1,0,0,0,0,0,0,0,0,0,0},
    {0,-1,0,0,0,0,0,0,0,0,0},
    {0,0,-1,0,0,0,0,0,0,0,0},
    {0,0,0,-1,0,0,0,0,0,0,0},
    {0,0,0,0,-1,0,0,0,0,0,0},
    {0,0,0,0,0,-1,0,0,0,0,0},
    {0,0,0,0,0,0,-1,0,0,0,0},
    {0,0,0,0,0,0,0,-1,0,0,0},
    {0,0,0,0,0,0,0,0,-1,0,0},
    {0,0,0,0,0,0,0,0,0,-1,0},
    {0,0,0,0,0,0,0,0,0,0,-1}
};
int M,N,O,P,Q,R,S,T,U,V,W;

bool IsInside(T11 t);

int main() {
    ios::sync_with_stdio(0); cin.tie(0); 
    cin >> M >> N >> O >> P >> Q >> R >> S >> T >> U >> V >> W;

    int arr[M][N][O][P][Q][R][S][T][U][V][W];
    bool visited[M][N][O][P][Q][R][S][T][U][V][W];
    int distance[M][N][O][P][Q][R][S][T][U][V][W];

    queue <pair<T11,int>> q;
    
    int MAX = M*N*O*P*Q*R*S*T*U*V*W;
    int Wcnt = 0, Tcnt = 0, Ecnt = 0;

    FOR(k,W) FOR(j,V) FOR(i,U) FOR(h,T) FOR(g,S) FOR(f,R) FOR(e,Q) FOR(d,P) FOR(c,O) FOR(b,N) FOR(a,M) {
        int x;
        cin >> x;
        arr[a][b][c][d][e][f][g][h][i][j][k] = x;
        visited[a][b][c][d][e][f][g][h][i][j][k] = false;
        distance[a][b][c][d][e][f][g][h][i][j][k] = 0;
        if (x == 1) {
            T11 ST = {a,b,c,d,e,f,g,h,i,j,k};
            q.push({ST,0});
            visited[a][b][c][d][e][f][g][h][i][j][k] = true;
            Tcnt++;
        }
        if (x == 0) {
            Ecnt++;
        }
        if (x == -1) Wcnt++;
    }
    
    //bfs

    while (!q.empty()) {
        T11 now = q.front().first;
        int dist = q.front().second;
        q.pop();
        /*
        
        cout << "dist\n";
        FOR(k,W) FOR(j,V) FOR(i,U) FOR(h,T) FOR(g,S) FOR(f,R) FOR(e,Q) FOR(d,P) FOR(c,O) FOR(b,N) FOR(a,M) cout << distance[a][b][c][d][e][f][g][h][i][j][k] <<' ';
        cout << '\n';
        
        */
        for (int i=0; i<22; i++) {
            T11 next = {now.M+dt[i].M, now.N+dt[i].N, now.O+dt[i].O, now.P+dt[i].P, now.Q+dt[i].Q, now.R+dt[i].R, now.S+dt[i].S, now.T+dt[i].T,now.U+dt[i].U,now.V+dt[i].V,now.W+dt[i].W};
            if (IsInside(next) && !visited[next.M][next.N][next.O][next.P][next.Q][next.R][next.S][next.T][next.U][next.V][next.W]) {
                if (arr[next.M][next.N][next.O][next.P][next.Q][next.R][next.S][next.T][next.U][next.V][next.W] == 0) {
                    //cout << "next: " << next.M << ' ' << next.N << ' ' << next.O << '\n';
                        
                    distance[next.M][next.N][next.O][next.P][next.Q][next.R][next.S][next.T][next.U][next.V][next.W] = dist+1;
                    visited[next.M][next.N][next.O][next.P][next.Q][next.R][next.S][next.T][next.U][next.V][next.W] = true;
                    arr[next.M][next.N][next.O][next.P][next.Q][next.R][next.S][next.T][next.U][next.V][next.W] = 1;
                
                    q.push({next,dist+1});
                }
            }
        }
    }

    //ouput
    
    if (Wcnt == MAX) cout << -1;
    else if (Wcnt+Ecnt == MAX) cout << -1;
    else if (Wcnt+Tcnt == MAX) cout << 0;
    else {
        bool NotAllRiped = false;
    
        FOR(k,W) FOR(j,V) FOR(i,U) FOR(h,T) FOR(g,S) FOR(f,R) FOR(e,Q) FOR(d,P) FOR(c,O) FOR(b,N) FOR(a,M) {
            if (arr[a][b][c][d][e][f][g][h][i][j][k] == 0) NotAllRiped = true;
        }

        if (NotAllRiped) cout << -1 << '\n';

        else {
            int ans = 0;
            //max(distance)
            FOR(k,W) FOR(j,V) FOR(i,U) FOR(h,T) FOR(g,S) FOR(f,R) FOR(e,Q) FOR(d,P) FOR(c,O) FOR(b,N) FOR(a,M) ans = max(ans,distance[a][b][c][d][e][f][g][h][i][j][k]);
            cout << ans;
        }
    }
    return 0;
}

bool IsInside(T11 t) {
    return (0<=t.M && t.M<M) && (0<=t.N && t.N<N) && (0<=t.O && t.O<O) && (0<=t.P && t.P<P) && (0<=t.Q && t.Q<Q) && (0<=t.R && t.R<R) && (0<=t.S && t.S<S) && (0<=t.T && t.T<T) && (0<=t.U && t.U<U) &&(0<=t.V && t.V<V) && (0<=t.W && t.W<W);
}