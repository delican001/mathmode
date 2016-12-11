#ifndef H_RK4_SHELL
#include "runge.h"
#include <iostream>
using namespace std;

float rung(float tt, float ht)
{
	const float h = 0.0001f;
	float k1 = 0;
	float k2 = 0;
	float k3 = 0;
	float k4 = 0;
	float dy = 0;
	k1 = ht;
	k2 = ht + h*k1 / 2;
	k3 = ht + h*k2 / 2;
	k4 = ht + h*k3;
	dy = h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
	return dy;
}

int main()
{
	Func * tewmqwe = new Func(11, 12);
	cout << (*tewmqwe)(11, 12);
	const double h = 0.0001;
	const double h0 = 24;
	const double t0 = 0;
	double ht = h0;
	double tt = t0;
	double dy = 0;
	double ex = 0;
	DescreteFunction test = DescreteFunction(tewmqwe, t0, h0, 0, 1, 0.0001);

	for (int i = 0; i < 10000; i++)
	{
		dy = rung(tt, ht);
		tt += h;
		ht -= dy;
		ex = h0*exp(-tt); cout << "t= " << tt << " " << "ht =" << ht << " " << ex << " delta h(t)=" << ex - ht << " test=" << test.get_value(i).y << endl;

	};
	cout << "t= " << tt << " " << "ht =" << ht << " " << ex << " delta h(t)=" << ex - ht << " test=" << test.get_value(test.get_size() - 1).y << endl;

	
	system("pause");
	return 0;
}



#endif