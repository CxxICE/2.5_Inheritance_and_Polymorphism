#include <iostream>
#include <string>

class Figure
{
public:
	int getQuantSides() { return quantSides; }
	std::string getName() { return name; }
protected:
	int quantSides = 0;
	std::string name = "Фигура";
};

class Triangle : public Figure
{
public:
	Triangle();
};

Triangle::Triangle()
{
	quantSides = 3;
	name = "Треугольник";
}

class Quadrilateral : public Figure
{
public:
	Quadrilateral();
};

Quadrilateral::Quadrilateral()
{
	quantSides = 4;
	name = "Четырехугольник";
}

int main()
{
	setlocale(LC_ALL, "RU");
	Figure figure;
	Triangle triangle;
	Quadrilateral quadrilateral;

	std::cout	<< "Количество сторон:\n"
				<< figure.getName() << ": " << figure.getQuantSides() << '\n'
				<< triangle.getName() << ": " << triangle.getQuantSides() << '\n'
				<< quadrilateral.getName() << ": " << quadrilateral.getQuantSides() << '\n';

	system("pause");
}