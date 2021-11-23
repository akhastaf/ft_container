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
    ft::pair<int, int> p(2, 3);
    ft::pair<int, int> p1(6, 7);
    ft::pair<int, int> p2(8, 9);
    ft::pair<int, int> p3(9, 9);
    ft::pair<int, int> p4(4, 9);
    ft::pair<int, int> p5(5, 9);
    tree1.insert(p2);
    tree1.insert(p1);
    tree1.insert(p);
    tree1.insert(p3);
    tree1.insert(p4);
    tree1.insert(p5);
    tree1.print2D();
    std::cout << tree1.size() << std::endl;
    std::cout << tree1.max_size() << std::endl;

    // }

    return 0;
}