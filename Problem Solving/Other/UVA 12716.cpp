#include<bits/stdc++.h>
using namespace std;


const int MAX = 30000000;
int A[MAX + 1];

void solve()
{
    for(int i = 1; i <= MAX; i++)
    {
        for(int j = i + i; j <= MAX; j += i)
            if(((j - i) ^ j) == i)
            {
                A[j]++;
            }
    }
    
    for(int i = 1; i <= MAX; i++)
        A[i] += A[i - 1];
}





int main()
{
    
    solve();
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cout << "Case " << i << ": " << A[x] << endl;
    }
}
