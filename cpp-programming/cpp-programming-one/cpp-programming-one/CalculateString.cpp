#include <iostream>
#include <string>
using namespace std;
/*
第一章第1小题:
	编写一个程序,将从键盘输入的n个字符串保存在一个一维数组A中,在输入字符串之前,
	先输入n的值,要求,数组A需要动态申请空间,程序运行结束前再释放掉
第一章第2小题:
	在题目1的基础上,输出n个字符串中最长和最短的串, 计算n个串的平均长度,并且输出结果
	
	计算平均值:
		例如n=3
		(字符串[0].length() + 字符串[1].length() + 字符串[2].length()) / 3
*/
int main() {

	//声明一个n用来接收用户输入的数组长度
	int n = 0;
	cout << "请输入数组的长度: " << endl;
	//等待用户输入
	cin >> n;
	//创建n个字符串数组
	string *str = new string[n];

	cout << "请输入" << n << "个字符串" << endl;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	string temp, longest, shortest;

	//直接使用冒泡排序
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (str[j].length() > str[j + 1].length()) {
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}

	//输出最长和最短的字符串
	longest = str[n - 1];
	shortest = str[0];
	cout << "最长的字符串是: " << longest << endl;
	cout << "最短的字符串是: " << shortest << endl;
	cout << endl;

	//输出n个字符串的平均值
	int avg = 0;
	for (int i = 0; i < n; i++) {
		avg += str[i].length();
	}
	
	avg = avg / n;
	cout << "字符串的平均值是: " << avg << endl;

	//释放掉字符串动态数组
	delete[]str;

	system("pause");
	return 0;
}