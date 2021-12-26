#pragma once
#include "04_triangle_mod.hxx"
#include <SDL2/SDL.h>
#include <cmath>
class engineQ{
    SDL_Window *window;
    SDL_Event event_eng;
    SDL_Renderer *rend;



    std::vector<bebe> points;
    std::vector<position> poss;
    std::vector<uint16_t> indexs;
    std::vector<position> poss_buff;
    std::vector<bebe> bebes;
     std::vector<bebe> bebes_buff;

    triangle triag;
    canva image;
    bebe buff_bebe;
    position buff_p;
    uint16_t mouse_posX;
    uint16_t mouse_posY;
    double wheel=10;

    col green={0,255,0};
    col red={255,0,0};
    col buff_col;

    struct bebeTriag{
        bebe p1;
        bebe p2;
        bebe p3;
    };
public:
    engineQ(){

        window=SDL_CreateWindow("Loop",
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

           poss.reserve(32*24);
           position g;
           for(int i=10;i<=230;){
               for(int j=10;j<=310;){
                   poss.push_back({j,i});
                   g.x=j;g.y=i;
                   bebes.push_back({g,green});
                   j+=10;
               }
               i+=10;
           }

           /*std::cout<<"total points:"<<poss.size()<<std::endl;
           for(auto i:poss){
               std::cout<<i.x<<":"<<i.y<<std::endl;
           }*/
           indexs.reserve(32*24*3*5);
           for(int j=0;j<23;j++){
               for(int i=0;i<30;i++){
                   indexs.push_back(i+j*31);
                   indexs.push_back(i+1+j*31);
                   indexs.push_back(i+j*31);
               }

           }

           for(int j=0;j<22;j++){
               for(int i=0;i<30;i++){
                   indexs.push_back(i+j*31);
                   indexs.push_back(i+31+j*31);
                   indexs.push_back(i+j*31);
               }

           }

           for(int i=30;i<690;){
               indexs.push_back(i);
               indexs.push_back(i+31);
               indexs.push_back(i);
               i+=31;
           }


}

    bool eventEng(){
        while(SDL_PollEvent(&event_eng)){
            if(event_eng.type==SDL_QUIT){
                return false;
            }else if(event_eng.type==SDL_MOUSEMOTION) {
                mouse_posX = event_eng.motion.x;
                mouse_posY = event_eng.motion.y;
                //std::cout<<std::to_string(mouse_posX)<<":"<<std::to_string(mouse_posY)<<std::endl;
                return true;
             }else if(event_eng.type==SDL_MOUSEWHEEL){
                wheel+=event_eng.wheel.y;
                std::cout<<std::to_string(wheel)<<std::endl;
                return true;
              }

         }
         return true;
    }

    bool render(){
        SDL_Surface* bitSurface;
        SDL_Texture* bitTexture;

        void*     pixels = image.getPixs().data();
        const int depth  = sizeof(col) * 8;
        const int pitch  = width * sizeof(col);
        const int rmask  = 0x000000ff;
        const int gmask  = 0x0000ff00;
        const int bmask  = 0x00ff0000;
        const int amask  = 0;

        bitSurface=SDL_CreateRGBSurfaceFrom(pixels,width,height,depth,pitch,rmask,gmask,bmask,amask);
        if(bitSurface==nullptr){
            std::cerr << SDL_GetError() << std::endl;
            return false;
        }
        bitTexture=SDL_CreateTextureFromSurface(rend,bitSurface);
        if(bitTexture==nullptr){
            std::cerr << SDL_GetError() << std::endl;
            return false;
        }

        SDL_FreeSurface(bitSurface);
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend,bitTexture, nullptr,nullptr);
        SDL_RenderPresent(rend);
        SDL_DestroyTexture(bitTexture);

    }
    void drawPolsMouse(){
        triangle buff_t;
        for(uint32_t i=0;i<indexs.size();i+=3){
            buff_t.p1=checkpos(poss[indexs[i]]);
            buff_t.p2=checkpos(poss[indexs[i+1]]);
            buff_t.p3=checkpos(poss[indexs[i+2]]);


            draw_triag(buff_t,{255,255,255},image);
        }

    }
    void drawPolsMouseMod(){
        bebeTriag qwe;
        for(uint32_t i=0;i<indexs.size();i+=3){
            qwe.p1=checkBebe(bebes[indexs[i]]);
            qwe.p2=checkBebe(bebes[indexs[i+1]]);
            qwe.p3=checkBebe(bebes[indexs[i+2]]);
            drawModTriangle(image,qwe.p1,qwe.p2,qwe.p3);
        }

    }
    void checkMap(){
        poss_buff.clear();
        poss_buff.assign(poss.begin(),poss.end());
        image.fillpixs({0,0,0});
        drawPolsMouse();
    }
    void checkMapMod(){
        bebes.clear();
        bebes_buff.assign(bebes.begin(),bebes.end());
        image.fillpixs({0,0,0});
        drawPolsMouseMod();
    }
    position checkpos(position& in){
        if(sqrt(pow(in.x-mouse_posX,2)+pow(in.y-mouse_posY,2))<=wheel){
            if(in.x<=mouse_posX && in.y<=mouse_posY){
                return {in.x-5,in.y-5};
            }
            if(in.x<=mouse_posX && in.y>=mouse_posY){
                return {in.x-5,in.y+5};
            }
            if(in.x>=mouse_posX && in.y>=mouse_posY){
                return {in.x+5,in.y+5};
            }
            if(in.x>=mouse_posX && in.y<=mouse_posY){
                return {in.x+5,in.y-5};
            }
        }else{
            return in;
        }
    }
    bebe checkBebe(bebe& in){
        double lenght=sqrt(pow(in.point.x-mouse_posX,2)+pow(in.point.y-mouse_posY,2));

        if(lenght<=wheel){
            if(in.point.x<=mouse_posX && in.point.y<=mouse_posY){
                buff_p.x=in.point.x-5;
                buff_p.y=in.point.y-5;
                buff_col=interpolCol(/*&(0.0),*/wheel,lenght);
                setBebe(buff_bebe,buff_col,buff_p);
                return buff_bebe;

            }
            if(in.point.x<=mouse_posX && in.point.y>=mouse_posY){
                buff_p.x=in.point.x-5;
                buff_p.y=in.point.y+5;
                buff_col=interpolCol(/*&(0.0),*/wheel,lenght);
                setBebe(buff_bebe,buff_col,buff_p);
                return buff_bebe;

            }
            if(in.point.x>=mouse_posX && in.point.y>=mouse_posY){
                buff_p.x=in.point.x+5;
                buff_p.y=in.point.y+5;
                buff_col=interpolCol(/*&(0.0),*/wheel,lenght);
                setBebe(buff_bebe,buff_col,buff_p);
                return buff_bebe;

            }
            if(in.point.x>=mouse_posX && in.point.y<=mouse_posY){
                buff_p.x=in.point.x+5;
                buff_p.y=in.point.y-5;
                buff_col=interpolCol(/*&(0.0),*/wheel,lenght);
                setBebe(buff_bebe,buff_col,buff_p);
                return buff_bebe;

            }
        }else{
            return in;
        }

    }
    col interpolCol(/*double& min,*/double& max,double& t){
        col buf_col;
        buf_col.r=interpol(red.r,green.r,0,max,t);
        buf_col.g=interpol(red.g,green.g,0,max,t);
        buf_col.b=interpol(red.b,green.b,0,max,t);
        return buf_col;
    }


};
