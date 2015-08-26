#include "StdAfx.h"
#include "Queue.h"
#include <exception>
#include <stdexcept>
#include <iostream>
using namespace std;
typedef int elementType;
Queue::Queue(void)
{
	front = 0;
	back = 25-1;
	numitems = 0;
}

void Queue::enqueue(elementType newItem){
	if (numitems==25){
		try{
			list_full();
		} //throw exception
		catch(exception e){
			cout<<e.what();
		}
	
	}
	else{
	back = (back+1) % 25;
	items[back] = newItem;
	++numitems;
	}
}

void Queue::dequeue(){
	if (numitems==0){
		try{
			list_empty();
		} //throw exception
		catch(exception e){
			cout<<e.what();
		}
	
	}
	else{
	front = (front+1) % 25;
	--numitems;
	}
}

Queue::~Queue(void)
{
}
void Queue::list_full(){

	throw std::exception("QueueException: Queue Full");

}

void Queue::list_empty(){
	throw std::exception("QueueException: Queue Empty");
}

void Queue::dequeueAll(){
	for (int i = 0; i<size();i++)
		items[i] = NULL;
	numitems = 0;
	front = 0;
	back = 25-1;

}

int Queue::size(){
	return numitems;
}

elementType Queue::peek(){
	if (numitems==0){
		try{
			list_empty();
	}
	catch(exception e){
		cout<<e.what();
			
	}
	return NULL;
	}
	return items[front];
}