    #pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <array>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <SDL2/SDL.h>




#pragma pack(push, 1)
struct col{
    uint8_t r=0;
    uint8_t g=0;
    uint8_t b=0;
    friend bool operator==(const col& l,const col& r){
        if(l.r==r.r && l.g==r.g && l.b==r.b){
            return true;
        }else{
            return false;
        }
    };
};
#pragma pack(pop)

struct point{
    col color;
    uint32_t x=0;//Xis
    uint32_t y=0;//Yis
    uint32_t q=0;
    uint32_t w=0;//changed X
    uint32_t e=0;//changed Y


};
class engine{
    //size_t width  = 320;
    //size_t height = 240;
    //size_t buff_size = width*height;

    size_t tex_width  = 320;
    size_t tex_height = 240;
    size_t tex_buff_size = tex_width*tex_height;


    //std::array<col, buff_size> pixs;
    std::vector<col> texture;
    std::vector<col> buff;
    std::vector<point> triangles_points;
    std::vector<uint32_t> indexs;
    std::vector<point> points;

    SDL_Window *window;
    SDL_Event event_log;
    SDL_Renderer *rend;

    char type_func='S';

    int8_t mouse_Wheel=1;
public:
    engine(){
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
    }
    ~engine(){
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(window);
    }
    void load_texture(const std::string& f_name){
        std::ifstream in_file;
        in_file.exceptions(std::ios_base::failbit);
        in_file.open(f_name, std::ios_base::binary);
        std::string header;
        std::string color_format;
        char        last_next_line = 0;
        in_file >> header
                >> tex_width
                >> tex_height
                >> color_format;
        in_file.read(&last_next_line, 1);
        std::cout<<"tex_width-"<<std::to_string(tex_width)
                <<":tex_height-"<<std::to_string(tex_height)
               <<std::endl;
        if (!iswspace(last_next_line))
        {
            throw std::runtime_error("expected witespace");
        }
        texture.resize(tex_width*tex_height);
        if (texture.size() != tex_width * tex_height)
        {
            throw std::runtime_error("image size not match");
        }

        std::streamsize buf_size =
            static_cast<std::streamsize>(sizeof(col) * texture.size());
        in_file.read(reinterpret_cast<char*>(texture.data()), buf_size);
        //buff.assign(texture.begin(),texture.end());
        buff.resize(tex_width*tex_height);
        //std::cout<<"buff_size-"<<std::to_string(buff[0].))<<std::endl;
        triangles_points.push_back(getPoint(1,0));
        triangles_points.push_back(getPoint(tex_width,0));
        triangles_points.push_back(getPoint(tex_width,tex_height));
        triangles_points.push_back(getPoint(0,tex_height));

        indexs.push_back(0);
        indexs.push_back(1);
        indexs.push_back(2);
        indexs.push_back(0);
        indexs.push_back(2);
        indexs.push_back(3);

        for(int i=0;i<indexs.size();i+=3){
            readTriangle(triangles_points[indexs[i]],
                    triangles_points[indexs[i+1]],
                    triangles_points[indexs[i+2]]
                    );


        }

    }
    bool event(){
        while(SDL_PollEvent(&event_log)){
            if(event_log.type==SDL_QUIT){
                return false;
            }else if(event_log.type==SDL_KEYDOWN) {
               if(event_log.key.keysym.scancode==SDL_SCANCODE_1){
                   if(type_func=='S'){
                       type_func='D';
                   }else{
                       type_func='S';
                   }

                   return true;
               }else if(event_log.key.keysym.scancode==SDL_SCANCODE_2){
                   if(type_func=='G'){
                       type_func='D';
                   }else{
                       type_func='G';
                   }
                   return true;
               }else if(event_log.key.keysym.scancode==SDL_SCANCODE_3){
                   if(type_func=='R'){
                       type_func='D';
                   }else{
                       type_func='R';
                   }
                   return true;
               }
                //return true;
              }else if(event_log.type==SDL_MOUSEWHEEL){
                mouse_Wheel=mouse_Wheel+event_log.wheel.y;
                return true;
            }

         }
         return true;
    }
    bool render(){


        SDL_Surface* bitSurface;
        SDL_Texture* bitTexture;

        void*     pixels = buff.data();
        const int depth  = sizeof(col) * 8;
        const int pitch  = tex_width * sizeof(col);
        const int rmask  = 0x000000ff;
        const int gmask  = 0x0000ff00;
        const int bmask  = 0x00ff0000;
        const int amask  = 0;

        bitSurface=SDL_CreateRGBSurfaceFrom(pixels,tex_width,tex_height,depth,pitch,rmask,gmask,bmask,amask);
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
    col& getPixelColor(uint32_t x, uint32_t y){
        if(x>tex_width || y>tex_height){
            //std::cout<<"wrong coordinates"<<std::endl;
        }else{
            uint32_t pos=0;
            if(y==0){
                pos=x;
            }else{
                pos=(tex_width*(y-1)+x)-1;
            }

            return texture[pos];
        }
    }
    point getPoint(uint32_t x, uint32_t y){
        point buff_p;
        buff_p.color=getPixelColor(x,y);
        buff_p.x=x;
        buff_p.y=y;
        return buff_p;
    }
    void getLine(std::vector<point>& pois, const point& p1,
                 const point& p2){
        int32_t x1=p1.x;
        int32_t y1=p1.y;
        int32_t x2=p2.x;
        int32_t y2=p2.y;
        point buff;
        const int dX=abs(x2-x1);
        const int dY=abs(y2-y1);
        const int signX=x1<x2?1:(-1);
        const int signY=y1<y2?1:(-1);
        uint32_t error=dX-dY;

        while(x1!=x2 || y1!=y2){
            buff.x=x1;
            buff.y=y1;
            buff.color=getPixelColor(x1,y1);
            pois.push_back(buff);
            int error2=error*2;
            if(error2>(-dY)){
                error-=dY;
                x1+=signX;
            }
            if(error2<dX){
                error+=dX;
                y1+=signY;
            }
        }
        pois.push_back(p2);

    }
    void setPixelColor(col& color,uint32_t x, uint32_t y){
        if(x>tex_width || y>tex_height){
            //std::cout<<"wrong coordinates"<<std::endl;
        }else{
            uint32_t pos=0;
            if(y==0){
                pos=x;
            }else{
                pos=(tex_width*(y-1)+x)-1;
            }

            buff[pos]=color;            
        }

    }
    void draw(){
        if(type_func=='S' || type_func=='R'){
            for(int j=0;j<buff.size();j++){
                buff[j]={0,0,0};
            }
        }
        if(type_func=='S'){
            for(auto i:points){
                setPixelColor(i.color,round(i.x*0.5),round(i.y*0.5));
            }
        }else if(type_func=='G'){
            for(auto i:points){
                col buff_c=greyScale(i.color);
                setPixelColor(buff_c,i.x,i.y);
            }
        }else if(type_func=='R'){
            /*for(auto i:points){
                setPixelColor()
            }*/
               rotateText(points);
        }else{
            for(auto i:points){
                setPixelColor(i.color,i.x,i.y);
            }

        }



    }
    void  readTriangle(const point& p1,
                       const point& p2,
                       const point& p3
                       ){
        //std::vector<point> bif;
        //bif.resize(tex_height*tex_width);
        std::vector<point> l1;
        getLine(l1,p1,p2);
        std::vector<point> l2;
        getLine(l2,p2,p3);
        std::vector<point> l3;
        getLine(l3,p3,p1);
        //std::vector<point> points;//all points of triangle

        getTrianglepoints(l1,l2,l3, points);



    }
    void getTrianglepoints(const std::vector<point>& l1,
                           const std::vector<point>& l2,
                           const std::vector<point>& l3,
                           std::vector<point>& points
                           ){
        if(l1[0].y == l1[l1.size()-1].y){
            //std::cout<<"l1"<<std::endl;

            int i=0;//l2 pointer
            int j=l3.size()-1;//l3 pointer from end to start
            for(;i<l2.size();i++,j--){
                getLine(points,l2[i],l3[j]);
               //check same points at OY at l2
                    for(bool q=false;q==false;){
                        if(i+1<=(l2.size()-1) && l2[i].y==l2[i+1].y){
                            i++;
                        }else{
                            q=true;
                        }
                    }
                    //check same points at OY at l3
                    for(bool q=false;q==false;){
                        if(j-1>=1 && l3[j].y==l3[j-1].y){
                            j--;
                        }else{
                            q=true;
                        }
                    }
            }
        }else if(l2[0].y == l2[l1.size()-1].y){
            //std::cout<<"l2"<<std::endl;
            int i=0;//l3 pointer
            int j=l1.size()-1;//l1 pointer from end to start
            for(;i<l3.size();i++,j--){
                getLine(points,l3[i],l1[j]);
                //check same points at OY at l2
                for(bool q=false;q==false;){
                    if(i+1<l3.size()-1 && l3[i].y==l3[i+1].y){
                        i++;
                    }else{
                        q=true;
                    }
                }
                //check same points at OY at l3
                for(bool q=false;q==false;){
                    if(j-1>1 && l1[j].y==l1[j-1].y){
                        j--;
                    }else{
                        q=true;
                    }
                }

            }

        }else if(l3[0].y == l3[l1.size()-1].y){
            //std::cout<<"l3"<<std::endl;
            int i=0;//l1 pointer
            int j=l2.size()-1;//l2 pointer from end to start
            for(;i<l1.size();i++,j--){
                getLine(points,l1[i],l2[j]);
                //check same points at OY at l2
                for(bool q=false;q==false;){
                    if(i+1<l1.size()-1 && l1[i].y==l1[i+1].y){
                        i++;
                    }else{
                        q=true;
                    }
                }
                //check same points at OY at l3
                for(bool q=false;q==false;){
                    if(j-1>1 && l2[j].y==l2[j-1].y){
                        j--;
                    }else{
                        q=true;
                    }
                }

            }
        }

    }

    col greyScale(const col& in){
        uint8_t mono = static_cast<uint8_t>(
            0.2125 * in.r + 0.7152 * in.g + 0.0721 * in.b);
        return {mono,mono,mono};
    }
    void rotateText(std::vector<point>& poss){
        for(auto i:poss){

            double poko_x=i.x;
            double poko_y=i.y;

            poko_x-=tex_width/2;
            poko_y-=tex_height/2;

            poko_x*=0.5;
            poko_y*=0.5;

            double alpha = (M_PI / 4) * mouse_Wheel;
            double x     = poko_x;
            double y     = poko_y;
            double x0    = tex_width/2;
            double y0    = tex_height/2;
            poko_x=x*std::cos(alpha)-y*std::sin(alpha);
            poko_y=y*std::cos(alpha)+x*std::sin(alpha);
            //poko_x=x0+(poko_x-x0)*std::cos(alpha)-(poko_y-y0)*sin(alpha);
            //poko_y=y0+(poko_y-y0)*std::cos(alpha)+(poko_x-x0)*sin(alpha);

            poko_x+=tex_width/2;
            poko_y+=tex_height/2;




            setPixelColor(i.color,poko_x,poko_y);
        }
    }
};
