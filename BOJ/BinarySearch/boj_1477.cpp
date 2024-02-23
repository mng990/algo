#include<bits/stdc++.h>

using namespace std;

int N, M, L;
vector<int> restArea;

void input(){
    cin >> N >> M >> L;

    restArea.push_back(0);
    restArea.push_back(L);

    for(int i=0; i<N; i++){
        int ra;
        cin >> ra;
        restArea.push_back(ra);
    }
    sort(restArea.begin(), restArea.end());
}


int getLength(int left, int right){
    if(left > right) return left;

    int mid = (left+right)/2;
    int newArea = 0;

    for(int i=0; i<restArea.size()-1; i++){
        int dist = restArea.at(i+1) - restArea.at(i);
        newArea += dist / mid;

        if(dist % mid == 0){
            newArea--;
        }
    }

    if(newArea > M)
        left  = mid+1;
    else
        right = mid-1;

    return getLength(left, right);
}

void output(){
    cout << getLength(1, L-1) << endl;
}



void run(){
    input();
    output();
}



int main(){
    run();
    return 0;
}
