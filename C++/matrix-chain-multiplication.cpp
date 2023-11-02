#include<iostream>
#include<climits>
#include <iomanip>
using namespace std;


int main()
{
    int num;
    cout<<"Enter the number of matrices to be multiplied: ";
    cin>>num;
    int dim[num+1];
    cout<<"Enter the dimension array: ";
    for(int i = 0; i<num+1; i++){
        cin>>dim[i];
    }

    int dp[num][num];
    for(int i = 0; i<num; i++){
        for(int j = 0; j<num; j++){
            dp[i][j] = 0;
        }
    }

    for(int len = 2; len<=num; len++){ 
        for(int i = 0; i<=num-len; i++){
            int j = i+len-1;
            int min_val = INT_MAX;

            for(int k = i; k<j; k++){
                int cost = dp[i][k] + dp[k+1][j] + dim[i]*dim[k+1]*dim[j+1];
                if(cost<min_val){
                    min_val = cost;
                }
            }
            dp[i][j] = min_val;
        }
    }

    cout<<"The cost matrix is: "<<endl;
    for(int i = 0; i<num; i++){
        for(int j = 0; j<num; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"The minimum cost for multiplying " <<num<<" matrices is: "<<dp[0][num-1]<<endl;
    return 0;
}