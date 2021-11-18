#include <iostream>
using namespace std;

class Furniture
{

private:
	int length, width;

public:

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

	void Add(int x, int y)
	{
		length = length + x;
		width = width + y;
		cout << "void Add(int x, int y) => length = " << length << " , width = " << width << "\n";
	}

	void Reset();

};

void Furniture::Reset()
{
	length = 0;
	width = 0;
}


int main()
{
	Furniture sub;
	Furniture sub2(10, 15);
	Furniture sub3(sub2);
	cout << "\n";

	Furniture* sub4 = new Furniture;
	Furniture* sub5 = new Furniture(10, 15);
	Furniture* sub6 = new Furniture(*sub5);

	delete sub4;
	delete sub5;
	delete sub6;

	sub2.Reset();
	sub2.Add(5, 6);

}