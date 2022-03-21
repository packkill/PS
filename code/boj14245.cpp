/*
    XOR
    구간 갱신 점 쿼리
    레이지 세그
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<long long> vll;

void init(vll &arr, vll &SegTree, int node, int st, int ed){
    if (st == ed) SegTree[node] = arr[st];
    else {
        int mid = (st+ed)/2;
        init(arr,SegTree,2*node,st,mid);
        init(arr,SegTree,2*node+1,mid+1,ed);
        SegTree[node] = SegTree[2*node] ^ SegTree[2*node+1];
    }
}

void update_lazy(vll &SegTree, vll &lazy, int node, int st, int ed) {
    if (lazy[node] != 0) {
        SegTree[node] ^= ( (ed-st+1)%2 )*lazy[node];
        if (st != ed) {
            lazy[2*node] ^= lazy[node];
            lazy[2*node+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(vll &SegTree, vll &lazy, int node, int st, int ed, int left, int right, long long val) {
    update_lazy(SegTree, lazy, node, st, ed);
    if (left > ed || right < st) return; // out of bound

    if (left <= st && ed <= right) {
        SegTree[node] ^= ((ed-st+1)%2)*val;
        if (st != ed) {
            lazy[2*node] ^= val;
            lazy[2*node+1] ^= val;
        }
        return;
    }
    int mid = (st+ed)/2;
    update_range(SegTree,lazy,2*node,st,mid,left,right,val);
    update_range(SegTree,lazy,2*node+1,mid+1,ed,left,right,val);
    SegTree[node] = SegTree[2*node] ^ SegTree[2*node+1];
}

long long query(vll &SegTree, vll &lazy, int node, int st, int ed, int left, int right) {
    update_lazy(SegTree, lazy, node, st, ed);
    if (left > ed || right < st) return 0;

    if (left <= st && ed <= right) return SegTree[node];
    int mid = (st+ed)/2;
    long long lquery = query(SegTree,lazy,2*node,st,mid,left,right);
    long long rquery = query(SegTree,lazy,2*node+1,mid+1,ed,left,right);

    return lquery ^ rquery;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin >> N;
    vll arr(N);
    vll SegTree(4*N);
    vll lazy(4*N);
    for (int i=0; i<N; i++) cin >> arr[i];
    init(arr,SegTree,1,0,N-1);
    cin >> M;
    while (M--) {
        int q,a,b,c;
        cin >> q;

        if (q == 1) {
            cin >> a >> b >> c;
            update_range(SegTree,lazy,1,0,N-1,a,b,c);
        }
        if (q == 2){
            cin >> a;
            cout << query(SegTree,lazy,1,0,N-1,a,a) << '\n';
        }
    }


    return 0;
}