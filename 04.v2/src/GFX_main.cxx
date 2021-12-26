#include "GFX.hxx"
int main(int, char **){

    if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    {
        std::cerr << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    engine eng;
    eng.load_texture("image.ppm");

    bool q=true;

    while(q){
        q=eng.event();
        //eng.kek();
        eng.draw();
        eng.render();
    }
}
