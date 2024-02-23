#include <bits/stdc++.h>

using namespace std;

int row, col, likeHorse, ans = INT_MAX;

vector<vector<int>> horseJump =
{
    {2,  1}, { 2, -1},
    {1,  2}, { 1, -2},
    {-2, 1}, {-2, -1},
    {-1, 2}, {-1, -2}
};

vector<vector<int>> moveTo =
{
    {1,  0}, {-1, 0},
    {0, -1}, { 0, 1}
};

vector<vector<int>>  squareMap;
vector<vector<vector<int>>> visitMap;


class monkeyWalk{
public:
    monkeyWalk(int mY, int mX, int cntH){
        y = mY;
        x = mX;
        cntHorse = cntH;
    }

    void update();
    void takeHorse();
    void takeMonkey();
    void backStep();
    int getLikeHorse(){ return likeHorse; }

private:
    int y;
    int x;
    int cntHorse;
};

queue<monkeyWalk*> qMonkey;


bool rangeCheck(int y, int x){
    return ((0 <= y) && (y < row)) && ((0 <= x) && (x < col));
}

void monkeyWalk::update(){
    ans = min(ans, visitMap.at(cntHorse).at(y).at(x));
}


void monkeyWalk::takeHorse(){
    if(cntHorse == likeHorse) return;

    if((y == row -1) && (x == col -1)) update();


    for(int i=0; i<horseJump.size(); i++){
        int nextY = y + horseJump.at(i).at(0);
        int nextX = x + horseJump.at(i).at(1);

        if(rangeCheck(nextY, nextX)){
            if(visitMap.at(cntHorse+1).at(nextY).at(nextX) == 0
                   && squareMap.at(nextY).at(nextX) == 0){

                qMonkey.push(new monkeyWalk(nextY, nextX, cntHorse+1));
                visitMap.at(cntHorse+1).at(nextY).at(nextX) = visitMap.at(cntHorse).at(y).at(x)+1;
            }
        }
    }
}

void monkeyWalk::takeMonkey(){

    if((y == row -1) && (x == col -1)) update();


    for(int i=0; i<moveTo.size(); i++){
        int nextY = y + moveTo.at(i).at(0);
        int nextX = x + moveTo.at(i).at(1);

        if(rangeCheck(nextY, nextX)){
            if(visitMap.at(cntHorse).at(nextY).at(nextX) == 0
               && squareMap.at(nextY).at(nextX) == 0){

                qMonkey.push(new monkeyWalk(nextY, nextX, cntHorse));
                visitMap.at(cntHorse).at(nextY).at(nextX) = visitMap.at(cntHorse).at(y).at(x)+1;
            }
        }
    }
}

void printVisitMap(){
    cout << endl;

    for(int k=0; k<visitMap.size(); k++){
        vector<vector<int>> visitSquare = visitMap.at(k);

        for(int i=0; i<visitSquare.size(); i++){
            vector<int> visitRow = visitSquare.at(i);

            for(int j=0; j<visitRow.size(); j++){
                cout << visitRow.at(j) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}


void BFS(){
    monkeyWalk* MW = new monkeyWalk(0, 0, 0);

    MW->takeMonkey();
    MW->takeHorse();

    while(!qMonkey.empty()){
        monkeyWalk* nowMW = qMonkey.front();
        nowMW->takeMonkey();
        nowMW->takeHorse();

        qMonkey.pop();
    }
}


void input(){
    cin >> likeHorse >> col >> row;

    vector<vector<int>> visitSquare;

    for(int i=0; i<row; i++){
        vector<int > squareRow;
        vector<int> visitRow;

        for(int j=0; j<col; j++){
            int data;
            cin >> data;
            squareRow.push_back(data);
            visitRow .push_back(0);
        }

        squareMap  .push_back(squareRow);
        visitSquare.push_back(visitRow);
    }

    for(int k=0; k <= likeHorse; k++)
        visitMap.push_back(visitSquare);

}


void output(){
    if(ans == INT_MAX) ans = -1;

    cout << ans;
}



void run(){
    input();
    BFS();
    //printVisitMap();
    output();
}




int main(){

    run();

    return 0;
}

