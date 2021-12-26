#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <array>
#include <cmath>

constexpr size_t width  = 320;
constexpr size_t height = 240;
const size_t buff_size = width*height;

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

struct position{
    int32_t x=0;
    int32_t y=0;

};
/*void copyPos(position& p1,const position& p2){
    p1.x=p2.x;
    p1.y=p2.y;
}*/

class canva{
    //std::vector<col,buff_size> pixs;
    std::array<col,buff_size> pixs;
    std::streamsize buf_s;


public:
    canva(){
        //pixs.reserve(buff_size);
        buf_s=static_cast<std::streamsize>(sizeof(col)*pixs.size());
        //std::cout<<width<<" "<<height<<std::endl;
        //std::cout<<buff_size<<" "<<pixs.size()<<std::endl;
        //std::cout<<buf_s<<std::endl;
    }
    void save_image(const std::string& f_name)  {
        std::ofstream save_file;
        save_file.exceptions(std::ios_base::failbit);
        save_file.open(f_name, std::ios_base::binary);
        save_file<<"P6\n"<<width<<' '<<height<<' '<<255<<'\n';
        save_file.write((char*)&pixs[0],buf_s);

    }
    void load_image(const std::string& f_name){
        std::ifstream load_file;
        load_file.open(f_name, std::ios_base::binary);
        size_t im_width=0;
        size_t im_heighth=0;
        std::string h;
        std::string col_f;
        load_file>>h>>im_width>>im_heighth>>col_f>>std::ws;
        std::cout<<std::to_string(im_width)<<" "
                <<std::to_string(im_heighth)<<std::endl;
        if(pixs.size()!=im_heighth*im_width){
            throw std::runtime_error("image size more than buff size");
        }
        //std::streamsize buf_size =
          //          static_cast<std::streamsize>(sizeof(col) * pixs.capacity());
        load_file.read((char*)&pixs[0],buf_s);


    }
    void fillpixs(const col& b){
        int a=0;
        for(int i=0;i<pixs.size();i++){
            pixs[i]=b;
        }
    }
    bool operator==(const canva& in) const{
        return this->pixs==in.pixs;
    }
    void setPixColor(const col& col_in,position in){
        //std::cout<<width<<":"<<height<<" "<<in.x<<":"<<in.y<<std::endl;
        if(in.x>width || in.y>height){
            std::cout<<"wrong coordinates"<<std::endl;
        }else{
            int pos=0;
            if(in.y==0){
                pos=in.x;
            }else{
                pos=(width*(in.y-1)+in.x)-1;
            }

            this->pixs[pos]=col_in;
            }

    }
    std::array<col,buff_size>& getPixs(){
        return pixs;
    }
};

