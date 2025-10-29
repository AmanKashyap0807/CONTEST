#include <iostream>
#include <vector>
#include <string>

void handle_test()
{
    int n;
    std::cin >> n;
    std::vector<long long> arr(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    std::vector<int> small_primes = {
        2, 3, 5, 7, 11, 13, 17, 19, 23,
        29, 31, 37, 41, 43, 47, 53};

    long long answer = -1;

    for (int p : small_primes)
    {
        bool all_divisible = true;

        for (long long val : arr)
        {
            if (val % p != 0)
            {
                all_divisible = false;
                break;
            }
        }

        if (!all_divisible)
        {
            answer = p;
            break;
        }
    }

    std::cout << answer << "\n";
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--)
    {
        handle_test();
    }
    return 0;
}