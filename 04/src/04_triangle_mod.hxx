#pragma once
#include "03_triangle_index.hxx"
#include <algorithm>
#include <cassert>
struct bebe{
    position point;
    col color;
};
uint8_t interpol(double a,double b,
                  double min, double max,
                  double t){
    double buff;
    if(t==min){
        return a;
    }
    if(t==max){
        return b;
    }
    if(b>a){
        buff= (((b-a)/(max-min))*t)+a;
        //std::cout <<buff<<std::endl
        return round(buff);
    }else{
        buff= a-(((a-b)/(max-min))*t);
        //std::cout <<buff<<std::endl;
        return round(buff);
    }

}
void setBebe(bebe& in_bebe,const col& color,const position& pos){
    in_bebe.color=color;
    in_bebe.point=pos;
}

void getModline(const bebe& f1,const bebe& f2, std::vector<bebe>& line){
    std::vector<position> pois;
    getLine(f1.point,f2.point,pois);
    col buff_c;
    bebe buff_b;
    uint32_t max=pois.size();
    for(uint32_t i=0;i<max;i++){
        buff_c.r=interpol(f1.color.r,f2.color.r,0,max,i);
        buff_c.g=interpol(f1.color.g,f2.color.g,0,max,i);
        buff_c.b=interpol(f1.color.b,f2.color.b,0,max,i);
        buff_b.color=buff_c;
        buff_b.point=pois[i];
        line.push_back(buff_b);
        //std::cout<<std::to_string(buff_c.r)<<" "<<std::to_string(buff_c.g)<<" "<<std::to_string(buff_c.b)<<std::endl;
    }
    //std::cout<<"------"<<std::endl;
}
void drawModLine(canva& pict,const bebe& f1, const bebe& f2){
    std::vector<bebe> bebes;
    getModline(f1,f2,bebes);
    for(auto i:bebes){
       pict.setPixColor(i.color,i.point);
    }
    pict.setPixColor(f2.color,f2.point);
}
void horizTriag(std::vector<bebe> l1, std::vector<bebe> l2,canva& pict){
    int i=0;
    int j=l2.size()-1;
    drawModLine(pict,l1[i],l2[j]);
    for(;i<l1.size()-1;i++,j--){
        for(bool q=false;q==false;){
            if(i+1<l1.size()-1 && l1[i].point.y==l1[i+1].point.y){
                i++;
            }else{
                q=true;
            }
        }
        for(bool q=false;q==false;){
            if(j-1>1 && l2[j].point.y==l2[j-1].point.y){
                j--;
            }else{
                q=true;
            }
        }
        drawModLine(pict,l1[i],l2[j]);
    }
}

void drawModTriangle(canva& pict,const bebe& f1, const bebe& f2,const bebe& f3){
    std::vector<bebe> f1f2;
    getModline(f1,f2,f1f2);
    for(auto i:f1f2){
        pict.setPixColor(i.color,i.point);
    }
    std::vector<bebe> f2f3;
    getModline(f2,f3,f2f3);
    for(auto i:f2f3){
        pict.setPixColor(i.color,i.point);
    }
    std::vector<bebe> f3f1;
    getModline(f3,f1,f3f1);
    for(auto i:f3f1){
        pict.setPixColor(i.color,i.point);
    }
    pict.setPixColor(f1.color,f1.point);

    if(f1f2.size()>f2f3.size() && f1f2.size()>f3f1.size()){ //f1f2 longest
        bebe finish;
        int fin=1;
        for(int j=0;j<f1f2.size();j++){//finding horizontal
            if(f1f2[j].point.y==f3.point.y){
                setBebe(finish,f1f2[j].color,f1f2[j].point);
                fin=j;
            }
        }
       std::vector<bebe> buff;
       buff.assign(f1f2.begin(),f1f2.begin()+fin+1);
       horizTriag(f3f1,buff,pict);
       buff.clear();
       buff.reserve(f3f1.size()-fin);
       buff.assign(f1f2.begin()+fin+1,f1f2.end());
       horizTriag(buff,f2f3,pict);

    }
    if(f2f3.size()>f1f2.size() && f2f3.size()>f3f1.size()){ //l2 longest
        bebe finish;
        int fin=1;
        for(int j=0;j<f2f3.size();j++){//finding horizontal
            if(f2f3[j].point.y==f1.point.y){
                setBebe(finish,f2f3[j].color,f2f3[j].point);
                fin=j;
            }
        }
       std::vector<bebe> buff;
       buff.assign(f2f3.begin(),f2f3.begin()+fin+1);
       horizTriag(f1f2,buff,pict);
       buff.clear();
       buff.reserve(f1f2.size()-fin);
       buff.assign(f2f3.begin()+fin+1,f2f3.end());
       horizTriag(buff,f3f1,pict);
    }
    if(f1f2.size()>f2f3.size() && f1f2.size()>f1f2.size()){ //l3 longest
        bebe finish;
        int fin=1;
        for(int j=0;j<f3f1.size();j++){//finding horizontal
            if(f3f1[j].point.y==f2.point.y){
                setBebe(finish,f3f1[j].color,f3f1[j].point);
                fin=j;
            }
        }
       std::vector<bebe> buff;
       buff.assign(f3f1.begin(),f3f1.begin()+fin+1);
       horizTriag(f2f3,buff,pict);
       buff.clear();
       buff.reserve(f2f3.size()-fin);
       buff.assign(f3f1.begin()+fin+1,f3f1.end());
       horizTriag(buff,f1f2,pict);
    }


}
