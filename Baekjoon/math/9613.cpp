#include <iostream>
using namespace std;
int gcd(int a, int b){
	if(a<b){
		int temp = a;
		a = b;
		b = temp;
	}
	while(b!=0){
		int r = a%b;
		a=b;
		b=r;
	}
	return a;
}

int main(){
	int n, x;
	cin>>n;
	long result[n];
	for(int i=0;i<n;i++){
		cin>>x;
		int arr[x];
		long sum=0;
		for(int j=0;j<x;j++){
			cin>>arr[j];
		}
		for(int p=0;p<x-1;p++){
			for(int q=p+1;q<x;q++){
				sum +=gcd(arr[p], arr[q]);
			}
		}
		result[i]=sum;
	}
	for(int i=0;i<n;i++){
		cout<<result[i]<<'\n';
	}
}
