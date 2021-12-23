#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP
# include <iostream>
# include "../tools.hpp"
# include "../iterator/reverse_iterator.hpp"
// # include "../iterator/bidirectional_iterator.hpp"

#define COUNT 25

namespace   ft
{
    template <class T>
    class bidirectional_iterator;
    
    template<class T, class Compare = std::less<typename T::first_type>, class Alloc = std::allocator<T> >
    class RedBlackTree
    {

        public:
            typedef T                                                        value_type;
            typedef value_type&                                              reference;
            typedef const value_type&                                        const_reference;
            typedef typename T::first_type                                   key;
            typedef Node<value_type>                                         node_element;
            typedef node_element*                                            node_pointer;
            typedef Alloc                                                    allocator_type;
            typedef std::allocator<node_element>                             allocator_node;
            typedef Compare                                                  compare_type;
            typedef size_t                                                   size_type;
            typedef typename ft::bidirectional_iterator<value_type>          iterator;
            typedef typename ft::bidirectional_iterator<const value_type>    const_iterator;
            typedef typename ft::reverse_iterator<iterator>                  reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>            const_reverse_iterator;
        
            RedBlackTree(const compare_type& compare = compare_type(), const allocator_type& alloc = allocator_type()) : _root(nullptr), _size(0), _comp(compare), _alloc(alloc) 
            {
                this->_endNode = this->_alloc_node.allocate(1);
                this->_alloc_node.construct(this->_endNode);
                this->_alloc.construct(&(this->_endNode->value), value_type());
            }
            // RedBlackTree(RedBlackTree const & src) 
            // {
            //     while ()
            // } 
            ~RedBlackTree()
            {
                //this->clear();
            }
            ft::pair<iterator, bool>    insert(const_reference e)
            {
                node_pointer new_node = this->_alloc_node.allocate(1);
                this->_alloc_node.construct(new_node);
                //new_node->value = this->_alloc.allocate(1);
                this->_alloc.construct(&(new_node->value), e);
                if (!this->_root)
                {
                    this->_root = new_node;
                    this->_root->black = true;
                    this->_size++;
                    return make_pair<iterator, bool>(iterator(new_node, this->_endNode), true);
                }
                add(this->_root, new_node);
                this->_endNode->parent = this->_root;
                this->_endNode->left = this->_root;
                this->_size++;
                return make_pair<iterator, bool>(iterator(new_node, this->_endNode), true);
            }
            void    add(node_pointer parent, node_pointer node)
            {
                if (this->_comp(parent->value.first, node->value.first)) //
                {
                    if (!(parent->right))
                    {
                        node->parent = parent;
                        node->isleft = false;
                        parent->right = node;
                    }
                    else
                        return add(parent->right, node);
                }
                else
                {
                    if (!(parent->left))
                    {
                        node->parent = parent;
                        node->isleft = true;
                        parent->left = node;
                    }
                    else
                        return add(parent->left, node);
                }
                checkColor(node);
                
            }
            void    fixDoubleBlack(node_pointer db)
            {
                node_pointer s;
                while (db)
                {
                    
                    s = getSebling(db);
                    if (!db->parent)
                        return ;
                    if ((!s || (s && (!s->right || (s->right && s->right->black))
                        && (!s->left || (s->left && s->left->black)))))
                    {
                        if (s)
                            s->black = false;
                        if (!db->parent->black)
                        {
                            db->parent->black = true;
                            return;
                        }
                        else  
                            return this->fixDoubleBlack(db->parent);
                    }
                    else if (s && !s->black)
                    {
                        std::swap(s->black, db->parent->black);
                        if (db->isleft)
                            left_rotation(db->parent);
                        else
                            right_rotation(db->parent);
                        return this->fixDoubleBlack(db);
                    }
                    else if (!s || s->black)
                    {
                        if (db->isleft && (!s->left || (s->left && s->left->black)) && (s->right && !s->right->black))
                        {
                            std::swap(s->black, db->black);
                            left_rotation(db->parent);
                            return;
                        }
                        else if (!db->isleft && (s->left && !s->left->black) && (!s->right || (s->right && s->right->black)))
                        {
                            std::swap(s->black, db->black);
                            right_rotation(db->parent);
                            return;
                        }
                        if (db->isleft && (s->left && !s->left->black))
                        {
                            std::swap(s->black, s->left->black);
                            right_rotation(s);
                        }
                        else if (!db->isleft && (s->right && !s->right->black))
                        {
                            std::swap(s->black, s->right->black);
                            left_rotation(s);
                        }
                    }
                }
            }
            void    remove(iterator positon)
            {
                remove(find(positon->first));
            }
            void    remove(node_pointer node)
            {
                node_pointer tmp = findPosition(node);
                if (!tmp->black || (!tmp->parent && !tmp->left && !tmp->right))
                    removeBST(tmp);
                else
                {
                    fixDoubleBlack(tmp);
                    removeBST(tmp);
                }
                this->balckNode(this->_root);
                this->_endNode->parent = this->_root;
                this->_endNode->left = this->_root;
            }
            void    removeBST(node_pointer node)
            {
                if (!node)
                    return ;
                if (!node->left && !node->right)
                {
                    if (node->isleft && node != this->_root)
                        node->parent->left = NULL;
                    else if (!node->isleft && node != this->_root)
                        node->parent->right = NULL;
                    if (node == this->_root)
                        this->_root = NULL;
                    this->_alloc.destroy(&(node->value));
                    this->_alloc_node.destroy(node);
                    this->_alloc_node.deallocate(node, 1);
                    this->_size--;
                    return ;
                }
            }
            void    checkColor(node_pointer node)
            {
                if (!node)
                    return;
                if (!node->black && node->parent && !node->parent->black)
                    correctTree(node);
                checkColor(node->parent);
            }
            void    correctTree(node_pointer node)
            {
                if (node->parent->isleft)
                {
                    if (!(node->parent->parent && node->parent->parent->right) || (node->parent->parent && node->parent->parent->right && node->parent->parent->right->black))
                        return rotate(node);
                    if (node->parent->parent->right)
                        node->parent->parent->right->black = true;
                    if (this->_root != node->parent->parent)
                        node->parent->parent->black = false;
                    node->parent->black = true;
                    return ;
                }
                if (!(node->parent->parent && node->parent->parent->left) || (node->parent->parent && node->parent->parent->left && node->parent->parent->left->black))
                    return rotate(node);
                if (node->parent->parent->left)
                    node->parent->parent->left->black = true;
                if (this->_root != node->parent->parent)
                    node->parent->parent->black = false;
                node->parent->black = true;
                return ;
            }
            void    rotate(node_pointer node)
            {
                if (node->isleft)
                {
                    if (node->parent->isleft)
                    {
                        right_rotation(node->parent->parent);
                        node->black = false;
                        node->parent->black = true;
                        if (node->parent->right)
                            node->parent->right->black = false;
                        return ;
                    }
                    else
                    {
                        rightleft_rotation(node->parent->parent);
                        node->black = true;
                        node->parent->black = false;
                        if (node->right)
                            node->right->black = false;
                    }
                }
                else
                {
                    if (!node->parent->isleft)
                    {
                        left_rotation(node->parent->parent);
                        node->black = false;
                        node->parent->black = true;
                        if (node->parent->left)
                            node->parent->left->black = false;
                        return ;
                    }
                    else
                    {
                        leftright_rotation(node->parent->parent);
                        node->black = true;
                        node->parent->black = false;
                        if (node->right)
                            node->right->black = false;
                    }
                }
            }
            void left_rotation(node_pointer node)
            {
                if (!node)
                    return;
                node_pointer tmp = node->right;
                node->right = tmp->left;
                if (node->right)
                {
                    node->right->parent = node;
                    node->right->isleft = false;
                }
                if (!node->parent)
                {
                    this->_root = tmp;
                    this->_root->parent = NULL;
                    this->_root->black = true; 
                }
                else
                {
                    tmp->parent = node->parent;
                    if (node->isleft)
                    {
                        tmp->isleft = true;
                        tmp->parent->left = tmp;
                    }
                    else
                    {
                        tmp->isleft = false;
                        tmp->parent->right = tmp;
                    }
                }
                tmp->left = node;
                node->isleft = true;
                node->parent = tmp; 
            }
            void right_rotation(node_pointer node)
            {
                if (!node)
                    return;
                node_pointer tmp = node->left;
                node->left = tmp->right;
                if (node->left)
                {
                    node->left->parent = node;
                    node->left->isleft = true;
                }
                if (!node->parent)
                {
                    this->_root = tmp;
                    this->_root->parent = NULL;
                    this->_root->black = true; 
                }
                else
                {
                    tmp->parent = node->parent;
                    if (node->isleft)
                    {
                        tmp->isleft = true;
                        tmp->parent->left = tmp;
                    }
                    else
                    {
                        tmp->isleft = false;
                        tmp->parent->right = tmp;
                    }
                }
                tmp->right = node;
                node->isleft = false;
                node->parent = tmp;
            }
            void leftright_rotation(node_pointer node)
            {
                left_rotation(node->left);
                right_rotation(node);
            }
            void rightleft_rotation(node_pointer node)
            {
                right_rotation(node->right);
                left_rotation(node);
            }
            int    balckNode(node_pointer node)
            {
                if (node == NULL)
                    return 1;
                int rightBlackNode = this->balckNode(node->right);
                int leftBlackNode = this->balckNode(node->left);
                if (leftBlackNode != rightBlackNode)
                {
                    std::cout << "unbalnced " << leftBlackNode << " " << rightBlackNode << std::endl;
                    std::cout << node->value << std::endl;
                }
                if (node->black)
                    leftBlackNode++;
                return leftBlackNode;
            }

            iterator begin()  { return iterator(this->getMinimum(), this->_endNode); }
            const_iterator begin() const { return const_iterator(this->getMinimum(), this->_endNode); }
            iterator end()  { return iterator(this->_endNode, this->_endNode); }
            const_iterator end() const { return const_iterator(this->_endNode, this->_endNode); }
            reverse_iterator rbegin()  { return reverse_iterator(iterator(this->_endNode, this->_endNode)); }
            // const_reverse_iterator rbegin() const { return const_reverse_iterator(this->_endNode, this->_endNode); }
            reverse_iterator rend()  { return reverse_iterator(iterator(this->getMinimum(), this->_endNode)); }
            // const_reverse_iterator rend() const { return const_reverse_iterator(this->getMinimum(), this->_endNode); }

            size_type empty() const { return (this->_size == 0); }
            size_type   size() const { return this->_size; }
            size_type   max_size() const { return this->_alloc_node.max_size(); }
            void clear()
            {
                node_pointer tmp;
                while (this->_root)
                {
                    tmp = findPosition(this->_root);
                    removeBST(tmp);
                }
                this->_size = 0;
            }
            void print2DUtil(node_pointer root, int space)
            {
                if (root == NULL)
                    return;
                space += COUNT;
                print2DUtil(root->right, space);
                std::cout<<std::endl;
                for (int i = COUNT; i < space; i++)
                    std::cout << " ";
                if (root->black)
                    std::cout << "\033[1;40m";
                else
                    std::cout << "\033[1;41m";
                std::cout << root->value;
                if (root->parent)
                    std::cout << " p(" << root->parent->value << ")";
                std::cout << "\033[0m" << std::endl;
                print2DUtil(root->left, space);
            }
            void print2D()
            {
                print2DUtil(this->_root, 0);
                std::cout << "======================================================================================" << std::endl;
            }
            iterator    upper_bound(key const k)
            {
                return iterator(upper_bound(this->_root, k), this->_endNode);
            }
            const_iterator    upper_bound(key const k) const
            {
                return const_iterator(upper_bound(this->_root, k), this->_endNode);
            }
            node_pointer    upper_bound(node_pointer parent, key const k)
            {
                node_pointer tmp = parent;
                while (tmp)
                {
                    if (tmp->value.first == k)
                        return this->getSuccessor(tmp);
                    if (this->_comp(tmp->value.first, k))
                    {
                        if (!tmp->right)
                            return getBigger(tmp);
                        tmp = tmp->right;
                    }
                    else
                    {
                        if (!tmp->left)
                            return getBigger(tmp);
                        tmp = tmp->left;
                    }
                }
                return NULL;
            }
            iterator    lower_bound(key const k)
            {
                return iterator(lower_bound(this->_root, k), this->_endNode);
            }
            const_iterator    lower_bound(key const k) const
            {
                return const_iterator(lower_bound(this->_root, k), this->_endNode);
            }
            node_pointer    lower_bound(node_pointer parent, key const k)
            {
                node_pointer tmp = parent;
                while (tmp)
                {
                    if (tmp->value.first == k)
                        return tmp;
                    if (this->_comp(tmp->value.first, k))
                    {
                        if (!tmp->right)
                            return getBigger(tmp);
                        tmp = tmp->right;
                    }
                    else
                    {
                        if (!tmp->right)
                            return getBigger(tmp);
                        tmp = tmp->left;
                    }
                }
                return NULL;
            }
            node_pointer getSuccessor()
            {
                return getSuccessor(this->_root);
            }
            node_pointer getPredecessor()
            {
                return getPredecessor(this->_root);
            }
            node_pointer getMaximum()
            {
                return getMaximum(this->_root);
            }
            node_pointer getMinimum()
            {
                return getMinimum(this->_root);
            }
            node_pointer getMaximum() const
            {
                return getMaximum(this->_root);
            }
            node_pointer getMinimum() const
            {
                return getMinimum(this->_root);
            }
            static node_pointer getParentSuccessor(node_pointer node)
            {
                node_pointer tmp;
                // std::cout << node->parent->value << " left : " << node->parent->isleft << std::endl;
                // if (node->parent && node->parent->isleft)
                //     return node->parent;
                tmp = node;
                while (tmp && tmp->isleft && tmp->parent)
                    tmp = tmp->parent;
                return tmp->parent;
            }
            static node_pointer getParentPredecessor(node_pointer node)
            {
                node_pointer tmp;
                // if (node->parent && node->parent->isleft)
                //     return node->parent;
                tmp = node; //->parent;
                while (tmp && !tmp->isleft && tmp->parent)
                    tmp = tmp->parent;
                //std::cout << " here : " << tmp->value << std::endl;
                return tmp->parent; //->parent->parent
            }
            bool    contains(const_reference value)
            {
                return this->contains(this->_root, value);
            }
            node_pointer    find(const_reference value)
            {
                return (this->find(this->_root, value));
            }
            static node_pointer getPredecessor(node_pointer node)
            {
                node_pointer    tmp;
                if (!node)
                    return NULL;
                tmp = node->left;
                if (!tmp)
                    return NULL;
                while (tmp->right)
                    tmp = tmp->right;
                return tmp;
            }
            static node_pointer getSuccessor(node_pointer node)
            {
                node_pointer    tmp;
                if (!node)
                    return NULL;
                tmp = node->right;
                if (!tmp)
                    return NULL;
                while (tmp->left)
                    tmp = tmp->left;
                return tmp;
            }
            static node_pointer getMinimum(node_pointer node)
            {
                node_pointer    tmp;
                if (!node)
                    return NULL;
                tmp = node->left;
                if (!tmp)
                    return NULL;
                while (tmp->left)
                    tmp = tmp->left;
                return tmp;
            }
            static node_pointer getMaximum(node_pointer node)
            {
                node_pointer    tmp;
                if (node->parent && node->parent == node->left)
                    return getMaximum(node->parent);
                if (!node)
                    return NULL;
                tmp = node->right;
                if (!tmp)
                    return NULL;
                while (tmp->right)
                    tmp = tmp->right;
                std::cout << tmp->value << std::endl;
                return tmp;
            }
 
        private:
            node_pointer    _root;
            node_pointer    _endNode;
            size_type       _size;
            compare_type    _comp;
            allocator_type  _alloc;
            allocator_node  _alloc_node;

            bool    hasOneChild(node_pointer node)
            {
                if ((node->left && !node->right) || (!node->left && node->right))
                    return true;
                return false;
            }
            node_pointer getSebling(node_pointer node)
            {
                if (node->isleft && node->parent->right)
                    return node->parent->right;
                else if (!node->isleft && node->parent->left)
                    return node->parent->left;
                return NULL;
                
            }
            bool    contains(node_pointer parent, const_reference value)
            {
                if (!parent)
                    return false;
                if (value == parent->value)
                    return true;
                if (this->_comp(parent->value.first, value.first))
                    return contains(parent->right, value);
                return contains(parent->left, value);
            }
            node_pointer    find(node_pointer parent, const_reference value)
            {
                if (!parent)
                    return NULL;
                if (value == parent->value)
                    return parent;
                if (this->_comp(parent->value.first, value.first))
                    return find(parent->right, value);
                return find(parent->left, value);
            }
            node_pointer findPosition(node_pointer node)
            {
                if (!node->left && !node->right)
                    return node;
                node_pointer node_predecessor = getSuccessor(node);
                if (!node_predecessor)
                    node_predecessor = getPredecessor(node);
                std::swap(node->value, node_predecessor->value);
                if (!node_predecessor->left && !node_predecessor->right)
                {
                    return node_predecessor;
                }
                return findPosition(node_predecessor);
            }
            node_pointer    getBigger(node_pointer node)
            {
                node_pointer tmp = node;
                while (tmp)
                {
                    if (tmp->isleft)
                        return tmp->parent;
                    if (this->_comp(node->value.first, tmp->value.first))
                        return tmp;
                    tmp = tmp->parent;
                }
                return NULL;
            }
    };
    
}

#endif