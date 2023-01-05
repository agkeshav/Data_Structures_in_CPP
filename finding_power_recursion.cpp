#include <iostream>
using namespace std;
long long Pow(int X, int N)
{
    // Write your code here.
    if(N==0){
        return 1;
    }
    if(N%2 !=0){
        return X*Pow(X,N/2)*Pow(X,N/2);
    }
    else{
        return Pow(X,N/2)*Pow(X,N/2);
    }
}
int main()
{
    cout<<"Enter X"<<endl;
    int x;cin >> x;
    cout<<"Enter N"<<endl;
    int n;cin >> n;
    long long ans = Pow(x, n);
    cout<<"Answer is "<<ans<<endl;
    return 0;
}