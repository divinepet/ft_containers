#pragma once

#include "Node.hpp"
#include "Utility.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>, class A = std::allocator<std::pair<const Key, T> > >
class Map {
	typedef Node_Base<Key, T>*										node_base_ptr;
	Node<Key, T>													node;
	A			 													allocator;
public:
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
	typedef typename Node_Base<Key, T>::iterator 					iterator;
	// const_iterator
	// reverse_iterator
	// reverse_const_iterator


									/********************************/
									/* CONSTRUCTORS AND DESTRUCTORS */
									/********************************/

	Map() {};

	explicit Map( const Compare& comp, const A& alloc = A()) {};

	template< class InputIt >
	Map(InputIt first, InputIt last, const Compare& comp = Compare(), const A& alloc = A()) {};

	Map(const Map& other) {};

	~Map() {};

	Map& operator=(const Map& other) {};

	allocator_type get_allocator() const { return allocator; };

	T& at(const Key& key) {
		node_base_ptr tmp = node.searchNode(key);
		return (tmp->first == -1) ? throw std::out_of_range("key not found") : tmp->first;
	};

	const T& at( const Key& key ) const { return at(key); };

	ft::pair<iterator, bool> insert(const value_type& value) {
		iterator it = node.insertNode(value.first, value.second);
		return ft::pair<iterator, bool>(it, true);
	};

//	iterator insert(iterator hint, const value_type& value) {
//
//	};

//	template< class InputIt>
//	void insert(InputIt first, InputIt last) {
//
//	};

};
}