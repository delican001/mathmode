#pragma once
#include <vector>
#include <math.h>
using namespace std;
class abs_func {
public:
	double x;
	double y;
	abs_func() :x(0), y(0) {}
	abs_func(double _x, double _y) :x(_x), y(_y) {}
	virtual double get_value(double x, double y)=0;
	virtual double operator() (double _x, double _y) = 0;
};

class Func : public abs_func
{
public:
	double x, y;
	Func() : abs_func() {}
	Func(double _x, double _y) : abs_func(_x, _y) {}
	double get_value(double x, double y)
	{
		return -y;
	}
	double operator()(double x, double _y)
	{
		return -_y;
	}
};
struct Point
{public:
	double x, y;
	Point() : x(0), y(0){}
	Point(double _x, double _y) :x(_x), y(_y) {}
};

class DescreteFunction {
private: vector<Point> m_values;
		 double x0, y0, a, b, h;
public: DescreteFunction()
		{
		m_values.resize(0);
		x0 = y0 = a = b = h = 0;
		}
		DescreteFunction(const DescreteFunction &temp)
		{
			m_values = temp.m_values;
			x0 = temp.x0;
			y0 = temp.y0;
			a = temp.a;
			b = temp.b;
			h = temp.h;
		}
		DescreteFunction(abs_func* _func, double _x0, double _y0, double _a, double _b, double _h): x0(_x0), y0(_y0),
			a(_a),b(_b),h(_h)
		{
			double const eps = 0.000000001;
			double x=_x0;
			double y = _y0;
			while (_b-x > eps)
			{
				double k1 = 0;
				double k2 = 0;
				double k3 = 0;
				double k4 = 0;
				double dy = 0;
				k1 = (*_func)(x, y);
				k2 = (*_func)(x, y) + _h/2 + _h*k1 / 2;
				k3 = (*_func)(x, y) + _h/2 + _h*k2 / 2;
				k4 = (*_func)(x, y) + _h+ _h*k3;
				dy = _h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
				y += dy;
				m_values.push_back(Point (x,y));
				x += h;
			}
		}
		Point get_value (int i) { return m_values[i]; }
		int get_size() { return m_values.size(); }
		void set_value(int i, Point _value) { m_values[i] = _value; } 
};