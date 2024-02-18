#include <bits/stdc++.h>

using namespace std;
const int INF = 9999;

int fastSum(int n){
    if(n == 1) return 1;
    if(n%2 == 1) return fastSum(n-1) + n;
    return 2*fastSum(n/2) + n/2 * n/2;
}

class SquareMatrix{
private:
    int N;
    vector<vector<int>> matrix;
public:

    SquareMatrix(int n){
        N = n;

        for(int i=0; i < n; i++){
            vector<int> row;
            for(int j=0; j < n; j++){
                int m;
                cin >> m;

                row.push_back(m);
            }
             matrix.push_back(row);
        }
    }

    SquareMatrix(vector<vector<int>> mtx){
        matrix = mtx;
        N = mtx.size();
    }

    int size(){ return matrix.size(); }

    SquareMatrix identify(int n){
        vector<vector<int>> matrix;

        for(int i=0; i<n; i++){
            vector<int> irow;
            for(int j=0; j<n; j++){
                if(i == j) irow.push_back(1);
                else       irow.push_back(0);
            }

            matrix.push_back(irow);
        }

        return SquareMatrix(matrix);
    }

    SquareMatrix operator*(SquareMatrix &ref){
        int N = this->getN();

        vector<vector<int>> retMat;

        for(int i=0; i<N; i++){
            vector<int> retRow;

            for(int j=0; j<N; j++){
                int newDot = 0;

                for(int k=0; k<N; k++){
                    newDot += this->getDot(i,k) * ref.getDot(k,j);
                }
                retRow.push_back(newDot);
            }
            retMat.push_back(retRow);
        }

        SquareMatrix* smp = new SquareMatrix(retMat);

        return *smp;
    }

    SquareMatrix pow(SquareMatrix& A, int m){
        if(m == 0) return identify(A.size());
        if(m % 2 > 0) return pow(A, m-1) * A;
        SquareMatrix half = pow(A, m/2);

        return half * half;
    }

    int getN(){ return N; }

    int getDot(int i, int j){
        return matrix.at(i).at(j);
    }

    vector<vector<int>> getMatrix(){
        return matrix;
    }

    friend ostream& operator<<(ostream& os, SquareMatrix& mtx){
        vector<vector<int>> vvint = mtx.getMatrix();

        for(int i=0; i<vvint.size(); i++){
            vector<int> vint = vvint.at(i);
            for(int j=0; j < vint.size(); j++){
                os << vint.at(j) << " ";
            }
            os << endl;
        }

        return os;
    }


};

int main()
{

    vector<vector<int>> mtx01 = {{1, 3, 2}, {3, 2, 1}, {2, 1, 3}};
    vector<vector<int>> mtx02 = {{2, 3, 1}, {1, 3, 2}, {3, 2, 1}};
    SquareMatrix* A = new SquareMatrix(mtx01);
    SquareMatrix* B = new SquareMatrix(mtx02);

    SquareMatrix ret = (*A) * (*B);

    cout << ret << endl;


    return 0;
}
