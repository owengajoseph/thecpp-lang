#include<iostream>
#include<cmath>
//calculate 2 points 
// illustrates mordern design patterns

class Point2d
{
private:
    double m_x1{ 0.0 };
    double m_x2{ 0.0 };
public:
    Point2d() = default;
    Point2d(double x, double y)
        : m_x1{ x }, m_x2{ y }
    {

    }
    void print()
    {
        std::cout << "point2d( " << m_x1 << "," << m_x2 << ")\n";

    }
    auto distanceTo(const Point2d& point)
    {
        return std::sqrt((m_x1 - point.m_x1) * (m_x1 - point.m_x1) + (m_x2 -point.m_x2) * (m_x2 - point.m_x2));
    }
};



int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}