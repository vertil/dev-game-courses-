#include "03_triangle_index.hxx"


int main(int, char **)
{
    canva g;
    g.load_image("0_canvas.ppm");
    col green={0,255,0};
    std::vector<position> poss;
    //addding points
    position buff={50,50};
    poss.push_back(buff);
    buff={0,0};
    poss.push_back(buff);
    buff={320,0};
    poss.push_back(buff);
    buff={320,240};
    poss.push_back(buff);
    buff={50,150};
    poss.push_back(buff);
    //adding indexs
    std::vector<uint32_t> indexs={0,1,2,1,2,3,2,3,4};
    /*std::vector<position> poss;
    std::vector<uint8_t> indexs;
    poss.reserve(32*24);
    for(int i=10;i<=230;){
        for(int j=10;j<=310;){
            poss.push_back({j,i});
            j+=10;
        }
        i+=10;
    }

    std::cout<<"total points:"<<poss.size()<<std::endl;
    for(auto i:poss){
        std::cout<<i.x<<":"<<i.y<<std::endl;
    }
    indexs.reserve(32*24*3);
    for(int j=0;j<99;j++){
        for(int i=0;i<30;i++){
            indexs.push_back(i+30*j);
            indexs.push_back(i+1+30*j);
            indexs.push_back(i+30*j);
        }

    }

*/
    drawPols(poss,indexs,green,g);

    g.save_image("03_triangle_index.ppm");
    return 0;
}
