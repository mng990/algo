#include <bits/stdc++.h>

using namespace std;

int N, M, S, E;
vector<int> numbers;
vector<pair<int,int>> questions;
int DP[2001][2001];


void initDP(){
    for(int i=1; i<=N; i++)
        DP[i][i] = 1;
}

void input(){
    cin >> N;

    numbers.push_back(-1);

    for(int i=1; i<=N; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    cin >> M;
    for(int i=0; i<M; i++){
        int startIdx, endIdx;
        cin >> startIdx >> endIdx;

        questions.push_back(pair<int,int>(startIdx, endIdx));
    }
}

bool palindrome(int startIdx, int endIdx){

    if(DP[startIdx][endIdx] == 1) return DP[startIdx][endIdx];

    if(startIdx >= endIdx) return true;

    if(numbers.at(startIdx) == numbers.at(endIdx))
        return DP[startIdx][endIdx] = palindrome(startIdx+1, endIdx-1);

    else return DP[startIdx][endIdx] = false;
}

void output(){
    for(int i=0; i<questions.size(); i++){
        pair<int, int> now = questions.at(i);

        cout << palindrome(now.first, now.second) << '\n';
    }
}

void printDP(){
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }
}

void run(){
    input();
    initDP();
    output();
   //printDP();
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run();
    return 0;
}

