#include "Data.hpp"
#include "Serializer.hpp"


int main()
{
    Data d(-233, 423);
    Data *c;

    c = Serializer::deserialize(Serializer::serialize(&d));
    std::cout << *c << std::endl;
}