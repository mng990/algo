#include <bits/stdc++.h>

using namespace std;

class sort_divide_conquer{
private:
    int N;
    vector<int> vec;
    vector<int> vec_sort;
public:
    sort_divide_conquer(){
        cin >> N;
        for(int i=0; i<N; i++){
            int num;
            cin >> num;
            vec.push_back(num);
            vec_sort.push_back(num);
        }
    }

    void print_vec(){
        for(auto i : vec){
            cout << i << " ";
        }
        cout << endl;
    }

    void quick_sort(int left, int right){
        int pivot = left;
        int low   = left+1;
        int high  = right;
        int vec_size = right - left;

        if(vec_size <= 1) return;


        while(true){
            while(low < right && vec.at(low) <= vec.at(pivot)){
                low++;
            }

            while(high > left && vec.at(high) >= vec.at(pivot)){
                high--;
            }

            if(low < high){
                swap(vec.at(low), vec.at(high));
            }
            else{
                swap(vec.at(high), vec.at(pivot));
                pivot = high;
                break;
            }
        }

        quick_sort(left, pivot-1);
        quick_sort(pivot+1, right);

    }

    void merge(int left, int mid, int right){
        int lidx, ridx, sidx;

        cout << "left:" << left << " / right:" << right << endl;
        print_vec();

        lidx = left; ridx = mid+1;
        sidx = left;


        while(lidx <= mid && ridx <= right){
            if(vec.at(lidx) <= vec.at(ridx)){
                vec_sort.at(sidx++) = vec.at(lidx++);
            }
            else{
                vec_sort.at(sidx++) = vec.at(ridx++);
            }
        }

        if(lidx > mid){
            for(int j=ridx; j<=right; j++){
                vec_sort.at(sidx++) = vec.at(j);
            }
        }
        else{
            for(int i=lidx; i<=mid; i++){
                vec_sort.at(sidx++) = vec.at(i);
            }
        }


        for(int i=left; i<=right; i++){
            vec.at(i) = vec_sort.at(i);
        }

        return;
    }

    void merge_sort(int left, int right){

        int mid = (left+right) / 2;

        if(left < right){
            merge_sort(left, mid);
            merge_sort(mid+1, right);
            merge(left, mid, right);

        }
    }

    int getN() { return N; }
};


int main()
{
    sort_divide_conquer* sdc = new sort_divide_conquer();

    cout << "start vec: ";
    sdc->print_vec();

    sdc->quick_sort(0, sdc->getN()-1);

    cout << "sorted vec: ";
    sdc->print_vec();


    return 0;
}
