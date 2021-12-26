#include "02_triangle.hxx"

int main(int, char **)
{
    canva g;
    g.load_image("0_canvas.ppm");
    position p1={160,20};
    position p2={60,120};
    position p3={260,120};
    col blue={0,0,255};
    draw_triag(p1,p2,p3,blue,g);
    g.save_image("02_triangle.ppm");


    return 0;
}
