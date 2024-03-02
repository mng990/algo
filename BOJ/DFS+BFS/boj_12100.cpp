#include<bits/stdc++.h>

using namespace std;

int N, nowMax = 0;
vector<vector<int>> initBoard;
vector<vector<int>> moveTo = {
    {1, 0}, {-1, 0},
    {0, 1}, { 0,-1}
}; // down, up, right, left

vector<vector<vector<int>>> resultBoard;
vector<int> vecDir({0, 1, 2, 3});
vector<int> path(5);

void input(){
    int data;
    cin >> N;

    for(int i=0;i<N; i++){
        vector<int> row;
        vector<int> mRow;
        for(int i=0; i<N; i++){
            cin >> data;
            row.push_back(data);
        }
        initBoard.push_back(row);
    }
}

class gameData{
public:
    gameData(int _cnt, vector<vector<int>> _board){
        cnt = _cnt;
        board = _board;
        int n = board.size();
        merged = vector<vector<int>>(n, vector<int>(n));
        maxData = 0;
    };

    gameData(gameData* _gameData){
        cnt = _gameData->getCnt();
        board = _gameData->getBoard();
        int n = board.size();
        merged = vector<vector<int>>(n, vector<int>(n));
        maxData = _gameData->getMaxData();
    };

    void down();
    void up();
    void right();
    void left();
    void slide(int dir);
    void flow(int startY, int startX, int dir);
    void setCnt(int _cnt) { cnt = _cnt; }
    bool rangeCheck(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }

    int getCnt()      const { return cnt; }
    int getMaxData()  const { return maxData; }
    vector<vector<int>> getBoard()  const { return board;  }
    vector<vector<int>> getMerged() const { return merged; }

    friend ostream& operator<<(ostream& os, gameData* ptrGD);

private:
    int cnt;
    int maxData;
    vector<vector<int>> board;
    vector<vector<int>> merged;
};




ostream& operator<<(ostream& os, gameData* ptrGD ){
    os << "CNT: " << ptrGD->getCnt() << endl;
    vector<vector<int>> thisBoard = ptrGD->getBoard();
    vector<vector<int>> thisMerged = ptrGD->getMerged();


    for(int i=0; i<thisBoard.size(); i++){
        for(int j=0; j<thisBoard.at(i).size(); j++){
            os << setw(4) << thisBoard.at(i).at(j);
        }
        os << endl;
    }
    os << endl;

    return os;
}

void gameData::down(){
    for(int nowY = N-1; nowY >= 0; nowY--){
        for(int nowX = 0; nowX < N; nowX++){
            flow(nowY,nowX,0);
        }
    }
}

void gameData::up(){
    for(int nowY = 0; nowY<N; nowY++){
        for(int nowX = 0; nowX < N; nowX++){
            flow(nowY, nowX, 1);
        }
    }
}

void gameData::right(){
    for(int nowX = N-1; nowX >= 0; nowX--){
        for(int nowY = 0; nowY < N; nowY++){
            flow(nowY, nowX, 2);
        }
    }
}

void gameData::left(){
    for(int nowX = 0; nowX < N; nowX++){
        for(int nowY = 0; nowY < N; nowY++){
            flow(nowY, nowX, 3);
        }
    }
}

void gameData::flow(int nowY, int nowX, int dir){

    while(true){
        int nextY = nowY + moveTo.at(dir).at(0);
        int nextX = nowX + moveTo.at(dir).at(1);

        if(!rangeCheck(nextY, nextX)) break;


        int now  = board.at(nowY).at(nowX);
        int next = board.at(nextY).at(nextX);

        if(now == 0) break;

        if((next !=0 && now != next) || (now == next && (merged[nowY][nowX]) || merged[nextY][nextX] )) break;


        if(now == next && !merged[nowY][nowX]){
            board.at(nowY).at(nowX) += board.at(nextY).at(nextX);
            board.at(nextY).at(nextX) = 0;
            merged[nowY][nowX] = true;
        }

        if(board.at(nextY).at(nextX) == 0){
            board.at(nextY).at(nextX) = board.at(nowY).at(nowX);
            board.at(nowY).at(nowX) = 0;
            swap(merged[nowY][nowX], merged[nextY][nextX]);
        }

        nowY = nextY;
        nowX = nextX;
    }

}

void gameData::slide(int dir){

    switch(dir){
    case 0:
        down();
        break;
    case 1:
        up();
        break;
    case 2:
        right();
        break;
    case 3:
        left();
        break;
    }
    cnt++;
}

void getMax(){
    for(int num=0; num < resultBoard.size(); num++){
        for(int i=0; i<resultBoard.at(num).size(); i++){
            for(int j=0; j<resultBoard.at(num).at(i).size(); j++){
                nowMax = max(nowMax, resultBoard.at(num).at(i).at(j));
            }
        }
    }
}

void play(gameData* nowData){
    if(nowData->getCnt() == 5){
        resultBoard.push_back(nowData->getBoard());
        getMax();
        return;
    }

    for(int dir =0; dir<moveTo.size(); dir++){
        gameData* nextData = new gameData(nowData);
        nextData->slide(dir);
        play(nextData);
    }

    return;
}


void output(){
    cout << nowMax << endl;
}

void run(){
    input();
    gameData* startData = new gameData(0, initBoard);
    play(startData);
    output();
}


int main(){
    run();
    return 0;
}
