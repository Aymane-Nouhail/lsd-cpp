#include <iostream>
#include <vector>
using namespace std;

template <typename T>
using matrix = vector<vector<T>>;

template <typename T>
matrix<T> operator*(matrix<T> a, matrix<T> b) {
    int n = a.size();
    int m = b[0].size();
    int p = b.size();
    matrix<T> res(n, vector<T>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

template <typename T>
matrix<T> matpow(matrix<T> a, int k){
    if (a.size() != a[0].size()){
        cout<<"squaring a non-square matrix makes no mathematical sense.";
        exit(EXIT_FAILURE); 
    }
    int n = a.size();
    if(k==0){
        matrix<T> identityMatrix(n,vector<T>(n));
        for(int i=0;i<n;i++)
            identityMatrix[i][i] = 1;
        return identityMatrix;
    }
    if(k%2 == 0)
        return matpow(a*a,k/2);
    return a * matpow(a*a,(k-1)/2);
}

template <typename T>
void matprint(matrix<T> a) {
    int n = a.size();
    int m = a[0].size();
    cout<<'[';
    for (int i = 0; i < n-1; i++){
        if(i>0) cout<<" ";
        cout<<"[";
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << ", ";
        }
        cout << "\b\b],"<<endl;
    }
    cout<<" [";
    for (int j = 0; j < m; j++) {
            cout << a[n-1][j] << ", ";
    }
    cout << "\b\b]";
    cout<<']'<<endl<<endl;
}

int main() {
    matrix<int> a {{1, 1, 1}, {2, 2, 2},{3,3,3}};
    matrix<double> b {{1.0, 1.23, 1.22}, {2.22, 2.33, 2.33}};
    matprint(matpow(a, 12));
    matprint(matpow(b, 15));
    return 0;
}
