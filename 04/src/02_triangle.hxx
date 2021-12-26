#pragma once
#include "01_render_line.hxx"

struct triangle{
    position p1;
    position p2;
    position p3;
};
void copyTriangle(triangle& t1,const triangle& t2){
    t1.p1.x=t2.p1.x;
    t1.p1.y=t2.p1.y;

    t1.p2.x=t2.p2.x;
    t1.p2.y=t2.p2.y;

    t1.p3.x=t2.p3.x;
    t1.p3.y=t2.p3.y;
    //copyPos(t1.p1,t2.p1);
    //copyPos(t1.p2,t2.p2);
    //copyPos(t1.p3,t2.p3);
}
/*void setTriangle(triangle& t1, uint8_t p1,
                 uint8_t p2, uint8_t p3){
    copy
}*/
void draw_triag(const position& p1, const position& p2,
                const position& p3,const col& trian_col,
                canva& pict){
    draw_line(p1,p2,trian_col,pict);
    draw_line(p2,p3,trian_col,pict);
    draw_line(p3,p1,trian_col,pict);
}
void draw_triag(const triangle& triag,const col& trian_col,
                canva& pict){
    draw_line(triag.p1,triag.p2,trian_col,pict);
    draw_line(triag.p2,triag.p3,trian_col,pict);
    draw_line(triag.p3,triag.p1,trian_col,pict);
}

