#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
#define e     0.00000001
#define maxn 50

int    n;//��ģnXn����
double a[maxn][maxn];//ϵ������
double b[maxn];//b����
double m[maxn][maxn];//�м��������
double x[maxn];//���ս�
int    H = 1;//����H�����㣨�Ż���

//��ȡ����
void read(){
	cout << "������ϵ�������ģn:= ";
	cin >> n;
	cout << "|-----------------------------\n";
	cout << "|������ϵ������,�磺\n";
	cout << "|1.1348 3.8326 1.1651 3.4017\n";
	cout << "|0.5301 1.7875 2.5330 1.5435\n";
	cout << "|3.4129 4.9317 8.7643 1.3142\n";
	cout << "|1.2371 4.9998 10.6721 0.0147\n";
	cout << "|-----------------------------\n";
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++){
		cin >> a[i][j];
		a[i][j] *= H;
	}
	cout << "|-----------------------------\n";
	cout << "|������b�����磺\n";
	cout << "|9.5342 6.3941 18.4231 16.9237\n";
	cout << "|-----------------------------\n";
	for (int i = 1; i <= n; i++){
		cin >> b[i];
		b[i] *= H;
	}
}

/*
�м�������
��������Ԫ����
*/
void PrintProc(int cases){
	printf("--------��%d����Ԫ������£�\n", cases);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cout << setw(10) << a[i][j] << ' ';
		}
		cout << setw(10) << b[i] << '\n';
	}
	cout << "END THIS SHOW-------------\n";
}


//��ʾ���

void Print(){
	cout << "|-----------------------------\n";
	cout << "|���Ϊ��\n";
	for (int i  = 1; i <= n; i++){
		printf("x[%d]=  %lf\n", i, x[i]);
	}
	cout << "|-----------------------------\n\n";
}


//˳����Ԫ��

void ShunXuXiaoYuan(){
	//��Ԫ����
	for (int k = 1; k<n; k++){
		for (int i = k + 1; i <= n; i++){
			m[i][k] = a[i][k] / a[k][k];
			for (int j = k + 1; j <= n; j++){
				a[i][j] -= m[i][k] * a[k][j];
			}
		}
		for (int i = k + 1; i <= n; i++){
			b[i] -= m[i][k] * b[k];
		}
		PrintProc(k);//����м�������
	}
	//�ش����
	x[n] = b[n] / a[n][n];
	for (int i = n - 1; i>0; i--){
		x[i] = b[i];
		for (int j = i + 1; j <= n; j++)
			x[i] -= a[i][j] * x[j];
		x[i] /= a[i][i];
	}
	//������
	Print();
}


//������Ԫ

void LieZhuXiaoYuan(){
	for (int k = 1; k<n; k++){
		//ѡ��Ԫ[��һ�еľ���ֵ���ֵ]
		double ab_max = -1;
		int       max_ik;
		for (int i = k; i <= n; i++){
			if (abs(a[i][k])>ab_max){
				ab_max = abs(a[i][k]);
				max_ik = i;
			}
		}
		//�����д���[���ж��Ƿ�Ϊ0����]
		if (ab_max<e){//0�������
			cout << "det A=0\n";
			break;
		}
		else if (max_ik != k){//�Ƿ��ǵ�ǰ�У����ǽ���
			double temp;
			for (int j = 1; j <= n; j++){
				temp = a[max_ik][j];
				a[max_ik][j] = a[k][j];
				a[k][j] = temp;
			}
			temp = b[max_ik];
			b[max_ik] = b[k];
			b[k] = temp;
		}
		//��Ԫ����
		for (int i = k + 1; i <= n; i++){
			a[i][k] /= a[k][k];
			for (int j = k + 1; j <= n; j++){
				a[i][j] -= a[i][k] * a[k][j];
			}
			b[i] -= a[i][k] * b[k];
		}
		PrintProc(k);//����м�������
		if (k<n - 1)continue;
		else{
			if (abs(a[n][n])<e){
				cout << "det A=0\n";
				break;
			}
			else{//�ش����
				x[n] = b[n] / a[n][n];
				for (int i = n - 1; i>0; i--){
					x[i] = b[i];
					for (int j = i + 1; j <= n; j++)
						x[i] -= a[i][j] * x[j];
					x[i] /= a[i][i];
				}
				//������
				Print();
			}
		}
	}
}

/*
������
*/
int main(){
	while (1){
		read();
		LieZhuXiaoYuan();
		//ShunXuXiaoYuan();
	}return 0;
}
/*
���ϸ�˹��Ԫ�����ӣ�
1 1 1
1 3 -2
2 -2 1

6 1 1
*/
/*
����������Ԫ�����ӣ�
-0.002 2 2
1 0.78125 0
3.996 5.5625 4

0.4 1.3816 7.4178
*/