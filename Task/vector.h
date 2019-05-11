#ifndef VECTOR_H_
#define VECTOR_H_

class vector
{
private:
	int * arr;		// array
	int size;		// size of array
public:
	vector();	// constructor default
	vector(const int * mas, int length);	// constructor for initialization by array
	vector(const vector & v); // copy constructor 
	~vector();	// desctructor  
	bool push(const int & item); // add item to end
	bool pushByIndex(int index, const int & item); // add item by index
	bool popByIndex(int index); // delete item by index
	void clear(); // delete all item`s
	int findIndex(const int & item); // find index of item by value
	vector & operator=(const vector & v);

	friend std::ostream & operator<<(std::ostream & os,
		const vector & v);
};

#endif