#include <iostream>
#include <string>

class Entity
{
    public:

        virtual ~Entity() {}

        virtual std::string GetName() { return "Entity"; } ;

        void PrintName() {
            std::cout  <<  this->GetName() << std::endl ;
        }

} ;


class Runner : public Entity
{
    std::string name ;

    public:

        Runner( std::string PlayerName ) :  name( PlayerName ) {}

        std::string GetName()
        {
            return "Runner: " + this->name ;
        }

} ;

class Biker : public Entity
{
    std::string name ;

    public:

        Biker( std::string PlayerName ) :  name( PlayerName ) {}

        std::string GetName() ;

} ;