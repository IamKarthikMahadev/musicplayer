#include "Common.h"
namespace MessageType
{
    bool GetMessageString(MessageEnum message, std::string& output)
    {
        switch (message) {
            case Play:
                output=PlayStr;
                return true;
            case Pause:
                output= PauseStr;
                return true;
            case Next:
                output= NextStr;
                return true;
            case Prev:
                output= PrevStr;
                return true;
            case Stop:
                output= StopStr;
                return true;
                
            default:
                return false;
        }
    }
    bool GetMessageEnum(const std::string input, MessageEnum& outputEnum)
    {
        if(input == PlayStr)
        {
            outputEnum = Play;
            return true;
        }
        if(input == PauseStr)
        {
            outputEnum = Pause;
            return true;
        }
        if(input == PrevStr)
        {
            outputEnum = Prev;
            return true;
        }
        if(input == NextStr)
        {
            outputEnum = Next;
            return true;
        }
        if(input == StopStr)
        {
            outputEnum = Stop;
            return true;
        }
        
        return false;
        
    }
    
    bool isValid(std::string message)
    {
        MessageEnum messageEnum;
        return GetMessageEnum(message, messageEnum);
        
    }

}
