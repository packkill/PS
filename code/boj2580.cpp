/*
    스도쿠
    백트래킹
    찾다가 알게 되었는데 모든 경우를 탐색하는 것이 아니라
    for (int i=idx; i<zeroList.size(); i++)
    왼쪽 위부터 탐색하면서 가능한 수를 집어넣는것이라고 한다.
    
*/

#include <iostream>
#include <vector>
using namespace std;

//int arr[9][9] = {0};
vector<vector<int> > sdoku(9,vector<int>(9,0));
vector <pair <int,int> > zeroList;
bool flag = false;

void printSdoku();
void backtrackDfs(int idx);
bool IsPossible(int x, int y, int num);


int main() {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++){
            cin >> sdoku[i][j];
            if (!sdoku[i][j]) 
                zeroList.push_back({i,j});
        }
    }
    cout << '\n';

    backtrackDfs(0);
    
    return 0;
}

void printSdoku() {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) 
            cout << sdoku[i][j] << ' ';
        cout << '\n';
    }
}

bool IsPossible(int x, int y, int num) {
    for (int i=0; i<9; i++) {
        if (sdoku[x][i] == num) return false;
        if (sdoku[i][y] == num) return false;
    }

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            int dx = x/3*3+i;
            int dy = y/3*3+j;
            if (sdoku[dx][dy] == num) return false;
        }
    }
    return true;
}

void backtrackDfs(int idx) {
    if (idx == zeroList.size()) {
        printSdoku();
        flag = true;
        return;
    }
    if (flag) return;

    int x = zeroList[idx].first;
    int y = zeroList[idx].second;
    for (int num = 1; num <10; num++) {
        if (IsPossible(x,y,num)) {
            sdoku[x][y] = num;
            backtrackDfs(idx+1);
            sdoku[x][y] = 0;
        }
    }
    return;
}