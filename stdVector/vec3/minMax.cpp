#include <iostream>
#include <vector>
#include <utility>
//find the minimum value
//my solution
template <typename T>
std::pair<T, T> getMin(std::vector<T> &v)
{
    T x{static_cast<T>(v[0])};
    int indexStore{};
    for (std::size_t i{1}; i < v.size(); i++)
    {
        if (x > v[i])
        {
            x = v[i];
            indexStore = static_cast<int>(i);
        }
    }
    return {x, indexStore};
}
//get maximum value
template <typename T>
std::pair<T, T> getMax(std::vector<T> &v)
{
    T x{static_cast<T>(v[0])};
    int indexStore{};
    for (std::size_t i{1}; i < v.size(); i++)
    {
        if (x < v[i])
        {
            x = v[i];
            indexStore = static_cast<int>(i);
        }
    }
    return {x, indexStore};
}


//gets the return of std::pair
template <typename U>
void getVal(std::vector<U> &v)
{
    std::cout << "with array (";
    for (std::size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << " )\n";
    std::pair p1{getMin(v)};
    std::pair p2{getMax(v)}; 
    std::cout << "The min element has index" << p1.first << " and value" << p1.second << '\n';
    std::cout<<"The max elemet has idex "<<p2.first<<" and value "<<p2.second<<'\n';
}

int main()
{
    std::vector v1{3, 8, 2, 5, 7, 8, 3};
    std::vector v2{5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6};
    getVal(v1);
    getVal(v2);
}

#include <iostream>
#include <vector>

template <typename T>
std::pair<std::size_t, std::size_t> findMinMaxIndices(const std::vector<T>& v)
{
    std::size_t min { 0 };
    std::size_t max { 0 };
    for (std::size_t index { 0 }; index < v.size(); ++index)
    {
        if (v[index] < v[min])
            min = index;
        if (v[index] > v[max])
            max = index;
    }

    return { min, max };
}

template <typename T>
void printArray(const std::vector<T>& v)
{
    bool comma { false };
    std::cout << "With array ( ";
    for (const auto& e: v)
    {
        if (comma)
            std::cout << ", ";

        std::cout << e;
        comma = true;
    }
    std::cout << " ):\n";
}

//answer 
//finding dificulties on working with true false statement


int main()
{
    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    printArray(v1);

    auto m1 { findMinMaxIndices(v1) };
    std::cout << "The min element has index " << m1.first << " and value " << v1[m1.first] << '\n';
    std::cout << "The max element has index " << m1.second << " and value " << v1[m1.second] << '\n';

    std::cout << '\n';

    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
    printArray(v2);

    auto m2 { findMinMaxIndices(v2) };
    std::cout << "The min element has index " << m2.first << " and value " << v2[m2.first] << '\n';
    std::cout << "The max element has index " << m2.second << " and value " << v2[m2.second] << '\n';

    return 0;
}
