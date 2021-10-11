#pragma once

#include "Node.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>, class A = std::allocator<std::pair<const Key, T> > >
class Map {
public:
	typedef Key											key_type;
	typedef T											mapped_type;
	typedef std::pair<const Key, T>						value_type;
	typedef std::size_t									size_type;
	typedef std::ptrdiff_t								difference_type;
	typedef Compare										key_compare;
	typedef A											allocator_type;
	typedef value_type&									reference;
	typedef const value_type&							const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef Node<Key, T>								node;
	typedef typename Node_Base<Key, T>::node_iterator				iterator;
	typedef typename Node_Base<Key, T>::const_node_iterator			const_iterator;
	typedef typename Node_Base<Key, T>::reverse_node_iterator 		reverse_iterator;
	typedef typename Node_Base<Key, T>::const_reverse_node_iterator 	const_reverse_iterator;
};
}