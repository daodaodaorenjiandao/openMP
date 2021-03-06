#include <iostream>
#include <omp.h>
#include <windows.h>

#define ARRAY_SIZE 100

using namespace std;

int main()
{
	int threadIds[ARRAY_SIZE] = { 0 };

#pragma omp parallel for
	for(int i = 0; i < ARRAY_SIZE; ++i)
	{
		//这里循环迭代器是一个私有变量，所有不需要用private子句明显指明
		threadIds[i] = omp_get_thread_num();
		//int k = 0;	//在此指令下，k也会被处理为私有属性，当前openMP的版本为2.0
		//threadIds[i] = (int)&k;
	}

	cout << "thread id : \n";
	for(auto e : threadIds)
	{
		cout << e << " ";
	}
	cout << endl;

	cin.get();
	return 0;
}