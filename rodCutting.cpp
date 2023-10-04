// #include <bits/stdcc++.h>
#include <iostream>
#include <chrono>
using namespace std;
vector<int> p(100);
int rod(int n){
    if(n==0) return 0;
    int m=-INT_MAX;
    for(int i=1;i<=n;i++){
        m=max(m,p[i]+rod(n-1));
    }
    return m;
}
int main(){
    // auto start = chrono::high_resolution_clock::now();
 
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int a;cin >> a;
        p[i]=a;
    }
    cout<<rod(n);
    
    // auto end = chrono::high_resolution_clock::now();
 
    // // Calculating total time taken by the program.
    // double time_taken =
    //   chrono::duration_cast<chrono::nanoseconds>(end - start).count();
 
    // time_taken *= 1e-9;
 
    // cout << "Time taken by program is : " << fixed
    //      << time_taken ;
    // cout << " sec" << endl;

}