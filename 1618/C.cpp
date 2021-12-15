#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forloop(i, a, b) for (int i = a; i < b; ++i)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        vector<ll> first, second;
        ll s, im;
        bool state = true;
        cin >> s;
        while (s--)
        {
            cin >> im;
            if (state)
                first.push_back(im), state = false;
            else
                second.push_back(im), state = true;
        }
        ll finput{first[0]}, fcount{0};
        ll sinput{second[0]}, scount{0};
        bool fstate{false}, sstate{false};
        if (first.size() == 1) // 各1
        {
            if (first[0] != second[0])
                cout << max(first[0], second[0]) << "\n";
            else
                cout << "0\n";
        }
        else
        {
            for (int i{1}; i < first.size(); ++i)
            {
                finput = __gcd(finput, first[i]);
                if (finput == 1)
                {
                    fstate = true;
                    break;
                }
            }
            if (finput != 1)
            {
                int i;
                forloop(i, 0, second.size())
                {
                    if (__gcd(finput, second[i]) == finput)
                    {
                        fstate = true;
                        break;
                    }
                }
            }

            //cout << "finput\t" << finput << "\n";
            if (fstate)
            {
                for (int i{1}; i < second.size(); ++i)
                {
                    sinput = __gcd(sinput, second[i]);
                    if (sinput == 1)
                    {
                        sstate = true;
                        break;
                    }
                }
                //cout << "sinput\t" << sinput << "\n";
                if (sinput != 1)
                {
                    for (int i{0}; i < first.size(); ++i)
                    {
                        if (__gcd(sinput, first[i]) == sinput)
                        {
                            sstate = true;
                            break;
                        }
                    }
                }

                if ((sstate && fstate) || (finput == 1 && sinput == 1))
                {
                    cout << "0\n";
                }
                else
                    cout << max(finput, sinput) << "\n";
            }
            else
            {
                cout << finput << "\n";
            }
        }
    }
}