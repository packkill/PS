/*
   LCA 2
   최소 공통 조상 O(log n) 풀이
   parent를 2차원으로 두어
   parents[x][k] = x번 정점의 2^k번째 조상 노드의 번호
   이때 다음이 성립한다고 한다.
   parents[x][k] = parent[parnt[x][k-1]][k-1]
   https://4legs-study.tistory.com/121
   참고함.
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;
const int MAXLVL = (int) floor(log2(MAX));
int N, M, parents[MAX][20], level[MAX];
vector <int> Tree[MAX];

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
   
   for (int i=1; i<=MAXLVL; i++) {
      parents[node][i] = parents[parents[node][i-1]][i-1];
   }

   for (int i=0; i<Tree[node].size(); i++) {
      int child = Tree[node][i];
      if (child == pnode) continue;
      set_tree(child, node, lvl + 1);
   }
}

int main() {
   cin.tie(0)->sync_with_stdio(0);
   cin >> N;
   for (int i=0; i<N-1; i++) {
      int a,b;
      cin >> a >> b;
      Tree[a].push_back(b);
      Tree[b].push_back(a);
   }

   set_tree(1,0,1);

   cin >> M;

   while (M--) {
      int x,y;
      cin >> x >> y;
      cout << lca(x,y) << '\n';
   }
   return 0;
}