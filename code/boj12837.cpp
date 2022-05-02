/*
    가계부 (Hard)
    세그먼트 트리 기본
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, Q;
vector <ll> SegTree(4000000);

void update(int idx, int nodeSt, int nodeEd, int reqIdx, ll val) {

    if (nodeSt == nodeEd) SegTree[idx] += val;

    else {
        int nodeMid = (nodeSt + nodeEd)/2;
        if (reqIdx <= nodeMid) update(2*idx, nodeSt, nodeMid, reqIdx, val);
        else update(2*idx+1, nodeMid+1, nodeEd, reqIdx, val);
        SegTree[idx] = SegTree[2*idx] + SegTree[2*idx+1];
    }
}


ll query(int idx, int nodeSt, int nodeEd, int reqSt, int reqEd) {
     
    if (reqSt > nodeEd || reqEd < nodeSt) return 0;
    
    else if (reqSt <= nodeSt && nodeEd <= reqEd) return SegTree[idx];
    
    else {
        int nodeMid = (nodeSt + nodeEd)/2;
        long long lQuery = query(2*idx, nodeSt, nodeMid, reqSt, reqEd);
        long long rQuery = query(2*idx+1, nodeMid+1, nodeEd, reqSt, reqEd);
        return lQuery + rQuery;
    }
}



int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> Q;

    while (Q--) {
        int q, a, b;
        cin >> q >> a >> b;
        if (q == 1) update(1,0,N-1,a-1,b);
        else cout << query(1,0,N-1,a-1,b-1) << '\n';
    }
    return 0;
}