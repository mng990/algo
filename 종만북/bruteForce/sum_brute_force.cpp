#include <bits/stdc++.h>

using namespace std;

class bruteForce{
private:
    int n;
    vector<int> vint;
public:
    bruteForce(){
        cin >> n;
        int sum=0;
        for(int i=1; i<=n; i++){
            vint.push_back(i);
        }
    }

    int sum(int n){
        int ret=0;
        for(int i=1; i<=n; i++)
            ret += i;
        return ret;

    }

    int recursiveSum(int n){
        if(n==1) return 1;
        return n+recursiveSum(n-1);
    }

    int getNumber(){
        return n;
    }
};


int main()
{
    bruteForce* bf = new bruteForce();

    int num = bf->getNumber();

    cout << "sum(for loop) = "  << bf->sum(num) << endl;
    cout << "sum(recursive) = " << bf->recursiveSum(num) << endl;

    return 0;
}
