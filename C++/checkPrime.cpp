// Check Prime Number in C++

#include <iostream>

using namespace std;
bool IsPrime(int n)
{
    bool flag=0;
    for(int i=2;i<n;i++){
        if(n%i==0){
           
            flag=1;
            break;  

        }
    }
    if(flag==0){
       return true;
    }else{
        return false;
    }
}

int main()
{
    int n = 73;
    bool result = IsPrime(n);
    cout << result;
    return 0;
}

// Output
// 73 is a prime number