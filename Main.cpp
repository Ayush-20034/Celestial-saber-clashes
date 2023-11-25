
#include "Game.h"
#include<time.h>






int main()
{
    // srand(time(static_cast<unsigned>(0)));
    std::time_t time(std::time_t * arg);
    std::srand(std::time(nullptr));
    Game game;
    game.run(); 
    
    
    return 0;
}
