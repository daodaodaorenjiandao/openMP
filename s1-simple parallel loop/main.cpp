#include <iostream>
#include <omp.h>
#include <windows.h>

#define ARRAY_SIZE 1000

using namespace std;

int main()
{
	int threadIds[ARRAY_SIZE] = { 0 };

#pragma omp parallel for
	for(int i = 0; i < ARRAY_SIZE; ++i)
	{
		//����ѭ����������һ��˽�б��������в���Ҫ��private�Ӿ�����ָ��
		threadIds[i] = omp_get_thread_num();
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