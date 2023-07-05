//--- строка компиляции и построения + запуск -----------------------
//--- g++ -std=c++17 -O2 -Wall -pedantic -pthread main.cpp && ./a.out
//
//--- Не работает с C++98 
//--- Работает, начиная с C++11 
//-------------------------------------------------------------------

#include <iostream>
#include <thread>
#include <string>

int main()
{
    if (__cplusplus == 201703L) std::cout << "C++17\n";	    //--- для параметра -std=c++17	
    else if (__cplusplus == 201402L) std::cout << "C++14\n";//--- для параметра -std=c++14
    else if (__cplusplus == 201103L) std::cout << "C++11\n";//--- для параметра -std=c++15
    else if (__cplusplus == 199711L) std::cout << "C++98\n";//--- для параметра -std=c++98
    else std::cout << "pre-standard C++\n"; 		    //--- для параметра -std=c++2a

    //--- лямбда принимает пару строк по ссылкам const std::string& 
    //--- и выводит пару const std::string 
    //--- благодаря типу auto возвращаемого результата
    auto func = [](const std::string& first, const std::string& second)
    {
        std::cout << first << second;
    };
    std::thread thread(func, "Hello, ", "threads!");
    thread.join();
}
