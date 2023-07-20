#include <iostream>
#include <unordered_map>

std::unordered_map<long long int, int> memo;

int collatzConjecture(long long int num) {
    if (num == 1)
        return 1;

    if (memo.find(num) != memo.end())
        return memo[num];

    int count = 1;
    long long int n = num;

    while (n != 1) {
        if (n % 2 == 0) {
            n >>= 1;
        } else {
            n = 3 * n + 1;
        }

        if (memo.find(n) != memo.end()) {
            count += memo[n];
            break;
        }

        count++;
    }

    memo[num] = count;
    return count;
}

bool checkCollatzUpTo(long long int num) {
    for (long long int i = 1; i <= num; i++) {
        if (collatzConjecture(i) != 1) {
            return false;
        }
    }
    return true;
}

int main() {
    long long int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    bool allEndWithOne = checkCollatzUpTo(num);

    std::cout << "All numbers from 1 to " << num << " end with 1: " << std::boolalpha << allEndWithOne << std::endl;

    return 0;
}
