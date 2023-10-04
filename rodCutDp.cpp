// #include <bits/stdcc++.h>
#include <iostream>
using namespace std;
vector<int> p(100);
vector<int> dp(100,-1);
int rod(int n){
    if(n==0) return 0;
    if(dp[n]>=0) return dp[n];
    int m=-INT_MAX;
    for(int i=1;i<=n;i++){
        m=max(m,p[i]+rod(n-1));
    }
    return dp[n]=m;
}
int main(){
     time_t start, end;
     time(&start);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int a;cin >> a;
        p[i]=a;
    }
    cout<<rod(n)<<endl;
    time(&end);
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
        << time_taken ;
    cout << " sec " << endl;

}