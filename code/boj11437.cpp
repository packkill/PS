/*
   LCA
   최소 공통 조상 O(n) 풀이
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 50001;
int N, M, parents[MAX], level[MAX];
vector <int> Tree[MAX];

int lca(int a, int b) {
   //a의 레벨이 더 크도록
   if (level[a] < level[b]) swap(a,b);

   //level 같게 만들기
   while (level[a] != level[b]) {
      a = parents[a];
   }

   //거슬러 올라가기
   while (a != b) {
      a = parents[a];
      b = parents[b];
   }

   return a;
}
void set_tree(int node, int pnode) {
   //DFS로 트리 구성

   parents[node] = pnode;
   level[node] = level[pnode] + 1;

   for (int i=0; i<Tree[node].size(); i++) {
      int child = Tree[node][i];
      if (child == pnode) continue;
      set_tree(child, node);
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

   set_tree(1,0);

   cin >> M;

   while (M--) {
      int x,y;
      cin >> x >> y;
      cout << lca(x,y) << '\n';
   }
   return 0;
}