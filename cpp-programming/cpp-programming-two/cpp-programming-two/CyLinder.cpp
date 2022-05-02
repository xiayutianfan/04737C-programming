#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class CyLinder {
private:
	//半径
	double r;
	//高
	double h;
public:
	//定义一个PI
	double PI = 3.1415926;
	CyLinder(double x, double y);
	//get set
	void setR(double x);
	void setH(double y);
	double getR();
	double getH();
	//计算表面积
	double area();
	double area2();
	//计算体积
	double volume();
	double volume2();
	//计算低圆周长
	double lowC();
	//计算圆柱的侧面积
	double perimeter();
	//计算低圆面积
	double lowArea();
};

CyLinder::CyLinder(double x, double y){
	r = x;
	h = y;
}
//get set
void CyLinder::setR(double x) {
	r = x;
}
void CyLinder::setH(double y) {
	h = y;
}
double CyLinder::getR() {
	return r;
}
double CyLinder::getH() {
	return h;
}
//计算表面积
//(PI*r*h*2) + (2*PI*r*r)
double CyLinder::area() {
	double s = (PI * r * h * 2) + (2 * PI * r * r);
	return s;
}
//计算体积
// 公式: V=π*r*r*h
double CyLinder::volume() {
	double v = PI * r * r * h;
	return v;
}

//计算低圆周长
//圆柱体底面周长公式是C=πd=2πr
double CyLinder::lowC() {
	double c = 2 * PI*r;
	return c;
}

//计算圆柱的侧面积
//圆柱的侧面积=底面周长x高，即：S侧面积=Ch=2πrh
double CyLinder::perimeter() {
	double s = lowC() * h;
	return s;
}

//计算低圆面积
//底面积：πr²（π×半径×半径）
double CyLinder::lowArea() {
	double l = PI * r * r;
	return l;
}

//圆柱的表面积=侧面积+两个底面积(S表=S侧+2S底)
double CyLinder::area2() {
	double s = perimeter() + (lowArea() * 2);
	return s;
}

//表达式为V=π*r²*h; 圆柱的体积=底面积x高
double CyLinder::volume2() {
	double v = lowC()*h;
	return v;
}

int main() {
	int r, h;
	cout << "请输入圆柱的半径: " << endl;
	cin >> r;
	cout << "请输入圆柱的高度: " << endl;
	cin >> h;
	CyLinder c(r, h);
	cout << c.area() << endl;
	cout << c.area2() << endl;
	system("pause");
	return 0;
}