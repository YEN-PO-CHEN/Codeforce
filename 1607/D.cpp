// D - Blue-Red Permutation
#include <bits/stdc++.h>
using namespace std;
struct node
{
    char c;
    long long ll;
};
bool crl(node a, node b)
{
    if (a.c < b.c)
        return true;
    else if (a.c > b.c)
        return false;
    else
        return a.ll < b.ll;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long X, N;
    cin >> N;
    while (N--)
    {
        cin >> X;
        string s;
        vector<node> n(X);
        bool yes = true;
        for (int i{0}; i < X; ++i)
            cin >> n.at(i).ll;
        cin >> s;
        for (int i{0}; i < X; ++i)
            n.at(i).c = s[i];
        sort(n.begin(), n.end(), crl);
        for (int i{0}; i < X; ++i)
        {
            if (n.at(i).ll < i + 1)
                if (n.at(i).c == 'B')
                {
                    yes = false;
                    break;
                }
                else
                    ;
            else if (n.at(i).ll > i + 1)
                if (n.at(i).c == 'R')
                {
                    yes = false;
                    break;
                }
                else
                    ;
            else
                ;
        }
        if (!yes)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}