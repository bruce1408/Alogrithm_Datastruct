#include<iostream>
#include<vector>
#include<random>
#include<ctime>
#include<sys/time.h>
#include <math.h>

using namespace std;

vector<int> x;
const int MAX_INT = 1000000000;
const int sample_num = 100000000;

void generate_data()
{
	std::default_random_engine generator (time(0));
	std::uniform_int_distribution<int> distribution(0, MAX_INT);

	for (int i = 0; i < sample_num; i++) {
		x.push_back(distribution(generator));
	}	

	cout << "Generated uniform distribution samples between 0 and " << MAX_INT << endl;
	cout << "Number of samples is " << sample_num << endl;
}

int test(int n)
{
	int sum = 0;
	for (int i=0; i<n; i++)
		sum += x[i];

	return sum;
}

int main(int argc, char *argv[])
{
        struct timeval tp_begin, tp_end, tp_scan;
	long sum = 0;
	
	generate_data();
        
	gettimeofday(&tp_begin, NULL);

	int n = x.size();
	sum = test(n);

	gettimeofday(&tp_scan, NULL);

	cout << "Sum is " << sum << endl; 

	int elapse_time = tp_scan.tv_usec - tp_begin.tv_usec;
	elapse_time += 1000000*(tp_scan.tv_sec - tp_begin.tv_sec);
	cout<< "scan time: " << elapse_time << "usec" << endl;
	cout<< "Bandwidth is " << sizeof(int) * 1.0 * n / elapse_time <<" MB/s" << endl;
	return 0;
}
