#pragma once

#include "Utility.hpp"

namespace ft {

	template <class Iter>
	struct iterator_traits {
	public:
		typedef typename Iter::value_type           							value_type;
		typedef typename Iter::difference_type      							difference_type;
		typedef typename Iter::pointer              							pointer;
		typedef typename Iter::const_pointer        							const_pointer;
		typedef typename Iter::reference            							reference;
		typedef typename Iter::const_reference      							const_reference;
		typedef typename Iter::iterator_category    							iterator_category;
	};

	template <typename T>
	struct iterator_traits<T*> {
	public:
		typedef T                                   							value_type;
		typedef T*                                  							pointer;
		typedef const T*                            							const_pointer;
		typedef T&                                  							reference;
		typedef const T&                            							const_reference;
		typedef ptrdiff_t                           							difference_type;
		typedef std::random_access_iterator_tag     							iterator_category;
	};

	template <class T>
	class iterator {
	private:
		T value;
	public:
		typedef T                                                            	iterator_type;
		typedef typename iterator_traits<iterator_type>::value_type         	value_type;
		typedef typename iterator_traits<iterator_type>::pointer            	pointer;
		typedef typename iterator_traits<iterator_type>::const_pointer      	const_pointer;
		typedef typename iterator_traits<iterator_type>::reference          	reference;
		typedef typename iterator_traits<iterator_type>::const_reference    	const_reference;
		typedef typename iterator_traits<iterator_type>::difference_type    	difference_type;
		typedef typename iterator_traits<iterator_type>::iterator_category  	iterator_category;

		iterator(T value = NULL) : value(value)									{}
		~iterator()																{};
		template <class U> iterator(const iterator<U>& other,
			typename ft::enable_if<std::is_convertible<U, iterator_type>::value>::type* = 0)
				: value(other.base()) 											{};
		T		base() const 													{ return value; }
		iterator	&operator=(const iterator &obj) 							{ this->value = obj.value; return *this; }
		iterator	operator++(int)												{ iterator tmp(*this); value++; return tmp; }
		iterator	operator--(int) 											{ iterator tmp(*this); value--; return tmp; }
		iterator	&operator++() 												{ value++; return *this; }
		iterator	&operator--() 												{ value--; return *this; }
		int		operator-(iterator const &obj) const 							{ return value - obj.value; }
		int		operator+(iterator const &obj) const 							{ return value + obj.value; }
		iterator	operator-(int n) const 										{ return iterator(this->value - n); }
		iterator	operator+(int n) const 										{ return iterator(this->value + n); }
		iterator	&operator-=(int n) 											{ this->value -= n; return (*this); }
		iterator	&operator+=(int n) 											{ this->value += n; return (*this); }
		reference 	operator*() const 											{ return *value; }
		pointer 	operator->() const 											{ return &(*value); }
		reference 	operator[](const unsigned int index) 						{ return *this->value[index]; }
		bool		operator==(iterator const &obj) const 						{ return value == obj.value; };
		bool		operator!=(iterator const &obj) const 						{ return value != obj.value; };
		bool 		operator<(iterator const &obj) const 						{ return value < obj.value; };
		bool 		operator>(iterator const &obj) const 						{ return value > obj.value; };
		bool 		operator<=(iterator const &obj) const 						{ return value <= obj.value; };
		bool 		operator>=(iterator const &obj) const 						{ return value >= obj.value; };
	};

	template <class T, class Pair>
	class node_iterator {
		T node;
		void next() {
			if (node->NIL && node->begin != node) node = node->begin;
			else if (!node->right->NIL) {
				node = node->right;
				while (!node->left->NIL)
					node = node->left;
			}
			else {
				T current = node;
				T tmp = node;
				node = node->parent;
				if (!node) { node = current->right; return; }
				while (node->left != tmp) {
					if (!node->parent) { node = current->right; break; }
					tmp = node;
					node = node->parent;
				}
			}
		}

		void prev() {
			if (node->NIL) node = node->parent;
			else if (!node->left->NIL) {
				node = node->left;
				while (!node->right->NIL)
					node = node->right;
			} else {
				T tmp = node;
				node = node->parent;
				while (node->right != tmp) {
					tmp = node;
					if (!node->parent) { node = tmp->left - 1; break; }
					node = node->parent;
				}
			}
		}
	public:
		typedef T                                            					iterator_type;
		typedef Pair                                            				value_type;
		typedef ptrdiff_t                                       				difference_type;
		typedef Pair&                                           				reference;
		typedef const Pair&                                     				const_reference;
		typedef Pair*                                           				pointer;
		typedef const Pair*                                     				const_pointer;
		typedef std::bidirectional_iterator_tag                 				iterator_category;

		node_iterator(T value = nullptr) : node(value)							{};
		~node_iterator()														{};
		template <class U, class Z> node_iterator(const node_iterator<U, Z>& other,
			typename ft::enable_if<std::is_convertible<U, T>::value>::type* = 0)
				: node(other.base()) 											{};
		iterator_type 		base() const 										{ return node; }
		node_iterator		&operator=(const node_iterator &obj) 				{ node = obj.node; return *this; }
		node_iterator		operator++(int)										{ node_iterator tmp(*this); next(); return tmp; }
		node_iterator		&operator++() 										{ next(); return *this; }
		node_iterator		operator--(int)										{ node_iterator tmp(*this); prev(); return tmp; }
		node_iterator		&operator--() 										{ prev(); return *this; }
		reference 			operator*()		 									{ return *(node->pair); }
		const_reference 	operator*() const									{ return *(node->pair); }
		pointer 			operator->()										{ return node->pair; }
		const_pointer 		operator->() const									{ return node->pair; }
		bool				operator==(node_iterator const &obj) const 			{ return node == obj.node; };
		bool				operator!=(node_iterator const &obj) const 			{ return node != obj.node; };
		bool 				operator>(node_iterator const &obj) const 			{ return node->pair > obj.node->pair; };
		bool 				operator<(node_iterator const &obj) const 			{ return obj.node->pair > node->pair; };
		bool 				operator<=(node_iterator const &obj) const 			{ return node->pair <= obj.node->pair; };
		bool 				operator>=(node_iterator const &obj) const 			{ return node->pair >= obj.node->pair; };
	};

	template <class T>
	class reverse_iterator {
		T iterator;
	public:
		typedef T                                                			iterator_type;
		typedef typename iterator_traits<T>::difference_type     			difference_type;
		typedef typename iterator_traits<T>::reference           			reference;
		typedef typename iterator_traits<T>::const_reference     			const_reference;
		typedef typename iterator_traits<T>::pointer             			pointer;
		typedef typename iterator_traits<T>::const_pointer       			const_pointer;

		reverse_iterator(iterator_type value = nullptr) : iterator(value) 		{};
		~reverse_iterator()														{};
		template <class U> reverse_iterator(const reverse_iterator<U>& other,
				typename ft::enable_if<std::is_convertible<U, T>::value>::type* = 0)
						: iterator(other.base()) 								{};
		reverse_iterator	&operator=(const reverse_iterator &obj)				{ iterator = obj.iterator; return *this; }
		iterator_type 		base() const										{ return iterator; }
		reference 			operator*()		                         			{ return *iterator; }
		pointer 			operator->()		                          		{ return &(operator*()); }
		reverse_iterator& 	operator++()                     					{ --iterator; return *this; }
		reverse_iterator 	operator++(int)                    					{ reverse_iterator tmp(*this); iterator--; return tmp; }
		reverse_iterator& 	operator--()                      					{ ++iterator; return *this; }
		reverse_iterator 	operator--(int)                    					{ reverse_iterator tmp(*this); iterator++; return tmp; }
		reverse_iterator 	operator+(difference_type n) const 					{ return reverse_iterator(iterator - n); }
		reverse_iterator& 	operator+=(difference_type n)     					{ iterator -= n; return *this; }
		reverse_iterator 	operator-(difference_type n) const 					{ return reverse_iterator(iterator + n); }
		reverse_iterator& 	operator-=(difference_type n)     					{ iterator += n; return *this; }
		reference 			operator[](difference_type n) const       			{ return *(*this + n); }
		bool				operator==(reverse_iterator const &obj) const 		{ return iterator == obj.iterator; };
		bool				operator!=(reverse_iterator const &obj) const 		{ return iterator != obj.iterator; };
		bool 				operator<(reverse_iterator const &obj) const 		{ return iterator < obj.iterator; };
		bool 				operator>(reverse_iterator const &obj) const 		{ return iterator > obj.iterator; };
		bool 				operator<=(reverse_iterator const &obj) const 		{ return iterator <= obj.iterator; };
		bool 				operator>=(reverse_iterator const &obj) const 		{ return iterator >= obj.iterator; };
	};

}