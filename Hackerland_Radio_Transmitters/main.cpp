#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for(int i=0; i<n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    
    int offset = arr[0];
    for(auto& n: arr)
        n -= offset;

    /*
    for(auto n: arr)
        cout << n << ' ';
    cout << endl;
    */
    
    int addr = 0;
    int rad = k;
    int range = 2 * rad;
    
    int idx = 0;
    //first station
    
    int cnt = 0;
    int start = 0;
    int pos = 0;


    while(idx < n) {
        //cout << "start: " << start << endl;
        while(idx < n-1 && arr[idx+1]  <= start + rad)
            idx++;
        // station at idx
        cnt++;
        pos = arr[idx];
        //cout << "pos: " << pos << endl;
        //cout << idx << endl;
    
        while( idx < n && arr[idx] <= pos + rad) {
            idx++;
        }

        start = arr[idx];
    }



    cout << cnt << endl;

    return 0;
}
