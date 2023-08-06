//
// Created by vaishnav on 06-08-2023.
//
/*
    Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

Example 1:

Input:
N = 5
A[] = {1,2,3,5}
Output: 4
Example 2:

Input:
N = 10
A[] = {6,1,2,8,3,4,7,10,5}
Output: 9

Your Task :
You don't need to read input or print anything. Complete the function MissingNumber() that takes array and N as input  parameters and returns the value of the missing number.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N ≤ 106
1 ≤ A[i] ≤ 106
 */

/*                                          MY SOLUTION                                                 */

/*
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
 {
  public:
    int missingNumber(vector<int>& array, int n)
    {
        int total = (n*(n+1))/2;
        int sum_of_elements = std::accumulate(array.begin(), array.end(), 0);
        return total - sum_of_elements;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
 */


/*                                         EDITORIAL                                                    */

/*
 #include <bits/stdc++.h>
using namespace std;

// Function to get the missing number
int getMissingNo(int a[], int n)
{
    // Given the range of elements
    // are 1 more than the size of array
    int N = n + 1;

    int total = (N) * (N + 1) / 2;
    for (int i = 0; i < n; i++)
        total -= a[i];
    return total;
}

// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    int miss = getMissingNo(arr, N);
    cout << miss;
    return 0;
}
 */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int missingNumber(vector<int>& array, int n)
    {
        int total = (n*(n+1))/2;
        int sum_of_elements = std::accumulate(array.begin(), array.end(), 0);
        return total - sum_of_elements;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}