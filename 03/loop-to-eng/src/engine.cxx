#include "engine.hxx"



engine::engine(/*float x,float y*/)
{
    window=SDL_CreateWindow("Loop",
                           SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED,
                           500,
                           500,
                           SDL_WINDOW_OPENGL
                           );

    if(window==NULL){
    std::cout<<"Couldn't create window"<<SDL_GetError()<<std::endl;
        SDL_DestroyWindow(window);
    }
    rend=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void engine::write(char *t)
{
    switch (*t) {
    case 'r':{
        SDL_RenderClear(rend);
        SDL_Rect rect={50,50,50,50};
        SDL_SetRenderDrawColor(rend,255,255,255,255);
        SDL_RenderDrawRect(rend,&rect);
        SDL_SetRenderDrawColor(rend,0,0,0,255);
        SDL_RenderPresent(rend);
        break;}
    case 't':{
        SDL_RenderClear(rend);

        SDL_SetRenderDrawColor(rend,255,255,255,255);
        SDL_RenderDrawLine(rend,50,50,50,150);
        SDL_RenderDrawLine(rend,50,150,100,100);
        SDL_RenderDrawLine(rend,100,100,50,50);
        SDL_SetRenderDrawColor(rend,0,0,0,255);
        SDL_RenderPresent(rend);
        break;}
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
                        return true;

                    }else{
                        std::cout<<i.name<<" is pressed"<<std::endl;
                        return true;
                    }
                }
            }
        }

    }
    return true;
};




engine::~engine()
{
    SDL_DestroyWindow(window);
    button_s.clear();
    SDL_Quit();
}
