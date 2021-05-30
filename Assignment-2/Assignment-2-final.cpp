#include<iostream>
#include<cmath>
using namespace std;
struct point {
	double x,y;
	point rotate(double angle) {
		angle = angle*3.14159/180;
		point p;
		p.x = x * cos(angle) + y * sin(angle);
		p.y = y * cos(angle) - x * sin(angle);
		return p;
	}
};
class Current {
public:
	point O;
	
	void translate(int x, int y) {
		O.x = O.x - x;
		O.y = O.y - y;
	}
};

class Circle : public Current
{
public:
	point centre{};
	float radius{};

	Circle(point p, float r)
	{
		centre=p;
		radius=r;
	}
	bool contains(point p) {
		float d = pow((p.x - (centre.x-O.x)),2) + pow((p.y - (centre.y-O.y)),2);
		if (d <= radius * radius) return true;
		return false;
	}
	Circle rotate(double angle) {
		Circle C{ centre.rotate(angle), radius };
		return C;
	}
};

int main() {
	point P = { 2.5,2.5 };
	Circle C1{ {0,0}, 5 };
	Current reg;
	C1.O = C1.centre;
	reg.O=C1.centre;
	std::cout<<" "<<C1.O.x<<" "<<C1.O.y<<"-"<<reg.O.x<<" "<<reg.O.y<<" ";
	if (C1.contains(P)) cout << "Yes\n";
	else cout << "No\n";

	P = { 4,4 };
	if (C1.contains(P)) cout << "Yes\n";
	else cout << "No\n";

	Circle C2 = C1;
	C2.translate(5,5);
	std::cout<<" "<<C2.O.x<<" "<<C2.O.y<<"-"<<reg.O.x<<" "<<reg.O.y<<" ";
	if (C1.contains(P) && !(C2.contains(P))) cout << "Yes\n";
	else cout << "No\n";

	Circle C3=C2.rotate(90);
	std::cout<<" "<<C3.O.x<<" "<<C3.O.y<<" ";
	if (C1.contains(P) && !(C2.contains(P))) cout << "Yes\n";
	else cout << "No\n";
}