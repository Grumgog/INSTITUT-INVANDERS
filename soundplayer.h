#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <string>

bool INITSOUND();

namespace MEngine
{
class SoundPlayer;

}
namespace MEngine
{
    class SoundPlayer
    {
    public:
        Mix_Music *music;
        std::string nameMusic;
    public:
        SoundPlayer(std::string name);
        SoundPlayer(std::string name, bool mode);
        SoundPlayer();

        bool setMusic(std::string name, bool mode);
        bool play();
        bool stop();


        virtual ~SoundPlayer();
    };

}

#endif // SOUNDPLAYER_H
