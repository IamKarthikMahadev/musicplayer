// This file generated by ngrestcg
// For more information, please visit: https://github.com/loentar/ngrest

#ifndef PLAYERPROXY_H
#define PLAYERPROXY_H
#include <string>
#include <ngrest/common/Service.h>


class playerProxy: public ngrest::Service
{
public:
    playerProxy();
    std::string Play();
    std::string Pause();
    std::string Next();
    std::string Prev();

};


#endif // PLAYERPROXY_H



