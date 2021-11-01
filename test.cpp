#include <iostream>
# include <memory>
#include <vector>
# include "vector/vector.hpp"

int main()
{
    // std::vector<std::string> ar(4, "Hello");
    // ft::vector<std::string> myar(2, "Hi");
    // ft::vector<std::string> myar1(4);

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
    
    // ft::vector<std::string> myar2(myar1);

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


    // ft::vector<int> testpush(3);
    // std::vector<int> testpush0(3);

    // for (int i = 0; i < 6; i++)
    // {
    //     testpush.push_back(i*2);
    //     testpush0.push_back(i*2);
    // }
    // std::cout << "std::vector : " << std::endl;
    // std::cout << testpush0.size() << std::endl;
    // std::cout << testpush0.capacity() << std::endl;
    // std::cout << "ft::vector : " << std::endl;
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
    // ft::vector<int> testop = testpush;
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
    // ft::vector<int> my(org.begin(), org.end());

    // std::cout << my.size() << std::endl;
    // std::cout << my.capacity() << std::endl;
    // for (int i = 0; i < my.size(); i++)
    //     std::cout << my[i] << std::endl;
    // int i = 0;
    // ft::vector<int>::iterator it = my.begin();
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
    ft::vector<int> a(10, 55);
    ft::vector<int> b(15, 33);
    std::cout << "A :" << std::endl;
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << std::endl;
    std::cout << "B :" << std::endl;
    for (int i = 0; i < b.size(); i++)
        std::cout << b[i] << std::endl;
    a.swap(b);
    std::cout << "A :" << std::endl;
    for (int i = 0; i < a.size(); i++)
        std::cout << a[i] << std::endl;
    std::cout << "B :" << std::endl;
    for (int i = 0; i < b.size(); i++)
        std::cout << b[i] << std::endl;
    std::cout << a.size() << std::endl;
    std::cout << a.capacity() << std::endl;
    std::cout << b.size() << std::endl;
    std::cout << b.capacity() << std::endl;
    return 0;
}