#include <map>
#include <iostream>

// class A {
//     int a;
//     public:
//         A () : a(15) {}
//         class B {
//             friend class A;
//             int b;
//                 B() : b(150) {}
//             public:
//                 void show(A aa) {
//                     std::cout << "a = " << aa.a << std::endl;
//                 }
//         };
//     void show(B bb) {
//         std::cout << "a = " << bb.b << std::endl;
//     }
// };

int     main()
{
    int a = 5;

    std::cout << ++a << std::endl;
    std::cout << a++ << std::endl;
    // std::map<std::string, std::string> m;
    // std::map<std::string, std::string>::iterator itm;

    // itm--;
    // std::cout << (*itm).first << std::endl;
    // std::pair<std::string, std::string> kv("jhon", "jhon@email.com");
    // std::pair<std::string, std::string> kv1("jhon1", "jhon1@email.com");
    // // m.insert(m.begin(), "jhon@email.com");
    // m.insert(kv);
    // m.insert(kv1);
    // std::map<std::string, std::string>::iterator it = m.begin();
    // std::map<std::string, std::string>::iterator ite = m.end();
    // //std::cout << (*it).first << " : " << (*it).second << std::endl;
    // it++;
    // it++;
    // std::cout << &(*it) << std::endl;
    // std::cout << &(*ite) << std::endl;
    // //std::cout << (*it).first << " : " << (*it).second << std::endl;
    // //std::cout << (*ite).first << " : " << (*ite).second << std::endl;
    // std::cout << m.size() << std::endl;
    // // std::map<std::string, std::string>::iterator it = m.begin();
    // // std::map<std::string, std::string>::iterator it1 = m.begin();
    // // std::cout << (it == it1) << std::endl;
    // // std::cout << (*it).first << std::cout;
//    std::map<char,int> mymap;

//     mymap['x'] = 100;
//     mymap['y'] = 200;
//     mymap['z'] = 300;

//     // show content:
//     std::map<char,int>::iterator rit = mymap.begin();
//     std::map<char,int>::iterator ritn = mymap.upper_bound('z');
//     //std::cout << ritn->first << " " << ritn->second << std::endl;
//     //std::map<char,int>::reverse_iterator rit = mymap.rbegin();
//     //std::map<char,int>::reverse_iterator rend = mymap.rend();
//     //--rit;
//     //std::cout << rit->first << " => " << rit->second << '\n';
//     //++rit;
//     //std::cout << rit->first << " => " << rit->second << '\n';
//     // std::cout << rend->first << " => " << rend->second << '\n';

//     for (rit=mymap.begin(); rit!=mymap.end(); ++rit)
//         std::cout << rit->first << " => " << rit->second << '\n';
    return 0;
}