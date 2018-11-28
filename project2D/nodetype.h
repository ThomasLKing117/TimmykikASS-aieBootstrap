#pragma once
template <typename i>
class nodetype
{
public:
	i info;
	nodetype*link;

	nodetype();
	nodetype(i info);
};

template<typename i>
nodetype<i>::nodetype()
{
}
template<typename i>
nodetype<i>::nodetype(i info)
{
}