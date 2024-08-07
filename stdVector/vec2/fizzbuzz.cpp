// h/t to reader Waldo for suggesting this quiz
#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

void fizzbuzz(int count)
{
    // We'll make these static so we only have to do initialization once
    static const std::vector divisors{3, 5, 7, 11, 13, 17, 19};
    static const std::vector<std::string_view> words{"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};
    assert(std::size(divisors) == std::size(words) && "fizzbuzz: array sizes don't match");

    // Loop through each number between 1 and count (inclusive)
    for (int i{1}; i <= count; ++i)
    {
        bool printed{false};

        // Check the current number against each possible divisor
        for (std::size_t j{0}; j < divisors.size(); ++j)
        {
            if (i % divisors[j] == 0)
            {
                std::cout << words[j];
                printed = true;
            }
        }

        // If there were no divisors
        if (!printed)
            std::cout << i;

        std::cout << '\n';
    }
}

int main()
{
    fizzbuzz(150);

    return 0;
}

// here is mine wich i wrote
#include <iostream>
#include <vector>
#include <string_view>
int main()
{
    std::vector num{3, 5, 7, 11, 13, 17, 19}; // no const here so i had to cast everything
    std::vector<std::string_view> words{"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};

    int storeVal{2};// holds a certain value then increments for continuation in the loop.
    for (std::size_t i = 0; i < num.size(); i++)
    {
        if (i == 0)
            std::cout << 1 + i << '\n';
        for (int count = storeVal; count < 10; count++)
        {
            // in the if, i compared each count with the num been divided by.
            if (count % static_cast<int>(num[0]) == 0)
            {
                std::cout << words[0] << '\n';
                storeVal = +count + 1;
                break;
            }
            else if (count % static_cast<int>(num[1]) == 0)
            {
                std::cout << words[2] << '\n';
                storeVal = +count + 1;
                break;
            }
            // here it rhymess , you get the idea.

            std::cout << count << '\n';
        }
    }
}
