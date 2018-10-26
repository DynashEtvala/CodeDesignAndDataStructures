#pragma once

template<typename T>
class tForwardList
{
	struct Node
	{
		T data;                     // data for the element stored
		Node * next;                // pointer to node following this node
	};

	Node * head;                    // pointer to head of linked list

public:
	tForwardList()                  // default constructor
	{
		head = nullptr;
	};
	 
	tForwardList(const tForwardList& other)             // copy-constructor
	{
		head = other.head
	};

	tForwardList& operator=(const tForwardList &rhs)    // copy-assignment
	{
		head = rhs.head;
	};

	~tForwardList()                 // destructor
	{
		delete head;
	};

	void push_front(const T& val)   // adds element to front (i.e. head)
	{
		temp = new Node{ val, head };
		head = temp;
		delete temp;
	};

	void pop_front()                // removes element from front
	{
		if (head != nullptr)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	};

	T& front()                      // returns the element at the head
	{
		return head->data;
	};

	const T& front() const          // returns the element at the head (const)
	{
		return head->data;
	};

	void remove(const T& val)       // removes all elements equal to the given value
	{
		Node* holdLast = nullptr;
		Node* hold = head;
		while (hold->next != nullptr)
		{
			if (hold->data == val)
			{
				if (holdLast == nullptr)
				{
					hold = hold->next;
					pop_front();
				}
				else
				{
					Node* delHold = hold;
					holdLast->next = hold->next;
					hold = hold->next;
					delete delHold;
				}
			}
			else
			{
				holdLast = hold;
				hold = hold->next;
			}
		}
	};

	void empty() const              // Returns true if there are no elements
	{
		return head == nullptr;
	};

	void clear()                    // Destroys every single node in the linked list
	{
		while (head != nullptr)
		{
			pop_front();
		}
	};

	void resize(size_t newSize)     // Resizes the linked list to contain the given number of elements
	{
		size_t size = 0;
		if (head != nullptr)
		{
			Node* hold = head;
			while (hold != nullptr)
			{
				size++;
				hold = hold->next;
			}
		}
		while (size < newSize)
		{
			push_front(T{});
		}
	};
};