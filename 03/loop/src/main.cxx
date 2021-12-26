#include <cstdlib>
#include <iostream>
#include <string_view>
#include <SDL.h>
#include <vector>
struct button_sdl{std::string_view name;SDL_KeyCode button;};
std::vector<button_sdl> button_s{
    {"a", SDLK_a},
    {"s", SDLK_s},
    {"d", SDLK_d},
    {"w", SDLK_w},
    {"space", SDLK_SPACE},
    {"up", SDLK_UP},
    {"down", SDLK_DOWN},
    {"left", SDLK_LEFT},
    {"right", SDLK_RIGHT},
    {"q", SDLK_q},
    {"e", SDLK_e}
};
void chech_button(const SDL_Event& eve){
    for(auto i:button_s){
        if(i.button==eve.key.keysym.sym){
            if(eve.key.type==SDL_KEYUP){
                std::cout<<i.name<<" is released"<<std::endl;
            }else /*(eve.key.type==SDL_KEYDOWN)*/ {
                std::cout <<i.name<<" is pressed"<<std::endl;
            }
        }
    }

}


int main(int /*argc*/, char* /*argv*/[])
{
    SDL_Event event;


    SDL_Window *window=SDL_CreateWindow("Loop",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       200,
                                       200,
                                       SDL_WINDOW_OPENGL
                                       );
    if(window==NULL){
        std::cout<<"Couldn't create window"<<SDL_GetError()<<std::endl;
        return 1;
    }
    bool q=true;
    while(q){
        while(SDL_PollEvent((&event))){
            chech_button(event);
            if(event.type==SDL_QUIT)
                q=false;
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;

}

