#include <iostream>
using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}

int main(){
    int a, b;
    cin>>a>>b;
    if(a<b){
        int temp = a;
        a = b;
        b = temp;
    }
    cout<<gcd(a, b)<<'\n'<<(a*b)/gcd(a, b)<<'\n';
}

