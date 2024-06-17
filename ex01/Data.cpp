

#include "Data.hpp"

Data::Data(): a(10), b(12){}

Data::~Data(){}

Data::Data(int a, int b): a(a), b(b){}

Data::Data(Data const & other): a(other.a), b(other.b){}

Data& Data::operator=(Data const & other)
{
    if (this != &other)
    {
        this->a = other.a;
        this->b = other.b;
    }
    return (*this);
}

int Data::getA() const
{
    return (this->a);
}
int Data::getB() const
{
    return (this->b);
}

std::ostream& operator<<(std::ostream& o, Data const & data)
{
    o << "a = " << data.getA() << "   " << "b = " << data.getB();
    return (o); 
}
