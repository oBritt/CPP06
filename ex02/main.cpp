
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>


Base * generate(void)
{
    Base *ptr;
    std::srand(std::time(0));
    int i = std::rand() % 3;
    if (i == 0)
        ptr = new A;
    else if (i == 1)
        ptr = new B;
    else
        ptr = new C;
    return (ptr);
}

void identify(Base* p)
{
    A *a;
    B *b;
    C *c;

    a = dynamic_cast<A *>(p);
    if (dynamic_cast<A *>(p))
    {
        std::cout << "it is A class" << std::endl;
    }
    else if (dynamic_cast<B *>(p))
    {
        std::cout << "it is B class" << std::endl;
    }
    else
    {
        std::cout << "it is C class" << std::endl;
    }
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A &>(p);
        std::cout << "it is A class" << std::endl;
    }
    catch(const std::exception& e)
    {
        try
        {
            B& b = dynamic_cast<B &>(p);
            std::cout << "it is B class" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << "it is C class" << std::endl;
        }
        
    }
    
}

int main()
{
    Base *p = generate();
    identify(p);
    identify(*p);
}