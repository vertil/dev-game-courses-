#include "01_render_line.hxx"
position sas(position poko){
    //position poko;
    double alpha = (M_PI /2);

    double x     = poko.x;
    double y     = poko.y;
    double x0    = 320/2;
    double y0    = 240/2;
    //poko.x=x0+(poko.x-x0)*std::cos(alpha)-(poko.y-y0)*sin(alpha);
    //poko.y=y0+(poko.y-y0)*std::cos(alpha)+(poko.x-x0)*sin(alpha);
    //poko.x=round(poko.x);
    //poko.y=round(poko.y);
    poko.x=x0+(poko.x-x0)*std::cos(alpha)-(poko.y-y0)*sin(alpha);
    poko.y=y0+(poko.y-y0)*std::cos(alpha)+(poko.x-x0)*sin(alpha);

    std::cout<<std::to_string(poko.x)<<":"
            <<std::to_string(poko.y)<<std::endl;
    return poko;
}
int main(int, char**){
    canva g;
    g.load_image("0_canvas.ppm");
    position f1={140,100};
    position f2={180,100};
    col green={0,255,0};


    g.setPixColor(green,{160,120});

    draw_line(f1,f2,green,g);
    draw_line(sas(f1),sas(f2)   ,green,g);

    g.save_image("01_line.ppm");

    return 0;
}
