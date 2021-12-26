#pragma once
#include <cstdlib>
#include <iostream>
#include <string_view>
//#include "engine.hxx"
#include <vector>
#include <SDL2/SDL.h>

class engine{
    SDL_Event event_eng;
    SDL_Window *window;
    struct button_sdl{
        std::string_view name;
        SDL_KeyCode button;
    };
    std::vector<button_sdl> button_s={{
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
    }};
public:
    engine(/*float x, float y*/);
    bool event();
    ~engine();
};


