#pragma once
template <typename Key, class Value>
class AbsIterator
{
public:
	virtual bool Next() = 0;
	//virtual bool IsDone() const = 0;
	//virtual void First() = 0;
	virtual Key & first() const = 0;
	virtual Value & second() const = 0;
};