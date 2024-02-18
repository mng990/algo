#include <bits/stdc++.h>

using namespace std;

int N, lis = 0;
vector<int> arr;
stack<int> ans;
int DP[1000] = {0, };

void input(){
    cin >> N;

    for(int i=0; i<N; i++){
        int num;
        cin >> num;

        arr.push_back(num);
    }

    DP[0] = 1;
}

void makeDP(){
    for(int i=1; i<N; i++){
        int now = arr.at(i);

        for(int j=0; j<i; j++){
            if(arr.at(j) < now){
                DP[i] = max(DP[i], DP[j]+1);
                lis = max(DP[i], lis);
            }
        }
    }
}

void printDP(){
    for(int i=0; i<N; i++){
        cout << DP[i] << " ";
    }
    cout << endl;
}

void buildAns(){
    for(int i=N-1; i >= 0; i--){
        if(DP[i] == lis){
            ans.push(arr.at(i));
            lis--;
        }
    }
}

void printAns(){
    if(ans.size() == 0)
        ans.push(arr.at(0));

    cout << ans.size() << endl;

    while(!ans.empty()){
        cout << ans.top() << ' ';
        ans.pop();
    }
}

void run(){
    input();
    makeDP();
    buildAns();
    printAns();
}


int main(){
    run();
    return 0;
}



