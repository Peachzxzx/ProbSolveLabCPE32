/*
LANG: C++
TASK: dreaming
*/
#include <iostream>
#include <string>
using namespace std;
typedef struct fullAdderResult
{
	int sum=0;
	int carry=0;
} fullAdderResult;

class int301digits
{
public:
	string value;
	int301digits(){}; 
	friend int301digits operator+(const int301digits &a, const int301digits &b);
	friend istream &operator>>(istream &in, int301digits &number);
	friend ostream &operator<<(ostream &out, const int301digits &number);
private:
	void fulladder(const char &a,const char &b,fullAdderResult *c);
};

void int301digits::fulladder(const char &a,const char &b,fullAdderResult *c)
{
	int sum = (a-'0')+(b-'0')+(c->carry);
	c->sum = sum%10;
	c->carry = sum/10;
	(this->value).push_back(c->sum+'0');
}

istream &operator>>(istream &in, int301digits &number)
{
	in >> number.value;
	return in;
}

ostream &operator<<(ostream &out, const int301digits &number)
{
	out << number.value;
	return out;
}

int301digits operator+ (const int301digits &a, const int301digits &b)
{
	string res1 = string(a.value.rbegin(),a.value.rend());
	string res2 = string(b.value.rbegin(),b.value.rend());
	int size;
	if (res1.length()>res2.length())
	{
		size = res1.length();
		for (int i = res2.length();i<size;i++)
			res2.push_back('0');
	}
	else
	{
		size = res2.length();
		for (int i = res1.length();i<size;i++)
			res1.push_back('0');
	}
	fullAdderResult c;
	int301digits out;
	for (int i=0;i<size;i++)
		out.fulladder(res1[i],res2[i],&c);
	if (c.carry>0)
		(out.value).push_back(c.carry+'0');
	out.value = string(out.value.rbegin(),out.value.rend());        
	return out;
}

int main()
{
	int301digits a,b;
	cin >> a >> b;
	cout << a+b << endl; 
}