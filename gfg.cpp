#include<iostream>
using namespace std;
void printPat(int n)
{
    for(int k = 0; k < n; k++)
    {
        for(int i = n; i > 0; i--)
        {
            for(int j = 0; j < n - k; j++)
            {
                cout << i << " ";
            }
        }
        cout << "$";
    }
}
int main()
{
    int n;
    cin >> n;
    printPat(n);
    return 0;
}