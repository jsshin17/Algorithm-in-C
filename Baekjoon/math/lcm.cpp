#include <iostream>
using namespace std;
int main(){
	int n, a, b, prev_a, prev_b;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>a>>b;
		prev_a = a;
		prev_b = b;
		while(b!=0){
			int r = a%b;
			a = b;
			b = r;
		}
		arr[i]=(prev_a*prev_b)/a;
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<'\n';
	}
}
