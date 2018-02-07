#pragma once

template <typename Key, class Value>
class Map
{
public:
	virtual bool add(Key key, Value val) = 0;
	virtual bool contains(Key key) = 0;
	
	virtual size_t size() = 0;
	virtual bool isEmpty() = 0;
	virtual void clear() = 0;

	virtual bool remove(Key key) = 0;
};
