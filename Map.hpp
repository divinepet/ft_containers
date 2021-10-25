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
	typedef ft::reverse_node_iterator<iterator>						reverse_iterator;
	typedef ft::reverse_node_iterator<const_iterator>					const_reverse_iterator;
	Tree<Key, T>*													_tree;
	class															value_compare;
private:
	A			 													_allocator;
	Compare		 													_comp;
public:


										/********************************/
										/* CONSTRUCTORS AND DESTRUCTORS */
										/********************************/

	Map() {
		_tree = new Tree<Key, T>();
	}

	explicit Map( const Compare& comp, const A& alloc = A()) : _comp(comp), _allocator(alloc) {
		_tree = new Tree<Key, T>();
	}

	template <class InputIt>
	Map(InputIt first, InputIt last, const Compare& comp = Compare(), const A& alloc = A()) : _comp(comp), _allocator(alloc) {
		_tree = new Tree<Key, T>();
		for (; first != last; first++) {
			insert(ft::make_pair(first->first, first->second));
		}
	}

	Map(const Map &other) : _comp(other._comp), _allocator(other._allocator) {
		_tree = new Tree<Key, T>(*(other._tree));
		_tree->fillTree(other._tree->root, _comp);
	}

	Map& operator=(const Map& other) {
		if (this == &other)
			return *this;
		_comp = other._comp;
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
	reverse_iterator 		rbegin()							{ return iterator(_tree->sentinel.parent); }
	const_reverse_iterator 	rbegin() const						{ return const_iterator(_tree->sentinel.parent); }
	// todo reverse iterator must return a pre-begin value
	reverse_iterator 		rend()								{ return iterator(_tree->get_begin()); }
	const_reverse_iterator 	rend() const						{ return iterator(_tree->get_begin()); }
	bool 					empty() const						{ return size() == 0; }
	size_type				size() const 						{ return _tree->m_size; }
	size_type				max_size() const { return (std::min((size_type) std::numeric_limits<difference_type>::max(),
																 std::numeric_limits<size_type>::max() / (sizeof(Node_<Key, T>) + sizeof(T*)))); }

	void clear() {
		delete _tree;
		_tree = new Tree<Key, T>();
	}

	ft::pair<iterator, bool> insert(const value_type& value) {
		return _tree->insertNode(value.first, value.second, _comp);
	}

	iterator insert(iterator hint, const value_type& value) {} // need to implement

	template< class InputIt >
	void insert( InputIt first, InputIt last ) {
		for (; first != last; first++)
			insert(ft::make_pair(first->first, first->second));
	}

	// todo doesnt work erase with iterators
	void erase( iterator pos ) {
		_tree->deleteNode(pos.base());
	}

	void erase( iterator first, iterator last ) {
		int i = 0;
		for (; first != last; first++)
			_tree->deleteNode(first.base());
	}

	size_type erase( const key_type& key ) {
		return _tree->deleteNode(_tree->findNode(key, _comp));
	}

	void swap( Map& other ) {} // need to imlpement

	size_type count( const Key& key ) const {} // need to implement

	iterator find( const Key& key ) {
		return _tree->findNode(key, _comp);
	}

	const_iterator find( const Key& key ) const {} // need to implement

	iterator lower_bound(const Key& key) {
		Node_<Key, T> *current = _tree->root;

		while (!current->NIL) {
			if (key == current->first)
				return iterator(current);
			else {
				if (_comp(key, current->first)) {
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
		Node_<Key, T> *current = _tree->root;

		while (!current->NIL) {
			if (key == current->first)
				return const_iterator(current);
			else {
				if (_comp(key, current->first)) {
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

	iterator upper_bound(const Key& key) {
		iterator tmp = lower_bound(key);

		return (tmp == end()) ? tmp : (_comp(key, tmp->first)) ? tmp : ++tmp;
	}

	const_iterator upper_bound( const Key& key ) const {
		const_iterator tmp = lower_bound(key);

		return (tmp == end()) ? tmp : (_comp(key, tmp->first)) ? tmp : ++tmp;
	}

	ft::pair<iterator,iterator> equal_range( const Key& key ) {
		return ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key));
	}

	ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {
		return ft::pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key));
	}

	key_compare key_comp() const {} // need to implement

	ft::Map<Key, T, Compare, A>::value_compare  value_comp() const {} // need to implement

};
}