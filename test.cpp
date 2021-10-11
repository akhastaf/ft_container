#include <iostream>
# include <memory>
#include <vector>
# include "includes/vector.hpp"

int main()
{
    std::vector<std::string> ar(4, "Hello");
    ft::vector<std::string> myar(4, "Hello");

    std::cout << ar.capacity() << std::endl;
    std::cout << ar.size() << std::endl;
    std::cout << ar.max_size() << std::endl;
    std::cout << myar.capacity() << std::endl;
    std::cout << myar.size() << std::endl;
    std::cout << myar.max_size() << std::endl;
    if (ar.max_size() == myar.max_size())
        std::cout << "are equal" << std::endl;
    else
        std::cout << "are not equal" << std::endl;
    

    std::cout << ar[0] << std::endl;
    std::cout << myar[0] << std::endl;

    try 
    {
        std::cout << myar.at(200) << std::endl;
        //std::cout << ar.at(20) << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << ar.front() << std::endl;
    std::cout << myar.front() << std::endl;

    return 0;
}