#include <iostream>
# include <memory>
#include <vector>
#include <list>
# include "stack/Stack.hpp"


int     main()
{
    ft::Stack<int>  s;

    for (int i = 0; i < 10; i++)
        s.push(i * 2 + 3);
    for (int i = 0; i < 10; i++)
    {
        std::cout << "i : " << i << " " << s.top() << std::endl;
        s.pop();
    }
    return 0;
}