#ifndef _TUTORIALSERVER_HPP_
#define _TUTORIALSERVER_HPP_

#include <sys/socket.h>
#include <netinet/in.h>

#include "SocketCommons.hpp"

class TutorialServer
{
private:
    SocketInfo clientSocketInfo;
    SocketInfo serverSocketInfo;

public:
    TutorialServer(/* args */);
    ~TutorialServer();
    int CreateSocket(const SocketInfo& serverSocketInfo);
    void RunService(int& iClientSocketHandler);
    int ListenForClientRequest(int& iServerSocketHandler);
    SocketInfo getClientSocketInfo();
    int CloseSocket(int& iSocketHandler);
    
private:
    int SetIPAddress(int& iSocketHandler, const sockaddr_in& socketAddr);

};


#endif