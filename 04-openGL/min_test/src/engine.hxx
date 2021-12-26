#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <array>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <stdexcept>
#include <SDL2/SDL.h>

#include "glad/glad.h"


#define OM_GL_CHECK()                                                      \
{                                                                          \
    const int err = static_cast<int>(glGetError());                        \
    if (err != GL_NO_ERROR)                                                \
    {                                                                      \
        switch (err)                                                       \
        {                                                                  \
            case GL_INVALID_ENUM:                                          \
                std::cerr << "GL_INVALID_ENUM" << std::endl;               \
                break;                                                     \
            case GL_INVALID_VALUE:                                         \
                std::cerr << "GL_INVALID_VALUE" << std::endl;              \
                break;                                                     \
            case GL_INVALID_OPERATION:                                     \
                std::cerr << "GL_INVALID_OPERATION" << std::endl;          \
                break;                                                     \
            case GL_INVALID_FRAMEBUFFER_OPERATION:                         \
                std::cerr << "GL_INVALID_FRAMEBUFFER_OPERATION"            \
                          << std::endl;                                    \
                break;                                                     \
            case GL_OUT_OF_MEMORY:                                         \
                std::cerr << "GL_OUT_OF_MEMORY" << std::endl;              \
                break;                                                     \
        }                                                                  \
        assert(false);                                                     \
    }                                                                      \
}

static void APIENTRY callback_opengl_debug(
    GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
    const GLchar* message, [[maybe_unused]] const void* userParam);

#pragma pack(push, 1)
struct col{
    uint8_t r=0;
    uint8_t g=0;
    uint8_t b=0;
    friend bool operator==(const col& l,const col& r){
        if(l.r==r.r && l.g==r.g && l.b==r.b){
            return true;
        }else{
            return false;
        }
    };
};
#pragma pack(pop)

struct point{

    col color;
    uint32_t x=0;//Xis
    uint32_t y=0;//Yis
    uint32_t q=0;
    uint32_t w=0;//changed X
    uint32_t e=0;//changed Y


};

struct  vertex{
    float x=0.f;
    float y=0.f;
    float z=0.f;

};

struct  triangle
{
    triangle()
    {
        v[0] = vertex();
        v[1] = vertex();
        v[2] = vertex();
    }
    vertex v[3];
};
class engine{
    GLuint        program_id_ = 0;
    size_t tex_width  = 320;
    size_t tex_height = 240;
    size_t tex_buff_size = tex_width*tex_height;

    triangle t;


    //std::array<col, buff_size> pixs;
    std::vector<col> texture;
    std::vector<col> buff;
    std::vector<point> triangles_points;
    std::vector<uint32_t> indexs;
    std::vector<point> points;

    uint16_t mouse_posX;
    uint16_t mouse_posY;

    std::vector<vertex>  buffofTriangle;

    SDL_Window *window;
    SDL_Event event_log;
    SDL_Renderer *rend;

    char type_func='S';

    float mouse_Wheel=0;
public:
    engine(){

        std::stringstream serr;
        using namespace std;


        const int init_result = SDL_Init(SDL_INIT_EVERYTHING);
        if (init_result != 0)
        {
            const char* err_message = SDL_GetError();
             serr << "error: failed call SDL_Init: " << err_message << std::endl;
            //return serr.str();
        }

        /*if (0 != SDL_Init(SDL_INIT_EVERYTHING))
        {
            std::cerr << SDL_GetError() << std::endl;
            //return EXIT_FAILURE;
        }*/
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);

        window=SDL_CreateWindow("Loop",
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  320,
                                  240,
                                  SDL_WINDOW_OPENGL
                                  );

           if(window==NULL){
           std::cout<<"Couldn't create window"<<SDL_GetError()<<std::endl;
               SDL_DestroyWindow(window);
           }

           rend=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

           int gl_major_ver       = 3;
           int gl_minor_ver       = 2;
           int gl_context_profile = SDL_GL_CONTEXT_PROFILE_ES;

           const char* platform_from_sdl = SDL_GetPlatform();
           std::string_view platform{platform_from_sdl};
           using namespace std::string_view_literals;
           using namespace std;
           auto list = { "Windows"sv, "Mac OS X"sv };
           auto it   = find(begin(list), end(list), platform);
           if (it != end(list))
           {
               gl_major_ver       = 4;
               gl_minor_ver       = (platform == "Mac OS X") ? 1 : 3;
               gl_context_profile = SDL_GL_CONTEXT_PROFILE_ES;
           }

           SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, gl_context_profile);
           SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, gl_major_ver);
           SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, gl_minor_ver);

           SDL_GLContext gl_context = SDL_GL_CreateContext(window);
           if (gl_context == nullptr)
           {
               gl_major_ver       = 3;
               gl_minor_ver       = 2;
               gl_context_profile = SDL_GL_CONTEXT_PROFILE_ES;

               SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, gl_context_profile);
               SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, gl_major_ver);
               SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, gl_minor_ver);
               gl_context = SDL_GL_CreateContext(window);
           }
           assert(gl_context != nullptr);

           int result =
               SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &gl_major_ver);
           assert(result == 0);
           result =
               SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &gl_minor_ver);
           assert(result == 0);

           if (gl_major_ver < 3)
           {
               std::clog << "current context opengl version: " << gl_major_ver
                         << '.' << gl_minor_ver << '\n'
                         << "need openg ES version at least: 3.2\n"
                         << std::flush;
               throw std::runtime_error("opengl version too low");
           }

           std::clog << "OpenGl "<< gl_major_ver << '.'<< gl_minor_ver<<'\n';

           if (gladLoadGLES2Loader(SDL_GL_GetProcAddress) == 0)
           {
               std::clog << "error: failed to initialize glad" << std::endl;
           }

           if (platform != "Mac OS X") // not supported on Mac
           {
               glEnable(GL_DEBUG_OUTPUT);
               glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
               glDebugMessageCallback(callback_opengl_debug, nullptr);
               glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0,
                                 nullptr, GL_TRUE);
           }
    }
    ~engine(){
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(window);
    }
    void load_texture(const std::string& f_name){
        std::ifstream in_file;
        in_file.exceptions(std::ios_base::failbit);
        in_file.open(f_name, std::ios_base::binary);
        std::string header;
        std::string color_format;
        char        last_next_line = 0;
        in_file >> header
                >> tex_width
                >> tex_height
                >> color_format;
        in_file.read(&last_next_line, 1);
        std::cout<<"tex_width-"<<std::to_string(tex_width)
                <<":tex_height-"<<std::to_string(tex_height)
               <<std::endl;
        if (!iswspace(last_next_line))
        {
            throw std::runtime_error("expected witespace");
        }
        texture.resize(tex_width*tex_height);
        if (texture.size() != tex_width * tex_height)
        {
            throw std::runtime_error("image size not match");
        }

        std::streamsize buf_size =
            static_cast<std::streamsize>(sizeof(col) * texture.size());
        in_file.read(reinterpret_cast<char*>(texture.data()), buf_size);
        //buff.assign(texture.begin(),texture.end());
        buff.resize(tex_width*tex_height);
        //std::cout<<"buff_size-"<<std::to_string(buff[0].))<<std::endl;
        triangles_points.push_back(getPoint(1,0));
        triangles_points.push_back(getPoint(tex_width,0));
        triangles_points.push_back(getPoint(tex_width,tex_height));
        triangles_points.push_back(getPoint(0,tex_height));

        indexs.push_back(0);
        indexs.push_back(1);
        indexs.push_back(2);
        indexs.push_back(0);
        indexs.push_back(2);
        indexs.push_back(3);

        for(int i=0;i<indexs.size();i+=3){
            readTriangle(triangles_points[indexs[i]],
                    triangles_points[indexs[i+1]],
                    triangles_points[indexs[i+2]]
                    );


        }

    }
    bool event(){
        while(SDL_PollEvent(&event_log)){
            if(event_log.type==SDL_QUIT){
                return false;
            }else if(event_log.type==SDL_KEYDOWN) {
               if(event_log.key.keysym.scancode==SDL_SCANCODE_1){
                   if(type_func=='S'){
                       type_func='D';
                   }else{
                       type_func='S';
                   }

                   return true;
               }else if(event_log.key.keysym.scancode==SDL_SCANCODE_2){
                   if(type_func=='G'){
                       type_func='D';
                   }else{
                       type_func='G';
                   }
                   return true;
               }else if(event_log.key.keysym.scancode==SDL_SCANCODE_3){
                   if(type_func=='R'){
                       type_func='D';
                   }else{
                       type_func='R';
                   }
                   return true;
               }
                //return true;
              }else if(event_log.type==SDL_MOUSEWHEEL){
                if(event_log.wheel.y>0){
                    mouse_Wheel+=0.05f;
                }
                if(event_log.wheel.y<0){
                    mouse_Wheel-=0.05f;
                }
                return true;
              }else  if(event_log.type==SDL_MOUSEMOTION) {
                mouse_posX = event_log.motion.x;
                mouse_posY = event_log.motion.y;
                return true;
             }

         }
         return true;
    }
    bool render(){


        SDL_Surface* bitSurface;
        SDL_Texture* bitTexture;

        void*     pixels = buff.data();
        const int depth  = sizeof(col) * 8;
        const int pitch  = tex_width * sizeof(col);
        const int rmask  = 0x000000ff;
        const int gmask  = 0x0000ff00;
        const int bmask  = 0x00ff0000;
        const int amask  = 0;

        bitSurface=SDL_CreateRGBSurfaceFrom(pixels,tex_width,tex_height,depth,pitch,rmask,gmask,bmask,amask);
        if(bitSurface==nullptr){
            std::cerr << SDL_GetError() << std::endl;
            return false;
        }
        bitTexture=SDL_CreateTextureFromSurface(rend,bitSurface);
        if(bitTexture==nullptr){
            std::cerr << SDL_GetError() << std::endl;
            return false;
        }

        SDL_FreeSurface(bitSurface);
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend,bitTexture, nullptr,nullptr);
        SDL_RenderPresent(rend);
        SDL_DestroyTexture(bitTexture);
    }
    col& getPixelColor(uint32_t x, uint32_t y){
        if(x>tex_width || y>tex_height){
            //std::cout<<"wrong coordinates"<<std::endl;
        }else{
            uint32_t pos=0;
            if(y==0){
                pos=x;
            }else{
                pos=(tex_width*(y-1)+x)-1;
            }

            return texture[pos];
        }
    }
    point getPoint(uint32_t x, uint32_t y){
        point buff_p;
        buff_p.color=getPixelColor(x,y);
        buff_p.x=x;
        buff_p.y=y;
        return buff_p;
    }
    void getLine(std::vector<point>& pois, const point& p1,
                 const point& p2){
        int32_t x1=p1.x;
        int32_t y1=p1.y;
        int32_t x2=p2.x;
        int32_t y2=p2.y;
        point buff;
        const int dX=abs(x2-x1);
        const int dY=abs(y2-y1);
        const int signX=x1<x2?1:(-1);
        const int signY=y1<y2?1:(-1);
        uint32_t error=dX-dY;

        while(x1!=x2 || y1!=y2){
            buff.x=x1;
            buff.y=y1;
            buff.color=getPixelColor(x1,y1);
            pois.push_back(buff);
            int error2=error*2;
            if(error2>(-dY)){
                error-=dY;
                x1+=signX;
            }
            if(error2<dX){
                error+=dX;
                y1+=signY;
            }
        }
        pois.push_back(p2);

    }
    void setPixelColor(col& color,uint32_t x, uint32_t y){
        if(x>tex_width || y>tex_height){
            //std::cout<<"wrong coordinates"<<std::endl;
        }else{
            uint32_t pos=0;
            if(y==0){
                pos=x;
            }else{
                pos=(tex_width*(y-1)+x)-1;
            }

            buff[pos]=color;            
        }

    }
    void draw(){
        if(type_func=='S' || type_func=='R'){
            for(int j=0;j<buff.size();j++){
                buff[j]={0,0,0};
            }
        }
        if(type_func=='S'){
            for(auto i:points){
                setPixelColor(i.color,round(i.x*0.5),round(i.y*0.5));
            }
        }else if(type_func=='G'){
            for(auto i:points){
                col buff_c=greyScale(i.color);
                setPixelColor(buff_c,i.x,i.y);
            }
        }else if(type_func=='R'){
            /*for(auto i:points){
                setPixelColor()
            }*/
               rotateText(points);
        }else{
            for(auto i:points){
                setPixelColor(i.color,i.x,i.y);
            }

        }



    }
    void  readTriangle(const point& p1,
                       const point& p2,
                       const point& p3
                       ){
        //std::vector<point> bif;
        //bif.resize(tex_height*tex_width);
        std::vector<point> l1;
        getLine(l1,p1,p2);
        std::vector<point> l2;
        getLine(l2,p2,p3);
        std::vector<point> l3;
        getLine(l3,p3,p1);
        //std::vector<point> points;//all points of triangle

        getTrianglepoints(l1,l2,l3, points);



    }
    void getTrianglepoints(const std::vector<point>& l1,
                           const std::vector<point>& l2,
                           const std::vector<point>& l3,
                           std::vector<point>& points
                           ){
        if(l1[0].y == l1[l1.size()-1].y){
            //std::cout<<"l1"<<std::endl;

            int i=0;//l2 pointer
            int j=l3.size()-1;//l3 pointer from end to start
            for(;i<l2.size();i++,j--){
                getLine(points,l2[i],l3[j]);
               //check same points at OY at l2
                    for(bool q=false;q==false;){
                        if(i+1<=(l2.size()-1) && l2[i].y==l2[i+1].y){
                            i++;
                        }else{
                            q=true;
                        }
                    }
                    //check same points at OY at l3
                    for(bool q=false;q==false;){
                        if(j-1>=1 && l3[j].y==l3[j-1].y){
                            j--;
                        }else{
                            q=true;
                        }
                    }
            }
        }else if(l2[0].y == l2[l1.size()-1].y){
            //std::cout<<"l2"<<std::endl;
            int i=0;//l3 pointer
            int j=l1.size()-1;//l1 pointer from end to start
            for(;i<l3.size();i++,j--){
                getLine(points,l3[i],l1[j]);
                //check same points at OY at l2
                for(bool q=false;q==false;){
                    if(i+1<l3.size()-1 && l3[i].y==l3[i+1].y){
                        i++;
                    }else{
                        q=true;
                    }
                }
                //check same points at OY at l3
                for(bool q=false;q==false;){
                    if(j-1>1 && l1[j].y==l1[j-1].y){
                        j--;
                    }else{
                        q=true;
                    }
                }

            }

        }else if(l3[0].y == l3[l1.size()-1].y){
            //std::cout<<"l3"<<std::endl;
            int i=0;//l1 pointer
            int j=l2.size()-1;//l2 pointer from end to start
            for(;i<l1.size();i++,j--){
                getLine(points,l1[i],l2[j]);
                //check same points at OY at l2
                for(bool q=false;q==false;){
                    if(i+1<l1.size()-1 && l1[i].y==l1[i+1].y){
                        i++;
                    }else{
                        q=true;
                    }
                }
                //check same points at OY at l3
                for(bool q=false;q==false;){
                    if(j-1>1 && l2[j].y==l2[j-1].y){
                        j--;
                    }else{
                        q=true;
                    }
                }

            }
        }

    }

    col greyScale(const col& in){
        uint8_t mono = static_cast<uint8_t>(
            0.2125 * in.r + 0.7152 * in.g + 0.0721 * in.b);
        return {mono,mono,mono};
    }
    void rotateText(std::vector<point>& poss){
        for(auto i:poss){

            double poko_x=i.x;
            double poko_y=i.y;

            poko_x-=tex_width/2;
            poko_y-=tex_height/2;

            poko_x*=0.5;
            poko_y*=0.5;

            double alpha = (M_PI / 4) * mouse_Wheel;
            double x     = poko_x;
            double y     = poko_y;
            double x0    = tex_width/2;
            double y0    = tex_height/2;
            poko_x=x*std::cos(alpha)-y*std::sin(alpha);
            poko_y=y*std::cos(alpha)+x*std::sin(alpha);
            //poko_x=x0+(poko_x-x0)*std::cos(alpha)-(poko_y-y0)*sin(alpha);
            //poko_y=y0+(poko_y-y0)*std::cos(alpha)+(poko_x-x0)*sin(alpha);

            poko_x+=tex_width/2;
            poko_y+=tex_height/2;




            setPixelColor(i.color,poko_x,poko_y);
        }
    }
    void swapBuffers(){
        SDL_GL_SwapWindow(window);

    }
    void renderOneColGL(){
        glClearColor(0.357,0.950,0.665,0.0f);
        OM_GL_CHECK()
        glClear(GL_COLOR_BUFFER_BIT);
        OM_GL_CHECK()

    }
    std::string initProgramOne(){
    std::stringstream serr;
    //vertex
    GLuint vert_shader = glCreateShader(GL_VERTEX_SHADER);
    OM_GL_CHECK()
    std::string_view vertex_shader_src = R"(
                                        #version 300 es
                                        in vec3 a_position;
                                        out vec4 v_position;

                                        void main()
                                        {
                                            v_position = vec4(a_position, 1.0);
                                            gl_Position = v_position;
                                        }
                                    )";
    const char* source            = vertex_shader_src.data();
    glShaderSource(vert_shader, 1, &source, nullptr);
    OM_GL_CHECK()

    glCompileShader(vert_shader);
    OM_GL_CHECK()

    GLint compiled_status = 0;
    glGetShaderiv(vert_shader, GL_COMPILE_STATUS, &compiled_status);
    OM_GL_CHECK()
    if (compiled_status == 0)
    {        
        GLint info_len = 0;
        glGetShaderiv(vert_shader, GL_INFO_LOG_LENGTH, &info_len);
        OM_GL_CHECK()
        std::vector<char> info_chars(static_cast<size_t>(info_len));
        glGetShaderInfoLog(vert_shader, info_len, nullptr, info_chars.data());
        OM_GL_CHECK()
        glDeleteShader(vert_shader);
        OM_GL_CHECK()

        std::string shader_type_name = "vertex";
        serr << "Error compiling shader(vertex)\n"
             << vertex_shader_src << "\n"
             << info_chars.data();
        return serr.str();
    }
    //fragment
    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    OM_GL_CHECK()
    std::string_view fragment_shader_src = R"(
                      #version 300 es
                      precision mediump float;

                      in vec4 v_position;

                      out vec4 frag_color;

                      void main()
                      {
                         if(v_position.x<0.0){
                             float red_c=(1.0-(v_position.x*(-1.0)))/2.0;
                             frag_color=vec4(red_c,0.0,0.0,1.0);
                         }else{
                             float red_c=0.5+v_position.x/2.0;
                             frag_color=vec4(red_c,0.0,0.0,1.0);
                         }
                      }
                      )";
    /**/
    source                          = fragment_shader_src.data();
    glShaderSource(fragment_shader, 1, &source, nullptr);
    OM_GL_CHECK()

    glCompileShader(fragment_shader);
    OM_GL_CHECK()

    compiled_status = 0;
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &compiled_status);
    OM_GL_CHECK()
    if (compiled_status == 0)
    {
        GLint info_len = 0;
        glGetShaderiv(fragment_shader, GL_INFO_LOG_LENGTH, &info_len);
        OM_GL_CHECK()
        std::vector<char> info_chars(static_cast<size_t>(info_len));
        glGetShaderInfoLog(
            fragment_shader, info_len, nullptr, info_chars.data());
        OM_GL_CHECK()
        glDeleteShader(fragment_shader);
        OM_GL_CHECK()

        serr << "Error compiling shader(fragment)\n"
             << vertex_shader_src << "\n"
             << info_chars.data();
        return serr.str();
    }
    //union shaderis in one program

    program_id_ = glCreateProgram();
    OM_GL_CHECK()
    if (0 == program_id_)
    {
        serr << "failed to create gl program";
        return serr.str();
    }

    glAttachShader(program_id_, vert_shader);
    OM_GL_CHECK()
    glAttachShader(program_id_, fragment_shader);
    OM_GL_CHECK()

    // bind attribute location
    glBindAttribLocation(program_id_, 0, "a_position");
    OM_GL_CHECK()
    // link program after binding attribute locations
    glLinkProgram(program_id_);
    OM_GL_CHECK()
    // Check the link status
    GLint linked_status = 0;
    glGetProgramiv(program_id_, GL_LINK_STATUS, &linked_status);
    OM_GL_CHECK()
    if (linked_status == 0)
    {
        GLint infoLen = 0;
        glGetProgramiv(program_id_, GL_INFO_LOG_LENGTH, &infoLen);
        OM_GL_CHECK()
        std::vector<char> infoLog(static_cast<size_t>(infoLen));
        glGetProgramInfoLog(program_id_, infoLen, nullptr, infoLog.data());
        OM_GL_CHECK()
        serr << "Error linking program:\n" << infoLog.data();
        glDeleteProgram(program_id_);
        OM_GL_CHECK()
        return serr.str();
    }

    // turn on rendering with just created shader program
    glUseProgram(program_id_);
    OM_GL_CHECK()

    //glEnable(GL_DEPTH_TEST);
    //glDisable(GL_DEPTH_TEST);

    return "";

}
    void renderTriangle(){
        getTriagMouse();




              glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), &t.v[0]);
              OM_GL_CHECK()
              glEnableVertexAttribArray(0);
              OM_GL_CHECK()
              glValidateProgram(program_id_);
              OM_GL_CHECK()
              // Check the validate status
              GLint validate_status = 0;
              glGetProgramiv(program_id_, GL_VALIDATE_STATUS, &validate_status);
              OM_GL_CHECK()
              if (validate_status == GL_FALSE)
              {
                  GLint infoLen = 0;
                  glGetProgramiv(program_id_, GL_INFO_LOG_LENGTH, &infoLen);
                  OM_GL_CHECK()
                  std::vector<char> infoLog(static_cast<size_t>(infoLen));
                  glGetProgramInfoLog(program_id_, infoLen, nullptr, infoLog.data());
                  OM_GL_CHECK()
                  std::cerr << "Error linking program:\n" << infoLog.data();
                  throw std::runtime_error("error");
              }
              glDrawArrays(GL_TRIANGLES, 0, 3);
              OM_GL_CHECK()



    }
    void getTriagMouse(){
        float x=-1.0f+((2.0f/320.0f)*mouse_posX);
        float y=1.0f-((2.0f/240.0f)*mouse_posY);

        //triangle t;
        t.v[0].x=x;
        t.v[0].y=y;
        t.v[0].z=mouse_Wheel;

        t.v[1].x=x-0.15f;
        t.v[1].y=y-0.15f;
        t.v[1].z=mouse_Wheel;

        t.v[2].x=0.0f;
        t.v[2].y=0.0f;
        t.v[2].z=0.0f;
    }
};
//tests for gl functions
static const char* source_to_strv(GLenum source)
{
    switch (source)
    {
        case GL_DEBUG_SOURCE_API:
            return "API";
        case GL_DEBUG_SOURCE_SHADER_COMPILER:
            return "SHADER_COMPILER";
        case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
            return "WINDOW_SYSTEM";
        case GL_DEBUG_SOURCE_THIRD_PARTY:
            return "THIRD_PARTY";
        case GL_DEBUG_SOURCE_APPLICATION:
            return "APPLICATION";
        case GL_DEBUG_SOURCE_OTHER:
            return "OTHER";
    }
    return "unknown";
}

static const char* type_to_strv(GLenum type)
{
    switch (type)
    {
        case GL_DEBUG_TYPE_ERROR:
            return "ERROR";
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
            return "DEPRECATED_BEHAVIOR";
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
            return "UNDEFINED_BEHAVIOR";
        case GL_DEBUG_TYPE_PERFORMANCE:
            return "PERFORMANCE";
        case GL_DEBUG_TYPE_PORTABILITY:
            return "PORTABILITY";
        case GL_DEBUG_TYPE_MARKER:
            return "MARKER";
        case GL_DEBUG_TYPE_PUSH_GROUP:
            return "PUSH_GROUP";
        case GL_DEBUG_TYPE_POP_GROUP:
            return "POP_GROUP";
        case GL_DEBUG_TYPE_OTHER:
            return "OTHER";
    }
    return "unknown";
}
static const char* severity_to_strv(GLenum severity)
{
    switch (severity)
    {
        case GL_DEBUG_SEVERITY_HIGH:
            return "HIGH";
        case GL_DEBUG_SEVERITY_MEDIUM:
            return "MEDIUM";
        case GL_DEBUG_SEVERITY_LOW:
            return "LOW";
        case GL_DEBUG_SEVERITY_NOTIFICATION:
            return "NOTIFICATION";
    }
    return "unknown";
}

static std::array<char, GL_MAX_DEBUG_MESSAGE_LENGTH> local_log_buff;

static void APIENTRY callback_opengl_debug(
    GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
    const GLchar* message, [[maybe_unused]] const void* userParam)
{
    // The memory formessageis owned and managed by the GL, and should onlybe
    // considered valid for the duration of the function call.The behavior of
    // calling any GL or window system function from within thecallback function
    // is undefined and may lead to program termination.Care must also be taken
    // in securing debug callbacks for use with asynchronousdebug output by
    // multi-threaded GL implementations.  Section 18.8 describes thisin further
    // detail.

    auto& buff{ local_log_buff };
    int   num_chars = std::snprintf(
        buff.data(), buff.size(), "%s %s %d %s %.*s\n", source_to_strv(source),
        type_to_strv(type), id, severity_to_strv(severity), length, message);

    if (num_chars > 0)
    {
        // TODO use https://en.cppreference.com/w/cpp/io/basic_osyncstream
        // to fix possible data races
        // now we use GL_DEBUG_OUTPUT_SYNCHRONOUS to garantie call in main
        // thread
        std::cerr.write(buff.data(), num_chars);
    }
}
