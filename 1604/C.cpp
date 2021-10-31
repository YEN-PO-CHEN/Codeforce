// C - Di-visible Confusion
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long temp{0}, i{1};
        bool status{true};
        while (n--)
        {
            cin >> temp;
            //cout << "temp " << temp << " status " << status << " i " << i << endl;
            if (status)
                for (int j{2}; j <= i + 1; j++)
                {
                    status = false;
                    if (temp % j != 0)
                    {
                        status = true;
                        break;
                    }
                }
            i++;
        }
        if (!status)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}