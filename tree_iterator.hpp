#pragma once

#include "nodda.hpp"
#include "Avl.hpp"
namespace ft
{
        template <class Key ,class Type,class T, class Alloc, class U>
    class tree_iterator{
    public:



    public: 
      typedef typename ft::iterator_traits < ft::iterator < std::bidirectional_iterator_tag,T > > ::value_type value_type;
      typedef typename ft::iterator_traits < ft::iterator < std::bidirectional_iterator_tag,T > > ::difference_type difference_type;
      typedef typename ft::iterator_traits < ft::iterator < std::bidirectional_iterator_tag,T > > ::pointer pointer;
      typedef typename ft::iterator_traits < ft::iterator < std::bidirectional_iterator_tag,T > > ::reference reference;
      typedef typename ft::iterator_traits < ft::iterator < std::bidirectional_iterator_tag,T > > ::iterator_category iterator_category;

        // typedef T value_type;
        // typedef std::ptrdiff_t difference_type; 
	    // typedef	T*  pointer;
		// typedef const T* const_pointer;
	    // typedef T& reference;
        // typedef const T& const_reference;
		// typedef std::bidirectional_iterator_tag iterator_category;
        typedef typename T::first_type   pair_first_pair;

        U tree;

        tree_iterator():nodas(NULL),tree(){
        }
        tree_iterator(nodaaa<Key,Type,T,Alloc> *node, U _tree):nodas(node),tree(_tree)
        {
 
         }
        tree_iterator(nodaaa<Key,Type,T,Alloc> *node):nodas(node){
        }
        tree_iterator(const tree_iterator &ref):nodas(ref.nodas),tree(ref.tree){
        };
        tree_iterator &operator=(const tree_iterator &rhs){
            if (this == &rhs)
	    	    return (*this);
	        this->nodas = rhs.nodas;
            this->tree = rhs.tree;
            return (*this);
        }
        ~tree_iterator(){
        }
    nodaaa<Key,Type,T,Alloc> *min_noode(nodaaa<Key,Type,T,Alloc> *noode) 
    {
        if (noode)
        {
            while (noode->left)
                noode = noode->left;
        }
        return (noode);
    }     
    nodaaa<Key,Type,T,Alloc> *max_noode(nodaaa<Key,Type,T,Alloc> *noode)
    {
        if (noode)
        {
            while (noode->right)
                noode = noode->right;
        }
        return (noode);
    }  

    nodaaa<Key,Type,T,Alloc> *parent_noode(nodaaa<Key,Type,T,Alloc> *root, pair_first_pair k)
    {
        nodaaa<Key,Type,T,Alloc> *noode;
        if(root == NULL || root->pair->first == k)
            return NULL;
            
        if ((root->left != NULL && root->left->pair->first == k) || (root->right != NULL && root->right->pair->first == k))
                return root;
        else if(root->pair->first > k)
        {

            noode  = parent_noode(root->left,k);
            if (noode != NULL)
            return noode;

        }
        noode = parent_noode(root->right,k);
        return noode;            
    }

    const tree_iterator& operator--()
    {

        if(nodas ==  nullptr)
        {
            nodas=max_noode(tree._head);
            return (*this);
        }
        if (nodas->left != nullptr)
        {
            nodas = max_noode(nodas->left);
        }else
        {
            nodaaa<Key,Type,T,Alloc> *parent = parent_noode(tree._head,nodas->pair->first);
            while (parent != nullptr && nodas == parent->left)
            {
                nodas = parent;
                parent = parent_noode(tree._head,parent->pair->first);
            }
            nodas = parent;
        }
        return (*this);
    }

    tree_iterator& operator++()
    {
        if(nodas ==  nullptr)
            return (*this);
        if (nodas->right != nullptr)
        {
            nodas = min_noode(nodas->right);
        }else
        {
            nodaaa<Key,Type,T,Alloc> *parent = parent_noode(tree._head,nodas->pair->first);
            while (parent != nullptr && nodas == parent->right)
            {
                nodas = parent;
                parent = parent_noode(tree._head,parent->pair->first);
            }
            nodas = parent;
        }
        return (*this);
    }

	    tree_iterator operator++(int){
            tree_iterator tmp(*this);
            operator++();
            return (tmp);
        }
			
        // Dereference operator (*it).
        reference operator * () const {
            return * (this->nodas->pair);
        }
        // Pointer operator (it.operator->()).
        pointer operator -> () const {
            return & (operator * ());
      }
	    tree_iterator operator--(int)
        {
			tree_iterator tmp(*this);
            operator--();
            return (tmp);
		} 

        bool operator==(const tree_iterator &it)const{
            return (nodas == it.nodas);
        };
        bool operator!=(const tree_iterator &it)const{
            return (nodas != it.nodas);
        };
        bool operator==(tree_iterator &x){
            return(this->nodas == x.nodas);
        }
        bool operator!=(tree_iterator &x){
            return(this->nodas != x.nodas);
        }
        public:
        nodaaa<Key,Type,T,Alloc> *nodas;
    }; 

}
