#include <bits/stdc++.h>

using namespace std;

int row, col, year = 0;
vector<vector<int>> iceMap;
vector<vector<int>> surface =
{
    { 1, 0}, {0,  1},
    {-1, 0}, {0, -1}
};

vector<vector<bool>>  visited;
vector<pair<int, int>> iceberg;

bool rangeCheck(int y, int x){
    return ((0 <= y) && (y < row)) && ((0 <= x) && (x < col));
}

void input(){
    cin >> row >> col;

    for(int i=0; i<row; i++){
        vector<int>  iceRow;
        vector<bool> visitedRow;

        for(int j=0; j<col; j++){
            int high;
            cin >> high;

            iceRow.push_back(high);
            visitedRow.push_back(false);

            if(high > 0) iceberg.push_back(pair<int,int>(i, j));
        }

        iceMap .push_back(iceRow);
        visited.push_back(visitedRow);
    }
}

void printIceSpot(){

    cout << endl <<"ice spot" << endl;

    for(auto ice: iceberg){
        cout << ice.second << " / " << ice.first << endl;
    }
}

void melting(int iceY, int iceX){

    if(iceMap.at(iceY).at(iceX) < 0) return;

    for(int i=0; i<surface.size(); i++){
        int adjY = iceY + surface.at(i).at(0);
        int adjX = iceX + surface.at(i).at(1);

        if(rangeCheck(adjY, adjX)){
            int adjIce = iceMap.at(adjY).at(adjX);

            if(adjIce <= 0 && adjIce > ((-1) * year) )
                iceMap.at(iceY).at(iceX) -= 1;
        }
    }

    if(iceMap.at(iceY).at(iceX) <= 0){
        iceMap.at(iceY).at(iceX) = -1 * year;
    }

    return;
}

void oneYear(){
    year++;

    for(int i=0; i < iceberg.size(); i++){
        pair<int, int> ice = iceberg.at(i);

        melting(ice.first, ice.second);
    }


    return ;
}

int DFS(int y, int x, int ibSize){

    visited.at(y).at(x) = true;

    for(int i=0; i<surface.size(); i++){
        int nextY = y + surface.at(i).at(0);
        int nextX = x + surface.at(i).at(1);

        if(rangeCheck(nextY, nextX))
            if(iceMap.at(nextY).at(nextX) > 0 && !visited.at(nextY).at(nextX))
                ibSize = DFS(nextY, nextX, ibSize+1);
    }

    visited.at(y).at(x) = false;

    return ibSize;
}

bool IBCheck(int ibSize){
    return ibSize < iceberg.size();
}

void output(){
    cout << year;
}


void printIceMap(){

    cout << endl;

    for(int i=0; i<iceMap.size(); i++){
        for(int j=0; j<iceMap.at(i).size(); j++){
            cout << iceMap.at(i).at(j) << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void run(){
    input();

    while(true){

        oneYear();

        //printIceMap();

        if(iceberg.empty()) break;

        pair<int, int> iceSpot = iceberg.front();

        int ibSize = DFS(iceSpot.first, iceSpot.second, 1);
        if(IBCheck(ibSize)) break;
    }

    output();
}



int main(){
    run();
    return 0;
}

