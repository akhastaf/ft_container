#include <iostream>
# include <memory>
#include <vector>
# include "stack/Stack.hpp"


int     main()
{
    ft::Stack<int>  s;

    for (int i = 0; i < 10; i++)
        s.push(i * 2 + 3);
    
    return 0;
}