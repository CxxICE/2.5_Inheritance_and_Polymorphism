#include <iostream>
#include <string>
#include <format>

class Figure
{
public:
	virtual void printParam();
	virtual bool checkParam();
protected:
	int quantSides = 0;
	std::string name = "Фигура";
};

void Figure::printParam()
{
	std::cout	<< '\n' << name << ": \n"
				<< (checkParam() ? "Правильная\n" : "Неправильная\n")
				<< "Количество сторон: " << quantSides << '\n';
}

bool Figure::checkParam()
{
	bool check = 0;
	if(quantSides == 0) { check = 1; }
	return check;
}

class Triangle : public Figure
{
public:
	Triangle(int a, int b, int c, int A, int B, int C);
	void printParam() override;
	bool checkParam() override;
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
	Figure::printParam();
	std::cout	<< std::format("Стороны: a={}, b={}, c={}\n",a,b,c)			//c++20
				<< std::format("Углы:\t A={}, B={}, C={}\n",A,B,C);			//c++20
}

bool Triangle::checkParam()
{
	bool check = 0;
	if((quantSides == 3) && (A + B + C == 180)) { check = 1; }
	return check;
}

class TriangleRight : public Triangle
{
public:
	TriangleRight(int a, int b, int c, int A, int B) :Triangle(a, b, c, A, B, 90) { name = "Прямоугольный треугольник"; }
	bool checkParam() override;
};

bool TriangleRight::checkParam()
{
	bool check = 0;
	if((Triangle::checkParam()) && (C == 90)) { check = 1; }
	return check;
}

class TriangleIsosceles : public Triangle
{
public:
	TriangleIsosceles(int a, int b, int A, int B) :Triangle(a, b, a, A, B, A) { name = "Равнобедренный треугольник"; }
	bool checkParam() override;
};

bool TriangleIsosceles::checkParam()
{
	bool check = 0;
	if((Triangle::checkParam()) && (a == c) && (A == C)) { check = 1; }
	return check;
}

class TriangleEquilateral : public Triangle
{
public:
	TriangleEquilateral(int a) :Triangle(a, a, a, 60, 60, 60) { name = "Равносторонний треугольник"; }
	bool checkParam() override;
};

bool TriangleEquilateral::checkParam()
{
	bool check = 0;
	if((Triangle::checkParam()) && (a == b) && (a == c) && (A == 60) && (B == 60) && (C == 60)) { check = 1; }
	return check;
}

class Quadrilateral : public Figure
{
public:
	Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);
	void printParam() override;
	bool checkParam() override;
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
	Figure::printParam();
	std::cout	<< std::format("Стороны: a={}, b={}, c={}, d={}\n",a,b,c,d)		//c++20
				<< std::format("Углы:\t A={}, B={}, C={}, D={}\n",A,B,C,D);		//c++20
}

bool Quadrilateral::checkParam()
{
	bool check = 0;
	if((quantSides == 4) && (A + B + C + D == 360)) { check = 1; }
	return check;
}

class Rectangle : public Quadrilateral
{
public:
	Rectangle(int a, int b) :Quadrilateral(a, b, a, b, 90, 90, 90, 90) { name = "Прямоугольник"; }
	bool checkParam() override;
};

bool Rectangle::checkParam()
{
	bool check = 0;
	if((Quadrilateral::checkParam()) && (a == c) && (b == d) && (A == 90) && (B == 90) && (C == 90) && (D == 90)) { check = 1; }
	return check;
}

class Square : public Quadrilateral
{
public:
	Square(int a) :Quadrilateral(a, a, a, a, 90, 90, 90, 90) { name = "Квадрат"; }
	bool checkParam() override;
};

bool Square::checkParam()
{
	bool check = 0;
	if((Quadrilateral::checkParam()) && (a == c) && (b == d) && (b == c) && (A == 90) && (B == 90) && (C == 90) && (D == 90)) { check = 1; }
	return check;
}

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(int a, int b, int A, int B) :Quadrilateral(a, b, a, b, A, B, A, B) { name = "Параллелограмм"; }
	bool checkParam() override;
};

bool Parallelogram::checkParam()
{
	bool check = 0;
	if((Quadrilateral::checkParam()) && (a == c) && (b == d) && (A == C) && (B == D)) { check = 1; }
	return check;
}

class Rombus : public Quadrilateral
{
public:
	Rombus(int a, int A, int B) :Quadrilateral(a, a, a, a, A, B, A, B) { name = "Ромб"; }
	bool checkParam() override;
};

bool Rombus::checkParam()
{
	bool check = 0;
	if((Quadrilateral::checkParam()) && (a == c) && (b == d) && (b == c) && (A == C) && (B == D)) { check = 1; }
	return check;
}

void print_info(Figure *f)
{
	f->printParam();
}	

int main()
{
	setlocale(LC_ALL, "RU");
	Figure				figure;
	Triangle			triangle(10,20,30,50,60,70);
	TriangleRight		triangleRight(10,20,30,50,60);
	TriangleRight		triangleRight2(10,20,30,50,40);
	TriangleIsosceles	triangleIsosceles(10,20,50,60);
	TriangleEquilateral triangleEquilateral(30);
	Quadrilateral		quadrilateral(10,20,30,40,50,60,70,80);
	Rectangle			rectangle(10,20);
	Square				square(20);
	Parallelogram		parallelogram(20,30,30,40);
	Rombus				rombus(30,30,40);

	print_info(&figure);
	print_info(&triangle);
	print_info(&triangleRight);
	print_info(&triangleRight2);
	print_info(&triangleIsosceles);
	print_info(&triangleEquilateral);
	print_info(&quadrilateral);
	print_info(&rectangle);
	print_info(&square);
	print_info(&parallelogram);
	print_info(&rombus);

	system("pause");
}