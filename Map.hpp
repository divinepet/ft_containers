#pragma once

#include "Utility.hpp"
#include "Iterator.hpp"
#include "Node.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>, class A = std::allocator<std::pair<const Key, T> > >
class Map {//: public Tree<Key, T, Compare> {
public:
//	friend class Tree<Key, T, Compare>;
	typedef Key														key_type;
	typedef T														mapped_type;
	typedef ft::pair<const Key, T>									value_type;
	typedef std::size_t												size_type;
	typedef std::ptrdiff_t											difference_type;
	typedef Compare													key_compare;
	typedef A														allocator_type;
	typedef value_type&												reference;
	typedef const value_type&										const_reference;
	typedef typename allocator_type::pointer						pointer;
	typedef typename allocator_type::const_pointer					const_pointer;
	typedef ft::node_iterator<Node_<Key, T>*>						iterator;
	typedef ft::node_iterator<const Node_<Key, T>*>					const_iterator;
	//	reverse_iterator
	//	reverse_const_iterator
	Tree<Key, T>*													_tree;
private:
	A			 													_allocator;
	size_t															_size;
	Compare		 													_comp;
public:


										/********************************/
										/* CONSTRUCTORS AND DESTRUCTORS */
										/********************************/

	Map() : _size(0) {
		_tree = new Tree<Key, T>();
	}

	explicit Map( const Compare& comp, const A& alloc = A()) : _size(0), _comp(comp), _allocator(alloc) {
		_tree = new Tree<Key, T>();
	}

	template <class InputIt>
	Map(InputIt first, InputIt last, const Compare& comp = Compare(), const A& alloc = A()) : _size(0), _comp(comp), _allocator(alloc) {
		_tree = new Tree<Key, T>();
		for (; first != last; first++) {
			insert(ft::make_pair(first->first, first->second));
		}
	}

	Map(const Map &other) : _size(other._size), _comp(other._comp), _allocator(other._allocator) {
		_tree = new Tree<Key, T>(*(other._tree));
		_tree->fillTree(other._tree->root, _comp);
	}

	Map& operator=(const Map& other) {
		if (this == &other)
			return *this;
		_comp = other._comp;
		_size = other._size;
		_allocator = other._allocator;
		delete _tree;
		_tree = new Tree<Key, T>(*(other._tree));
		_tree->fillTree(other._tree->root, _comp);
		return *this;
	}

	allocator_type get_allocator() const { return _allocator; }

	~Map() { delete _tree; }

										/********************************/
										/*       MEMBER FUNCTIONS       */
										/********************************/


	mapped_type& at(const Key& key) {
		iterator tmp = _tree->findNode(key, _comp);
		return (tmp == _tree->get_end()) ? throw std::out_of_range("key not found") : tmp->second;
	}

	const T& at( const Key& key ) const { return static_cast<const T>(at(key)); }

	T&	operator[](const Key& key) 								{ return insert(ft::make_pair(key, T())).first->second; }
	iterator 				begin()								{ return _tree->get_begin(); }
	const_iterator 			begin() const						{ return _tree->get_begin(); }
	iterator 				end()								{ return _tree->get_end(); }
	const_iterator 			end() const							{ return _tree->get_end(); }
/*
 *
 * 	reverse iterator
 *
 */
	bool 					empty() const						{ return _size == 0; }
	size_type				size() const 						{ return _size; }
	size_type				max_size() const { return (std::min((size_type) std::numeric_limits<difference_type>::max(),
																 std::numeric_limits<size_type>::max() / (sizeof(Node_<Key, T>) + sizeof(T*)))); }

	void clear() {
		_size = 0;
		delete _tree;
		_tree = new Tree<Key, T>();
	}

	ft::pair<iterator, bool> insert(const value_type& value) {
		bool isAdded = false;
		iterator it;

		if (_tree->findNode(value.first, _comp) == _tree->get_end()) {
			_size++;
			isAdded = true;
		}
		it = _tree->insertNode(value.first, value.second, _comp);
		return ft::pair<iterator, bool>(it, isAdded);
	}

	iterator insert(iterator hint, const value_type& value) {

//		if (_tree->findNode(value.first, _comp) == _tree->get_end()) {
//			_size++;
//		}
		iterator it = _tree->insertNode(hint.base(), value.first, value.second, _comp);
		return it;
	}

	iterator find( const Key& key ) {
		return _tree->findNode(key, _comp);
	}

	size_type erase( const key_type& key ) {
//		iterator it = _tree.findNode(key, _comp);
		_tree->deleteNode(_tree->findNode(key, _comp), _comp);
		_size--;
		return 1;
	}
};
}