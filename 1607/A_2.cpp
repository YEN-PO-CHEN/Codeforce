// A - Linear Keyboard
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    cin >> N;
    while (N--)
    {
        string s, text;
        cin >> s;
        int table[26], ans{0};
        for (int i{0}; i < 26; ++i)
        {
            table[s[i] - 'a'] = i + 1;
        }
        cin >> text;
        int pre = table[text[0] - 'a'];
        for (int i{0}; i < text.size(); ++i)
        {
            ans += abs(table[text[i] - 'a'] - pre);
            pre = table[text[i] - 'a'];
        }
        cout << ans << "\n";
    }
}