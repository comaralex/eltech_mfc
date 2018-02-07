#pragma once

#include "AbsIterator.h"
#include <iostream>
#include "TreeMap.h"
#include "Exception.h"

template <typename Key, class Value>
class TreeMapIterator : public AbsIterator<Key, Value>
{
public:
	TreeMapIterator() {};
	TreeMapIterator(TreeMap<Key, Value> & map, Node<Key, Value> * node);
	virtual Key & first() const;
	virtual Value & second() const;
	virtual void setSecond(const Value &val);
	TreeMapIterator<Key, Value>& toNext() {
		if (m_node == nullptr) {
			std::cout << "Warning." << std::endl;
			return *this;
		}
		if (Next()) {
			//std::cout << "Nice. " << m_node->m_key << std::endl;
		}
		else {
			//std::cout << "End of ++." << std::endl;
		};
		return *this;
	}
	
	TreeMapIterator<Key, Value> operator++() {
		if (m_node == nullptr) {
			std::cout << "Warning. ++" << std::endl;
			return *this;
		}
		if (Next()) {
			//std::cout << "Nice. " << m_node->m_key << std::endl;
		}
		else {
			//std::cout << "End of ++." << std::endl;
		};
		return *this;
	}

	bool operator== (TreeMapIterator<Key, Value> right) {
		if (m_node == nullptr) {
			std::cout << "Warning. ==" << std::endl;
			return false;
		}
		return this->first() == right.first();
	}

	bool operator!= (TreeMapIterator<Key, Value> right) {
		if (m_node == nullptr) {
			std::cout << "Warning. ==" << std::endl;
			return false;
		}
		return this->first() != right.first();
	}

	//Value* operator* (TreeMapIterator<Key, Value>& right) {
	//	if (m_node == nullptr) {
	//		std::cout << "Warning. ==" << std::endl;
	//		return *this;
	//	}
	//	return right.second();
	//}

	//TreeMapIterator<Key, Value>&operator++() {
	//	if (m_node == nullptr) {
	//		std::cout << "Warning." << std::endl;
	//		return nullptr;
	//	}
	//	if (Next()) {
	//		std::cout << "Nice. " << m_node->m_key << std::endl;
	//	}
	//	else {
	//		std::cout << "End of ++." << std::endl;
	//	};
	//	return *this;
	//}

	//bool operator!=(TreeMapIterator<Item> & other) {
	//	return (other.CurrentItem != this->CurrentItem) && (other.m_node != this->m_node);
	//}

	//bool operator==(TreeMapIterator<Item> & other) {
	//	return (other.CurrentItem == this->CurrentItem) && (other.m_node == this->m_node);
	//}

private:
	bool Next();
	bool returnBack();

	TreeMap<Key, Value>& m_map;
	Node<Key, Value>* m_node;
};

template <typename Key, class Value>
TreeMapIterator<Key, Value>::TreeMapIterator(TreeMap<Key, Value> & map, Node<Key, Value> * node)
	: m_map(map), m_node(node) {
	//std::cout << "Iterator. " << node->m_key << " m_node " << m_node->m_key << std::endl;
}

template<typename Key, class Value>
inline Key & TreeMapIterator<Key, Value>::first() const
{
	if (m_node == nullptr) {
		throw InvalidIndexToGetException("TreeMapIterator");
	}
	//std::cout << " In key. Here. " << m_node->m_key << std::endl;
	return m_node->m_key;
}

template<typename Key, class Value>
inline Value & TreeMapIterator<Key, Value>::second() const
{
	if (m_node == nullptr) {
		throw InvalidIndexToGetException("TreeMapIterator");
	}
	return m_node->m_value;
}

template<typename Key, class Value>
inline void TreeMapIterator<Key, Value>::setSecond(const Value &val)
{
	if (m_node == nullptr) {
		throw InvalidIndexToGetException("TreeMapIterator");
	}
	m_node->m_value = val;
}

template<typename Key, class Value>
inline bool TreeMapIterator<Key, Value>::Next()
{
	if (m_node == nullptr) {
		return false;
	}
	if (m_node->m_left != nullptr) {
		m_node = m_node->m_left;
		return true;
	}
	if (m_node->m_right != nullptr) {
		m_node = m_node->m_right;
		return true;
	}
	returnBack();
	return false;
}

template<typename Key, class Value>
inline bool TreeMapIterator<Key, Value>::returnBack()
{
	if (m_node == nullptr) {
		std::cout << "Assert. returnBack" << std::endl;
		return false;
	}
	if (m_node->m_root != nullptr) {
		if (m_node->m_root->m_left == m_node) {
			m_node = m_node->m_root;
		}
		if (m_node->m_right != nullptr) {
			m_node = m_node->m_right; // BugTree
			return true;
		}
		else {
			m_node = m_node->m_root;
			return returnBack();
		}
	}
	else {
		std::cout << "End of iterator!" << std::endl;
		return false;
	}
	return false;
}
