#include <iostream>
#include <math.h>

using namespace std;

//�������ɵĽڵ������
double dataX_[1000];
//�������ɵĽڵ�������
double dataY[1000];
//����һ����ѧ����
double function(double x);
//�ָ�����
void devide(double a, double b, int N);
//�����������
double getIntegralValue(double a, double b, int N);

int main_c()
{
	//�����Ľڵ���
	double a, b;
	int N;
	char ch = 'n';
	while (ch != 'y')
	{
		cout << "������ȷ���������";
		cin >> N;
		cout << "�������������䷶Χ��";
		cin >> a;
		cin >> b;
		devide(a, b, N);
		cout << "����ֵΪ��" << getIntegralValue(a, b, N) << endl;
		cout << "�Ƿ��������y�˳�:";
		cin >> ch;
	}
	return 0;
}
//����һ����ѧ����
double function(double x)
{
	return 4/(1+x*x);
}
//�ָ�����
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
//�����������
double getIntegralValue(double a, double b, int N)
{
	double sum = 0;
	//��2*f(xk)���ܺͣ�1<= k <= n-1
	for (int i = 1; i <= N - 1; i++)
	{
		sum += 2 * dataY[i];
	}
	double value = 0.5* ((b - a) / N)*(dataY[0] + sum + dataY[N]);
	return value;
}