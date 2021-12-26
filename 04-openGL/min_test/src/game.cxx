#include "engine.hxx"

int main(int, char **){
    engine eng;
    const std::string error =eng.initProgramOne();
    if (!error.empty())
    {
        std::cerr << error << std::endl;
        return EXIT_FAILURE;
    }

    bool q=true;

    while(q){
        //q=eng.event();
        eng.renderOneColGL();
        eng.renderTriangle();
        eng.swapBuffers();

    }
}
