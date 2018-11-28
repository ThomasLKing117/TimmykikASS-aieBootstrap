#pragma once
#include "nodetype.h"
#include "iterator.h"
template <typename h>
class list
{
protected:
	int count;
	nodetype<h> * first;
	nodetype<h> *last;
public:
	const list<h> &operator= (const list<h> & linkedlist);
	void initialize();
	const bool isEmpty();
	const void print();
	const int length();
	void destroy();
	h front() const;
	h back() const;
	virtual bool search(const h& object) const = 0;
	virtual void insertfirst(const h& object) = 0;
	virtual void insertlast(const h& object) = 0;
	virtual void deleteNode(const h& object) = 0;
	virtual void sort() = 0;
	iterator<h> begin();
	iterator<h> end();
	list();
	list(const list<h>&);
	~list();
private:
	void copylist(const list&);

};

template<typename h>
iterator<h> list<h>::begin()
{
	iterator<h> iterator(*this->first);
	return iterator;
}

template<typename h>
iterator<h> list<h>::end()
{
	iterator<h> iterator(*this->last);
	return iterator;
}

template<typename h>
list<h>::list()
{

}
template<typename h>
list<h>::list(const list<h>& other)
{
	this->first = new nodetype<h>;
	nodetype<h>* iter = &(*this->first);
	nodetype<h>*iter2 = &(*other.first);
	while (true)
	{

		iter->info = iter2->info;
		iter->link = new nodetype<h>;
		iter = &(*iter->link);
		if (count == (other.count - 1))
		{
			iter->info = iter2->info;
			iter->link = nullptr;
			this->last = iter;
			break;
		}
		iter2 = &(*iter2->link);
		count++;
	}
}
template<typename h>
list<h>::~list()
{
	destroy();
}

template<typename h>
void list<h>::copylist(const list &other)
{
	nodetype<h>* iter = &(*this->first);
	nodetype<h>*iter2 = &(*other.first);
	int x = 1;
	while (true)
	{
		if (iter == nullptr)
		{
			insertlast(iter2->info);
		}
		else
		{
			iter->info = iter2->info;
		}

		if (x == other.count)
		{
			break;
		}
		iter = &(*iter->link);
		iter2 = &(*iter2->link);
		x++;

	}

}


template<typename h>
const list<h> & list<h>::operator=(const list<h> & linkedlist)
{
	this->copylist(linkedlist);
	return *this;
}



template<typename h>
void list<h>::initialize()
{
	count = 0;
	first = last;
	last = nullptr;
}
template<typename h>
const bool list<h>::isEmpty()
{
	if (count == 0)
		return true;
	else
		return false;
}

template<typename h>
const void list<h>::print()
{
	nodetype<h>* iter = &(*this->first);
	while (iter != nullptr)
	{
		std::cout << iter->info << std::endl;
		iter = &(*iter->link);

	}
	return void();
}

template<typename h>
const int list<h>::length()
{
	return count;
}

template<typename h>
void list<h>::destroy()
{
	nodetype<h>* iter = &(*this->first);
	while (count != 0)
	{
		if (count == 1)
		{
			delete this->first;
			count--;
			break;
		}
		else
		{
			iter = &(*iter->link);
			delete this->first;
			this->first = &(*iter);
			count--;
		}
	}
}

template<typename h>
h list<h>::front() const
{
	return this->first->info;
}

template<typename h>
inline h list<h>::back() const
{
	return this->last->info;
}