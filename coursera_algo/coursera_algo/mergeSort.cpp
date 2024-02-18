#include <bits/stdc++.h>

using namespace std;

vector<int> arr = {5, 7, 4, 2, 1, 3, 6, 8};
vector<int> sorted(arr);

void printSortedArr(int startIdx, int endIdx){
    for(int i=startIdx; i < endIdx; i++){
        cout << sorted.at(i) << " ";
    }
    cout << endl;
}

void merge(int startIdx, int midIdx, int endIdx){
    int frontIdx = startIdx;
    int backIdx = midIdx + 1;
    int mergeIdx = startIdx;

    while(frontIdx <= midIdx && backIdx <= endIdx){
        if(arr.at(frontIdx) <= arr.at(backIdx)){
            sorted.at(mergeIdx) = arr.at(frontIdx);
            frontIdx++;
        }
        else{
            sorted.at(mergeIdx) = arr.at(backIdx);
            backIdx++;
        }
        mergeIdx++;
    } // frontIdx나 backIdx가 상한을 지날 때 탈출

    if(frontIdx > midIdx){
        for(int idx = backIdx; idx<=endIdx; idx++)
            sorted.at(mergeIdx++) = arr.at(idx);
    } // 남은 backIdx를 추가
    else{
        for(int idx = frontIdx; idx <= midIdx; idx++)
            sorted.at(mergeIdx++) = arr.at(idx);
    } // 남은 frontIdx를 추가

    for(int idx = startIdx; idx <= endIdx; idx++){
        arr.at(idx) = sorted.at(idx);
    }
}

void mergeSort(int startIdx, int endIdx){
    int sizeArr = endIdx - startIdx;
    if(sizeArr < 1) return;

    int midIdx = (startIdx+endIdx)/2;

    cout << "before" << endl;
    printSortedArr(startIdx, endIdx);

    mergeSort(startIdx, midIdx);
    mergeSort(midIdx+1, endIdx);
    merge(startIdx, midIdx, endIdx);

    cout << "after" << endl;
    printSortedArr(startIdx, endIdx);
}

int main()
{
    mergeSort(0, arr.size()-1);

    return 0;
}
