#include <iostream>
#include <Windows.h>
using namespace std;

#define n 5

class Vector
{
private:
	double X[n];
public:
	friend void input(Vector  Y[]);
	friend void output(Vector  Y[]);
	friend void output_f(Vector  Y[]);
	void merge(double arr[], int l, int m, int r)
	{
		int i, j, k;
		int n1 = m - l + 1;
		int n2 = r - m;
		double *L = new double[n1];
		double *R = new double[n2];
		for (i = 0; i < n1; i++)
			L[i] = arr[l + i];
		for (j = 0; j < n2; j++)
			R[j] = arr[m + 1 + j];
		i = 0;
		j = 0;
		k = l;
		while (i < n1 && j < n2)
		{
			if (L[i] >= R[j])
			{
				arr[k] = L[i];
				i++;
			}
			else
			{
				arr[k] = R[j];
				j++;
			}
			k++;
		}
		while (i < n1)
		{
			arr[k] = L[i];
			i++;
			k++;
		}
		while (j < n2)
		{
			arr[k] = R[j];
			j++;
			k++;
		}
		delete[]L;
		delete[]R;
	}
	void mergeSort(double arr[], int l, int r)
	{
		if (l < r)
		{
			int m = l + (r - l) / 2;
			mergeSort(arr, l, m);
			mergeSort(arr, m + 1, r);
			merge(arr, l, m, r);
		}
	}
	void sort(Vector  Y[])
	{
		for (int i = 0; i < n; i++)
		{
			mergeSort(Y[i].X, 0, n - 1);
		}
	}
	void _f(Vector  Y[], Vector Q[])
	{
		for (int j = 1; j < n; j++)
		{
			Q[0].X[j] = 0;
			for (int i = 0; i < j; i++)
				Q[0].X[j] += Y[i].X[j];//����������� ���� ��������, �� ����������� ��� �������� ���������
		}
	}
	float F(Vector  Y[])//������� ��� ����������� F
	{
		double F = 1;
		for (int i = 1; i < n; i++)
			F *= Y[0].X[i];//������������ ��� �������� ������ f
		return F;
	}
};



void input(Vector  Y[])//������ ������� ��� ����� ������� 
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> Y[i].X[j];
}

void output(Vector  Y[])//������ ������� ��� ������ ������� 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout <<  Y[i].X[j] << "\t";
		cout << endl;
	}
}

void output_f(Vector  Y[])
{
	for (int j = 1; j < n; j++)
		cout << Y[0].X[j] << "\t";
	cout << endl;
}

int main()
{
	SetConsoleOutputCP(1251);//���� ��������� ��� ����������� ����������� ���������� ����
	Vector B[n];//����� �� ����������� ������
	cout << "������ �������� �������" << endl;
	input(B);//�������� ������
	system("cls");//�������� ������
	cout << "������� ������� �� ������:" << endl;
	output(B);//���� ������
	B->sort(B);//���������� ����� � �����
	cout << "³���������� �������:" << endl;
	output(B);//���� ����������� �������
	Vector f[1];//����� �� ���������� f
	f->_f(B,f);//����������� �������� f
	cout << "����� f �� ������:" << endl;
	output_f(f);//���� ������ f
	float _F= f->F(f);//������ ������� ��� ����������� F
	cout << "F=" << _F << endl;//���� �� ����� �������� F
	system("pause");//�������� ���������� �� �����
	return 0;
}