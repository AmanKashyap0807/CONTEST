#include <iostream>
#include <string>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    std::cin >> q;
    while (q--)
    {
        int n;
        std::cin >> n;
        std::string s, t;
        std::cin >> s >> t;

        std::multiset<char> s_chars;
        for (char c : s)
        {
            s_chars.insert(c);
        }

        std::multiset<char> t_chars;
        for (char c : t)
        {
            t_chars.insert(c);
        }

        if (s_chars == t_chars)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }
    return 0;
}