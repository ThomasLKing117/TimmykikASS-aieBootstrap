#pragma once
#include "nodetype.h"
template <typename h>
class  iterator
{
private:
	nodetype<h> * current;
public:
	iterator();
	iterator(nodetype<h>*);
	h operator *();
	iterator<h> operator ++();
	const bool operator == (const iterator<h>& iter);
	const bool operator != (const iterator<h>& iter);
};

template<typename h>
iterator<h>::iterator()
{
}

template<typename h>
iterator<h>::iterator(nodetype<h>*object)
{
	current = object;
}

template<typename h>
h iterator<h>::operator*()
{
	return current->info;
}

template<typename h>
iterator<h> iterator<h>::operator++()
{
	return current = current->link;
}

template<typename h>
const bool iterator<h>::operator==(const iterator<h>& iter)
{
	return current == iter.current;
}

template<typename h>
const bool iterator<h>::operator!=(const iterator<h>& iter)
{
	return current != iter.current;
}