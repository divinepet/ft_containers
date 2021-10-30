#pragma once

#include "Utility.hpp"
#include "Iterator.hpp"
#include "Node.hpp"

namespace ft {
template <class Key, class Compare = std::less<Key>, class A = std::allocator<Key > >
class Set {
public:
	typedef Key														key_type;
	typedef Key														value_type;
	typedef std::size_t												size_type;
	typedef std::ptrdiff_t											difference_type;
	typedef Compare													key_compare;
	typedef A														allocator_type;
	typedef value_type&												reference;
	typedef const value_type&										const_reference;
	typedef typename allocator_type::pointer						pointer;
	typedef typename allocator_type::const_pointer					const_pointer;
	typedef ft::node_iterator<Node_<value_type>*, value_type>		iterator;
	typedef ft::node_iterator<const Node_<value_type>*, value_type>	const_iterator;
	typedef ft::reverse_iterator<iterator>							reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
private:
	A			 													_allocator;
	Compare		 													_comp;
	Tree<value_type >*												_tree;
public:





	Set() {
		_tree = new Tree<value_type>();
	}

	explicit Set(const Compare& comp, const A& alloc = A())
		: _comp(comp), _allocator(alloc) {
		_tree = new Tree<value_type>();
	}

	template< class InputIt >
	Set( InputIt first, InputIt last,
		 const Compare& comp = Compare(), const A& alloc = A() ) {
			_tree = new Tree<value_type>();
			for (; first != last; first++)
				insert(*first);
	}

	Set(const Set& other) {
		_tree = new Tree<value_type>(*(other._tree));
		_tree->fillTree(other._tree->root, _comp);
	}

	~Set() {
		delete _tree;
	}

	Set& operator=( const Set& other ) {
		if (this == &other)
			return *this;
		_comp = other._comp;
		_allocator = other._allocator;
		delete _tree;
		_tree = new Tree<value_type>(*(other._tree));
		_tree->fillTree(other._tree->root, _comp);
		return *this;
	}


	allocator_type			get_allocator() const			{ return _allocator; }
	iterator 				begin()							{ return _tree->getBegin(); }
	const_iterator 			begin() const					{ return _tree->getBegin(); }
	iterator 				end()							{ return _tree->getEnd(); }
	const_iterator 			end() const						{ return _tree->getEnd(); }
	reverse_iterator 		rbegin()						{ return iterator(_tree->getLast()); }
	const_reverse_iterator 	rbegin() const					{ return const_iterator(_tree->getLast()); }
	reverse_iterator 		rend()							{ return iterator(_tree->getEnd()); }
	const_reverse_iterator 	rend() const					{ return const_iterator(_tree->getEnd()); }
	bool 					empty() const					{ return size() == 0; }
	size_type				size() const 					{ return _tree->m_size; }
	size_type				max_size() const 				{ return (std::min((size_type) std::numeric_limits<difference_type>::max(),
																 		std::numeric_limits<size_type>::max() / (sizeof(Node_<value_type>) + sizeof(Key*)))); }

	void clear() {
		delete _tree;
		_tree = new Tree<value_type>();
	}

	ft::pair<iterator, bool> insert( const value_type& value ) {
		return _tree->insertNodeInSet(_tree->root, value, _comp);
	}

	iterator insert(iterator hint, const value_type& value) {

	}

};
}

