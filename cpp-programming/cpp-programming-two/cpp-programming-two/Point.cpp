#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
	设计并实现二维坐标系下点的类point,类的每个对象含有横  纵坐标,为类point添加必要的计算函数,
	例如,计算给定点到(0,0)的距离,计算给定两点间的距离, 判断给定3个点是否构成三角形等
	公式:
	计算给定点到0，0的距离 公式:
		根号(x1-x2)平方+(y1-y2)平方 的绝对值.
	计算两点之间的距离 公式: 
		根号(x1 - x2)平方 + 根号(y1 - y2)平方
*/
class Point {
private:
	double x;
	double y;
public:
	//构造函数
	Point();
	Point(double x1, double y1);
	//get set
	void setX(int x1);
	double getX();
	void setY(int y1);
	double getY();
	//计算给定点到0.0的距离
	double distance(Point p);
	//计算两点之间的距离
	double distancePoint(Point p1, Point p2);
	//判断三个点是否形成三角形
	bool isTriangle(Point p1, Point p2, Point p3);
	bool isTriangleTwo(Point p1, Point p2, Point p3);
};

Point::Point(double x1, double y1) {
	x = x1;
	y = y1;
}

//get set
void Point::setX(int x1) {
	x = x1;
}
double Point::getX() {
	return x;
}

void Point::setY(int y1) {
	y = y1;
}
double Point::getY() {
	return y;
}
//计算给定点到0.0的距离
//	根号(x1 - x2)平方 + (y1 - y2)平方 的绝对值. 由于计算的是0.0所以不需要x2
//例如: abs( sqrt( pwo( x, 2 ) + pow( y, 2 ) ) )
double Point::distance(Point p) {
	return abs(sqrt(pow(p.getX(), 2) + pow(p.getY(), 2)));
}

//计算两点之间的距离
//根号(x1 - x2)平方 + (y1 - y2)平方的绝对值
double Point::distancePoint(Point p1, Point p2) {
	return abs( sqrt( pow( p1.getX() - p2.getX(), 2) + pow( p1.getY() - p2.getY(), 2) ) );
}
//判断三个点是否形成三角形
bool Point::isTriangle(Point p1, Point p2, Point p3) {
	double t1, t2, t3;
	t1 = sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
	t2 = sqrt(pow(p1.getX() - p3.getX(), 2) + pow(p1.getY() - p3.getY(), 2));
	t3 = sqrt(pow(p3.getX() - p2.getX(), 2) + pow(p3.getY() - p2.getY(), 2));
	if (t1 + t2 > t3 || t1 + t3 > t2 || t2 + t3 > t1) {
		cout << "构成三角形" << endl;
		return true;
	}else {
		cout << "不构成三角形" << endl;
		return false;
	}
}
//给定的三个点是否是三角形 任意两边之和大于第三边即成立  或者判断是否在一条直线 
bool Point::isTriangleTwo(Point p1, Point p2, Point p3) {
	double t1, t2, t3;
	t1 = abs(sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2)));
	t2 = abs(sqrt(pow(p1.getX() - p3.getX(), 2) + pow(p1.getY() - p3.getY(), 2)));
	t3 = abs(sqrt(pow(p2.getX() - p3.getX(), 2) + pow(p2.getY() - p3.getY(), 2)));
	if (t1 + t2 > t3 && t1 + t3 > t2 && t2 + t3 > t1) {
		cout << "构成三角形" << endl;
		return true;
	}
	cout << "不构成三角形" << endl;
	return false;
}

int main()
{
	Point p(3, 3), p2(4, 4), p3(5, 6);
	cout << p.distance(p) << endl;
	cout << p.distancePoint(p, p2) << endl;
	cout << p.isTriangle(p, p2, p3) << endl;
	cout << p.isTriangleTwo(p, p2, p3) << endl;
	system("pause");
	return 0;
}
