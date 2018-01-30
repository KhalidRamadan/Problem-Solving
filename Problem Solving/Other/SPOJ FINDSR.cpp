#include<bits/stdc++.h>
using namespace std;

// http://www.spoj.com/problems/FINDSR/
vector<int> prefix(string s)
{
    int m = (int)s.size();
    vector<int> pre(m);
    for(int i = 1, k = 0; i < m; i++)
    {
        while (k > 0 && s[k] != s[i])
            k = pre[k - 1];
        if(s[k] == s[i])
            pre[i] = ++k;
        else pre[i] = 0;
    }
    return pre;
}

int main()
{
    string s;
    while(cin >> s)
    {
        if(s == "*") break;
        vector<int> failure = prefix(s);
        
        int n = (int)s.size();
        int ans = 1;
        
        if(n % (n - failure[n - 1]) == 0) ans = n / (n - failure[n - 1]);
        cout << ans << endl;
    }
}
