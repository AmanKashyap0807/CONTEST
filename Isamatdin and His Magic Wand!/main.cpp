#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void process_case()
{
    int n;
    std::cin >> n;

    std::vector<long long> arr(n);
    int num_odd = 0;
    int num_even = 0;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
        if (arr[i] % 2 == 0)
        {
            num_even++;
        }
        else
        {
            num_odd++;
        }
    }

    if (num_odd > 0 && num_even > 0)
    {
        std::sort(arr.begin(), arr.end());
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i];
        if (i < n - 1)
        {
            std::cout << " ";
        }
    }
    std::cout << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--)
    {
        process_case();
    }
    return 0;
}