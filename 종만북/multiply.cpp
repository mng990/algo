#include <bits/stdc++.h>

using namespace std;

void normalize(vector<int>& num){
    num.push_back(0);
    for(int i=0; i+1 < num.size(); i++){
        if(num.at(i) < 0){
            int borrow = (abs(num.at(i)+9)/10);
            num.at(i+1) -= borrow;
            num.at(i) += borrow *10;
        }

        else{
            num.at(i+1) += num.at(i) / 10;
            num.at(i) %= 10;
        }
    }

    while(num.size() > 1 && num.back() == 0) num.pop_back();

    return ;
}

vector<int> multiply(vector<int>& a, vector<int>& b){
        vector<int> c(a.size() + b.size() +1, 0);

        for(int i=0; i<a.size(); i++)
            for(int j=0; j<b.size(); j++)
                c.at(i+j) += a.at(i) * b.at(j);

        normalize(c);
        return c;
}


int main(){

    vector<int> num1 = {2, 1};
    vector<int> num2 = {3, 1};
    vector<int> ans  = multiply(num1, num2);

    for(int i=ans.size()-1; i >=0; i--){
        cout << ans.at(i);
    }


    return 0;
}

