#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int AB{0};
        string s;
        cin >> s;
        char a[s.length() + 1];
        strcpy(a, s.c_str());
        bool AorB = false; //false is B
        int Last_A{0};
        int Last_B{0};
        if (s[0] == 'a')
            AorB = true;
        for (int i{1}; i < s.length(); i++)
        {
            if (s[i] == 'b')
            {
                Last_B = i;
                if (AorB)
                    AB++;
                AorB = false;
            }
            else
            {
                Last_A = i;
                if (!AorB)
                    AB--;
                AorB = true;
            }
        }
        if (AB > 0) // AB > BA
            a[Last_B] = a[Last_B] - 1;
        else if (AB < 0) // AB > BA
            a[Last_A] = a[Last_A] + 1;
        cout << a << "\n";
    }
}