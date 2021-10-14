#pragma once

#include "Utility.hpp"
#include "Iterator.hpp"
#include "oldNode.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>, class A = std::allocator<std::pair<const Key, T> > >
class Map {
	//	typedef Node_Base<Key, T>*										node_base_ptr;
	//	Node<Key, T>													_node;

	Tree<Key, T>													_tree;
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
	typedef ft::node_iterator<Tree<int, int>::Node_* >				iterator;
	typedef ft::node_iterator<const Tree<int, int>::Node_* >		const_iterator;
	//	reverse_iterator
	//	reverse_const_iterator


										/********************************/
										/* CONSTRUCTORS AND DESTRUCTORS */
										/********************************/

	Map() : _size(0) {};

	explicit Map( const Compare& comp, const A& alloc = A()) {}; // assign comp to tree

	template< class InputIt >
			Map(InputIt first, InputIt last, const Compare& comp = Compare(), const A& alloc = A()) {};

	Map(const Map& other) : _size(other._size) {
		_tree = other._tree;
	};

	~Map() {};

	Map& operator=(const Map& other) {
		if (this == &other)
			return *this;
		_tree = other._tree;
		_size = other._size;
		return *this;
	};

	allocator_type get_allocator() const { return _allocator; };

	T& at(const Key& key) {
		iterator tmp = _tree.findNode(key);
		return (tmp == &_tree.sentinel) ? throw std::out_of_range("key not found") : tmp->second;
	};

	const T& at( const Key& key ) const { return static_cast<const T>(at(key)); };

	T&			       		operator[](const Key& key)			{ return _tree.findNode(key)->second; };
	iterator 				begin()								{ return _tree.get_begin(); };
	const_iterator 			begin() const						{ return _tree.get_begin(); };
	iterator 				end()								{ return _tree.get_end(); };
	const_iterator 			end() const							{ return _tree.get_end(); };
	//	reverse_iterator 		rbegin()							{ return reverse_iterator(buffer + _size - 1); };
	//	const_reverse_iterator 	rbegin() const						{ return const_reverse_iterator(buffer + _size - 1); };
	//	reverse_iterator 		rend()								{ return reverse_iterator(buffer - 1); };
	//	const_reverse_iterator 	rend() const						{ return const_reverse_iterator(buffer - 1); };
	bool 					empty() const						{ return _size == 0; };
	size_type				size() const 						{ return _size; };
	size_type				max_size() const { return (std::min((size_type) std::numeric_limits<difference_type>::max(),
															   std::numeric_limits<size_type>::max() / (sizeof(struct Tree<Key, T>::Node_) + sizeof(T*))));
	};



		ft::pair<iterator, bool> insert(const value_type& value) {
			iterator it = _tree.findNode(value.first);
			bool isAdded = false;

			if (it == &_tree.sentinel) {
				it = _tree.insertNode(value.first, value.second);
				cout << it->first << endl;
				cout << it->second << endl;
				_size++;
				isAdded = true;
			}
			return ft::pair<iterator, bool>(it, true);
		};
};
}