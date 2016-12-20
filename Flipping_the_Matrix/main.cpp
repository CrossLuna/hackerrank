#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

LL maxsub(vector<vector<int>>& mat, int row, int col, int len) {
    if(len == 1)
        return mat[row][col];
    else if(len == 2) {
        //return mat[row][col] + mat[row+1][col] + mat[row][col+1] + mat[row+1][col+1];
        int tm = 0;
        tm = max(tm, mat[row][col]);
        tm = max(tm, mat[row+1][col]);
        tm = max(tm, mat[row][col+1]);
        tm = max(tm, mat[row+1][col+1]);
        return tm;
    }
    //else
    //    return 0;
    
    else {
        LL ans = 0;
        //corner
        int tm = 0;
        tm = max(tm, mat[row][col]);
        tm = max(tm, mat[row+len-1][col]);
        tm = max(tm, mat[row][col+len-1]);
        tm = max(tm, mat[row+len-1][col+len-1]);
        ans += tm;
        //ans += max(mat[row][col], max(mat[row+len-1][col], max(mat[row][col+len-1], max(mat[row+len-1][col+len-1]))));
        // alone row
        int N;
        if(len % 2 == 0)
            N = len/2;
        else
            N = len/2 + 1;
        for(int i=1; i<N; ++i) {
            int tm = 0;
            tm = max(tm, mat[row+i][col]);
            tm = max(tm, mat[row+len-i-1][col]);
            tm = max(tm, mat[row+i][col+len-1]);
            tm = max(tm, mat[row+len-i-1][col+len-1]);
            ans += tm;
        }
        for(int j=1; j<N; ++j) {
            int tm = 0;
            tm = max(tm, mat[row][col+j]);
            tm = max(tm, mat[row+len-1][col+j]);
            tm = max(tm, mat[row][col+len-j-1]);
            tm = max(tm, mat[row+len-1][col+len-j-1]);
            ans += tm;
        }
        
        ans += maxsub(mat, row+1, col+1, len-2);
        return ans;
    }
    
        
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin >> q;
    //vector<vector<int>> mat;
    while(q-->0) {
        int n;
        cin >> n;
        vector<vector<int>> mat(2*n, vector<int>());
        for(int i=0; i<2*n; ++i) {
            for(int j=0; j<2*n; ++j) {
                int tmp;
                cin >> tmp;
                mat[i].push_back(tmp);
            }
        }
        //cout << mat.size();
        cout << maxsub(mat, 0, 0, mat.size()) << endl;
    }
    return 0;
}

