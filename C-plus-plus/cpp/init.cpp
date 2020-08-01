#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int row = 2;
	int col = 3;
	int **p = new int*[row];
	for (int i = 0; i < row; ++i)
	{
		p[i] = new int[col];
		for (int j = 0; j < col; ++j)
		{
			p[i][j] = i * col + j;
		}
	}
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			printf("p[%d][%d] = %d\n", i, j, p[i][j]);


	cout << "--------------------" << endl;
	int *p1 = new int[5];  // 未初始化， p 指向含 5 的整数的堆内存空间的首地址
	cout << p1[0] << " " << p1[1] << " " << *p1 << endl;
	int *p2 = new int(5);   // 初始化一个值，p 指向一个数
	cout << p2[0] << " " << p2[1] << " " << *p2 << endl;


	cout << "----------------------" << endl;
	int a = 2, b = 2, c = 3;
	vector<vector<vector<int> > > v(a, vector<vector<int> >(b, vector<int>(c, 5)));
	for (int i = 0; i < v.size(); ++i)
		for (int j = 0; j < v[0].size(); ++j)
			for (int k = 0; k < v[0][0].size(); ++k)
				printf("v[%d][%d][%d] = %d\n", i, j, k, v[i][j][k]);


	cout << "-------------------------" << endl;
	vector<int> v1(c, 6);
	vector<vector<int> >v2(b, v1);
	vector<vector<vector<int> > >v3(a, v2);
	for (int i = 0; i < v.size(); ++i)
		for (int j = 0; j < v[0].size(); ++j)
			for (int k = 0; k < v[0][0].size(); ++k)
				printf("v3[%d][%d][%d] = %d\n", i, j, k, v3[i][j][k]);


	cout << "-------------------------" << endl;
	int* pmalloc = (int *)malloc(sizeof(int) * row * col);
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			pmalloc[i * col + j] = i * col + j;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			printf("pmalloc[%d * %d + %d] = %d\n", i, col, j, pmalloc[i * col + j]);
	free(pmalloc);
			

	getchar();
}