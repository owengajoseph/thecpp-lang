#include <iostream>
#include <limits> // for std::numeric_limits
#include <vector>
// takes num and arry and prints the index and if the num exist in the array
template <typename T>
T printArray(const std::vector<T> &arr, int num)
{
    int store{};
    for (std::size_t index{0}; index < arr.size(); index++)
    {
        if (arr[index] == num)
        {
            store = arr[index];
        }
    }
    return store;
}

// returns true if std::cin has unextracted input on the current line, false otherwise
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getiInput()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter a number between 0 and 9 inclusive ";
        int x{};
        std::cin >> x;

        if (!std::cin) // If the previous extraction failed
        {
            // Let's handle the failure
            std::cin.clear(); // Put us back in 'normal' operation mode
            ignoreLine();     // And remove the bad input
            continue;
        }

        // Our extraction succeeded
        ignoreLine(); // Ignore any extraneous input
        if (x >= 0 && x <= 9)
            return x; // Return the value we extracted
    }
}

template <typename T>
void printArr(std::vector<T> &arr)
{
    for (std::size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << '\n';
    }
}
int main()
{
    std::vector arr{4, 6, 7, 3, 8, 2, 1, 9};
    int num{getiInput()};
    printArr(arr);
    int store{printArray(arr, num)};
    if (store)

        std::cout << "\nThe number" << num << " has value" << store << '\n';

    else
        std::cout << "\nThe number " << num << " was not found";
}
