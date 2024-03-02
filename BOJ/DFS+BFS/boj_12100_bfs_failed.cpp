#include<bits/stdc++.h>

using namespace std;

int N, nowMax = 0;
vector<vector<int>> initBoard;
vector<vector<int>> moveTo = {
    {1, 0}, {-1, 0},
    {0, 1}, {0, -1}
};

struct PLAYDATA{
    int maxData;
    int cnt;
    vector<vector<int>> board;
};

ofstream fout;

enum State
{
    STATE_DOWN = 0,
    STATE_UP,
    STATE_RIGHT,
    STATE_LEFT
};
//visited




void input(){
    int data;
    cin >> N;

    for(int i=0;i<N; i++){
        vector<int> row;
        for(int i=0; i<N; i++){
            cin >> data;
            row.push_back(data);
        }
        initBoard.push_back(row);
    }
}

bool blocked(int y, int x, int nextY, int nextX, int dir, vector<vector<int>> board){
    return board.at(nextY).at(nextX) != board.at(y).at(x)
        && board.at(nextY).at(nextX) != 0;
}

bool mergeBox(int y, int x, int nextY, int nextX, int dir,
              vector<vector<int>>& board){

    int next = board.at(nextY).at(nextX);
    int now  = board.at(y).at(x);

    board.at(y).at(x) = 0;
    board.at(nextY).at(nextX) = now + next;

    return true;
}

bool rangeCheck(int y, int x){
    return (0 <= y && y < N) && (0 <= x && x < N);
}


void flowBox(int nowY, int nowX, int dir, vector<vector<int>>& board){
    bool mergeYet = false;
    int nextY, nextX;
    if(board.at(nowY).at(nowX) == 0) return;

    while(true){
        nextY = nowY + moveTo.at(dir).at(0);
        nextX = nowX + moveTo.at(dir).at(1);

        if(!rangeCheck(nextY, nextX)) break;
        if(blocked(nowY, nowX, nextY, nextX, dir, board)) break;

        mergeBox(nowY, nowX, nextY, nextX, dir, board);


        nowY = nextY;
        nowX = nextX;
    }

    return ;
}


/*
void flowBox(int nowY, int nowX, int dir, vector<vector<int>>& board){
    int nextY, nextX;
    if(board.at(nowY).at(nowX) == 0) return;

    nextY = nowY + moveTo.at(dir).at(0);
    nextX = nowX + moveTo.at(dir).at(1);

    if(!rangeCheck(nextY, nextX)) return;
    if(blocked(nowY, nowX, nextY, nextX, dir, board)) return;

    mergeBox(nowY, nowX, nextY, nextX, dir, board);

    return ;
}
*/

void right(PLAYDATA& pd){
    vector<vector<int>> nowBoard = pd.board;

    for(int x=N-1; x >=0 ; x--){
        for(int y=0; y<N; y++){
            flowBox(y, x, STATE_RIGHT, nowBoard);
            pd.maxData = max(pd.maxData, nowBoard.at(y).at(x));
        }
    }

    pd.board = nowBoard;
    pd.cnt += 1;
}

void left(PLAYDATA& pd){
    vector<vector<int>> nowBoard = pd.board;

    for(int x=0; x<N ; x++){
        for(int y=0; y<N; y++){
            flowBox(y, x, STATE_LEFT, nowBoard);
            pd.maxData = max(pd.maxData, nowBoard.at(y).at(x));
        }
    }

    pd.board = nowBoard;
    pd.cnt += 1;
}

void up(PLAYDATA& pd){
    vector<vector<int>> nowBoard = pd.board;

    for(int y=0; y <N ; y++){
        for(int x=0; x<N; x++){
            flowBox(y, x, STATE_UP, nowBoard);
            pd.maxData = max(pd.maxData, nowBoard.at(y).at(x));
        }
    }

    pd.board = nowBoard;
    pd.cnt += 1;
}

void down(PLAYDATA& pd){
    vector<vector<int>> nowBoard = pd.board;

    for(int y=N-1; y >= 0 ; y--){
        for(int x=0; x<N; x++){
            flowBox(y, x, STATE_DOWN, nowBoard);
            pd.maxData = max(pd.maxData, nowBoard.at(y).at(x));
        }
    }

    pd.board = nowBoard;
    pd.cnt += 1;
}

void slide(State dir, PLAYDATA& pd){

    switch(dir){

    case STATE_RIGHT:
        right(pd);
        break;

    case STATE_LEFT:
        left(pd);
        break;

    case STATE_DOWN:
        down(pd);
        break;

    case STATE_UP:
        up(pd);
        break;
    }

    return ;
}

void printBoard(PLAYDATA pd, State dir){
    cout << "nowCNT: " << pd.cnt  << " / DIR: " << dir << endl;
    for(int i=0; i<pd.board.size(); i++){
        for(int j=0; j<pd.board.at(i).size(); j++){
            cout << pd.board.at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void fprintBoard(PLAYDATA pd, State dir){
    fout << "nowCNT: " << pd.cnt  << " / DIR: " << dir << endl;
    for(int i=0; i<pd.board.size(); i++){
        for(int j=0; j<pd.board.at(i).size(); j++){
            fout << setw(5) <<pd.board.at(i).at(j);
        }
        fout << endl;
    }
    fout << endl;
}

void play(){
    queue<PLAYDATA> queData;
    PLAYDATA nowPD = {0, 0, initBoard};

    for(int dir=0; dir<moveTo.size(); dir++){
        PLAYDATA nextPD = nowPD;
        slide(static_cast<State>(dir), nextPD);

        queData.push(nextPD);
    }

    while(!queData.empty()){
        PLAYDATA nowPD = queData.front();

        nowMax = max(nowMax, nowPD.maxData);

        if(nowPD.cnt == 5) break;

        for(int dir=0; dir<moveTo.size(); dir++){
            PLAYDATA nextPD = nowPD;

            fout << "before" << endl;
            fprintBoard(nextPD, static_cast<State>(dir));

            slide(static_cast<State>(dir), nextPD);

            fout<< "after" << endl;
            fprintBoard(nextPD, static_cast<State>(dir));

            queData.push(nextPD);
        }
        queData.pop();
    }
}

void output(){
    cout << nowMax << endl;
}

void run(){
    fout.open("output.txt");

    input();
    play();

    fout.close();
    output();
}

int main(){
    run();
    return 0;
}
