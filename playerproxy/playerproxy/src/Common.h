#ifndef COMMON_H_
#define COMMON_H_
#include <string>
namespace MessageType
{
    const std::string PlayStr = "play";
    const std::string PauseStr = "pause";
    const std::string NextStr = "next";
    const std::string PrevStr = "prev";
    const std::string StopStr = "stop";
    
    enum MessageEnum
    {
        Play, Pause, Next, Prev, Stop
    };
    
    bool GetMessageString(MessageEnum message, std::string& output);
    bool GetMessageEnum(const std::string input, MessageEnum& outputEnum);
    
    bool isValid(std::string message);
}
#endif //COMMON_H_
