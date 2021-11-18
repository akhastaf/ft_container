#include <map>
#include <iostream>

int     main()
{
    std::map<std::string, std::string> m;
    std::pair<std::string, std::string> kv("jhon", "jhon@email.com");
    m.insert(kv);
    std::cout << m.size() << std::endl;
    std::map<std::string, std::string>::iterator it = m.begin();
    std::map<std::string, std::string>::iterator it1 = m.begin();
    std::cout << (*it).first << std::cout;
    return 0;
}