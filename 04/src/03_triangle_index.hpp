#pragma once
#include "02_triangle.hxx"
#include <algorithm>

void drawPols(const std::vector<position> uniq_pos,
              const std::vector<uint8_t> indexs,
              const col& line_col,
              canva& pict){
    triangle buff_t;
    for(uint32_t i=0;i<indexs.size();i+=3){
        buff_t.p1=uniq_pos[indexs[i]];
        buff_t.p2=uniq_pos[indexs[i+1]];
        buff_t.p3=uniq_pos[indexs[i+2]];
        draw_triag(buff_t,line_col,pict);
    }

}
