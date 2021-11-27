#include <map>
#include <iostream>

int     main()
{
    std::map<std::string, std::string> m;
    std::pair<std::string, std::string> kv("jhon", "jhon@email.com");
    std::pair<std::string, std::string> kv1("jhon1", "jhon1@email.com");
    // m.insert(m.begin(), "jhon@email.com");
    m.insert(kv);
    m.insert(kv1);
    std::map<std::string, std::string>::iterator it = m.begin();
    std::cout << (*it).first << " : " << (*it).second << std::endl;
    it--;
    std::cout << (*it).first << " : " << (*it).second << std::endl;
    std::cout << m.size() << std::endl;
    // std::map<std::string, std::string>::iterator it = m.begin();
    // std::map<std::string, std::string>::iterator it1 = m.begin();
    // std::cout << (it == it1) << std::endl;
    // std::cout << (*it).first << std::cout;
    return 0;
}