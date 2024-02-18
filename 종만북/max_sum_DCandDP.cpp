#include <bits/stdc++.h>

using namespace std;

class maxSum{
private:
    vector<int> vint;
    int low;
    int high;

public:
    maxSum(){
        int len, num;
        cin >> len;

        for(int i=0; i<len; i++){
            cin >> num;
            vint.push_back(num);
        }

        low  = 0;
        high = len-1;
    }


    int divideAndConquer(int low, int high){

        cout << "low = " << low << " / high = " << high << endl;

        if(low == high){
            return vint.at(low);
        }

        int mid = (low+high) / 2;

        int left = INT_MIN, right = INT_MIN, sum = 0;

        for(int i=low; i<=mid; i++){
            sum += vint.at(i);
            left = max(left, sum);
        }

        sum = 0;

        for(int j=mid+1; j<=high; j++){
            sum += vint.at(j);
            right = max(right, sum);
        }

        int single = max(divideAndConquer(low, mid), divideAndConquer(mid+1, high));

        return max(left+right, single);
    }

    int dynamicProgramming(){
        int len = vint.size(), ret = INT_MIN, sum = 0;

        for(int i=0; i<len; i++){
            sum = max(sum, 0) + vint.at(i);
            ret = max(sum, ret);

            cout << "sum = " << sum << " / ret = "<< ret <<endl;
        }

        return ret;
    }

    int getLow(){
        return low;
    }

    int getHigh(){
        return high;
    }

};

int main()
{
    maxSum* ms = new maxSum();

    cout << ms->divideAndConquer(ms->getLow(), ms->getHigh()) <<endl;
    cout << ms->dynamicProgramming() << endl;

    return 0;
}
