#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, k, cp, len;
    string strpx;
    bool answer;


    cout << "input x" << endl;

    cin >> x;

    strpx = to_string((int)pow(x,2));
    len = strpx.length();
    k = to_string(x).length();


    cp = stoi(strpx.substr(len-k,len));

    if(cp == x){
        answer = 1;
    }
    else{
        answer = 0;
    }

    cout << "answer: " <<answer<<endl;

    return 0;
}
