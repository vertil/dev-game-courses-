#include "04_triangle_mod.hxx"

int main(int, char **)
{
    canva g;
    col blue={0,0,255};
    col black={0,0,0};
    col green={0,255,0};

    g.load_image("0_canvas.ppm");

    bebe p1;
    position b1={100,60};
    setBebe(p1,blue,b1);

    bebe p2;
    b1={130,180};
    setBebe(p2,black,b1);

    bebe p3;    
    b1={50,100};
    setBebe(p3,green,b1);
    drawModTriangle(g,p1,p2,p3);

    //line test
    /*bebe p4;
    b1={310,10};
    setBebe(p4,green,b1);
    bebe p5;
    b1={160,240};
    setBebe(p5,black,b1);
    drawModLine(g,p4,p5);*/


    g.save_image("04_triangle_mod.ppm");
    return 0;
}
