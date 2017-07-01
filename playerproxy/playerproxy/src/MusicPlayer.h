//
//  MusicPlayer.hpp
//  MusicPlayer
//
//  Created by Vidhya Karthikeyan on 6/25/17.
//  Copyright © 2017 Vidhya Karthikeyan. All rights reserved.
//

#ifndef MusicPlayer_hpp
#define MusicPlayer_hpp

#include <stdio.h>
#include <string>
#include <list>

enum MusicPlayerState
{
    Playing,
    Paused,
    Stopped
};

class IMusicPlayer
{
public:
    virtual bool AddToPlayList(std::string filePath) = 0;
    virtual bool RemoveFromPlayList(std::string filePath) = 0;
    virtual bool Pause() = 0;
    virtual bool Play() = 0;
    virtual bool Next() = 0;
    virtual bool Prev() = 0;
    virtual std::string GetCurrentSong() = 0;
    virtual ~IMusicPlayer(){}
};

class OSXMusicPlayer:public IMusicPlayer
{
public:
    static OSXMusicPlayer& Inst()
    {
        static OSXMusicPlayer musicPlayer;
        return musicPlayer;
    }
    virtual bool AddToPlayList(std::string filePath);
    virtual bool RemoveFromPlayList(std::string filePath);
    virtual bool Pause();
    virtual bool Play();
    virtual bool Next();
    virtual bool Prev();
    virtual std::string GetCurrentSong();
    
private:
    std::list<std::string> m_playList;
    unsigned int m_currentSongIndex;
    MusicPlayerState m_PlayerState;
    
    OSXMusicPlayer();
    ~OSXMusicPlayer();
    
};



#endif /* MusicPlayer_hpp */
