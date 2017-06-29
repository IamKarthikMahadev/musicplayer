//
//  MusicPlayer.cpp
//  MusicPlayer
//
//  Created by Vidhya Karthikeyan on 6/25/17.
//  Copyright © 2017 Vidhya Karthikeyan. All rights reserved.
//

#include "MusicPlayer.h"

bool OSXMusicPlayer::AddToPlayList(std::string filePath)
{
    //Check if the file path is valid
    if(filePath.size()<1)
    {
        return false;
    }
    return true;
}

bool OSXMusicPlayer::RemoveFromPlayList(std::string filePath)
{
    if(filePath.size()<1)
    {
        return false;
    }
    return true;
}
bool OSXMusicPlayer::Pause()
{
    
    return true;
}
 bool OSXMusicPlayer::Play()
{
    return true;
}
bool OSXMusicPlayer::Next()
{
    return true;
}
bool OSXMusicPlayer::Prev()
{
    return true;
}

std::string OSXMusicPlayer::GetCurrentSong()
{
    return "No Song";
}
OSXMusicPlayer::OSXMusicPlayer():m_currentSongIndex(0),m_PlayerState(Stopped)
{
    
}
OSXMusicPlayer::~OSXMusicPlayer()
{
   
}


