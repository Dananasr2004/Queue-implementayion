 #include<iostream>
using namespace std;

#include "Queue.h"

template<class T>
Queue <T> ::Queue(int s){
	size = s > 0 ? s : 10;
	head = -1;                  // intialized to -1 
	tail = -1;
	peekptr = new T [s];
}
template<class T>
Queue<T>::~Queue() {
	delete[] peekptr;
}

template<class T>
bool Queue<T> ::isFull() {
	return (tail == (size - 1) && head==0);           /*the  2 conditions must  be fulfilled for ex if the size of the array is 5 and the head is on position 4
										       the position 0 should also contain a value otherwise we can't consider it fullalso if the position 4
											 don't contain a value it's not full*/
}
template<class T>
bool Queue<T> ::isEmpty(){
	return ( head==-1 );             // same value as initialized then no item in it  

}
template<class T>
bool Queue<T>::enqueue(const T & object) {

	if (!isFull())
	{
	    if (head== -1)
			head = 0;

		  peekptr[++tail]=object;
		  
			return true;
	}
	else
		return false;

}
template<class T>
bool Queue<T>::dequeue(T & object) {


	if (!isEmpty())
	{
      object = peekptr[head++];
		
	
		if (head > tail)
		{
			tail = -1;
			head = -1;           // reseting
			
		}
		return true;
	}
	else

		return false;
	}




int main() {
	
	Queue<int> myQueue(8);
	int x = 1;

	Queue<double> Queue(8);
	double h = 1.1;

	cout << "pushing elements: ";
	while (myQueue.enqueue(x)) {

		cout << x << " ";
		x += 1;
	}
	cout << "Queue is full can't push \n" << x << "\n pop in elements \n";

	while (myQueue.dequeue(x)) {

		cout << x -- << " ";
	}

	cout << endl << "Queue is empty, can't pop" << endl;


	cout << "pushing elements: ";
	while (Queue.enqueue(h)) {

		cout << h << " ";
		h += 1;
	}
	cout << "Queue is full can't push \n" << h << "\n pop in elements \n";

	while (Queue.dequeue(h)) {

		cout << h-- << " ";
	}

	cout << endl << "Queue is empty, can't pop";
}



