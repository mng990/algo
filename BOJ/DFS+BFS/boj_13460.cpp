#include<bits/stdc++.h>

using namespace std;

bool red = false, blue = false;
int row, col, L, minCnt = -1;
vector<vector<char>> board;
vector<vector<int>> moveTo = {
    { 1, 0}, {0,  1},
    {-1, 0}, {0, -1}
}; // down, right, up, left

vector<int> R, B; // (RY, RX, cnt), (BY, BX, cnt)
queue<vector<vector<int>>> quePath;

int visited[10][10][10][10] = {0,};
// 2*N*M (x) N*M*N*M


void input(){
    cin >> row >> col;

    for(int i=0; i<row; i++){
        vector<char> bRow;
        for(int j=0; j<col; j++){
            char mark;
            cin >> mark;

            if(mark == 'R'){
                R = vector<int>({i, j, 0});
            }
            if(mark == 'B'){
                B = vector<int>({i, j, 0});
            }

            bRow.push_back(mark);
        }
        board.push_back(bRow);
    }
}

bool goalCheck(vector<int> marble, int dir){

    marble.at(0) += moveTo.at(dir).at(0);
    marble.at(1) += moveTo.at(dir).at(1);

    return board.at(marble.at(0)).at(marble.at(1)) == 'O';
}

bool blocked(vector<int> marble){
    return board.at(marble.at(0)).at(marble.at(1)) != '.';
}

bool rangeCheck(int y, int x){
    return (0 <= y && y < row) && (x <= 0 && x < col);
}

void printBoard(){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << board.at(i).at(j);
        }
        cout<<endl;
    }
    cout << endl;

}

bool moveToMarble(vector<int>& marble, int dir, char color){
    bool blockedM = false;
    char prevData = board.at(marble.at(0)).at(marble.at(1)); // R 5,8

    int prevY = marble.at(0), prevX = marble.at(1);

    board.at(prevY).at(prevX) = '.';
    marble.at(0) += moveTo.at(dir).at(0);
    marble.at(1) += moveTo.at(dir).at(1); // 6,8

    if(blocked(marble)){
        marble.at(0) -= moveTo.at(dir).at(0);
        marble.at(1) -= moveTo.at(dir).at(1);
        blockedM = true;
    }

    if(blockedM && !(goalCheck(marble, dir) && color == 'R')){
        board.at(marble.at(0)).at(marble.at(1)) = prevData;
    }
    else if(!blockedM){
        board.at(marble.at(0)).at(marble.at(1)) = color;
    }

    return blockedM;
}

void roll(vector<int>& NR, vector<int>& NB, int dir){

    vector<int> prevR;
    vector<int> prevB;
    bool blockedR;
    bool blockedB;

    while(true){
        prevR = NR, prevB = NB;

        blockedR = moveToMarble(NR, dir, 'R');
        blockedB = moveToMarble(NB, dir, 'B'); // B: 8

        if(blockedR && blockedB){
            break;
        }
    }

    red  = goalCheck(NR,dir);
    blue = goalCheck(NB, dir);

    return ;
}

void redrawBoard(vector<int> prevR, vector<int> prevB,
                vector<int> nowR, vector<int> nowB){

    board.at(prevR.at(0)).at(prevR.at(1)) = '.';
    board.at(prevB.at(0)).at(prevB.at(1)) = '.';

    board.at(nowR.at(0)).at(nowR.at(1)) = 'R';
    board.at(nowB.at(0)).at(nowB.at(1)) = 'B';

}


void slide(){
    vector<int> nowR = R;
    vector<int> nowB = B;
    int nowCnt = nowR.at(2);

    visited[nowB.at(0)][nowB.at(1)][nowR.at(0)][nowR.at(1)] = 1;

    for(int dir=0; dir<moveTo.size(); dir++){
        vector<int> nextR = nowR;
        vector<int> nextB = nowB;
        nextR.at(2) = nowCnt+1;
        blue = false; red = false;

        roll(nextR, nextB, dir);
        redrawBoard(nextR, nextB, nowR, nowB);

        if(blue == true){
            continue;
        }

        if(red){
            minCnt = nextR.at(2);
            return;
        }

        if(visited[nextB.at(0)][nextB.at(1)][nextR.at(0)][nextR.at(1)] == 0){
            quePath.push(vector<vector<int>>({nextR, nextB}));
            visited[nextB.at(0)][nextB.at(1)][nextR.at(0)][nextR.at(1)] = 1;
        }
    }

    vector<int> prevR, prevB;

    while(!quePath.empty()){
        vector<vector<int>> now = quePath.front();

        prevR = nowR;
        prevB = nowB;

        nowR = now.at(0);
        nowB = now.at(1);
        nowCnt = nowR.at(2);

        redrawBoard(prevR, prevB, nowR, nowB);

        for(int dir=0; dir<moveTo.size(); dir++){
            vector<int> nextR = nowR;
            vector<int> nextB = nowB;
            nextR.at(2) = nowCnt+1;

            if(nextR.at(2) > 10) return;

            roll(nextR, nextB, dir);

            redrawBoard(nextR, nextB, nowR, nowB);

            if(blue == true){
                blue = false;
                red = false;
                continue;
            }

            if(red){
                minCnt = nextR.at(2);
                return;
            }

            if(visited[nextB.at(0)][nextB.at(1)][nextR.at(0)][nextR.at(1)] == 0){

                quePath.push(vector<vector<int>>({nextR, nextB}));
                visited[nextB.at(0)][nextB.at(1)][nextR.at(0)][nextR.at(1)] = 1;
            }

        }

        quePath.pop();
    }
}

void output(){
    cout << minCnt << endl;
}

void run(){
    input();
    slide();
    //test();
    output();
}

int main(){
    run();
    return 0;
}
