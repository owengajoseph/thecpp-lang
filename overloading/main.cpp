#include <iostream>
#include <cstdint>
class Average
{
private:
    std::int32_t m_sum{};
    int m_NumCount{};

public:
//this is constructor 
    Average(int num = 0)
        : m_sum{num}
    {
    }
//supposed to increment m_NumCount 
    Average &operator++()
    {

        m_NumCount++;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, Average &num)
    {

        out << num.m_sum;
        ++num;
        return out;
    }
    Average operator+=(const int val)
    {
        m_sum += val;
        return *this;
    }
};

int main()
{
    Average avg{};
    std::cout << avg << '\n';

    avg += 4;
    std::cout << avg << '\n'; // 4 / 1 = 4

    avg += 8;
    std::cout << avg << '\n'; // (4 + 8) / 2 = 6

    /**    avg += 24;
       std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

       avg += -10;
       std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

       (avg += 6) += 10;         // 2 calls chained together
       std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

       Average copy{avg};
       std::cout << copy << '\n';
      **/
    return 0;
}