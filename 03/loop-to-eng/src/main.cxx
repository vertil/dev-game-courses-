
#include <cstdlib>
#include <iostream>
#include <string_view>
#include <vector>
#include "engine.hxx"




int main(int /*argc*/, char* /*argv*/[])
{
    engine eng;

    bool q=true;

    while(q){
       q=eng.event();
       char f='r';
       eng.write(&f);

 SDL_Delay(500);
       f='t';
       eng.write(&f);
       SDL_Delay(500);
    }

    //eng.~engine();
    return 0;

}

