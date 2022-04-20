/*
  Вариант 2.
  Дана последовательность из N чисел. Посчитать количество простых чисел.
*/

#include <iostream>
#include <fstream>
#include <chrono>
#include <math.h>

#define N 30

using namespace std;	


class Timer
{
private:
	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, ratio<1> >;
	chrono::time_point<clock_t> m_beg;
public:
	Timer() : m_beg(clock_t::now())
	{
	}
	void reset()
	{
		m_beg = clock_t::now();
	}
	double elapsed() const
	{
		return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};


bool IfSimple(int x) 
{
	bool flag = 1;
	if (x == 1) 
		return 0;
	for (int i = 2; i <= sqrt(x); i++) 
	{
		if (x % i == 0) 
		{
			flag = 0;
		}
	}
	return flag;
}


int main()
{
	Timer t;
	int counter = 0;
	for (int i = 0; i < N; i++) 
	{
		srand(time(0));
		int mas[N];
		for (int i = 0; i < N; i++)
			mas[i] = rand();

		cout << mas[i] << endl;

		if (IfSimple(mas[i]) == 1) 
		{
			counter += 1;
		}
	}
	cout << "Time: " << t.elapsed() << endl;
	cout << counter;
}

//Оценка сложности  О(n^3)





