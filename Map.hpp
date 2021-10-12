#pragma once

#include "Node.hpp"
#include "Utility.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>, class A = std::allocator<std::pair<const Key, T> > >
class Map {
	typedef Node_Base<Key, T>*										node_base_ptr;
	Node<Key, T>													_node;
	A			 													_allocator;
	size_t															_size;
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
	typedef ft::node_iterator<Node_Base<Key, T>* >					iterator;
	typedef ft::node_iterator<const Node_Base<Key, T>* >			const_iterator;
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

	allocator_type get_allocator() const { return _allocator; };

	T& at(const Key& key) {
		node_base_ptr tmp = _node.searchNode(key);
		return (tmp == _node.NIL) ? throw std::out_of_range("key not found") : tmp->second;
	};

	const T& at( const Key& key ) const { return at(key); };

	T&			       		operator[](const Key& key)			{ return _node.searchNode(key)->second; };
	iterator 				begin()								{ return (_node.header->next == _node.NIL) ? _node.root : _node.header->next; };
	const_iterator 			begin() const						{ return (_node.header->next == _node.NIL) ? _node.root : _node.header->next; };
	iterator 				end()								{ return _node.header; };
	const_iterator 			end() const							{ return _node.header; };
//	reverse_iterator 		rbegin()							{ return reverse_iterator(buffer + _size - 1); };
//	const_reverse_iterator 	rbegin() const						{ return const_reverse_iterator(buffer + _size - 1); };
//	reverse_iterator 		rend()								{ return reverse_iterator(buffer - 1); };
//	const_reverse_iterator 	rend() const						{ return const_reverse_iterator(buffer - 1); };
	bool 					empty() const						{ return _node.isEmptyNode(); };
	size_type				size() const 						{ return _size; };
	// todo std map not equal this size
	size_type				max_size() const {return (std::min((size_type) std::numeric_limits<difference_type>::max(),
															   std::numeric_limits<size_type>::max() / (sizeof(_node) + sizeof(T*)))); };

	//todo check unique key incoming
	ft::pair<iterator, bool> insert(const value_type& value) {
		_size++;
		iterator it = _node.insertNode(value.first, value.second);
		return ft::pair<iterator, bool>(it, true);
	};

};
}