#include "engine.hxx"

int main(int /*argc*/, char* /*argv*/ [])
{
    SDL_Window *window=SDL_CreateWindow("Loop",
                                        SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED,
                                        320,
                                        240,
                                        SDL_WINDOW_OPENGL
                                        );

    if(window==NULL){
    std::cout<<"Couldn't create window"<<SDL_GetError()<<std::endl;
        SDL_DestroyWindow(window);
    }

    rend=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}
