#include <iostream>
using namespace std;

class Furniture
{
public:
	int length, width;



	Furniture()
	{
		cout << "Furniture()\n";
		length = 0;
		width = 0;

	}

	Furniture(int l, int w)
	{
		cout << "Furniture(int l, int w)\n";
		length = l;
		width = w;
	}

	Furniture(const Furniture& f)
	{
		cout << "Furniture(const Furniture &f)\n";
		length = f.length;
		width = f.width;

	}

	~Furniture()
	{
		cout << length << ", " << width << "\n";
		cout << "~Furniture()\n";
	}

};



int main()
{
	Furniture sub;
	Furniture sub2(10, 15);
	Furniture sub3(sub2);
	cout << "\n";



}