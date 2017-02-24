#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <omp.h>

using namespace std;

void Parallel()
{
	omp_set_dynamic(1);
	omp_set_nested(1);
	#pragma omp parallel
	{
		//omp_set_nested(0);
		#pragma omp parallel
		{
			#pragma omp single
			{
				cout << "first group, thread id : " << omp_get_thread_num() << "\t num threads : " << omp_get_num_threads() << endl;
			}
		}

		#pragma omp barrier
		#pragma omp single
		{
			cout << "\n\n\n";
		}

		omp_set_nested(1);
		#pragma omp parallel
		{
			#pragma omp single
			{
				cout << "second group, thread id : " << omp_get_thread_num() << "\t num threads : " << omp_get_num_threads() << endl;
			}
		}
	}
}

int main()
{
	const char * evnPath = getenv("OMP_NUM_THREADS");

	if(evnPath)
	{
		cout << "found the env : ";
		cout << evnPath << endl;
	}
	else
	{
		cout << "can not found the OMP_NUM_THREADS env!" << endl;
	}

	Parallel();

	cin.get();
	return 0;
}
