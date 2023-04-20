#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int width, height;
int matrix[100][100];
vector<int>p;

void inputData()
{
	
	cout << "Кількість рядків: ";
	cin >> height;
	cout << "Кількість стовпців: ";
	cin >> width;
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			cin >> matrix[i][j];
		}
	}
}
int minColumn()
{
	int sum, minSum = 1000, minI;
	for(int i = 0; i < width; i++)
	{
		sum = 0;
		for(int j = 0; j < height; j++)
		{
			if(matrix[j][i] == 1)
			{
				sum++;
			}
		}
		if(sum < minSum && sum > 0)
		{
			minSum = sum;
			minI = i;
		}
	}
	return minI;
}

int maxLine(int minColumn)
{
	int sum, maxSum = -1, maxI;
	for(int i = 0; i < height; i++)
	{
		sum = 0;
		for(int j = 0; j < width; j++)
		{
			if(matrix[i][j] == 1 && matrix[i][minColumn] == 1)
			{
				sum++;
			}
		}
		if(sum > maxSum)
		{
			maxSum = sum;
			maxI = i;
		}
	}
	p.push_back(maxI);
	return maxI;
}
void deleteColumns_Line(int maxLine)
{
	for(int i = 0; i < width; i++)
	{
		if(matrix[maxLine][i])
		{
			for(int j = 0; j < height; j++)
			{
				matrix[j][i] = -1;
			}	
		}
		else
		{
			matrix[maxLine][i] = -1;
		}
	}
}

void outputMatrix()
{
	cout << "--------------------------------" << endl;
	for(int i = 0; i < height; i++)
	{
		cout<< char(65+i) << ": ";
		for(int j = 0; j < width; j++)
		{
			if(matrix[i][j] == -1)
				cout << "- ";
			else
				cout << matrix[i][j] << " ";
		}
		cout<<endl;
	}
}
bool check()
{
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			if(matrix[i][j] != -1)
				return false;
		}
	}
	return true;
}
void outputData()
{
	sort(p.begin(), p.end());
	cout << "--------------------------------" << endl;
	cout << "Найкоротше покриття: ";
	
	for(int i = 0; i < p.size(); i++)
	{
		cout << char(65+p[i]) << " ";
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int maxLin, minCol;
	
	inputData();
	outputMatrix();
	
	do{
		minCol = minColumn();
    	maxLin = maxLine(minCol);
    	
    	deleteColumns_Line(maxLin);
    	
    	outputMatrix();
	}while(!check());
	
	outputData();
}
