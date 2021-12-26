#include "engine.hxx"



engine::engine(/*float x,float y*/)
{
    window=SDL_CreateWindow("Loop",
                           SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED,
                           200,
                           200,
                           SDL_WINDOW_OPENGL
                           );

    if(window==NULL){
    std::cout<<"Couldn't create window"<<SDL_GetError()<<std::endl;
        SDL_DestroyWindow(window);
    }

}

bool engine::event()
{
    while(SDL_PollEvent(&event_eng)){
        if(event_eng.type==SDL_QUIT){
            return false;
        }else{
            for(auto i:button_s){
                if(i.button==event_eng.key.keysym.sym){
                    if(event_eng.type==SDL_KEYUP){
                        std::cout<<i.name<<" is released"<<std::endl;
                        SDL_Delay(20);
                        return true;

                    }else{
                        std::cout<<i.name<<" is pressed"<<std::endl;
                        SDL_Delay(20);
                        return true;
                    }
                }
            }
        }

    }
    SDL_Delay(100);
    return true;
};




engine::~engine()
{
    SDL_DestroyWindow(window);
    button_s.clear();
    SDL_Quit();
}
