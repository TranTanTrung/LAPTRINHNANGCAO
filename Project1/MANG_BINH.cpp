#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a[100], n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b[100];
    for(int i=0;i<n;i++){
        b[i]=a[i]*a[i];
    }
    sort(b, b+n);
    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
