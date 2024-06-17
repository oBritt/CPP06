
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include "Data.hpp"

class Data;

class Serializer{

    private:
        Serializer();
        ~Serializer();
        Serializer(Serializer const & other);
        Serializer& operator=(Serializer const & other);
    public:

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);


};


#endif