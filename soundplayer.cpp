#include "soundplayer.h"
#include <QDebug>
bool INITSOUND()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw -1;

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) == -1 )
        throw -2;
    return true;
}

MEngine::SoundPlayer::SoundPlayer(std::string name):
    nameMusic(name)
{
    music = Mix_LoadMUS(nameMusic.c_str());
    if (music == NULL)
        throw -3;
}

MEngine::SoundPlayer::SoundPlayer(std::string name, bool mode):
    nameMusic(name)
{
    music = Mix_LoadMUS(nameMusic.c_str());
    if (music == NULL)
        throw -3;
    if(mode)
    {
        this->play();
    }
}

MEngine::SoundPlayer::SoundPlayer():
    nameMusic("")
{
}

bool MEngine::SoundPlayer::setMusic(std::string name, bool mode)
{
    this->nameMusic = name;
    if(mode)
    {
        bool stat;
        stat = this->stop();

        music = Mix_LoadMUS(nameMusic.c_str());
        if (music == NULL)
            throw -3;

        stat = this->play();

        return stat;
    }
    return true;
}


bool MEngine::SoundPlayer::play()
{
    if ( Mix_PlayMusic( this->music, -1) == -1 )
        return false;
    else
    {
        //while(Mix_PlayingMusic())
          //  qDebug() << "music";
        Mix_PlayingMusic();
        return true;
    }
}

bool MEngine::SoundPlayer::stop()
{
    if( Mix_PausedMusic() == -1)
        return false;
    else
        return true;
}

MEngine::SoundPlayer::~SoundPlayer()
{
    Mix_FreeMusic(music);

    // quit SDL_mixer
    Mix_CloseAudio();
}
