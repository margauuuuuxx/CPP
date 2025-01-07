#include <iostream>
#include <string>
#include <map>

class   Harl
{
    private:
        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void);
        int     getLevel(std::string level);
    public:
        Harl();
        ~Harl();
        void    complain( std::string level); 
};