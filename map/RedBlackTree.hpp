#ifndef REDBLACKTREE_HPP
# define REDBLACKTREE_HPP
# include <iostream>
# include "../tools.hpp"
// # include "../iterator/bidirectional_iterator.hpp"

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
                std::cout << "add new : " << new_node->value << std::endl;
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
            void    remove(node_pointer node)
            {
                // std::cout << "node to be deleted  " << node->value << std::endl;
                node_pointer tmp = findPosition(node);
                // std::cout << "tmp : " << tmp->value << std::endl;
                if (!tmp->black || (!tmp->parent && !tmp->left && !tmp->right))
                    removeBST(tmp);
                else
                {
                    fixDoubleBlack(tmp);
                    removeBST(tmp);
                }

                // else if ((tmp->left && !tmp->left->black) || (tmp->right && !tmp->right->black))
                // {
                //     if (tmp->left && !tmp->left->black)
                //     {
                //         std::swap(tmp->value, tmp->left->value);
                //         tmp->black = true;
                //         removeBST(tmp->left);
                //     }
                //     else
                //     {
                //         std::swap(tmp->value, tmp->right->value);
                //         tmp->black = true;
                //         removeBST(node->right);
                //     }
                // }
                // else if (getSebling(tmp) && !(getSebling(tmp)->black))
                // {
                //     if (getSebling(tmp)->left)
                //         right_rotation(tmp->parent);
                //     else
                //         left_rotation(tmp->parent);
                //     getSebling(tmp)->black = true;
                //     tmp->parent->black = false;
                //     removeBST(tmp);
                // }
                // else
                // {
                //     if (tmp->isleft && tmp->parent->right && tmp->parent->right->black)
                //     {
                //         if (tmp->parent->right->right && !tmp->parent->right->right->black)
                //         {
                //             tmp->parent->right->right->black = true;
                //             left_rotation(tmp->parent);
                //             removeBST(tmp);
                //         }
                //         else if (tmp->parent->right->left && !tmp->parent->right->left->black)
                //         {
                //             tmp->parent->right->left->black = true;
                //             rightleft_rotation(tmp->parent);
                //             removeBST(tmp);
                //         }
                //     }
                //     else if (!tmp->isleft && tmp->parent->left && tmp->parent->left->black)
                //     {
                //         if (tmp->parent->left->left && !tmp->parent->left->left->black)
                //         {
                //             tmp->parent->left->left->black = true;
                //             std::cout << tmp->parent->value << std::endl;
                //             right_rotation(tmp->parent);
                //             removeBST(tmp);
                //         }
                //         else if (tmp->parent->left->right && !tmp->parent->left->right->black)
                //         {
                //             //node->parent->left->right->black = true;
                //             leftright_rotation(tmp->parent);
                //             removeBST(tmp);
                //         }
                //     }
                // }
                this->balckNode(this->_head);
            }
            void    removeBST(node_pointer node)
            {
                std::cout << "delte node : " << node->value << std::endl;
                node_pointer tmp;
                if (!node)
                    return ;
                if (!node->left && !node->right)
                {
                    if (node->isleft && node != this->_head)
                        node->parent->left = NULL;
                    else if (!node->isleft && node != this->_head)
                        node->parent->right = NULL;
                    if (node == this->_head)
                        this->_head = NULL;
                    this->_alloc.destroy(&(node->value));
                    this->_alloc_node.destroy(node);
                    this->_alloc_node.deallocate(node, 1);
                    this->_size--;
                    return ;
                }
                // else 
                // {
                //     node_pointer node_predecessor = getPredecessor(node);
                //     if (!node_predecessor)
                //         node_predecessor = getSuccessor(node);
                //     std::swap(node->value, node_predecessor->value);
                //     //std::cout << node_predecessor->value << std::endl;
                //     this->removeBST(node_predecessor);
                // }
                // else if (this->hasOneChild(node))
                // {
                //     std::cout << "delete node with one child" << std::endl;
                //     // delete node with one child
                //     if (node->left)
                //         tmp = node->left; //->parent = node->parent;
                //     else
                //         tmp = node->right;//->parent = node->parent;
                //     tmp->parent = node->parent;
                //     if (!tmp->parent)
                //     {
                //         this->_head = tmp;
                //         tmp->black = true;
                //     }
                //     else
                //     {
                //         if (node->isleft)
                //         {
                //             node->parent->left = tmp;
                //             tmp->isleft = true;
                //         }
                //         else
                //         {
                //             node->parent->right = tmp;
                //             tmp->isleft = false;
                //         }
                //     }
                //     this->_alloc.destroy(&(node->value));
                //     this->_alloc_node.destroy(node);
                //     this->_alloc_node.deallocate(node, 1);
                //     this->_size--;
                // }
            }
            void    checkColor(node_pointer node)
            {
                if (!node)
                    return;
                if (!node->black && node->parent && !node->parent->black)
                    correctTree(node);
                //balckNode(node);
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
                    if (this->_head != node->parent->parent)
                        node->parent->parent->black = false;
                    node->parent->black = true;
                    return ;
                }
                if (!(node->parent->parent && node->parent->parent->left) || (node->parent->parent && node->parent->parent->left && node->parent->parent->left->black))
                    return rotate(node);
                if (node->parent->parent->left)
                    node->parent->parent->left->black = true;
                if (this->_head != node->parent->parent)
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
                std::cout << "left rotation" << std::endl;
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
                    // if (node->right && node->right->black)
                    //     node->right->black = false;
                    // if (node->left && node->left->black)
                    //     node->left->black = false;
                    // this->correctTree(node);
                }
                if (node->black)
                    leftBlackNode++;
                return leftBlackNode;
            }
            // void    clear_tree(node_pointer node);
            bool empty() const { return (this->_size == 0); }
            size_type   size() const { return this->_size; }
            size_type   max_size() const { return this->_alloc_node.max_size(); }
            void clear()
            {
                while (this->_size > 0)
                    removeBST(this->_head);
                //this->_size = 0;
            }
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
                // if (root->value.first == 120)
                //     std::cout << " here : " << root->left << std::endl;
                // if (root->isleft && root != this->_head)
                //     std::cout << " left ";
                // else if (!root->isleft && root != this->_head)
                //     std::cout << " right ";
                if (root->parent)
                    std::cout << " p(" << root->parent->value << ")";
                std::cout << "\033[0m" << std::endl;
            
                // Process left child
                print2DUtil(root->left, space);
            }
            
            // Wrapper over print2DUtil()
            void print2D()
            {
                // Pass initial space count as 0
                print2DUtil(this->_head, 0);
                std::cout << "======================================================================================" << std::endl;
            }
 
            node_pointer getSuccessor()
            {
                return getSuccessor(this->_head);
            }
            node_pointer getPredecessor()
            {
                return getPredecessor(this->_head);
            }
            node_pointer getMaximum()
            {
                return getMaximum(this->_head);
            }
            node_pointer getMinimum()
            {
                return getMinimum(this->_head);
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
                return this->contains(this->_head, value);
            }
            node_pointer    find(const_reference value)
            {
                return (this->find(this->_head, value));
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
            node_pointer getMinimum(node_pointer node)
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
            node_pointer getMaximum(node_pointer node)
            {
                node_pointer    tmp;
                if (!node)
                    return NULL;
                tmp = node->right;
                if (!tmp)
                    return NULL;
                while (tmp->right)
                    tmp = tmp->right;
                return tmp;
            }
 
        private:
            node_pointer    _head;
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
    };
    
}

#endif