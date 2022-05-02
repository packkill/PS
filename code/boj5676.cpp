/*
    음주 코딩
    점 갱신
    구간 쿼리(구간 곱셈)
    -> 세그트리
*/

#include <iostream>
#include <vector>
using namespace std;

int init(vector<int> &SegTree, int N, int arr[], int node, int st, int ed) {
    if (st == ed) {
        return SegTree[node] = arr[st];
    }
    int mid = (st + ed)/2;
    int left = init(SegTree,N,arr,2*node,st,mid);
    int right = init(SegTree,N,arr,2*node+1,mid+1,ed);
    return SegTree[node] = left * right;
}

void update(vector<int> &SegTree,int N, int arr[],int node, int st, int ed, int reqIdx, int val) {
    int mid = (st + ed)/2;

    if (st == ed) SegTree[node] = val;
    else {
        if (reqIdx <= mid) update(SegTree,N,arr,2*node,st,mid,reqIdx,val);

        else update(SegTree,N,arr,2*node+1,mid+1,ed,reqIdx,val);

        SegTree[node] = SegTree[2*node] * SegTree[2*node+1];
    }
}
//st ed 시작 끝 인덱스
//left right 구하고자하는 구간의 범위 (안 변함.)
int query(vector <int> &SegTree, int N, int arr[], int node, int st, int ed, int left, int right) {
    int mid = (st + ed)/2;

    if (right < st || ed < left) return 1;

    else if (left <= st && ed <= right) return SegTree[node];

    else {
        int l = query(SegTree,N,arr,2*node,st,mid,left,right);
        int r = query(SegTree,N,arr,2*node+1,mid+1,ed,left,right);

        return l*r; 
    }
}
void solve(int N, int K) {

    int arr[N];
    vector <int> SegTree(4*N);

    for (int i=0; i<N; i++){
        int x;
        cin >> x;
        arr[i] = x? abs(x)/x:0;
    }

    init(SegTree,N,arr,1,0,N-1);

    while (K--) {
        char q;
        int a, b;
        cin >> q >> a >> b;

        if (q == 'C') {
            b = b? abs(b)/b : 0;
            update(SegTree, N, arr, 1, 0, N-1, a-1, b);
        }
        if (q == 'P') {
            int ans = query(SegTree,N, arr, 1, 0, N-1, a-1, b-1);
            if (ans > 0 ) cout << '+';
            else if (ans == 0) cout << '0';
            else cout << '-';
        }
    }
    cout << '\n';

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;

    while (cin >> N >> K) {
        solve(N,K);
    }
    
    return 0;
}