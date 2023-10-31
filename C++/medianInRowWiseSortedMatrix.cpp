// Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.
//Example
// R = 3, C = 3
// M = [[1, 3, 5], 
//      [2, 6, 9], 
//      [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives 
// us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median.
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countLessThanOrEqual(const vector<int>& row, int target) {
    int left = 0, right = row.size() - 1;
    int count = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (row[mid] <= target) {
            count = mid + 1;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return count;
}

int median(vector<vector<int>>& matrix, int R, int C) {
    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = 0; i < R; i++) {
        minVal = min(minVal, matrix[i][0]);
        maxVal = max(maxVal, matrix[i][C - 1]);
    }

    int desired = (R * C + 1) / 2;
    
    while (minVal < maxVal) {
        int midVal = minVal + (maxVal - minVal) / 2;
        int count = 0;
        for (int i = 0; i < R; i++) {
            count += countLessThanOrEqual(matrix[i], midVal);
        }

        if (count < desired) {
            minVal = midVal + 1;
        } else {
            maxVal = midVal;
        }
    }

    return minVal;
}

};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends