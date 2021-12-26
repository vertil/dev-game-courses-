
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

    }

    //eng.~engine();
    return 0;

}

