// B - Odd Grasshopper
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, o, q, p, r;
    cin >> n;
    while (n--)
    {
        cin >> o >> p >> q >> r;
        if (o * pow(10, p) > q * pow(10, r))
            cout << ">\n";
        else if (o * pow(10, p) < q * pow(10, r))
            cout << "<\n";
        else
            cout << "=\n";
    }
}