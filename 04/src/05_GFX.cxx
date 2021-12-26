#include "05_GFX.hxx"

/*engineQ::engineQ()
{
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

       for(int i=0;i<=240;i+10){
           for(int j=0;j<=320;j+10){
               buff_p={j,i};
               setBebe(buff,{0,255,0},buff_p);
               points.push_back(buff);
           }
       }
       std::cout<<"total points"<<std::endl;
       for(auto i:points){
           std::cout<<i.point.x<<":"<<i.point.y<<std::endl;
       }
       for(int i=0;i<=767;i++){
           indexs.push_back(i);
           indexs.push_back(i+1);
           indexs.push_back(i);
       }
       //-----
       for(int i=0;i<150;){
           triag.p1=points[indexs[i]].point;
           triag.p1=points[indexs[i+1]].point;
           triag.p1=points[indexs[i+2]].point;
           draw_triag(triag,{0,255,0},image);
           i+=3;
       }
       //---------

}*/

/*bool engineQ::eventEng()
{
    while(SDL_PollEvent(&event_eng)){
        if(event_eng.type==SDL_QUIT){
            return false;
        }else if(event_eng.type==SDL_MOUSEMOTION) {
            mouse_posX = event_eng.motion.x;
            mouse_posY = event_eng.motion.y;
            return true;
         }else if(event_eng.type==SDL_MOUSEWHEEL){
            wheel+=event_eng.wheel.y;
            return true;
          }

     }
                      return true;
       }*/

/*bool engineQ::render()
{
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
}*/


