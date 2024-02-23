#include <bits/stdc++.h>

using namespace std;

using ll = long long;


ll calculator(ll first, ll second, int opIdx){
    if(opIdx == 0) return first+second;
    if(opIdx == 1) return first-second;
    if(opIdx == 2) return first*second;
    if(opIdx == 3) return first/second;
}

int main(){
    int n;
    ll ansMax = INT_MIN;
    ll ansMin = INT_MAX;

    vector<ll>  param;
    vector<int> voper;


    cin >> n;

    for(int i=0; i<n; i++)
    {
        ll p;
        cin >> p;
        param.push_back(p);
    }

    for(int i=0; i<4; i++)
    {
        ll cntOp;
        cin >> cntOp;
        for(ll j=0; j<cntOp; j++){
            voper.push_back(i);
        }
    }

    do{
        int pidx = 0;
        ll newOne = param.at(pidx);

        for(auto it = voper.begin(); it != voper.end(); it++){
            pidx++;

            newOne = calculator(newOne, param.at(pidx), *it);
        }
        ansMax = max(newOne, ansMax);
        ansMin = min(newOne, ansMin);
    }while(next_permutation(voper.begin(), voper.end()));

    cout << ansMax << endl;
    cout << ansMin << endl;


    return 0;
}
