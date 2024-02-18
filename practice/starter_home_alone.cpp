#include <bits/stdc++.h>

using namespace std;

int DP[100] = {0,};
vector<int> scoreBoard;

int boxOpen(int start, int group, int score, vector<int> cards){

    if(DP[start] != 0){
        return score;
    }

    DP[start] = group;
    int next  = cards.at(start) - 1;

    return boxOpen(next, group, score+1, cards);
}

int getScore(){
    int len = scoreBoard.size();

    if(len < 2) return 0;

    sort(scoreBoard.begin(), scoreBoard.end());
    return scoreBoard.at(len-1) * scoreBoard.at(len-2);
}

int solution(vector<int> cards) {
    int len = cards.size();

    for(int idx =0; idx<len; idx++){
        int newScore = boxOpen(idx, idx+1, 0, cards);

        if(newScore > 0)
            scoreBoard.push_back(newScore);
    }

    return getScore();
}
