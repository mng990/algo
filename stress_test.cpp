#include <bits/stdc++.h>
#define llng long long

using namespace std;

llng maxPairwiseProduct(vector<llng>& arr){
    llng result = 0;
    llng n = arr.size();

    for(llng i = 0; i<n; i++){
        for(llng j=i+1; j<n; j++){
            if((llng)arr[i]*arr[j]> result){
                result = arr[i]*arr[j];
            }
        }
    }

    return result;

}

llng maxFunc(vector<llng>& arr){

    llng len = arr.size();


    llng firstIdx = -1, secondIdx = -1;

    for(llng i=0; i<len; i++){


        if(firstIdx == -1 || arr.at(i) > arr.at(firstIdx)){
            firstIdx = i;
        }
    }

    for(llng j=0; j<len; j++){

        if(j != firstIdx && secondIdx == -1 || (arr.at(j) > arr.at(secondIdx))){
            secondIdx = j;
        }
    }


    return arr.at(firstIdx) * arr.at(secondIdx);
}


llng maxPair(vector<llng>& arr){
    llng len = arr.size();

    sort(arr.begin(), arr.end());

    return arr.at(len-1) * arr.at(len-2);
}

void stressTest(){

    while (true) {
        llng n = rand() % 10 + 2;

        cout << n << "\n";
        vector<llng> a;

        for (llng i = 0; i < n; ++i) {
            a. push_back(rand() % 10);
        }

        for (llng i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }

        cout << "\n";
        llng res1 = maxPairwiseProduct(a);
        llng res2 = maxPair(a);

        if (res1 != res2){
            cout << "Wrong answer:"<< res1 << " "<< res2 << "\n";
            break;
        }

        else {
            cout << "OK\n";
        }

        }
}






int main()
{
    llng loop;
    llng x;

    vector<llng> arr;

    cin >> loop;

    for(llng i=0; i<loop; i++){
        cin >> x;
        arr.push_back(x);
    }

    cout << maxPair(arr);



    //stressTest();

    return 0;
}
