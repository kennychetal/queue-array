#pragma once


typedef int elementType;
class Queue
{
public:

	elementType items[25];
	Queue(void);

	/* Inserts an item at the back of this queue
	* @pre newItem is the item to be inserted
	* @post If the insertion is successful, newItem is at the back of this queue.
	* @throw QueueException If Memmory allocation fails.
	*/
	void enqueue(elementType newItem);

	/** Dequeues the front of this queue.
	* @pre None.
	* @post If this queue is not empty, the item that was added to this queue earliest is deleted.
	* @throw QueueException If this queue is empty.
	*/
	void dequeue();
	
	/* Dequeues the entire queue 
	* @pre None.
	* @post If the queue is not empty, the entire queue is emptied and numitems is set to 0.
	* @throw QueueException If this queue is empty.
	*/
	void dequeueAll();

	/* Retrieves the first element
	* @pre None.
	* @post If the queue is not empty the front elmement is retrieved and returned.
	* @throw QueueException If this queue is empty.
	*/
	elementType peek();

	/* Dequeues the entire queue 
	* @pre None.
	* @post If the queue is not empty the size of the queue is returned
	* @throw QueueException If this queue is empty.
	*/
	int size();
	~Queue(void);
	
	void list_full();
	void list_empty();
	void allocation_error();

private:
	int numitems;
	int front;
	int back;
};
