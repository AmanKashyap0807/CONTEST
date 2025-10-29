#include <iostream>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--)
    {
        std::set<int> lengths;
        for (int i = 0; i < 4; ++i)
        {
            int s;
            std::cin >> s;
            lengths.insert(s);
        }
        if (lengths.size() == 1)
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