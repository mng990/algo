#include <bits/stdc++.h>

using namespace std;



void subFrom(vector<int>& a, vector<int>& b);


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

void addTo(vector<int>& a, vector<int>& b, int k){


    int originA = a.size();

    if (a.size() < b.size() + k)
		a.resize(b.size() + k+1);


    for(int i=originA; i < a.size(); i++){
        a.at(i) = 0;
    }


    for(int i=0; i < b.size(); i++){
        a.at(i+k) += b.at(i);
    }

    normalize(a);

    return ;
}

// a >= b
void subFrom(vector<int>& a, vector<int>& b){
    for(int i=0; i < a.size(); i++){
        a.at(i) -= b.at(i);
    }

    normalize(a);

    return ;
}


vector<int> karatsuba(vector<int> &a, vector<int> &b){
    int an = a.size(), bn = b.size();
    if(an < bn) return karatsuba(b, a); // a가 b보다 짧으면 둘을 교환

    if(an == 0 || bn == 0) return vector<int>();

    if(an <= 50) return multiply(a, b);
    int half = an/2;

    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    addTo(a0, a1, 0);
    addTo(b0, b1, 0);

    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);

    return ret;
}

int main(){

    vector<int> num1 = {2, 1};
    vector<int> num2 = {3, 1};
    addTo(num1, num2, 10);

    for(int i=num1.size()-1; i >=0; i--){
        cout << num1.at(i);
    }

    return 0;
}



