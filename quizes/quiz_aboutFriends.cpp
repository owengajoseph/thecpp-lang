#include<iostream>

// forward declaration of class  vector to tell tell the compiler 
// the existece ofe calss Vector3d
class Vector3d;

class Point3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point3d(double x, double y, double z)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{ }

	void print() const
	{
		std::cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ")\n";
	}
	// tells the compiler "oh! ,the is a function wich is going to be friend "

	void moveByVector(const Vector3d& v);
	
};




class Vector3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Vector3d(double x, double y, double z)
		: m_x{ x }, m_y{ y }, m_z{ z }
	{
	}

	void print() const
	{
		std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
	}
	// friend function 
	friend void Point3d::moveByVector(const Vector3d& v);
};

void Point3d::moveByVector(const Vector3d& v)
{

	// implement this function as a friend of class Vector3d

	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}

int main()
{
	Point3d p{ 1.0, 2.0, 3.0 };
	Vector3d v{ 2.0, 2.0, -3.0 };

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}