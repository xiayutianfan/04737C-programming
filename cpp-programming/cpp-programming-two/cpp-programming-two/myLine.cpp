#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
	设计并实现一个类MyLine,它表示直线. 定义一些基本计算函数,
	例如: 求直线的斜率  判别给定点是否在线上, 计算给定点到给定直线的距离等
*/

class MyLine {
private :
	double px1, py1;
	double px2, py2;
public:
	//构造函数
	MyLine(double x1, double y1, double x2, double y2);
	//直线的斜率
	double slope();
	//点是否在线上
	bool isOnLine(double x, double y);
	//点到直线的距离
	double distance(double x, double y);
};

MyLine::MyLine(double x1, double y1, double x2, double y2) {
	px1 = x1;
	py1 = y1;
	px2 = x2;
	py2 = y2;
}

//斜率 公式：k=(y2-y1)/(x2-x1)
double MyLine::slope() {
	return (py2 - py1) / (px2 - px1);
}

//点是否在线上  y-beginY =(斜率)k * (x - beginX)
bool MyLine::isOnLine(double x, double y) {
	if ((y - py1) == (slope() * (x - px1))) {
		return true;
	}
	return false;
}

//点到直线的距离 d = [A*X + B*Y + C的绝对值]/[(A*A + B*B)的算术平方根]
//求出 A 的公式 py2 - py1
//求出 B 的公式 px1 - px2
//求出C的公式 px2 * py1 - px1 * py2
double MyLine::distance(double x, double y) {
	double a = py2 - py1;
	double b = px1 - px2;
	double c = (px2 * py1) - (px1 * py2);
	return abs(a*x + b*y + c) / sqrt(a*a + b*b);
}

int main()
{
	MyLine test(3, 3, 8, 8);
	cout << test.slope() << endl;
	cout << test.isOnLine(6, 6) << endl;
	cout << test.distance(6, 6) << endl;

	system("pause");
	return 0;
}