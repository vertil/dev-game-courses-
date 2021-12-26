#include "engine.hxx"
//-------reload
void (*reload(const char* libn,const char* tmplib,void*& oldhand))(engine*){


    if(0!=std::filesystem::remove(tmplib))
        std::cerr<<"can't remove tmp lib"<<std::endl;
    try{
    std::filesystem::copy(libn,tmplib);
    }
    catch(const std::exception& ex){
        std::cerr << "error: can't copy [" << libn << "] to ["
                  << tmplib << "]" << std::endl;
        return nullptr;
    }
    void* gamehandl=SDL_LoadObject(tmplib);
    if (gamehandl == nullptr)
    {
        std::cerr << "error: failed to load: [" << tmplib << "] "
                  << SDL_GetError() << std::endl;
        return nullptr;
    }
    oldhand=gamehandl;
    //---search of edited function
    void* func_render_ptr=SDL_LoadFunction(gamehandl,"render");//adress of function
    if(func_render_ptr==nullptr){
        std::cerr<<"can't find function"<<SDL_GetError()<<std::endl;
    }
    typedef decltype (&render) create_g; //----указатель
    auto func_render = reinterpret_cast<create_g>(func_render_ptr); //func
    return func_render;
}










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
    rend=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}

void engine::write(char*t)
{
    switch (*t) {
        case 'r':{
            SDL_RenderClear(rend);
            SDL_Rect rect={50,50,50,50};
            SDL_SetRenderDrawColor(rend,255,255,255,255);
            SDL_RenderDrawRect(rend,&rect);
            SDL_SetRenderDrawColor(rend,0,0,0,255);
            SDL_RenderPresent(rend);
             break;
        }
        case 't':{
            SDL_RenderClear(rend);
            SDL_SetRenderDrawColor(rend,255,255,255,255);
            SDL_RenderDrawLine(rend,50,50,50,150);
            SDL_RenderDrawLine(rend,50,150,100,100);
            SDL_RenderDrawLine(rend,100,100,50,50);
            SDL_SetRenderDrawColor(rend,0,0,0,255);
            SDL_RenderPresent(rend);
            break;
        }
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


int main(int /*argc*/, char* /*argv*/[])
{

    const char* libname="./libgame.so";
    const char* tmp_lib="./temp.so";

    engine eng;
    void(*render_yk)(engine*);
    void* game_lib_han{};
    render_yk=reload(libname,tmp_lib,game_lib_han);

    bool q=true;
    auto time_dur_load=std::filesystem::last_write_time(libname);//first time get
    //---------------------
    while(q){

        auto curr_w_time=std::filesystem::last_write_time(libname);//last edit time
        if(curr_w_time!=time_dur_load){   //---checkinh when rewrite
            std::filesystem::file_time_type next_time;
            for(;;){
                SDL_Delay(100);
                next_time=std::filesystem::last_write_time(libname);
                if(next_time!=curr_w_time){
                    curr_w_time=next_time;
                }else{//when edit time stop changing
                    break;
                }

            }
            std::cout<<"reloading"<<std::endl;
            render_yk=reload(libname,tmp_lib,game_lib_han);//----------reloading
            time_dur_load=next_time;
        }
        //---render and events
        //q=eng.event();
        render_yk(&eng);
    }
    //--------------------
    return 0;
}



