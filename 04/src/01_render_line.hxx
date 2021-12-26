#pragma once
#include "0_canvas_base.cxx"

void getLine(const position& p1,const position& p2,std::vector<position>& vect){
    //std::vector<position> line;

    uint32_t x1=p1.x;
    uint32_t y1=p1.y;
    uint32_t x2=p2.x;
    uint32_t y2=p2.y;
    position buff;

    const int dX=abs(x2-x1);
    const int dY=abs(y2-y1);
    const int signX=x1<x2?1:(-1);
    const int signY=y1<y2?1:(-1);
    uint32_t error=dX-dY;
    //buff={x2,y2};

    //vect.push_back(buff);

    while(x1!=x2 || y1!=y2){
        buff={x1,y1};
        //std::cout<<buff.x<<":"<<buff.y<<std::endl;
        vect.push_back(buff);
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
    vect.push_back(p2);
}
void draw_line(const position& p1, const position& p2, const col& line_col, canva& Y){
    std::vector<position> line_p;
    getLine(p1,p2,line_p);
    for(auto i:line_p){
        Y.setPixColor(line_col,i);
    }
}
