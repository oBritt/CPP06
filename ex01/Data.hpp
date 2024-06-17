#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
    public:
        Data();
        ~Data();
        Data(int a, int b);
        Data(Data const& other);
        Data& operator=(Data const& other);
        int a;
        int b;
        int getA() const;
        int getB() const;

};

std::ostream& operator<<(std::ostream& o, Data const & data);


#endif