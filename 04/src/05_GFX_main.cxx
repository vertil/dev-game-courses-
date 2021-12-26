#include "05_GFX.cxx"

int main(int, char **)
{
    if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        std::cerr << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    engineQ eng;

    bool q=true;
    while(q){
        q=eng.eventEng();
        //eng.checkMap();
        eng.checkMapMod();
        eng.render();
    }

}
