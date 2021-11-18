#include <iostream>
using namespace std;

class Furniture
{

protected:

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

	void Add(int x, int y) // метод для работы с недоступными полями private
	{
		length = length + x;
		width = width + y;
		cout << "void Add(int x, int y) => length = " << length << " , width = " << width << "\n";
	}

	void Reset();

};

class Table: public Furniture
{
protected:
	string color;

public:

	Table() : Furniture()
	{
		cout << "Table() : Furniture()\n";
		color = "none";

	}

	Table(int l, int w, string clr) : Furniture(l,w)
	{
		cout << "Table(int l, int w, string clr) : Furniture(l,w))\n";
		color = clr;
		
	}

	Table(const Table& t) 
	{
		cout << "Table(const Table &f)\n";
		length = t.length;
		width = t.width;
		color = t.color;
	}

	~Table()
	{
		cout << length << ", " << width << ", " << color << "\n";
		cout << "~Table()\n";
	}

	void ChangeColor(string clr)
	{
		color = clr;
		cout << "void ChangeColor(int clr) => color = " << color << "\n";
	}

};

void Furniture::Reset() // реализация метода после определения
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
	cout << "\n";

	delete sub4;
	delete sub5;
	delete sub6;
	cout << "\n";

	sub2.Reset();
	sub2.Add(5, 6);
	cout << "\n";

	Table tab1(1,2,"blue");
	tab1.ChangeColor("red");
}