#pragma once
#include "Map.h"

template <typename Key, class Value>
class TreeMapIterator;

enum TREE_PRINT {
	PREFIX = 0,
	INFIX,
	POSTFIX
};

template <typename Key, class Value>
struct Node {
	Key m_key;
	Value m_value;

	Node *m_root;
	Node *m_left;
	Node *m_right;
};

template <typename Key, class Value>
class TreeMap :
	virtual public Map<Key, Value>
{
public:
	TreeMap();
	~TreeMap();

	// Map
	virtual bool add(Key key, Value val) override;
	virtual bool contains(Key key) override;

	virtual size_t size() override;
	virtual bool isEmpty() override;
	virtual void clear() override;

	virtual bool remove(Key key) override;
	void print(TREE_PRINT wayOfTreePrint = INFIX);

	// Iterator
	TreeMapIterator<Key, Value> begin();
	TreeMapIterator<Key, Value> end();
	
private:
	void goHead();
	void insertNode(Key key, Value val);

	bool hasRoot();
	bool hasLeft();
	bool hasRight();
	bool goRoot();
	bool goLeft();
	bool goRight();
	void createLeftNode(Key key, Value val);
	void createRightNode(Key key, Value val);

private:
	// Here Node.

	Node<Key, Value> *m_head;
	Node<Key, Value> *m_cur;

	void printInfixRealisation(Node<Key, Value>* node);
};

template <typename Key, class Value>
TreeMap<Key, Value>::TreeMap()
{
	m_head = m_cur = nullptr;
}

template <typename Key, class Value>
TreeMap<Key, Value>::~TreeMap()
{
}

template<typename Key, class Value>
bool TreeMap<Key, Value>::add(Key key, Value val)
{
	if (key == "Com3") {
		std::cout << std::endl;
	}
	if ( isEmpty() ) {
		Node<Key, Value> *pointer = new Node<Key, Value>();
		pointer->m_key = key;
		pointer->m_value = val;
		pointer->m_root = pointer->m_left = pointer->m_right = nullptr;
		m_head = m_cur = pointer;

		std::cout << "Create head"
			<< " Key=" << m_head->m_key
			<< " Val=" << *(m_head->m_value) << std::endl;
	}
	else {
		insertNode(key, val);
	}
	m_cur = m_head;
	std::cout << "TreeMap::add"
		<< " Key=" << key 
		<< " Val=" << *val << std::endl;
	return true;
}

template<typename Key, class Value>
bool TreeMap<Key, Value>::contains(Key key)
{
	std::cout << "TODO TreeMap::contains Key= Value=" << std::endl;
	return true;
}

template<typename Key, class Value>
size_t TreeMap<Key, Value>::size()
{
	std::cout << "TODO TreeMap::size" << std::endl;
	return 0;
}

template<typename Key, class Value>
bool TreeMap<Key, Value>::isEmpty()
{
	if (m_head == nullptr)
		std::cout << "TreeMap::isEmpty" << std::endl;
	return m_head == nullptr;
}

template<typename Key, class Value>
void TreeMap<Key, Value>::clear()
{
	std::cout << "TODO TreeMap::clear" << std::endl;
	// TODO RootLeftRight round or other, remove each from end
}

template<typename Key, class Value>
bool TreeMap<Key, Value>::remove(Key key)
{
	std::cout << "TODO TreeMap::remove" << std::endl;
	return 0;
}

template<typename Key, class Value>
inline void TreeMap<Key, Value>::goHead()
{
	m_cur = m_head;
}

template<typename Key, class Value>
inline void TreeMap<Key, Value>::insertNode(Key key, Value val)
{
	if (key == m_cur->m_key) {
		m_cur->m_value = val;
	} else 	if (key < m_cur->m_key) {
		if (goLeft()) {
			insertNode(key, val);
		}
		else {
			createLeftNode(key, val);
		}
	}
	else {
		if (goRight()) {
			insertNode(key, val);
		}
		else {
			createRightNode(key, val);
		}
	};
}

// Iterator

template<typename Key, class Value>
inline TreeMapIterator<Key, Value> TreeMap<Key, Value>::begin()
{
	return TreeMapIterator<Key, Value>(*this, m_head);
}


template<typename Key, class Value>
inline bool TreeMap<Key, Value>::hasRoot()
{
	return m_cur->m_root != nullptr;
}

template<typename Key, class Value>
inline bool TreeMap<Key, Value>::hasLeft()
{
	return m_cur->m_left != nullptr;
}

template<typename Key, class Value>
inline bool TreeMap<Key, Value>::hasRight()
{
	return m_cur->m_right != nullptr;
}

template<typename Key, class Value>
inline bool TreeMap<Key, Value>::goRoot()
{
	if (!hasRoot()) {
		return false;
	}
	m_cur = m_cur->m_root;
	return true;
}

template<typename Key, class Value>
inline bool TreeMap<Key, Value>::goLeft()
{
	if (!hasLeft()) {
		return false;
	}
	m_cur = m_cur->m_left;
	return true;
}

template<typename Key, class Value>
inline bool TreeMap<Key, Value>::goRight()
{
	if (!hasRight()) {
		return false;
	}
	m_cur = m_cur->m_right;
	return true;
}

template<typename Key, class Value>
inline void TreeMap<Key, Value>::createLeftNode(Key key, Value val)
{
	Node<Key, Value> *pointer = new Node<Key, Value>();
	pointer->m_key = key;
	pointer->m_value = val;
	pointer->m_left = pointer->m_right = nullptr;
	pointer->m_root = m_cur;
	m_cur->m_left = pointer;
}

template<typename Key, class Value>
inline void TreeMap<Key, Value>::createRightNode(Key key, Value val)
{
	Node<Key, Value> *pointer = new Node<Key, Value>();
	pointer->m_key = key;
	pointer->m_value = val;
	pointer->m_left = pointer->m_right = nullptr;
	pointer->m_root = m_cur;
	m_cur->m_right = pointer;
}

template<typename Key, class Value>
inline void TreeMap<Key, Value>::print(TREE_PRINT wayOfTreePrint)
{
	switch (wayOfTreePrint) {
	case PREFIX:
		break;
	case INFIX:
		printInfixRealisation(m_head);
		break;
	case POSTFIX:
		break;
	}
}

template<typename Key, class Value>
inline void TreeMap<Key, Value>::printInfixRealisation(Node<Key, Value>* node)
{
	if (node != nullptr) {
		printInfixRealisation(node->m_left);
		std::cout << node->m_key << " " << *node->m_value << std::endl;
		printInfixRealisation(node->m_right);
	}
}

#include "Color.h"
template<typename Key, class Value>
inline TreeMapIterator<Key, Value> TreeMap<Key, Value>::end()
{
	// TODO Need add item after real end.
	Node<Key, Value> *node = new Node<Key, Value>();
	node->m_key = comEnd;
	node->m_value = nullptr;
	return TreeMapIterator<Key, Value>(*this, node);
}