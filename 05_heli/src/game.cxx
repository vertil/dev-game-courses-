#include "engine.hxx"

int main(int, char **){


    engine eng;

    eng.triagInit();//init triag

    std::string error = eng.initProgramBody();//init opengl programs
    if (!error.empty())
    {
        std::cerr << error << std::endl;
        return EXIT_FAILURE;
    }
    error = eng.initProgramWings();
    if (!error.empty())
    {
        std::cerr << error << std::endl;
        return EXIT_FAILURE;
    }
    error = eng.ininProgramBackground();
    if (!error.empty())
    {
        std::cerr << error << std::endl;
        return EXIT_FAILURE;
    }

    //dowload textures
    if (!eng.load_texture("body.png",0))
    {
        std::cout<<"failed to load body.png"<<std::endl;
        return EXIT_FAILURE;;
    }
    if (!eng.load_texture("blades.png",1))
    {
        std::cout<<"failed to load blades.png"<<std::endl;
        return EXIT_FAILURE;;
    }
    if (!eng.load_texture("chernarus2.png",2)){
        std::cout<<"failed to load map.png"<<std::endl;
        return EXIT_FAILURE;;
    }
    if (!eng.load_texture("bip.png",3)){
        std::cout<<"failed to load map.png"<<std::endl;
        return EXIT_FAILURE;;
    }

    eng.animationInit();
    bool q=true;

    while(q){
        q=eng.event();
        //eng.renderOneColGL();
        eng.render();
        eng.swapBuffers();

    }
}
