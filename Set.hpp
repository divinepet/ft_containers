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
	typedef Compare													value_compare;
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
		fillTree(other._tree->root);
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
		fillTree(other._tree->root);
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
	size_type				max_size() const 				{ return std::numeric_limits<size_type>::max() / sizeof(Node_<value_type>); }

	void clear() {
		delete _tree;
		_tree = new Tree<value_type>();
	}

	ft::pair<iterator, bool> insert( const value_type& value ) {
		Node_<value_type> *current, *parent, *x;

		current = _tree->root;
		parent = 0;

		while (!current->NIL) {
			if (value == *current->pair) return ft::make_pair(current, false);
			parent = current;
			current = _comp(value, *current->pair) ?
					current->left : current->right;
		}

		x = new Node_<value_type>(value);
		x->parent = parent;
		x->left = &_tree->sentinel;
		x->right = &_tree->sentinel;
		x->color = 1;

		if (parent) {
			if (_comp(value, *parent->pair))
				parent->left = x;
			else
				parent->right = x;
		} else {
			_tree->root = x;
		}

		_tree->insertFixup(x);

		if (x == _tree->getLast()) { _tree->sentinel.parent = x; }
		if (x == _tree->getBegin()) { _tree->sentinel.begin = x; }
		_tree->m_size++;
		return ft::make_pair(x, true);
	}

	iterator insert(iterator hint, const value_type& value) {
		if (*hint > value)
		{
			iterator prev = hint;
			--prev;
			while (prev != end() && *prev >= value) {
				--hint;
				--prev;
			}
		}else if (*hint < value) {
			iterator next = hint;
			++next;
			while (next != end() && *next <= value) {
				++hint;
				++next;
			}
		}
		Node_<value_type> *current, *parent, *x;

		current = hint.base();
		parent = 0;

		while (!current->NIL) {
			if (value == *current->pair) return current;
			parent = current;
			current = _comp(value, *current->pair) ?
					current->left : current->right;
		}

		x = new Node_<value_type>(value);
		x->parent = parent;
		x->left = &_tree->sentinel;
		x->right = &_tree->sentinel;
		x->color = 1;

		if (parent) {
			if (_comp(value, *parent->pair))
				parent->left = x;
			else
				parent->right = x;
		} else {
			_tree->root = x;
		}

		_tree->insertFixup(x);

		if (x == _tree->getLast()) { _tree->sentinel.parent = x; }
		if (x == _tree->getBegin()) { _tree->sentinel.begin = x; }
		_tree->m_size++;
		return x;
	}

	template< class InputIt >
	void insert( InputIt first, InputIt last ) {
		for (; first != last; first++)
			insert(*first);
	}

	void erase( iterator pos ) {
		iterator tmp = pos;
		_tree->deleteNode(tmp.base());
	}

	void erase( iterator first, iterator last ) {
		iterator tmp;

		for (; first != last ;) {
			tmp = first++;
			_tree->deleteNode(tmp.base());
		}
	}

	size_type erase( const key_type& key ) {
		return _tree->deleteNode(find(key).base());
	}

	void swap( Set& other ) {
		std::swap(_tree, other._tree);
	}

	size_type count( const Key& key ) const {
		return (find(key) == end()) ? 0 : 1;
	}

	iterator find( const Key& key ) {
		Node_<value_type> *current = _tree->root;

		while (!current->NIL) {
			if (key == *current->pair)
				return (current);
			else
				current = _comp(key, *current->pair) ? current->left : current->right;
		}
		return end();
	}

	const_iterator find( const Key& key ) const {
		Node_<value_type> *current = _tree->root;

		while (!current->NIL) {
			if (key == *current->pair)
				return (current);
			else
				current = _comp(key, *current->pair) ? current->left : current->right;
		}
		return end();
	}

	iterator lower_bound( const Key& key ) {
		Node_<value_type> *current = _tree->root;

		while (!current->NIL) {
			if (key == *current->pair)
				return iterator(current);
			else {
				if (_comp(key, *current->pair)) {
					if (!current->left->NIL)
						current = current->left;
					else
						return iterator(current);
				}
				else {
					if (!current->right->NIL)
						current = current->right;
					else
						return ++iterator(current);
				}
			}
		}
		return end();
	}

	const_iterator lower_bound( const Key& key ) const {
		Node_<value_type> *current = _tree->root;

		while (!current->NIL) {
			if (key == *current->pair)
				return const_iterator(current);
			else {
				if (_comp(key, *current->pair)) {
					if (!current->left->NIL)
						current = current->left;
					else
						return const_iterator(current);
				}
				else {
					if (!current->right->NIL)
						current = current->right;
					else
						return ++const_iterator(current);
				}
			}
		}
		return end();
	}

	iterator upper_bound( const Key& key ) {
		iterator tmp = lower_bound(key);

		return (tmp == end()) ? tmp : (_comp(key, *tmp)) ? tmp : ++tmp;
	}

	const_iterator upper_bound( const Key& key ) const {
		const_iterator tmp = lower_bound(key);

		return (tmp == end()) ? tmp : (_comp(key, *tmp)) ? tmp : ++tmp;
	}

	ft::pair<iterator,iterator> equal_range( const Key& key ) {
		return ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key));
	}

	ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {
		return ft::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key));
	}

	key_compare key_comp() const {
		return _comp;
	}

	Set::value_compare value_comp() const {
		return _comp;
	}

	friend bool operator== (const Set &lhs, const Set &rhs) {
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	friend bool operator!= (const Set &lhs, const Set &rhs) {
		return !(lhs == rhs);
	}

	friend bool operator< (const Set &lhs, const Set &rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	friend bool operator> (const Set &lhs, const Set &rhs) {
		return rhs < lhs;
	}

	friend bool operator>= (const Set &lhs, const Set &rhs) {
		return !(lhs < rhs);
	}

	friend bool operator<= (const Set &lhs, const Set &rhs) {
		return !(rhs < lhs);
	}

private:

	void fillTree(Node_<value_type> *t) {
		if (!t->left->NIL)
			fillTree(t->left);
		if (!t->NIL) insert(*t->pair);
		if (!t->right->NIL)
			fillTree(t->right);
	}

};
}

