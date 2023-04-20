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
int findMinLine()
{
	int minI, minCount = 10000, counter;
	for(int i = 0; i < height; i++)
	{
		counter = 0;
		for(int j = 0; j < width; j++)
		{
			if(matrix[i][j] == 1)
				counter++;
		}
		if(counter < minCount && counter != 0)
		{
			minCount = counter;
			minI = i;
		}
	}
	return minI;
}
void deleteColumns(int line)
{
	for(int i = 0; i < width; i++)
	{
		if(matrix[line][i])
		{
			for(int j = 0; j < height; j++)
			{
				matrix[j][i] = -1;
			}	
		}
	}
}

void deleteLine(int line)
{
	for(int i = 0; i < width; i++)
	{
		matrix[line][i] = -1;
	}
}

bool findKernel()
{
	int counter, findJ;
	for(int i = 0; i < width; i++)
	{
		counter = 0;
		for(int j = 0; j < height; j++)
		{
			if(matrix[j][i] == 1)
			{
				counter++;
				findJ=j;
			}
		}
		if(counter == 1)
		{
			p.push_back(findJ);
			deleteColumns(findJ);
			deleteLine(findJ);
			
			outputMatrix();
			findKernel();
			return true;
		}
	}
	return false;
}

void linesAbsorbed(int minLine)
{
	int counter;
	for(int i = 0; i < width; i++)
	{
		counter = 1;
		if(matrix[minLine][i])
		{
			counter = 0;
			for(int j = 0; j < height; j++)
			{
				if(matrix[j][i] == 1){
					counter++;
				}
			}
			if(counter == 1){
				break;
			}
				
		}
	}
	if(counter != 1){
		deleteLine(minLine);
		outputMatrix();
		linesAbsorbed(findMinLine());
	}
}

bool check()
{
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			if(matrix[i][j] != -1)
				return true;
		}
	}
	return false;
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
	
	while(findKernel()){ 
		linesAbsorbed(findMinLine());
		
	}
	if(check())
	{
		cout << "Знайти покриття методом інтервалів";
	}else{
		outputData();
	}
	
}
