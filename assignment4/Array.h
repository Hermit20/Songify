#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;


template< class T>
class Array {

	template<class A>
	friend ostream& operator<<(ostream&, Array<A>&);
		public:
			//constructor
			Array();

			//destructor
			~Array();

			//other
			void add(T);
			T& operator[](int index) const;
			Array<T>& operator+=(T&);
			Array<T>& operator-=(T&);
			int getSize() const;
			bool isFull();
			void clear();

			T& operator[] (int index);
		private:
			T* elements;
			int size;

};

template<class T>
Array<T>::Array(){
	elements = new T[MAX_ARRAY];
	size = 0;
}

template<class T>
Array<T>::~Array(){
	// for(int i = 0; i < size; i++){
	// 	delete elements[i];
	// }
	delete [] elements;
}

template<class T>
void Array<T>::add(T t){
	if (size >= MAX_ARRAY)   return;
  	elements[size++] = t;
}

template<class T>
int Array<T>::getSize() const{
	return size;
}

template<class T>
bool Array<T>::isFull(){
	return size >= MAX_ARRAY;
}

template<class T>
T& Array<T>:: operator[](int index) const{
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template<class T>
T& Array<T>::operator[](int index){
	if(index < 0 || index >= size){
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template<class T>
ostream& operator<<(ostream& out, Array<T>& list)
{

  for(int i = 0; i < list.size; i++){
    out<<list.elements[i]<<endl<<endl;
  }
  return out;
}

template<class T>
Array<T>& Array<T>::operator+=(T& element){
		if (size >= MAX_ARRAY)   return *this;
		elements[size++] = element;
		return *this;
}

template<class T>
Array<T>& Array<T>::operator-=(T& element){
	for(int i = 0; i < size; i++){
		if(elements[i] == element){
			delete &element[i];
			for(int j = i + 1; j < size; j++){
				elements[j-1] = elements[j];
			}
			size--;
			return *this;
		}
	}
	return *this;
}
template<class T>
void Array<T>::clear(){
	// for(int i = 0; i < size; i++){
	// 	delete elements[i];
	// }
	//delete [] elements;
	size = 0;
}
#endif
