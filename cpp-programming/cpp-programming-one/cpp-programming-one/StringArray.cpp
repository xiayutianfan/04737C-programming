#include <iostream>
#include <string>
using namespace std;
/*
	第一章第1小题:
		编写一个程序,将从键盘输入的n个字符串保存在一个一维数组A中,在输入字符串之前,
		先输入n的值,要求,数组A需要动态申请空间,程序运行结束前再释放掉
*/
//int main() {
//
//	//声明一个n用来接收用户输入的数组长度
//	int n;
//	cout << "请输入数组的长度: " << endl;
//	//等待用户输入
//	cin >> n;
//	//创建n个字符串数组
//	string *str = new string[n];
//
//	cout << "请输入" << n << "个字符串" << endl;
//	for (int i = 0; i < n; i++) {
//		cin >> str[i];
//	}
//
//	for (int i = 0; i < n; i++) {
//		cout << str[i] << ", ";
//	}
//	cout << endl;
//	//释放掉字符串动态数组
//	delete[]str;
//
//	//这样子是申请二维动态数组的,列数必须是一个常量
//	//string (*str)[2] = new string[n][2];
//
//	system("pause");
//	return 0;
//}