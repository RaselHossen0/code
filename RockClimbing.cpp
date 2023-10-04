#include <iostream>
using namespace std;
void rock(vector<vector<int> > & a,vector<vector<int> > & c){
    int m=c.size();
    int n=c[0].size();

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(j==1)
            a[i][j]=c[i][j]+min(a[i-1][j],a[i-1][j+1]);
            else if(j==n+1)
            a[i][j]=c[i][j]+min(a[i-1][j],a[i-1][j-1]);
            else
            a[i][j]=c[i][j]+min(a[i-1][j+1],min(a[i-1][j],a[i-1][j-1]));
        }
    }
}
void print_path(vector<vector<int> > & a,int i,int j){
   if(i==0||j==0||j==a[0].size()) return;
   int index;
   if(a[i-1][j-1]<=a[i-1][j] && a[i-1][j-1]<=a[i-1][j+1])
   print_path(a,i-1,j-1);
   if(a[i-1][j+1]<=a[i-1][j] && a[i-1][j+1]<=a[i-1][j-1])
   print_path(a,i-1,j+1);
   if(a[i-1][j]<=a[i-1][j+1] && a[i-1][j]<=a[i-1][j-1])
   print_path(a,i-1,j);
   cout<<a[i][j]<<endl;


}
int main(){
    int m,n;
    cin >> m>> n;
     vector<vector<int> > c(m+1);
    for(int i=1;i<=m;i++){
        c[i].resize(n + 1); 
        for(int j=1;j<=n;j++){
            int a;
            cin >> a;
            c[i][j]=a;

        }
    }
    vector<vector<int> >  a(m+3,vector<int> (n+3));
    for(int i=0;i<=m+2;i++){
        for(int j=0;j<=n+2;j++){
            
            if(i==1){
                a[i][j]=c[i][j];
            }
            if(j==0|| j==n+1)
            a[i][j]=100;
           
        }
    }
    // rock(a,c);
     for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(j==1)
            a[i][j]=c[i][j]+min(a[i-1][j],a[i-1][j+1]);
            else if(j==n+1)
            a[i][j]=c[i][j]+min(a[i-1][j],a[i-1][j-1]);
            else
            a[i][j]=c[i][j]+min(a[i-1][j+1],min(a[i-1][j],a[i-1][j-1]));
        }
    }
  
    int ans=INT_MAX;
    //  cout<<ans<<endl;
    int ans_index=-1;
    for(int i=1;i<=n;i++){
       // ans=min(ans,a[m][i]);
        if(ans>=a[m][i]){
            ans=a[m][i];
        ans_index=i;
        }
    }
    cout<<"ans ";
    cout<<ans<<endl;
    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<=n+1;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //print path
    cout<<"path: "<<endl;
     print_path(a,m,ans_index);


}