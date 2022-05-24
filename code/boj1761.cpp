/*
   정점들의 거리
   LCA
   dist배열을 추가
   dist[n] = n번째 node와 루트node사이의 거리
   두 정점a,b간의 거리
   = d(a,lcaNode) + d(lcaNode,b)
   = dist[a] - dist[lcaNode] + dist[b] - dist[lcaNode]
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;
const int MAXLVL = (int) floor(log2(MAX));
int N, M, parents[MAX][20], level[MAX], dist[MAX];
vector <pair<int,int>> Tree[MAX];

int lca(int a, int b) {
   //a의 레벨이 더 크도록
   int target = a, cmp = b;
   if (level[a] < level[b]) swap(target,cmp);

   //level 같게 만들기
   if (level[target] != level[cmp]) {
      //레벨이 다르다면
      for (int i = MAXLVL; i>=0; i--) { // 위에서부터
         //lvl 비교
         if (level[parents[target][i]] >= level[cmp]) {
            //결국 lvl이 같아질때까지 16,8,4,2씩 줄어들면서 체크
            target = parents[target][i];
         }
      }
   }

   //거슬러 올라가기
   int ret = target;
   if (target != cmp) {
      for (int i= MAXLVL; i>=0; i--) {
         //공통조상 찾기
         //못찾았으면 둘다 올라가기
         if (parents[target][i] != parents[cmp][i]) {
            target = parents[target][i];
            cmp = parents[cmp][i];
         }
         ret = parents[target][i];
      }

   }

   return ret;
}
void set_tree(int node, int pnode, int lvl) {
   //DFS로 트리 구성
   level[node] = lvl;
   parents[node][0] = pnode;
   //현재 노드에서 루트노드까지의 거리

   for (int i=1; i<=MAXLVL; i++) {
      parents[node][i] = parents[parents[node][i-1]][i-1];
   }

   for (int i=0; i<Tree[node].size(); i++) {
      int child = Tree[node][i].first;
      if (child == pnode) continue;
      //중복 방지를 위해 continue 뒤에
      dist[child] = dist[node] + Tree[node][i].second;
      set_tree(child, node, lvl + 1);
   }
}

int main() {
   cin.tie(0)->sync_with_stdio(0);
   cin >> N;
   for (int i=0; i<N-1; i++) {
      int a,b,c;
      cin >> a >> b >> c;
      Tree[a].push_back({b,c});
      Tree[b].push_back({a,c});
   }

   set_tree(1,0,1);
   
   cin >> M;

   while (M--) {
      int x,y;
      cin >> x >> y;
      int lcaNode = lca(x,y);
      int dist1 = dist[x] - dist[lcaNode];
      int dist2 = dist[y] - dist[lcaNode];
      int ans = dist1 + dist2;
      cout << ans << '\n';
   }
   return 0;
}