// A - Linear Keyboard
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
        string dict, key;
        cin >> dict >> key;
        map<char, int> mp;
        int count = 0;
        int front = 0, second = 0;
        for (int i = 0; i < dict.length(); ++i)
        {
            if (mp.find(dict[i]) == mp.end())
                mp.insert({dict[i], {i}});
        }
        front = mp[key[0]];
        for (auto i{1}; i < key.length(); ++i)
        {
            second = mp[key[i]];
            if (second > front)
                count += second - front;
            else
                count -= second - front;
            front = second;
        }
        cout << count << "\n";
    }
}
