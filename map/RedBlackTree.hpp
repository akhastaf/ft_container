#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP
# include <iostream>
# include "../tools.hpp"
#define COUNT 25

namespace   ft
{
    template<class T, class Compare = std::less<typename T::first_type>, class Alloc = std::allocator<T> >
    class RedBlackTree
    {

        public:
            typedef T                               value_type;
            typedef value_type&                     reference;
            typedef const value_type&               const_reference;
            typedef Node<value_type>                node_element;
            typedef node_element*                   node_pointer;
            typedef Alloc                           allocator_type;
            typedef std::allocator<node_element>    allocator_node;
            typedef Compare                         compare_type;
            typedef size_t                          size_type;
        
            RedBlackTree(const compare_type& compare = compare_type(), const allocator_type& alloc = allocator_type()) : _head(nullptr), _size(0), _comp(compare), _alloc(alloc) {} 
            //RedBlackTree() : _head(nullptr), _size(0), p_alloc(alloc) {} 
            ~RedBlackTree()
            {
                //clear_tree(this->_head);
                this->_size = 0;
            }
            void    insert(const_reference e)
            {
                node_pointer new_node = this->_alloc_node.allocate(1);
                this->_alloc_node.construct(new_node);
                //new_node->value = this->_alloc.allocate(1);
                this->_alloc.construct(&(new_node->value), e);
                if (!this->_head)
                {
                    this->_head = new_node;
                    this->_head->black = true;
                    this->_size++;
                    return ;
                }
                add(this->_head, new_node);
                this->_size++;
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
                    if (!(node->parent->parent->right) || (node->parent->parent->right && node->parent->parent->right->black))
                        return rotate(node);
                    if (node->parent->parent->right)
                        node->parent->parent->right->black = true;
                    node->parent->parent->black = false;
                    node->parent->black = true;
                    return ;
                }
                if (!(node->parent->parent->left) || (node->parent->parent->left && node->parent->parent->left->black))
                    return rotate(node);
                if (node->parent->parent->left)
                    node->parent->parent->left->black = true;
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
                    }
                }
            }
            void left_rotation(node_pointer node)
            {
                std::cout << "left rotation" << std::endl;
                node_pointer tmp = node->right;
                node->right = tmp->left;
                if (node->right)
                {
                    node->right->parent = node;
                    tmp->right->isleft = false;
                }
                if (!node->parent)
                {
                    this->_head = tmp;
                    this->_head->parent = NULL;
                    this->_head->black = true; 
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
                std::cout << "right rotation" << std::endl;
                node_pointer tmp = node->left;
                node->left = tmp->right;
                if (node->left)
                {
                    tmp->left->parent = node;
                    tmp->left->isleft = true;
                }
                if (!node->parent)
                {
                    this->_head = tmp;
                    this->_head->parent = NULL;
                    this->_head->black = true; 
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
                std::cout << "leftright rotation" << std::endl;
                left_rotation(node->left);
                right_rotation(node);
            }
            void rightleft_rotation(node_pointer node)
            {
                std::cout << "rightleft rotation" << std::endl;
                right_rotation(node->right);
                left_rotation(node);
            }
            // void    clear_tree(node_pointer node);
            bool empty() const { return (this->_size == 0); }
            size_type   size() const { return this->_size; }
            size_type   max_size() const { return this->_alloc_node.max_size(); }
            void print2DUtil(node_pointer root, int space)
            {
                // Base case
                if (root == NULL)
                    return;
            
                // Increase distance between levels
                space += COUNT;
            
                // Process right child first
                print2DUtil(root->right, space);
            
                // Print current node after space
                // count
                std::cout<<std::endl;
                for (int i = COUNT; i < space; i++)
                    std::cout << " ";
                if (root->black)
                    std::cout << "\033[1;40m";
                else
                    std::cout << "\033[1;41m";
                std::cout << root->value;
                if (root->isleft && root != this->_head)
                    std::cout << " left ";
                else if (root != this->_head)
                    std::cout << " right ";
                if (root->parent)
                    std::cout << " parent(" << root->parent->value << ")";
                std::cout << "\033[0m" << std::endl;
            
                // Process left child
                print2DUtil(root->left, space);
            }
            
            // Wrapper over print2DUtil()
            void print2D()
            {
                // Pass initial space count as 0
                print2DUtil(this->_head, 0);
            }
 
 
        private:
            node_pointer    _head;
            size_type       _size;
            compare_type    _comp;
            allocator_type  _alloc;
            allocator_node  _alloc_node;
    };
    
}

#endif