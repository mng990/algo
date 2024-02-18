#include <bits/stdc++.h>

using namespace std;

bool goal = false;
int row, col, ans = 0;
vector<vector<int>> Map;
queue<pair<int,int>> queDot;
queue<pair<int,int>> queAns;
vector<vector<int>> moveTo =
{
    {0,  1}, { 1, 0},
    {0, -1}, {-1, 0}
};

bool visited[500][500] = {false,};
int DP[500][500] = {-1,};

bool rangeCheck(int y, int x){
    return (0 <= y && y < row) && (0 <= x && x < col);
}


void printDP(){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << DP[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int DFS(int y, int x){

    int now = Map.at(y).at(x);

    if(DP[y][x] != -1)
        return DP[y][x];

    DP[y][x] = 0;

    if(y == row-1 && x == col-1)
        return DP[y][x]+=1;


    for(int i=0; i<moveTo.size(); i++){
        int nextY = y + moveTo.at(i).at(0);
        int nextX = x + moveTo.at(i).at(1);

        if(rangeCheck(nextY, nextX)){
            int next = Map.at(nextY).at(nextX);

            if(now > next)
                DP[y][x] += DFS(nextY, nextX);
        }
    }

    //printDP();

    return DP[y][x];
}


void input(){
    cin >> row >> col;

    for(int i=0; i<row; i++){
        vector<int> mapRow;

        for(int j=0; j<col; j++){
            int high;
            cin >> high;
            mapRow.push_back(high);
            DP[i][j] = -1;
        }

        Map.push_back(mapRow);
    }
}

void output(){
    cout << DP[0][0] << endl;
}

void run(){
    input();
    DFS(0,0);
    output();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run();

    return 0;
}

