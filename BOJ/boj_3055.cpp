#include <bits/stdc++.h>

using namespace std;

int row, col, ans, prevCost = 0;
string ansStr = "KAKTUS";
bool goal = false;

queue<pair<pair<int, int>, int>> hedgePath;
vector<vector<char>>  riverMap;
vector<vector<bool>>  visitMap;
vector<vector<bool>>  sinkMap;
queue<pair<int,int>> queSink;
pair<int, int> hedgeDot;
pair<int, int> beaverDot;

vector<vector<int>> moveTo =
{
    {0,  1}, {0, -1},
    {1,  0}, {-1, 0}
};

void input(){
    cin >> row >>col;

    for(int i=0; i<row; i++){
        vector<char> riverRow;
        vector<bool> visitRow;
        vector<bool> sinkRow;

        for(int j=0; j<col; j++){
            char dot;
            cin >> dot;
            riverRow.push_back(dot);
            visitRow.push_back(false);
            sinkRow .push_back(false);

            if(dot == '*'){
                queSink.push(pair<int,int>(i,j));
                sinkRow.at(j) = true;
            }

            if(dot == 'S'){
                hedgeDot.first  = i;
                hedgeDot.second = j;
            }
        }
        riverMap.push_back(riverRow);
        visitMap.push_back(visitRow);
        sinkMap .push_back(sinkRow);
    }
}

bool rangeCheck(int y, int x){
    return ((0 <= y) && (y < row)) && ((0 <= x) && (x < col));
}

void printMap(){
    for(int i=0; i<riverMap.size(); i++){
        for(int j=0; j<riverMap.at(i).size(); j++){
            cout << riverMap.at(i).at(j);
        }
        cout << endl;
    }
    cout << endl;
}

void sink(){
    queue<pair<int, int>> nextQueSink;

    while(!queSink.empty()){
        pair<int, int> nowSink = queSink.front();

        for(int i=0; i < moveTo.size(); i++){
            int nextSinkY = nowSink.first  + moveTo.at(i).at(0);
            int nextSinkX = nowSink.second + moveTo.at(i).at(1);

            if(rangeCheck(nextSinkY, nextSinkX)){
                if(!sinkMap.at(nextSinkY).at(nextSinkX)
                   && riverMap.at(nextSinkY).at(nextSinkX) == '.'){

                    pair<int, int> nextSink(nextSinkY, nextSinkX);
                    nextQueSink.push(nextSink);
                    riverMap.at(nextSinkY).at(nextSinkX) = '*';
                }
            }
        }

        queSink.pop();
    }

    queSink = nextQueSink;

    //printMap();
}



void hedgeHog(int startY, int startX){
    pair<int, int> startDot(startY, startX);

    sink();

    for(int i=0; i<moveTo.size(); i++){
        int nextY = startY + moveTo.at(i).at(0);
        int nextX = startX + moveTo.at(i).at(1);


        if(rangeCheck(nextY, nextX)){
            if(!visitMap.at(nextY).at(nextX) &&
               riverMap.at(nextY).at(nextX) == '.' || riverMap.at(nextY).at(nextX) == 'D'){

                hedgePath.push(pair<pair<int, int>, int>(pair<int,int>(nextY, nextX), 1));
                visitMap.at(nextY).at(nextX) = true;
            }
        }
    }

    while(!hedgePath.empty()){
        pair<pair<int, int>, int> now = hedgePath.front();
        hedgePath.pop();

        pair<int, int> nowDot = now.first;
        int nowCost = now.second;


        if(nowCost != prevCost){
            sink();
            prevCost = nowCost;
        }
/*
        if(riverMap.at(nowDot.first).at(nowDot.second) == '*'){
            continue;
        }
*/
        if(riverMap.at(nowDot.first).at(nowDot.second) == 'D'){
            ans  = nowCost;
            goal = true;
            break;
        }

        for(int i=0; i<moveTo.size(); i++){
            int nextY = nowDot.first  + moveTo.at(i).at(0);
            int nextX = nowDot.second + moveTo.at(i).at(1);

            if(rangeCheck(nextY, nextX)){
                if(!visitMap.at(nextY).at(nextX) &&
                    riverMap.at(nextY).at(nextX) == '.' || riverMap.at(nextY).at(nextX) == 'D'){

                    hedgePath.push(pair<pair<int, int>, int>(pair<int, int>(nextY, nextX), nowCost+1));
                    visitMap.at(nextY).at(nextX) = true;
                }
            }
        }
    }
}

void output(){
    if(goal == true) cout << ans    << endl;
    else             cout << ansStr << endl;
}

void run(){
    input();
    hedgeHog(hedgeDot.first, hedgeDot.second);
    output();
}




int main(){
    run();
    return 0;
}

