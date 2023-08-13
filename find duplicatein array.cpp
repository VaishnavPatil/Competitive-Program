//
// Created by vaishnav on 13-08-2023.
//
/*
 Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array. Return the answer in ascending order.

Note: The extra space is only for the array to be returned.
Try and perform all operations within the provided array.

Example 1:

Input:
N = 4
a[] = {0,3,1,2}
Output: -1
Explanation: There is no repeating element in the array.Therefore output is -1.
Example 2:

Input:
N = 5
a[] = {2,3,1,2,3}
Output: 2 3
Explanation: 2 and 3 occur more than once
in the given array.
Your Task:
Complete the function duplicates() which takes array a[] and n as input as parameters and returns a list of elements that occur more than once in the given array in a sorted manner. If no such element is found, return list containing [-1].

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= N <= 105
0 <= A[i] <= N-1, for each valid i
 */

/*                                          EDITORIAL

            Given an array of n elements containing elements from 0 to n-1, with any of these numbers appearing any number of times, find these repeating numbers in O(n) and using only constant memory space.

Example:

Input: n = 7 , array = {1, 2, 3, 1, 3, 6, 6}
Output: 1, 3 and 6.
Explanation: Duplicate element in the array are 1 , 3 and 6

Input: n = 6, array = {5, 3, 1, 3, 5, 5}
Output: 3 and 5.
Explanation: Duplicate element in  the array are 3 and 6
We have discussed an approach for this question in the below post:
Duplicates in an array in O(n) and by using O(1) extra space | Set-2.
But there is a problem in the above approach. It prints the repeated number more than once.

We strongly recommend that you click here and practice it, before moving on to the solution.
Approach: The basic idea is to use a HashMap to solve the problem. But there is a catch, the numbers in the array are from 0 to n-1, and the input array has length n. So, the input array can be used as a HashMap. While traversing the array, if an element a is encountered then increase the value of a%n'th element by n. The frequency can be retrieved by dividing the a%n'th element by n.

Algorithm:

Traverse the given array from start to end.
For every element in the array increment the arr[i]%n'th element by n.
Now traverse the array again and print all those indices i for which arr[i]/n is greater than 1. Which guarantees that the number n has been added to that index.
Note: This approach works because all elements are in the range from 0 to n-1 and arr[i]/n would be greater than 1 only if a value "i" has appeared more than once.

Below is the implementation of the above approach:

// C++ program to print all elements that
// appear more than once.
#include <iostream>
using namespace std;

// function to find repeating elements
void printRepeating(int arr[], int n)
{
    // First check all the values that are
    // present in an array then go to that
    // values as indexes and increment by
    // the size of array
    for (int i = 0; i < n; i++)
    {
        int index = arr[i] % n;
        arr[index] += n;
    }

    // Now check which value exists more
    // than once by dividing with the size
    // of array
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] / n) >= 2)
            cout << i << " ";
    }
}

// Driver code
int main()
{
    int arr[] = { 1, 6, 3, 1, 3, 6, 6 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "The repeating elements are: \n";

    // Function call
    printRepeating(arr, arr_size);
    return 0;
}

Output
The repeating elements are:
1 3 6
Complexity Analysis:

Time Complexity: O(n).
Only two traversals are needed. So the time complexity is O(n)
Auxiliary Space: O(1).
As no extra space is needed, so the space complexity is constant
 */

/*                                      Authors Solution

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // First check all the values that are
        // present in an array then go to that
        // values as indexes and increment by
        // the size of array
        for (int i = 0; i < n; i++) {
            int index = arr[i] % n;
            arr[index] += n;
        }

        // Now check which value exists more
        // than once by dividing with the size
        // of array
        bool flag = false;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if ((arr[i] / n) > 1) {
                ans.push_back(i);
                flag = true;
            }
        }
        if (!flag) ans.push_back(-1);
        return ans;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> duplicates(int arr[], int n)
    {

        // All elements are incremented by 1 so that the elements become positive
        for(int i=0; i<n; i++)
            arr[i]++;

        // Using the index based approach
        for(int i=0; i<n; i++)
            arr[arr[i]%(n+1)-1] += (n+1);

        vector<int> result;
        for(int i=0; i<n; i++)
        {
            if(arr[i]/(n+1) > 1)
                result.push_back(i);
        }

        if(result.empty())
            result.push_back(-1);

        return result;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}