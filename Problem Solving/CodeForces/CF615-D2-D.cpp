#include<bits/stdc++.h>
using namespace std;


long long mod = 1e9 + 7;



long long powlog(long long n, long long k, long long mod)
{
    if(k == 0)
        return 1;
    long long ret = powlog(n, k / 2, mod) % mod;
    ret *= ret;
    ret %= mod;
    if(k % 2)
        return (ret * n) % mod;

    return ret;
}


int main()
{
    int m;
    cin >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<pair<int, long long> > prim;
    long long ans = 1;
    for(int i = 0; i < m; i++)
    {
        if(prim.size() && prim.back().first == a[i])
            prim.back().second++;
        else prim.push_back({a[i], 1});
    }
    int numprime = (int)prim.size();
    vector<long long> prefix(numprime, 1), suffix(numprime, 1);
    for(int i = 0, ii = numprime - 1; i < numprime; i++, ii--)
    {
        if(i != 0) prefix[i] *= prefix[i - 1], prefix[i] %= (mod - 1);
        if(ii != numprime - 1) suffix[ii] *= suffix[ii + 1], suffix[ii] %= (mod - 1);
        prefix[i] *= (prim[i].second + 1);
        prefix[i] %= (mod - 1);
        suffix[ii] *= (prim[ii].second + 1);
        suffix[ii] %= (mod - 1);
    }
    
    for(int i = 0; i < numprime; i++)
    {
        long long pre = 1;
        long long suf = 1;
        if(i != 0) pre = prefix[i - 1];
        if(i != numprime - 1) suf = suffix[i + 1];
        long long copy = pre * suf;
        copy %= (mod - 1);
        long long cur = prim[i].first;
        for(int j = 1; j <= prim[i].second; j++)
        {
            ans *= powlog(cur, copy, mod);
            cur *= prim[i].first;
            cur %= mod;
            ans %= mod;
        }
    }
    
    cout << ans << endl;
}

