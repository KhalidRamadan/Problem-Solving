#include<bits/stdc++.h>
using namespace std;


// http://codeforces.com/contest/282/problem/E

int const MAX = 6000600;
int Trie[MAX][2];
int nodes = 1;
void insert(long long x)
{
    int cur  = 0;
    for(long long i = 50; i >= 0; i--)
    {
        bool bit = (x >> i) & 1;
        if(Trie[cur][bit] == 0)
            Trie[cur][bit] = nodes++;
        cur = Trie[cur][bit];
    }
}


long long q(long long x)
{
    int cur = 0;
    long long ret = 0;
    for(long long i = 50; i >= 0; i--)
    {
        bool bit = (x >> i) & 1;
        if(Trie[cur][!bit])
        {
            cur = Trie[cur][!bit];
            ret |= (1LL << i);
        }
        else cur = Trie[cur][bit];
    }
    return ret;
}


int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    
    long long pf = 0, sf = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        pf ^= a[i];
    }
    long long ans = pf;
    insert(sf);
    for(int i = n - 1; i >= 0; i--)
    {
        pf ^= a[i], sf ^= a[i];
        insert(sf);
        ans = max(ans, q(pf));
    }
    cout << ans << endl;
    
    
}
