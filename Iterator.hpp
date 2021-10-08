#pragma once

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
		T* count;
	public:
		typedef T*															iterator_type;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type       	value_type;
		typedef typename iterator_traits<iterator_type>::difference_type  	difference_type;
		typedef typename iterator_traits<iterator_type>::pointer          	pointer;
		typedef typename iterator_traits<iterator_type>::reference        	reference;

		iterator(T* value = nullptr) : count(value)			{}
		~iterator()											{};
		iterator(const iterator &temp)						{ *this = temp; }
		iterator	&operator=(const iterator &obj) 		{ this->count = obj.count; return *this; }
		iterator	operator++(int)							{ count++; return *this; }
		iterator	operator--(int) 						{ count--; return *this; }
		iterator	&operator++() 							{ count++; return *this; }
		iterator	&operator--() 							{ count--; return *this; }
		int			operator-(iterator const &obj) const 	{ return count - obj.count; }
		int			operator+(iterator const &obj) const 	{ return count + obj.count; }
		iterator	operator-(int n) const 					{ return iterator(this->count - n); }
		iterator	operator+(int n) const 					{ return iterator(this->count + n); }
		iterator	&operator-=(int n) 						{ this->count -= n; return (*this); }
		iterator	&operator+=(int n) 						{ this->count += n; return (*this); }
		T& 			operator*() const 						{ return *this->count; }
		T&		 	operator[](const unsigned int index) 	{ return *this->count[index]; }
		bool		operator==(iterator const &obj) const 	{ return count == obj.count; };
		bool		operator!=(iterator const &obj) const 	{ return count != obj.count; };
		bool 		operator<(iterator const &obj) const 	{ return count < obj.count; };
		bool 		operator>(iterator const &obj) const 	{ return count > obj.count; };
		bool 		operator<=(iterator const &obj) const 	{ return count <= obj.count; };
		bool 		operator>=(iterator const &obj) const 	{ return count >= obj.count; };
	};


	template <class T>
	class reverse_iterator {
	private:
		T* count;
	public:
		typedef T*                                                     		iterator_type;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		typedef typename iterator_traits<iterator_type>::value_type       	value_type;
		typedef typename iterator_traits<iterator_type>::difference_type  	difference_type;
		typedef typename iterator_traits<iterator_type>::pointer          	pointer;
		typedef typename iterator_traits<iterator_type>::reference        	reference;

		reverse_iterator(T* value = nullptr) : count(value)					{}
		~reverse_iterator() {};
		reverse_iterator(const reverse_iterator &temp)						{ *this = temp; }
		reverse_iterator	&operator=(const reverse_iterator &obj) { count = obj.count; return *this; }
		reverse_iterator	operator++(int) { count--; return *this; }
		reverse_iterator	operator--(int) { count++; return *this; }
		reverse_iterator	&operator++() { count--; return *this; }
		reverse_iterator	&operator--() { count++; return *this; }
		int					operator-(reverse_iterator const &obj) const { return count + obj.count; }
		int					operator+(reverse_iterator const &obj) const { return count - obj.count; }
		reverse_iterator	operator-(int n) const { return reverse_iterator(this->count + n); }
		reverse_iterator	operator+(int n) const { return reverse_iterator(this->count - n); }
		reverse_iterator	&operator-=(int n) { this->count += n; return (*this); }
		reverse_iterator	&operator+=(int n) { this->count -= n; return (*this); }
		T&					operator*() const { return *this->count; }
		T&					operator[] (const unsigned int index) { return *this->count[index]; }
		bool				operator== (reverse_iterator const &obj) const { return count == obj.count; };
		bool				operator!= (reverse_iterator const &obj) const { return count != obj.count; };
		bool				operator< (reverse_iterator const &obj) const { return count > obj.count; };
		bool				operator> (reverse_iterator const &obj) const { return count < obj.count; };
		bool				operator<= (reverse_iterator const &obj) const { return count >= obj.count; };
		bool				operator>= (reverse_iterator const &obj) const { return count <= obj.count; };
	};

}