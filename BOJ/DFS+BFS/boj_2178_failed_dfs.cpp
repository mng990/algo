#include <bits/stdc++.h>

using namespace std;

int row, col;
int minCost = INT_MAX, cost = 0;

queue<pair<int, int>> path;
vector<vector<bool>> DP;
vector<vector<int>> maze;
vector<vector<int>> moveTo = {
    {  0, 1}, { 1, 0},
    { -1, 0}, { 0, -1}
};

bool rangeCheck(int y, int x){
    return ((0 <= x) && (x < col)) && ((0 <= y) && (y < row));
}

void input(){
    int enable;
    string strInput;

    cin >> row >> col;

    for(int i=0; i<row; i++){
        vector<int > vrow;
        vector<bool> drow;

        cin >> strInput;

        for(int j=0; j<col; j++){
            vrow.push_back(strInput.at(j) - '0');
            drow.push_back(false);
        }

        maze.push_back(vrow);
        DP.push_back(drow);
    }
}


void DFS(int ny, int nx){
    if(DP   .at(ny).at(nx)) return;
    if(!maze.at(ny).at(nx)) return;

    cost++;
    DP.at(ny).at(nx) = true;

    //cout << "now: " << nx << "," << ny << endl;

    if(ny == (row-1) && nx == (col-1)){
        minCost = min(minCost, cost);
    }

    for(int i=0; i<moveTo.size(); i++){
        int nextY = ny + moveTo.at(i).at(0);
        int nextX = nx + moveTo.at(i).at(1);

        if(rangeCheck(nextY, nextX)){
            DFS(nextY, nextX);
        }
    }

    DP.at(ny).at(nx) = false;
    cost--;

    return ;
}

void BFS(int startY, startX){
    DP.at(startY, startX) = true;
    path.push(pair<int>(startY, startX));


    for(int i=0; i<moveTo.size(); i++){
        int nextY = moveTo.at(i).at(0);
        int nextX = moveTo.at(i).at(1);

        if(rangeCheck(nextY, nextX) && !DP.at(nextY, nextX)){
            if(maze.at(nextY).at(nextX)){
                    path.push(pair<int>(nextY, nextX));
                    DP.at(nextY).at(nextX) = true;
            }
        }
    }

    cost++;
    path.pop();


    while(!path.empty()){
        pair<int, int> now = path.front();

        for(int i=0; i<moveTo.size(); i++){
            int nextY = moveTo.at(i).at(0);
            int nextX = moveTo.at(i).at(1);

            if(rangeCheck(nextY, nextX) && !DP.at(nextY, nextX)){
                if(maze.at(nextY).at(nextX)){
                    path.push(pair<int>(nextY, nextX));
                    DP.at(nextY).at(nextX) = true;
                }
            }
        }
        cost++;
        path.pop();

        if(now.first == row-1 && now.second == col-1){
            minCost = cost;
            break;
        }

        cost--;
    }

    cost--;
}

int main(){
    input();
    DFS(0,0);
    cout << minCost;
    return 0;
}
