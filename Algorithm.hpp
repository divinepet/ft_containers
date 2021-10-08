#pragma once

#include "Vector.hpp"

namespace ft {
	template<class T, bool v>
	struct integral_constant {
		static const bool value = v;
		typedef T value_type;
		typedef integral_constant type;
		operator value_type() const { return value; }
	};
	template <class T> struct is_integral : public ft::integral_constant<T, false> {};
	template <> struct is_integral<bool> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<char> : public ft::integral_constant<bool, true> {};
	template <> struct is_integral<signed char> : public integral_constant<bool, true> {};
	template <> struct is_integral<unsigned char> : public integral_constant<bool, true> {};
	template <> struct is_integral<wchar_t> : public integral_constant<bool, true> {};
	template <> struct is_integral<char16_t> : public integral_constant<bool, true> {};
	template <> struct is_integral<short> : public integral_constant<bool, true> {};
	template <> struct is_integral<unsigned short> : public integral_constant<bool, true> {};
	template <> struct is_integral<int> : public integral_constant<bool, true> {};
	template <> struct is_integral<unsigned int> : public integral_constant<bool, true> {};
	template <> struct is_integral<long> : public integral_constant<bool, true> {};
	template <> struct is_integral<unsigned long> : public integral_constant<bool, true> {};
	template <> struct is_integral<long long> : public integral_constant<bool, true> {};
	template <> struct is_integral<unsigned long long> : public integral_constant<bool, true> {};

	template<bool B, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };

//	template <> struct is_integral<std::remove_cv<bool> > : public ft::integral_constant<bool, true> {};
//	template <> struct is_integral<std::remove_cv<char> > : public integral_constant<bool, true> {};
//	template <> struct is_integral<std::remove_cv<signed char> > : public integral_constant<bool, true> {};
//	template <> struct is_integral<std::remove_cv<unsigned char> > : public integral_constant<bool, true> {};
//	template <> struct is_integral<std::remove_cv<wchar_t> > : public integral_constant<bool, true> {};
//	template <> struct is_integral<std::remove_cv<char16_t> > : public integral_constant<bool, true> {};
//	template <> struct is_integral<std::remove_cv<short> > : public integral_constant<bool, true> {};
//	template <> struct is_integral<std::remove_cv<unsigned short> > : public integral_constant<bool, true> {};
//	template <> struct is_integral<std::remove_cv<int> > : public integral_constant<bool, true> {};
//	template <> struct is_integral<std::remove_cv<unsigned int> > : public integral_constant<bool, true> {};
//	template <> struct is_integral<std::remove_cv<long> > : public integral_constant<bool, true> {};
//	template <> struct is_integral<std::remove_cv<unsigned long> > : public integral_constant<bool, true> {};
//	template <> struct is_integral<std::remove_cv<long long> > : public integral_constant<bool, true> {};
//	template <> struct is_integral<std::remove_cv<unsigned long long> > : public integral_constant<bool, true> {};

template< class InputIt1, class InputIt2 >
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 ) {
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}

template< class InputIt1, class InputIt2, class BinaryPredicate >
	bool equal( InputIt1 first1, InputIt1 last1,
				InputIt2 first2, BinaryPredicate p ) {
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}

	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}
}

namespace std {
	template <class T, class A>
	void swap(ft::Vector<T, A> &v1, ft::Vector<T, A> &v2 ) {
		v1.swap(v2);
	}
}
