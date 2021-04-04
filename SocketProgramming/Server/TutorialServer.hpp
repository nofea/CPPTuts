#ifndef _TUTORIALSERVER_HPP_
#define _TUTORIALSERVER_HPP_

#include <sys/socket.h>
#include <netinet/in.h>

#include "SocketCommons.hpp"

class TutorialServer
{
private:
    SocketCommons::SocketInfo clientSocketInfo;
    SocketCommons::SocketInfo serverSocketInfo;

public:
    TutorialServer(/* args */);
    ~TutorialServer();
    int CreateSocket(const SocketCommons::SocketInfo& serverSocketInfo);
    void RunService(int& iClientSocketHandler);
    int ListenForClientRequest(int& iServerSocketHandler);
    SocketCommons::SocketInfo getClientSocketInfo();
    int CloseSocket(int& iSocketHandler);
    
private:
    int SetIPAddress(int& iSocketHandler, const sockaddr_in& socketAddr);

};

#endif
