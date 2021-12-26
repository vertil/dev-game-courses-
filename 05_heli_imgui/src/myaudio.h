#pragma once
#include <string_view>
#include <SDL2/SDL.h>


class sound_buffer_wav{
    SDL_AudioSpec audio_spec;
    Uint32 lenght=0;    
    Uint8 *buffer;
public:
    sound_buffer_wav(uint32_t wav_lenght,
                SDL_AudioSpec wav_audio_spec){
        lenght=wav_lenght;
        audio_spec=wav_audio_spec;
        
    }
    bool loadwaw(std::string_view path){
        if(SDL_LoadWAV(path.data(),&audio_spec,&buffer,&lenght)==NULL){
            return false;
        }
        if(SDL_OpenAudio(&audio_spec,NULL)<0){
            return false;
        }
    }
    bool play(){
        SDL_PauseAudio(0);
    }
    
};
