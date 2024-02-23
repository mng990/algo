#include<bits/stdc++.h>

using namespace std;

int row, col, ice, melted, age = 0;
int visited[301][301] = {0,};
bool connect = true;

vector<vector<int>> iceMap;
queue<pair<int,int>> iceQue;
vector<pair<int,int>> iceberg;
vector<vector<int>> adj = {
    { 1, 0}, {0,  1},
    {-1, 0}, {0, -1}
};


void input(){
    cin >> row >> col;

    for(int i=0; i<row; i++){
        vector<int>  iceRow;

        for(int j=0; j<col; j++){
            int high;
            cin >> high;

            iceRow.push_back(high);
        }
        iceMap .push_back(iceRow);
    }

}

bool rangeCheck(int y, int x){
    return (0 <= y && y < row) && (0 <= x && x < col);
}

void melt(int y, int x){
    if(iceMap[y][x] > 0){
        iceMap[y][x]--;

        if(iceMap[y][x] == 0){
            melted++;
        }
    }
}

void printIceMap(){
    cout << "Year: " << age <<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            cout << iceMap.at(i).at(j) << " ";

        cout << endl;
    }
}

void printVisited(){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            cout << visited[i][j] << " ";

        cout << endl;
    }
}

pair<int,int> getIBStart(){
    for(int i=0; i<iceberg.size();i++){
        pair<int,int> now = iceberg.at(i);

        if(iceMap.at(now.first).at(now.second) == 0)
            continue;
        else
            return now;
    }

    return pair<int,int>(-1,-1);
}

int DFS(pair<int,int> IBStart, int IBSize){
    int IBY = IBStart.first;
    int IBX = IBStart.second;

    visited[IBY][IBX]--;


    if(iceMap.at(IBY).at(IBX) == 0) return IBSize-1;


    for(int i=0; i<adj.size(); i++){
        int adjY = IBY + adj.at(i).at(0);
        int adjX = IBX + adj.at(i).at(1);

        if(rangeCheck(adjY, adjX)){
            if(visited[adjY][adjX] > age){
                IBSize =  max(IBSize, DFS(pair<int,int>(adjY, adjX), IBSize+1));

            }
        }
    }

    return IBSize;
}

void years(){

    while(1){
        int startY = 0, startX = 0;

        age++;
        visited[startY][startX] = age;

        for(int i=0; i<adj.size(); i++){
            int nextY = startY + adj.at(i).at(0);
            int nextX = startX + adj.at(i).at(1);

            if(rangeCheck(nextY, nextX)){
                int nextIce = iceMap[nextY][nextX];

                if(visited[nextY][nextX] < age){
                    pair<int,int> next(nextY, nextX);

                    iceQue.push(next);
                    visited[nextY][nextX] = age;

                    if(nextIce >0){
                        visited[nextY][nextX]++;
                        iceberg.push_back(next);
                    }
                }
            }
        }

        pair<int,int> now;
        melted = 0;

        while(!iceQue.empty()){


            pair<int, int> now = iceQue.front();

            int nowY  = now.first , nowX = now.second;
            int nowIce = iceMap[nowY][nowX];


            for(int i=0; i<adj.size(); i++){
                int nextY = nowY + adj.at(i).at(0);
                int nextX = nowX + adj.at(i).at(1);

                if(rangeCheck(nextY, nextX)){
                    int nextIce = iceMap[nextY][nextX];

                    if(visited[nextY][nextX] < age){
                        pair<int,int> next(nextY, nextX);
                        iceQue.push(next);

                        visited[nextY][nextX] = age;

                        if(nextIce >0){
                            visited[nextY][nextX]++;
                            iceberg.push_back(next);
                        }
                    }

                    if(nextIce == 0 && visited[nextY][nextX] <= age) melt(nowY, nowX);
                }
            }

            iceQue.pop();
        }



        pair<int, int> IBS = getIBStart();

        if(IBS.first == -1 && IBS.second == -1){
            iceberg.clear();
            return ;
        }

        int ibsize = DFS(IBS,1);
        int wholeIB = iceberg.size() - melted;

        if(wholeIB != ibsize){
            return;
        }

        //printIceMap();
        //printVisited();

        iceberg.clear();
    }
}






void output(){
    if(iceberg.empty()) cout << 0 << endl;
    else                 cout << age << endl;
}

void run(){
    input();
    years();
    output();
}

int main(){
    run();
    return 0;
}
