#include <iostream>
#include <math.h>

using namespace std;

//保存生成的节点横坐标
double dataX_[1000];
//保存生成的节点纵坐标
double dataY[1000];
//定义一个数学函数
double function(double x);
//分割区间
void devide(double a, double b, int N);
//复化梯形求积
double getIntegralValue(double a, double b, int N);

int main_c()
{
	//产生的节点数
	double a, b;
	int N;
	char ch = 'n';
	while (ch != 'y')
	{
		cout << "请输入等分区间数：";
		cin >> N;
		cout << "请输入左右区间范围：";
		cin >> a;
		cin >> b;
		devide(a, b, N);
		cout << "积分值为：" << getIntegralValue(a, b, N) << endl;
		cout << "是否继续？按y退出:";
		cin >> ch;
	}
	return 0;
}
//定义一个数学函数
double function(double x)
{
	return 4/(1+x*x);
}
//分割区间
void devide(double a, double b, int N)
{
	double x;
	double dX = (b - a) / (N);
	for (int i = 0; i <= N; i++)
	{
		x = a + i * dX;
		dataX_[i] = x;
		dataY[i] = function(x);
	}
}
//复化梯形求积
double getIntegralValue(double a, double b, int N)
{
	double sum = 0;
	//求2*f(xk)的总和，1<= k <= n-1
	for (int i = 1; i <= N - 1; i++)
	{
		sum += 2 * dataY[i];
	}
	double value = 0.5* ((b - a) / N)*(dataY[0] + sum + dataY[N]);
	return value;
}