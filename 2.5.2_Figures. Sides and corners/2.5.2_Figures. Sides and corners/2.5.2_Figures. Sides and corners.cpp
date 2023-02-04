#include <iostream>
#include <string>
#include <format>

class Figure
{
public:
	virtual void printParam() {};
protected:
	int quantSides = 0;
	std::string name = "Фигура";
};

class Triangle : public Figure
{
public:
	Triangle(int a, int b, int c, int A, int B, int C);
	void printParam() override;
protected:
	int a, b, c, A, B, C;
};

Triangle::Triangle(int a, int b, int c, int A, int B, int C)
{	
	quantSides = 3;
	name = "Треугольник";
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	this->C = C;
}

void Triangle::printParam()
{
	std::cout	<< name << ": \n"
				<< std::format("Стороны: a={}, b={}, c={}\n",a,b,c)		//c++20
				<< std::format("Углы:\t A={}, B={}, C={}\n\n",A,B,C);	//c++20
}

class TriangleRight : public Triangle
{
public:
	TriangleRight(int a, int b, int c, int A, int B) :Triangle(a, b, c, A, B, 90) { name = "Прямоугольный треугольник"; }
};

class TriangleIsosceles : public Triangle
{
public:
	TriangleIsosceles(int a, int b, int A, int B) :Triangle(a, b, a, A, B, A) { name = "Равнобедренный треугольник"; }
};

class TriangleEquilateral : public Triangle
{
public:
	TriangleEquilateral(int a) :Triangle(a, a, a, 60, 60, 60) { name = "Равносторонний треугольник"; }
};

class Quadrilateral : public Figure
{
public:
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);
	void printParam() override;
protected:
	int a, b, c, d, A, B, C, D;
};

Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
{
	quantSides = 4;
	name = "Четырехугольник";
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;
}

void Quadrilateral::printParam()
{
	std::cout	<< name	<< ": \n"
				<< std::format("Стороны: a={}, b={}, c={}, d={}\n",a,b,c,d)		//c++20
				<< std::format("Углы:\t A={}, B={}, C={}, D={}\n\n",A,B,C,D);	//c++20
}

class Rectangle : public Quadrilateral
{
public:
	Rectangle(int a, int b) :Quadrilateral(a, b, a, b, 90, 90, 90, 90) { name = "Прямоугольник"; }
};

class Square : public Quadrilateral
{
public:
	Square(int a) :Quadrilateral(a, a, a, a, 90, 90, 90, 90) { name = "Квадрат"; }
};

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(int a, int b, int A, int B) :Quadrilateral(a, b, a, b, A, B, A, B) { name = "Параллелограмм"; }
};

class Rombus : public Quadrilateral
{
public:
	Rombus(int a, int A, int B) :Quadrilateral(a, a, a, a, A, B, A, B) { name = "Ромб"; }
};

void print_info(Figure *f)
{
	f->printParam();
}	

int main()
{
	setlocale(LC_ALL, "RU");
	Triangle			triangle(10,20,30,50,60,70);
	TriangleRight		triangleRight(10,20,30,50,60);
	TriangleIsosceles	triangleIsosceles(10,20,50,60);
	TriangleEquilateral triangleEquilateral(30);
	Quadrilateral		quadrilateral(10,20,30,40,50,60,70,80);
	Rectangle			rectangle(10,20);
	Square				square(20);
	Parallelogram		parallelogram(20,30,30,40);
	Rombus				rombus(30,30,40);

	print_info(&triangle);
	print_info(&triangleRight);
	print_info(&triangleIsosceles);
	print_info(&triangleEquilateral);
	print_info(&quadrilateral);
	print_info(&rectangle);
	print_info(&square);
	print_info(&parallelogram);
	print_info(&rombus);
	
	system("pause");
}