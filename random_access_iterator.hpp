#pragma once
#include <iostream>

#include "iterator_traits.hpp"

namespace ft {
  template < class T, class Alloc = std::allocator < T > >
    class random_access_iterator {
      public: typedef typename ft::iterator_traits < ft::iterator < std::random_access_iterator_tag,
      T > > ::value_type value_type;
      typedef typename ft::iterator_traits < ft::iterator < std::random_access_iterator_tag,
      T > > ::difference_type difference_type;
      typedef typename ft::iterator_traits < ft::iterator < std::random_access_iterator_tag,
      T > > ::pointer pointer;
      typedef typename ft::iterator_traits < ft::iterator < std::random_access_iterator_tag,
      T > > ::reference reference;
      typedef typename ft::iterator_traits < ft::iterator < std::random_access_iterator_tag,
      T > > ::iterator_category iterator_category;
 
      random_access_iterator(): _pointer(nullptr) {};
      random_access_iterator(value_type * ptr): _pointer(ptr) {};
      ~random_access_iterator() {};
      random_access_iterator(random_access_iterator
        const & rhs) {
        ( * this) = rhs;
      }

      random_access_iterator & operator = (const random_access_iterator & other) {
        this -> _pointer = other._pointer;
        return * this;
      }
        // Prefix increment operator (++it). 
      random_access_iterator & operator++() {
        ++_pointer;
        return * this;
      }
        // Postfix increment operator (it++). that increments an iterator, but returns the original value of the iterator before it was incremented.
      random_access_iterator operator++(int) {
        random_access_iterator tmp =_pointer;
        _pointer++;
        return tmp;
      }
      random_access_iterator & operator--() {
        --_pointer;
        return * this;
      }

      random_access_iterator operator--(int) {
        random_access_iterator tmp = _pointer;
        _pointer--;
        return tmp;
      }
        // Addition assignment operator (it += n).
      random_access_iterator & operator += (difference_type n) {
        _pointer += n;
        return * this;
      }
        // Subtraction assignment operator (it -= n).
      random_access_iterator & operator -= (difference_type n) {
        _pointer -= n;
        return * this;
      }
      random_access_iterator operator + (difference_type n) {
        random_access_iterator temp = * this;
        temp._pointer += n;
        return temp;
      }
      random_access_iterator operator - (difference_type n) {
        random_access_iterator temp = _pointer;
        temp._pointer -= n;
        return temp;
      }
      difference_type operator - (const random_access_iterator & other) {
        return _pointer - other.get_p();
      }
        // Element access operator (it[n]).
      reference operator[](difference_type n) const {
        return * (_pointer + n);
      }
        // Dereference operator (*it).
      reference operator * () const {
        return * _pointer;
      }
        // Pointer operator (it.operator->()).
      pointer operator -> () const {
        return & (operator * ());
      }
      operator random_access_iterator <
      const value_type > () const {
        return random_access_iterator <
          const value_type > (_pointer);
      }

      pointer get_p() const {
        return this -> _pointer;
      }

      private: pointer _pointer;

    };

  template < class T >
    bool operator == (const random_access_iterator < T > & it1,
      const random_access_iterator < T > & it2) {
      return (it1.get_p() == it2.get_p());
    };
  template < class T >
    bool operator != (const random_access_iterator < T > & it1,
      const random_access_iterator < T > & it2) {
      return (it1.get_p() != it2.get_p());
    };
  template < class T >
    bool operator < (const random_access_iterator < T > & it1,
      const random_access_iterator < T > & it2) {
      return (it1.get_p() < it2.get_p());
    };
  template < class T >
    bool operator > (const random_access_iterator < T > & it1,
      const random_access_iterator < T > & it2) {
      return (it1.get_p() > it2.get_p());
    };
  template < class T >
    bool operator <= (const random_access_iterator < T > & it1,
      const random_access_iterator < T > & it2) {
      return (it1.get_p() <= it2.get_p());
    };
  template < class T >
    bool operator >= (const random_access_iterator < T > & it1,
      const random_access_iterator < T > & it2) {
      return (it1.get_p() >= it2.get_p());
    };
  template < class T >
    typename random_access_iterator < T > ::difference_type operator - (const random_access_iterator < T > & it1,
      const random_access_iterator < T > & it2) {
      return (it1.get_p() - it2.get_p());
    };
  template < class T >
    typename random_access_iterator < T > ::difference_type operator + (const random_access_iterator < T > & it1,
      const random_access_iterator < T > & it2) {
      return (it1.get_p() + it2.get_p());
    };
  template < class T >
    random_access_iterator < T > operator + (typename random_access_iterator < T > ::difference_type n,
      const random_access_iterator < T > & it) {
      return (it.get_p() + n);
    };

}