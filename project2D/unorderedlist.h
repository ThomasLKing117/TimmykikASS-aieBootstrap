#pragma once
#include "list.h"

template <typename h>
class unorderedList : public list<h>
{
public:
	void insertfirst(const h & object)
	{
		if (this->count == 0)
		{
			nodetype<h> *newNode = new nodetype<h>;
			newNode->info = object;
			this->last = newNode;
			this->first = newNode;
			this->count++;
		}
		else
		{

			nodetype<h> *newNode = new nodetype<h>;
			newNode->info = object;
			newNode->link = this->first;
			this->first = newNode;
			this->count++;
		}
	}
	void insertlast(const h& object)

	{
		if (this->count == 0)
		{
			nodetype<h> *newNode = new nodetype<h>;
			newNode->info = object;
			this->last = newNode;
			this->first = newNode;
			newNode->link = nullptr;
			this->count++;
		}
		else
		{
			nodetype<h> *newNode = new nodetype<h>;
			newNode->info = object;
			this->last->link = newNode;
			this->last = newNode;
			newNode->link = nullptr;
			this->count++;
		}
	}
	bool search(const h& object) const
	{

		iterator<h> iter1(this->first);
		while (object != *iter1)
		{

			if (*iter1 == object)
			{
				return true;
			}
			if (*iter1 != object && iter1 == nullptr)
			{
				return false;
			}
			++iter1;
		}
	}
	void deleteNode(const h& object)
	{
		if (this->count != 0)
		{
			nodetype<h>* iter = &(*this->first);
			nodetype<h>* iter2 = &(*this->first->link);
			while (object != iter2->info)
			{

				if (iter->info == object && this->count == 1)
				{
					delete this->first;
					this->initialize();
					this->count--;
					break;
				}
				else if ((iter2->info || iter->info) == object && this->count == 2)
				{
					if (iter->info == object)
					{
						delete iter;
						this->first = &(*iter2);
						this->last = &(*iter2);
						this->count--;
						break;
					}
					else if (iter2->info == object)
					{
						delete iter2;
						this->first = &(*iter);
						this->last = &(*iter);
						this->count--;
						break;
					}

				}
				else if (iter2->info == object && this->count > 2)
				{
					iter = &(*iter2->link);
					delete iter2;
					this->count--;
					break;
				}
				else if (iter->info == object)
				{
					delete iter;
					this->first = &(*iter2);
					this->count--;
					break;
				}
				else if (iter2->info != object && iter2->link == nullptr)
				{
					break;
				}
				iter = &(*iter->link);;
				iter2 = &(*iter2->link);
			}
		}
	}

	/*void sort()
	{
		nodetype<h> * ptr1 = &(*this->first);
		nodetype<h> * ptr2 = &(*this->first);
		h temp;
		for (int i = 0; i != this->count; i++)
		{
			for (int j = i + 1; j != this->count; j++)
			{
				if (ptr1->info <= ptr2->info)
				{
					ptr2 = &(*ptr2->link);
					continue;
				}
				else
				{
					temp = ptr1->info;
					ptr1->info = ptr2->info;
					ptr2->info = temp;
				}

			}
			if (ptr1->link == nullptr)
			{
				break;
			}
			ptr1 = &(*ptr1->link);
			ptr2 = &(*ptr1->link);
		}
	}*/
};