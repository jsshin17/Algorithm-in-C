#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 10000000;
bool arr_prime[MAX];
void eratos(){
    for (int i = 2; i <= MAX; i++)
        arr_prime[i] = true;
    for (int i = 2; i*i <= MAX; i++) {
        if (arr_prime[i])
            for (int j = i * i; j <= MAX; j += i) {
                arr_prime[j] = false;
            }
    }
}

int main(){
    vector<int> arr;
    int temp;
    eratos();
    while(1){
        scanf("%d", &temp);
        if(temp==0)
            break;
        arr.push_back(temp);
    }
    int n = arr.size();
    for(int i=0; i<n;i++){
        bool check=false;
        for(int j=1; j<arr[i]/2; j++){ #왜 arr[i]/4로 하면 틀리게 나오는지 아직도 의문이다. 예를 들어 36이면 17까지만 검사해도 되는 게 아닌가? 하여튼 이해가 안된다. arr[i]/2로 하면 35까지 다 검사되는데 그럴 필요가 있을까.
            int constant = 2*j+1;
            if(arr_prime[constant]) {
                if (arr_prime[arr[i] - constant]) {
                    printf("%d = %d + %d\n", arr[i], constant, arr[i]-constant);
                    check = true;
                    break;
                }
            }
        }
        if(!check) {
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
}