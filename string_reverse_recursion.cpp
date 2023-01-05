#include <iostream>
#include <string.h>
using namespace std;
void reverseString(string &str,int i,int j){
    if(i>j){
        return;
    }
    swap(str[i],str[j]);
    i++;
    j--;
    reverseString(str,i,j);
}   
int main()
{
    cout<<"Enter the string"<<endl;
    string str;cin>>str;
    int a = str.length()-1;
    reverseString(str,0,a);
    cout<<str<<endl;
    return 0;
}