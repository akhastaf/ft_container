#include <iostream>
# include <memory>
#include <vector>
# include <ctime>
# include <iomanip>
# include <unistd.h>
# include <signal.h>
# include <sys/time.h>
# include "vector/vector.hpp"
# include "map/RedBlackTree.hpp"
# include "map/map.hpp"
# include "iterator/bidirectional_iterator.hpp"

// # define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
// # define TIME_FAC 20 // the ft::vector methods can be slower up to std::vector methods * TIME_FAC (MAX 20)

int main()
{

    // std::vector<std::string> ar(4, "Hello");
    // ft::Vector<std::string> myar(2, "Hi");
    // ft::Vector<std::string> myar1(4);

    // std::cout << ar.capacity() << std::endl;
    // std::cout << ar.size() << std::endl;
    // std::cout << ar.max_size() << std::endl;
    // std::cout << myar.capacity() << std::endl;
    // std::cout << myar.size() << std::endl;
    // std::cout << myar.max_size() << std::endl;
    // if (ar.max_size() == myar.max_size())
    //     std::cout << "are equal" << std::endl;
    // else
    //     std::cout << "are not equal" << std::endl;
    

    // std::cout << ar[0] << std::endl;
    // std::cout << myar[0] << std::endl;

    // try 
    // {
    //     std::cout << myar.at(200) << std::endl;
    //     //std::cout << ar.at(20) << std::endl;
    // }
    // catch (std::out_of_range &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    // std::cout << ar.front() << std::endl;
    // std::cout << myar.front() << std::endl;

    // std::cout << myar.size() << std::endl;
    // std::cout << myar.capacity() << std::endl;
    // std::cout << myar1.size() << std::endl;
    // std::cout << myar1.capacity() << std::endl;
    
    // myar1 = myar;

    // std::cout << myar.size() << std::endl;
    // std::cout << myar.capacity() << std::endl;
    // std::cout << myar1.size() << std::endl;
    // std::cout << myar1.capacity() << std::endl;

    // for (int i = 0; i < myar1.size(); i++)
    //     std::cout << myar1[i] << std::endl;
    
    // ft::Vector<std::string> myar2(myar1);

    // std::cout << myar1.size() << std::endl;
    // std::cout << myar1.capacity() << std::endl;
    // std::cout << myar2.size() << std::endl;
    // std::cout << myar2.capacity() << std::endl;

    // for (int i = 0; i < myar2.size(); i++)
    //     std::cout << myar2[i] << std::endl;

    // myar2.assign(1, "He");

    // std::cout << myar2.size() << std::endl;
    // std::cout << myar2.capacity() << std::endl;
    // for (int i = 0; i < myar2.size(); i++)
    //     std::cout << myar2[i] << std::endl;


    // ft::Vector<int> testpush(3);
    // std::vector<int> testpush0(3);

    // for (int i = 0; i < 6; i++)
    // {
    //     testpush.push_back(i*2);
    //     testpush0.push_back(i*2);
    // }
    // std::cout << "std::vector : " << std::endl;
    // std::cout << testpush0.size() << std::endl;
    // std::cout << testpush0.capacity() << std::endl;
    // std::cout << "ft::Vector : " << std::endl;
    // std::cout << testpush.size() << std::endl;
    // std::cout << testpush.capacity() << std::endl;
    // for (int i = 0; i < testpush0.size(); i++)
    //     std::cout << testpush0[i] << " : " << testpush[i] << std::endl;


    // testpush.pop_back();
    
    // std::cout << testpush[testpush.size()] << std::endl;
    // std::cout << testpush.size() << std::endl;
    // std::cout << testpush.capacity() << std::endl;
    // for (int i = 0; i < testpush.size(); i++)
    //     std::cout << testpush0[i] << " : " << testpush[i] << std::endl;

    // try 
    // {
    //     testpush.reserve(testpush.max_size() + 10);
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // std::cout << testpush.size() << std::endl;
    // std::cout << testpush.capacity() << std::endl;
    
    // try 
    // {
    //     testpush.resize(testpush.max_size() + 10, 45);
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // std::cout << testpush.size() << std::endl;
    // std::cout << testpush.capacity() << std::endl;
    // ft::Vector<int> testop = testpush;
    // if (testpush == testop)
    //     std::cout << "the vector are equal" << std::endl;
    // else if (testop != testpush)
    //     std::cout << "the vector are not equal" << std::endl;

    // testpush.clear();
    // std::cout << testpush.size() << std::endl;
    // std::cout << testpush.capacity() << std::endl;
    
    // if (testpush == testop)
    //     std::cout << "the vector are equal" << std::endl;
    // else if (testop != testpush)
    //     std::cout << "the vector are not equal" << std::endl;
        
    // std::vector<int> org(20);
    // for (int i = 0; i < org.size(); i++)
    //     org.push_back(i);
    // ft::Vector<int> my(org.begin(), org.end());

    // std::cout << my.size() << std::endl;
    // std::cout << my.capacity() << std::endl;
    // for (int i = 0; i < my.size(); i++)
    //     std::cout << my[i] << std::endl;
    // int i = 0;
    // ft::Vector<int>::iterator it = my.begin();
    // for (it = my.begin(); it != my.end(); it++)
    // {
    //     std::cout << "my[" << i << "] = " << *it << std::endl;
    //     i++;
    // }

    // it = my.end();
    // it--;
    // my.erase(my.begin(), it);
    // std::cout << my.size() << std::endl;
    // std::cout << my.capacity() << std::endl;

    // std::cout << my[0] << std::endl;
    // ft::Vector<int> a(10, 55);
    // ft::Vector<int> b(15, 33);
    // std::cout << "A :" << std::endl;
    // for (int i = 0; i < a.size(); i++)
    //     std::cout << a[i] << std::endl;
    // std::cout << "B :" << std::endl;
    // for (int i = 0; i < b.size(); i++)
    //     std::cout << b[i] << std::endl;
    // a.swap(b);
    // std::cout << "A :" << std::endl;
    // for (int i = 0; i < a.size(); i++)
    //     std::cout << a[i] << std::endl;
    // std::cout << "B :" << std::endl;
    // for (int i = 0; i < b.size(); i++)
    //     std::cout << b[i] << std::endl;
    // std::cout << a.size() << std::endl;
    // std::cout << a.capacity() << std::endl;
    // std::cout << b.size() << std::endl;
    // std::cout << b.capacity() << std::endl;
    // ft::Vector<int> a;
    // ft::Vector<int> b(10, 55);
    // a.push_back(6);
    // ft::Vector<int>::iterator ir = a.begin();
    // std::cout << "size : here " << a.size() << std::endl;
    // ir++;
    // a.insert(ir, 5, 45);
    // std::cout << "size: " << a.size() << std::endl;
    // std::cout << "capcity: " << a.capacity() << std::endl;
    // for (int i = 0; i < a.size(); i++)
    //     std::cout << a[i] << std::endl;

    // a.push_back(8);
    // a.push_back(9);
    // a.push_back(10);
    // a.push_back(11);
    // for (int i = 0; i < a.size(); i++)
    //     std::cout << a[i] << std::endl;
    // ir = a.begin();
    // ir++;
    // std::cout << "ir : " << *ir << std::endl;
    // a.erase(ir);
    // for (int i = 0; i < a.size(); i++)
    //     std::cout << a[i] << std::endl;
    // ft::Vector<int>::iterator st = a.begin();
    // ft::Vector<int>::iterator en = a.end();
    // st++;
    // en--;
    // a.erase(st, a.end());
    // std::cout << "after" << std::endl;
    // for (int i = 0; i < a.size(); i++)
    //     std::cout << a[i] << std::endl;
    // ir = a.end();
    // ir--;
    // ir--;
    // ft::Vector<int>::iterator it = a.erase(ir);
    // std::cout << *it << std::endl;
    // ft::Vector<int> myvector (5);  // 5 default-constructed ints

    // int i=0;

    // ft::Vector<int>::reverse_iterator rit = myvector.rbegin();
    // for (; rit != myvector.rend(); ++rit)
    // {
    //     std::cout << "i : " << i << std::endl;
    //     *rit = ++i;
    // }

    // std::cout << "myvector contains:";
    // for (ft::Vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';
    // ft::Vector<int>  a(4, 55);
    // std::cout << a.end() - a.begin() << std::endl;
    // std::vector<int> v(3);
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
	// ft::reverse_iterator<std::vector<int>::iterator> my_rit(v.end()), my_rit1(v.end() - 1);
    // std::cout << "\nvalue : " << *(v.end() - 1) << std::endl;
    // std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " base function " << "] --------------------]\t\t\033[0m";
    // EQUAL((&(*my_rit) == &(*my_rit1.base())));
    // std::cout << &(*my_rit1.base()) << " " << &(*my_rit) << std::endl;
    //std::vector<int> v(3);
    // std::vector<int> v(3);
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // std::vector<int>::reverse_iterator rit(v.end()), rit_1(v.end() - 1);
    // /*----------------------------------*/
    // /*------------ ft::reverse_iterator ---------*/
    // ft::vector<int> my_v(3);
    // //ft::vector<int> my_v(3,4);
    // my_v.push_back(1);
    // my_v.push_back(2);
    // my_v.push_back(3);
    // ft::vector<int>::reverse_iterator my_rit(my_v.end()), my_rit1(my_v.end() - 1);
    // std::cout << " my : " << *my_rit << " " << *(my_rit1.base()) << std::endl;
    // std::cout << " v : " << *rit << " " << *(rit_1.base()) << std::endl;
    // std::cout << " my : " << &(*my_rit) << " " << &(*(my_rit1.base())) << std::endl;
    // std::cout << " v : " << &(*rit) << " " << &(*(rit_1.base())) << std::endl;
    // std::cout << " my : " << &(*my_rit) << " " << &(*(my_rit1 - 1)) << std::endl;
    // std::cout << " v : " << &(*rit) << " " << &(*(rit_1 - 1)) << std::endl;
    // std::cout << (&(*rit) == &(*(rit_1 - 1))) << std::endl;
    // std::cout << (&(*my_rit) == &(*(my_rit1 - 1))) << std::endl;
    // std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " - operator " << "] --------------------]\t\t\033[0m";
    // EQUAL((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))));
    // std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " base function " << "] --------------------]\t\t\033[0m";
    // EQUAL((&(*rit) == &(*rit_1.base())) && (&(*my_rit) == &(*my_rit1.base())));
    // std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " riterator to const_riterator " << "] --------------------]\t\t\033[0m";
    // {
	// 	ft::vector<int> v(4,5);
	// 	ft::vector<int>::reverse_iterator 		my_rit2(v.end());
    //     ft::vector<int>::const_reverse_iterator c_it, c_ob(v.end());
    //     c_it = my_rit2;
    //     std::cout << (&(*my_rit2) == &(*c_it)) << " " << (&(*my_rit2) == &(*c_ob)) << std::endl;
    //     std::cout << &(*my_rit2) << "  " << &(*c_it) << std::endl;
    //     std::cout << (&(*my_rit2)  - &(*c_it)) << std::endl;;
    //     EQUAL(&(*my_rit2) == &(*c_it) && (&(*my_rit2) == &(*c_ob)));
    // }
    // ft::RedBlackTree<ft::pair<std::string, std::string> > tree1;
    // ft::pair<std::string, std::string> p("test", "test");
    // ft::pair<std::string, std::string> p1("test1", "test");
    // ft::pair<std::string, std::string> p2("test2", "test");
    // ft::pair<std::string, std::string> p3("test3", "test");
    // ft::pair<std::string, std::string> p4("test4", "test");
    // ft::pair<std::string, std::string> p5("test5", "test");
    // tree1.insert(p2);
    // tree1.insert(p1);
    // tree1.insert(p);
    // tree1.insert(p3);
    // tree1.insert(p4);
    // tree1.insert(p5);
    // tree1.print2D();
    // std::cout << tree1.size() << std::endl;
    // std::cout << tree1.max_size() << std::endl;
    // {
    ft::RedBlackTree<ft::pair<int, int> > tree1;
    ft::map<int, int> map1;
    ft::pair<int, int> p(170, 3);
    ft::pair<int, int> p1(160, 7);
    ft::pair<int, int> p2(150, 9);
    ft::pair<int, int> p3(100, 9);
    ft::pair<int, int> p4(140, 9);
    ft::pair<int, int> p5(120, 9);
    ft::pair<int, int> p6(145, 9);
    ft::pair<int, int> p7(130, 9);
    ft::pair<int, int> p8(35, 9);
    ft::pair<int, int> p9(38, 9);
    ft::pair<int, int> p10(75, 9);
    ft::pair<int, int> p11(68, 9);
    ft::pair<int, int> p12(12, 9);
    ft::pair<int, int> p13(47, 9);
    ft::pair<int, int> p14(24, 9);
    ft::pair<int, int> p15(34, 9);
    ft::pair<int, int> p16(33, 9);
    ft::pair<int, int> p17(0, 9);
    ft::pair<int, int> p18(87, 9);
    ft::pair<int, int> p19(15, 9);
    ft::pair<int, int> p20(44, 9);
    ft::pair<int, int> p21(70, 9);
    ft::pair<int, int> p22(135, 9);
    ft::pair<int, int> p23(142, 9);
    ft::pair<int, int> p24(90, 9);
    tree1.insert(p3);
    map1.insert(p3);

    //tree1.print2D();
    tree1.insert(p5);
    map1.insert(p5);
    // tree1.print2D();
    tree1.insert(p4);
    map1.insert(p4);
    // tree1.print2D();
    tree1.insert(p2);
    map1.insert(p2);
    // tree1.print2D();
    tree1.insert(p7);
    map1.insert(p7);
    // tree1.print2D();
    tree1.insert(p1);
    map1.insert(p1);
    // tree1.print2D();
    tree1.insert(p6);
    map1.insert(p6);
    // tree1.print2D();
    tree1.insert(p);    
    map1.insert(p);
    // tree1.print2D();
    tree1.insert(p22);
    map1.insert(p22);
    // tree1.print2D();
    tree1.insert(p23);
    map1.insert(p23);
    // tree1.print2D();
    tree1.insert(p24);
    map1.insert(p24);
    // tree1.print2D();
    tree1.insert(p10);
    map1.insert(p10);
    // tree1.print2D();
    tree1.insert(p9);
    map1.insert(p9);
    // tree1.print2D();
    tree1.insert(p8);
    map1.insert(p8);
    // tree1.print2D();
    tree1.insert(p11);
    map1.insert(p11);
    // tree1.print2D();
    tree1.insert(p12);
    map1.insert(p12);
    // tree1.print2D();
    tree1.insert(p13);
    map1.insert(p13);
    // tree1.print2D();
    tree1.insert(p14);
    map1.insert(p14);
    // tree1.print2D();
    tree1.insert(p15);
    map1.insert(p15);
    // tree1.print2D();
    tree1.insert(p16);
    map1.insert(p16);
    // tree1.print2D();
    tree1.insert(p17);
    map1.insert(p17);
    // tree1.print2D();
    tree1.insert(p18);
    map1.insert(p18);
    // tree1.print2D();
    tree1.insert(p19);
    map1.insert(p19);
    // tree1.print2D();
    tree1.insert(p20);
    map1.insert(p20);
    // tree1.print2D();
    tree1.insert(p21);
    map1.insert(p21);
    std::cout << "map" << std::endl;
    std::cout << "empty  " << map1.empty() << std::endl;
    std::cout << "size   " << map1.size() << std::endl;
    std::cout << "maxsize    " << map1.max_size() << std::endl;
    std::cout << "red black tree" << std::endl;
    std::cout << "empty " << tree1.empty() << std::endl;
    std::cout << "size  " << tree1.size() << std::endl;
    std::cout << "maxsize   " << tree1.max_size() << std::endl;
    ft::map<int, int>::iterator begin = map1.begin();
    ft::map<int, int>::iterator end = map1.end();
    for (; begin != end; begin++)
        std::cout << begin->first << " " << begin->second << std::endl;
    begin--;
    std::cout << begin->first << " " << begin->second << std::endl;
    map1.insert(begin, ft::make_pair<int, int>(895, 8));
    // map1.erase(begin);
    for (begin = map1.begin(); begin != end; begin++)
        std::cout << begin->first << " " << begin->second << std::endl;
    std::cout << "map 2" << std::endl;
    ft::map<int, int> map2;
    map2.insert(map1.begin(), map1.end());
    for (begin = map2.begin(); begin != map2.end(); begin++)
        std::cout << begin->first << " " << begin->second << std::endl;
    //map2.erase(map2.begin(), map2.end());
    map2.print2D();
    map2.check_balance();
    ft::map<int, int>::iterator lower = map2.lower_bound(90);
    ft::map<int, int>::iterator upper = map2.upper_bound(90);
    std::cout << lower->first << " " << lower->second << std::endl;
    std::cout << upper->first << " " << upper->second << std::endl;
    // ft::map<int, int>::const_iterator clower = map2.lower_bound(90);
    // ft::map<int, int>::const_iterator cupper = map2.upper_bound(90);
    // std::cout << clower->first << " " << clower->second << std::endl;
    // std::cout << cupper->first << " " << cupper->second << std::endl;
    std::cout << map2.count(9) << std::endl;
    ft::map<int, int>::iterator testfind = map2.find(9);
    std::cout << testfind->first << " " << testfind->second << std::endl;
    // ft::map<int, int>::const_iterator ctestfind = map2.find(90);
    // std::cout << ctestfind->first << " " << ctestfind->second << std::endl;
    // map1.check_balance();
    // map1.print2D();
    // begin--;
    // std::cout << begin->first << " " << begin->second << std::endl;
    // map1.erase(begin->first);
    // for (begin = map1.begin(); begin != end; begin++)
    //     std::cout << begin->first << " " << begin->second << std::endl;
    // map1.check_balance();
    // map1.print2D();
    // tree1.print2D();
    // ft::RedBlackTree<ft::pair<int, int> >::node_pointer n5 = tree1.find(p5);
    // n1->black = true;
    // n2->black = true;
    // n3->black = true;
    // n4->black = true;
    // ft::bidirectional_iterator<ft::pair<int, int> > itb(tree1.getMinimum());
    // ft::bidirectional_iterator<ft::pair<int, int> > ite(tree1.getMaximum());
    // std::cout << "value : " << *itb << std::endl;
    // ++itb;
    // std::cout << "value : " << *itb << std::endl;
    // ++itb;
    // std::cout << "value : " << *itb << std::endl;
    // ++itb;
    // std::cout << "value : " << *itb << std::endl;
    // ++itb;
    // std::cout << "value : " << *itb << std::endl;
    // ++itb;
    // std::cout << "value : " << *itb << std::endl;

    // for ( ; itb != ite; ++itb)
    //     std::cout << "value : " << *itb << std::endl;
    // ft::bidirectional_iterator<ft::pair<int, int> > itb1(tree1.getMinimum());
    // std::cout << "operator--" << std::endl;
    // for ( ; ite != itb1; --ite)
    //     std::cout << "value : " << *ite << std::endl; 

    // std::cout << n1 << std::endl;
    // std::cout << n2 << std::endl;
    // tree1.contains(p2);
    // tree1.contains(p11);
    // std::cout << n1->value << std::endl;
    // n1->black = true;
    // std::cout << n2->value << std::endl;
    // ft::RedBlackTree<ft::pair<int, int> >::node_pointer np = tree1.getParentSuccessor(n2);
    // std::cout << "parent predecessor of : " << n2->value << " " << np->value << std::endl;
    // tree1.remove(n1);
    // tree1.print2D();
    // tree1.remove(n5);
    // ft::RedBlackTree<ft::pair<int, int> >::node_pointer n4 = tree1.find(p7);
    // tree1.print2D();
    // tree1.remove(n4);
    // ft::RedBlackTree<ft::pair<int, int> >::node_pointer n3 = tree1.find(p22);
    // tree1.print2D();
    // tree1.remove(n3);
    // tree1.print2D();
    // ft::RedBlackTree<ft::pair<int, int> >::node_pointer n1 = tree1.find(p);
    // tree1.remove(n1);
    // //std::cout << n1->value << std::endl;
    // tree1.print2D();
    // ft::RedBlackTree<ft::pair<int, int> >::node_pointer n2 = tree1.find(p23);
    // tree1.remove(n2);
    // tree1.print2D();
    // tree1.clear();
    // tree1.print2D();
    // tree1.print2D();
    
    // std::cout << tree1.size() << std::endl;
    // std::cout << tree1.max_size() << std::endl;

    // }

    // tree1.print2D();
    // ft::RedBlackTree<ft::pair<int, int> >::iterator begin = tree1.begin();
    // ft::RedBlackTree<ft::pair<int, int> >::iterator end = tree1.end();
    // ft::RedBlackTree<ft::pair<int, int> >::reverse_iterator rbegin = tree1.rbegin();
    // ft::RedBlackTree<ft::pair<int, int> >::reverse_iterator rend = tree1.rend();
    
    // ft::RedBlackTree<ft::pair<int, int> >::const_iterator cbegin = begin;
    // std::cout << (*begin).first << " " << (*begin).second << std::endl;
    // --begin;
    // std::cout << (*begin).first << " " << (*begin).second << std::endl;
    // ++begin;
    // std::cout << (*begin).first << " " << (*begin).second << std::endl;
    
    // ft::bidirectional_iterator<ft::pair<int, int> > it(tree1.getMinimum());
    // std::cout << (*it).first << " " << (*it).second << std::endl; 
    // ++it;
    // std::cout << (*it).first << " " << (*it).second << std::endl; 
    // std::cout << "=======================================================================" << std::endl;
    // //std::cout << (*begin).first << " " << (*begin).second << std::endl;
    // for (; begin != end; begin++)
    //     std::cout << (*begin).first << " " << (*begin).second << std::endl;
    // // std::cout << rend->first << " " << rend->second << std::endl;
    // std::cout << "=======================================================================" << std::endl;
    // for (; rbegin != rend; ++rbegin)
    //     std::cout << (*rbegin).first << " " << (*rbegin).second << std::endl;
    // // ++end;
    // // --end;
    // // std::cout << (*rend).first << " " << (*rend).second << std::endl;
    // // ft::RedBlackTree<ft::pair<int, int> >::iterator end2 = end--;
    // // std::cout << (*end).first  << "  " << (*end).second << std::endl;
    // ft::RedBlackTree<ft::pair<int, int> >::iterator itn6 = tree1.upper_bound(90);
    // std::cout << itn6->first << " " << itn6->second << std::endl;
    // ft::RedBlackTree<ft::pair<int, int> >::iterator itn7 = tree1.lower_bound(170);
    // std::cout << itn7->first << " " << itn7->second << std::endl;
    // int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    
    
    
    

    // ft::vector<int> v((std::istream_iterator<int>(std::cin)), std::istream_iterator<int>());
    // // std::vector<int>::iterator b = v.begin();
    // std::cout << v.capacity() << " " << v.size() << "\n";
    // std::vector<int> v1(v.begin(), v.end());
    // // std::vector<int>::iterator b = v.begin();
    // std::cout << v1.capacity() << " " << v1.size() << "\n";
    ft::map<int, int>::iterator itf = map2.find(70);
    std::cout << itf->first << " " << itf->second << std::endl;
    ft::map<int, int>::const_iterator citf = map2.begin();
    std::cout << citf->first << " " << citf->second << std::endl;
    map2[13] = 99;

    // map2.print2D();
    //std::cout << map2[70] << std::endl;
    map2.print2D();
    ft::map<int, int> map3(map2);
    std::cout << "Map3" << std::endl;
    map3.print2D();

    // ft::vector<int> av(5, 55);
    // ft::vector<int>::iterator itv =  av.begin();
    // ft::vector<int>::const_iterator citv =  av.begin();
    // std::cout << *citv << std::endl;
    

    return 0;
}