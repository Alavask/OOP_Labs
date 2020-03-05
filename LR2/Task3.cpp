#include <iostream>
#include <iomanip>

using namespace std;

class Collection
{
protected:
	int* array;
	int size;
public:
	Collection(int n) : size(n) { array = new int[n]; memset(array, 0, n * sizeof(int)); }
	~Collection() { delete[] array; }

	int get(int i) { return (i>=0&&i<size) ? i[array] : -1 ; }
	virtual void put(int element) = 0;
	virtual int take() = 0;
};

class Stack : public Collection
{
private:
	int pos;
public:
	explicit Stack(int n) : Collection(n) { pos = 0; }
	void put(int element) override { (pos < size) ? array[pos++] = element : true; }
	int take() override { return ((pos > 0) ? array[--pos] : 0 ); }
};

class Queue : public Collection
{
private:
	int pos;
public:
	explicit Queue(int n) : Collection(n) { pos = size; }
	void put(int element) override { (pos > 0) ? array[--pos] = element : true; }
	int take() override { return ((pos < size) ? array[pos++] : 0); }
};


int main() {
	Collection** array = new Collection*[10];
	for (int i = 0; i < 10; i++)
	{
		if (((bool)((i % 3) % 2)))	{
			array[i] = new Queue(i * 3);
		}
		else {
			array[i] = new Stack(i * 2);
		}
	}
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			array[i]->put(j% (i+1) + i % (j+1) + 1);
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			array[i]->take();
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			cout << setw(3) << array[i]->get(j) << ' ';
		}
		cout << endl;
	}

    return 0;
}