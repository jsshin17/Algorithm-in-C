#include <iostream>
using namespace std;
bool isPrime(int x){
	int half= x/2+1;
	for(int i=2;i<half;i++){
		if(x%i==0)
			return false;
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	int cnt=0;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(isPrime(arr[i])&&arr[i]!=1){
			cnt +=1;
		}
	}
	cout<<cnt<<'\n';
}
