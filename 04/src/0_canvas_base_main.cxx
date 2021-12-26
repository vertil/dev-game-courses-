#include "0_canvas_base.hxx"

int main(int, char**){
    const col red={255,0,0};
    const col black={0,0,0};
    //std::cout<<std::to_string(red.r)<<std::to_string(red.g)<<std::to_string(red.b)<<std::endl;
    canva zzz;

    zzz.fillpixs(red);

    zzz.save_image("0_canvas.ppm");
     std::cout << "ppp\n";
    canva ppp;
    ppp.load_image("0_canvas.ppm");
    if(!(ppp==zzz)){
        std::cerr << "image != image_loaded\n";
        return 1;
    }else{
        std::cout << "image == image_loaded\n";
    }
    /*position t1={320,240};
    zzz.load_image("0_canvas.ppm");
    zzz.setPixColor(red,t1);
    zzz.save_image("0_canvas.ppm");*/
    return 0;
}
