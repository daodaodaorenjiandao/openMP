#include <iostream>
#include <omp.h>

#define ARRAY_SIZE 100
using namespace std;

void setNumber(int ids[], int startPos, int nElement,int value)
{
	for(int i = 0; i < nElement; ++i)
	{
		ids[startPos + i] = value;
	}
}

void ParallelizeSetNumber(int ids[], int size)
{
	int nElementPerThread;
	int startPos;
	int threadId;
	int nThread;

#pragma omp parallel default(shared) private(nElementPerThread,startPos,threadId,nThread)
	{
		nThread = omp_get_num_threads();
		threadId = omp_get_thread_num();
		nElementPerThread = size / nThread;
		startPos = threadId * nElementPerThread;

		if(threadId == nThread - 1)
			nElementPerThread = size - startPos;

		setNumber(ids, startPos, nElementPerThread, threadId);
	}
}

int main()
{
	int ids[ARRAY_SIZE];
	//init ids
	for(auto& e : ids)
		e = -1;

	ParallelizeSetNumber(ids, ARRAY_SIZE);

	//print ids;
	for(auto e : ids)
		cout << e << " ";
	cout << endl;

	cin.get();
	return 0;
}