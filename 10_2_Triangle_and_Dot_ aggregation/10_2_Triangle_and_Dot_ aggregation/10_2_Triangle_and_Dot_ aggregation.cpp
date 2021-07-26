using namespace std;
#include <iostream>
#include <math.h>

class Dot
{
	friend class Triangle;
private:
	double x;
	double y;
public:
	Dot() :x(0), y(0)
	{}

	Dot(double px, double py) :x(px), y(py)
	{}

	double DistTo(Dot p)
	{
		return  sqrt((p.x - x)*(p.x - x) + (p.y - y)*(p.y - y));

	}

	void Set(double px, double py)
	{
		x = px;
		y = py;
	}

};

struct TriangleSide {
	double side1;
	double side2;
	double side3;
};
class Triangle
{
	Dot *a;
	Dot *b;
	Dot *c;

public:
	Triangle(Dot *pa, Dot *pb, Dot *pc) :a(pa), b(pb), c(pc) // агрегация
	{}

	TriangleSide getSide(Dot *pa, Dot *pb, Dot *pc)
	{
		TriangleSide tr;
		tr.side1 = pa->DistTo(*pb);
		tr.side2 = pb->DistTo(*pc);
		tr.side3 = pc->DistTo(*pa);
		return tr;
	}


	double getArea()
	{
		return abs((a->x - c->x) * (b->y - c->y) - (b->x - c->x) * (a->y - c->y)) / 2;
	}

	double getPerimetr(TriangleSide trin)
	{
		return (trin.side1 + trin.side2 + trin.side3);
	}
};


int main()
{
	cout.precision(5);
	Dot* a = new Dot(1, 10);
	Dot* b = new Dot(2, 20);
	Dot* c = new Dot(16, 3);
	Triangle tr1( a, b, c);
	double Area = tr1.getArea();
	cout << "Square = " << Area << endl;
	TriangleSide tri;
	tri = tr1.getSide( a,  b,  c);
	cout << "Sides  " << tri.side1 << "--" << tri.side2 << "--" << tri.side3 << endl;
	double Perimetr = tr1.getPerimetr(tri);
	cout << "Perimetr = " << Perimetr << endl;


}

