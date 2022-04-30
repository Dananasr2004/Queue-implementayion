#include<iostream>
template<class T>
class Queue{

private:
	int head;
	int tail;
	int size;
	T *peekptr;

public:
	Queue(int);
	~Queue();

	bool enqueue( const T &);
	bool dequeue( T &);
	bool isEmpty();
	bool isFull();
};

