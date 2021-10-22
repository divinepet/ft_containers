#pragma once

#include "Utility.hpp"


namespace ft {

	template <class Iter>
	struct iterator_traits {
	public:
		typedef typename Iter::value_type           value_type;
		typedef typename Iter::difference_type      difference_type;
		typedef typename Iter::pointer              pointer;
		typedef typename Iter::reference            reference;
		typedef typename Iter::iterator_category    iterator_category;
	};

	template <typename T>
	struct iterator_traits<T*> {
	public:
		typedef T                                   value_type;
		typedef T*                                  pointer;
		typedef T&                                  reference;
		typedef ptrdiff_t                           difference_type;
		typedef std::random_access_iterator_tag     iterator_category;
	};

	template <class T>
	class iterator {
	private:
		T value;
	public:
		typedef T								iterator_type;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type       	value_type;
		typedef typename iterator_traits<iterator_type>::difference_type  	difference_type;
		typedef typename iterator_traits<iterator_type>::pointer          	pointer;
		typedef typename iterator_traits<iterator_type>::reference        	reference;

		iterator(T value = NULL) : value(value)					{}
		~iterator()								{};
		template <class U> iterator(const iterator<U>& other,
			typename ft::enable_if<std::is_convertible<U, iterator_type>::value>::type* = 0)
				: value(other.base()) 					{};
		T		base() const 						{ return value; }
		iterator	&operator=(const iterator &obj) 			{ this->value = obj.value; return *this; }
		iterator	operator++(int)						{ iterator tmp(*this); value++; return tmp; }
		iterator	operator--(int) 					{ iterator tmp(*this); value--; return tmp; }
		iterator	&operator++() 						{ value++; return *this; }
		iterator	&operator--() 						{ value--; return *this; }
		int		operator-(iterator const &obj) const 			{ return value - obj.value; }
		int		operator+(iterator const &obj) const 			{ return value + obj.value; }
		iterator	operator-(int n) const 					{ return iterator(this->value - n); }
		iterator	operator+(int n) const 					{ return iterator(this->value + n); }
		iterator	&operator-=(int n) 					{ this->value -= n; return (*this); }
		iterator	&operator+=(int n) 					{ this->value += n; return (*this); }
		reference 	operator*() const 					{ return *value; }
		pointer 	operator->() const 					{ return &(*value); }
		reference 	operator[](const unsigned int index) 			{ return *this->value[index]; }
		bool		operator==(iterator const &obj) const 			{ return value == obj.value; };
		bool		operator!=(iterator const &obj) const 			{ return value != obj.value; };
		bool 		operator<(iterator const &obj) const 			{ return value < obj.value; };
		bool 		operator>(iterator const &obj) const 			{ return value > obj.value; };
		bool 		operator<=(iterator const &obj) const 			{ return value <= obj.value; };
		bool 		operator>=(iterator const &obj) const 			{ return value >= obj.value; };
	};


	template <class T>
	class reverse_iterator {
	private:
		T value;
	public:
		typedef T                                                     		iterator_type;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type       	value_type;
		typedef typename iterator_traits<iterator_type>::difference_type  	difference_type;
		typedef typename iterator_traits<iterator_type>::pointer          	pointer;
		typedef typename iterator_traits<iterator_type>::reference        	reference;

		reverse_iterator(T value = NULL) : value(value)				{}
		~reverse_iterator() 							{};
		template <class U> reverse_iterator(const iterator<U>& other,
			typename ft::enable_if<std::is_convertible<U, iterator_type>::value>::type* = 0)
				: value(other.base()) 					{};
		T			base() const 					{ return value; }
		reverse_iterator	&operator=(const reverse_iterator &obj) 	{ value = obj.value; return *this; }
		reverse_iterator	operator++(int) 				{ reverse_iterator tmp(*this); value--; return tmp; }
		reverse_iterator	operator--(int) 				{ reverse_iterator tmp(*this); value++; return tmp; }
		reverse_iterator	&operator++() 					{ value--; return *this; }
		reverse_iterator	&operator--() 					{ value++; return *this; }
		int			operator-(reverse_iterator const &obj) const 	{ return value + obj.value; }
		int			operator+(reverse_iterator const &obj) const 	{ return value - obj.value; }
		reverse_iterator	operator-(int n) const 				{ return reverse_iterator(this->value + n); }
		reverse_iterator	operator+(int n) const 				{ return reverse_iterator(this->value - n); }
		reverse_iterator	&operator-=(int n) 				{ this->value += n; return (*this); }
		reverse_iterator	&operator+=(int n) 				{ this->value -= n; return (*this); }
		reference 		operator*() const 				{ return *value; }
		pointer 		operator->() const 				{ return &(*value); }
		reference 		operator[](const unsigned int index) 		{ return *this->value[index]; }
		bool			operator== (reverse_iterator const &obj) const 	{ return value == obj.value; };
		bool			operator!= (reverse_iterator const &obj) const 	{ return value != obj.value; };
		bool			operator< (reverse_iterator const &obj) const	{ return value > obj.value; };
		bool			operator> (reverse_iterator const &obj) const 	{ return value < obj.value; };
		bool			operator<= (reverse_iterator const &obj) const 	{ return value >= obj.value; };
		bool			operator>= (reverse_iterator const &obj) const 	{ return value <= obj.value; };
	};

	template <class T>
	class node_iterator {
	private:
		T node;

		/*
		 *	This method is replacement of Compare class
		 *	which define on what basis RBTree constructed (less or greater)
		 *	Another way is pass the Compare in node_iterator
		 */
		bool compare(T tmp, T node, bool it) {
			if (!node->parent) {
				if ((!node->left->NIL && node->first < node->left->first) || (!node->right->NIL && node->first > node->right->first))
					return (it) ? tmp->first < node->first : tmp->first > node->first; // std::greater case;
				else
					return (it) ? tmp->first > node->first : tmp->first < node->first; // std::less case
			}
			if (node->parent->left == node) {
				if (node->parent->first < node->first) {
					return (it) ? tmp->first < node->first : tmp->first > node->first; // std::greater case
				} else {
					return (it) ? tmp->first > node->first : tmp->first < node->first; // std::less case
				}
			} else {
				if (node->parent->first < node->first) {
					return (it) ? tmp->first > node->first : tmp->first < node->first; // std::less case
				} else {
					return (it) ? tmp->first < node->first : tmp->first > node->first; // std::greater case
				}
			}
		}

		void next() {
			if (!node->right->NIL) {
				node = node->right;
				while (!node->left->NIL)
					node = node->left;
			}
			else {
				T tmp = node;
				while (compare(tmp, node, 1) || tmp->first == node->first) {
					if (!node->parent) { node = tmp->right; break; }
					node = node->parent;
				}
			}
		}

		void prev() {
			if (node->NIL) {
				node = node->parent;
				return;
			}
			if (!node->left->NIL) {
				node = node->left;
				while (!node->right->NIL)
					node = node->right;
			} else {
				T tmp = node;
				while (compare(tmp, node, 0) || tmp->first == node->first) {
					if (!node->parent) { node = node->left - 1; break; }
					node = node->parent;
				}
			}
		}
	public:
		node_iterator(T value = nullptr) : node(value)					{};
		~node_iterator()								{};
		template <class U> node_iterator(const node_iterator<U>& other,
			typename ft::enable_if<std::is_convertible<U, T>::value>::type* = 0)
				: node(other.base()) 						{};
		T			base() const 						{ return node; }
		node_iterator		&operator=(const node_iterator &obj) 			{ node = obj.node; return *this; }
		node_iterator		operator++(int)						{ node_iterator tmp(*this); next(); return tmp; }
		node_iterator		&operator++() 						{ next(); return *this; }
		node_iterator		operator--(int)						{ node_iterator tmp(*this); prev(); return tmp; }
		node_iterator		&operator--() 						{ prev(); return *this; }
		T& 			operator*() const 					{ return *node; }
		T			operator->() const 					{ return &(*node); }
		bool			operator==(node_iterator const &obj) const 		{ return node == obj.node; };
		bool			operator!=(node_iterator const &obj) const 		{ return node != obj.node; };
		bool 			operator<(node_iterator const &obj) const 		{ return node < obj.node; };
		bool 			operator>(node_iterator const &obj) const 		{ return node > obj.node; };
		bool 			operator<=(node_iterator const &obj) const 		{ return node <= obj.node; };
		bool 			operator>=(node_iterator const &obj) const 		{ return node >= obj.node; };
	};

}
