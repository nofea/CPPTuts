#include <iostream>
#include <arpa/inet.h>

#include "TutorialServer.hpp"

using namespace std;
using namespace SocketCommons;

TutorialServer::TutorialServer(/* args */)
{
    clientSocketInfo.connectionType = ConnectionType_NONE;
    clientSocketInfo.domainType = DomainType_NONE;
    clientSocketInfo.iPort = 0;
    clientSocketInfo.sIPAddress.clear();

    serverSocketInfo.connectionType = ConnectionType_NONE;
    serverSocketInfo.domainType = DomainType_NONE;
    serverSocketInfo.iPort = 0;
    serverSocketInfo.sIPAddress.clear();
}

TutorialServer::~TutorialServer()
{
}

int TutorialServer::CreateSocket(const SocketInfo& socketInfo)
{
    sockaddr_in socketAddr = {};
    int iSocketHandler = 0;
    int iDomainType = 0;
    int iConnectionType = 0;
    serverSocketInfo = socketInfo;

    switch (serverSocketInfo.domainType)
    {
    case IPV4:
        iDomainType =  AF_INET;
        break;

    case IPV6:
        iDomainType = AF_INET6;
        break;
    
    default:
        cout << "Oops! wrong domain type!" << endl;
        break;
    }

    switch (serverSocketInfo.connectionType)
    {
    case UDP:
        iConnectionType = SOCK_DGRAM;
        break;

    case TCP:
        iConnectionType = SOCK_STREAM;
        break;
    
    default:
        break;
    }

    iSocketHandler = socket(iDomainType, iConnectionType, 0);
    socketAddr.sin_family = iDomainType;
    socketAddr.sin_addr.s_addr = inet_addr(serverSocketInfo.sIPAddress.c_str());
    socketAddr.sin_port = htons(serverSocketInfo.iPort);

    if(SetIPAddress(iSocketHandler, socketAddr) < 0)
    {
        cout << "Unable to bind!" << endl;
        iSocketHandler = -1;
    }

    return iSocketHandler;
}

int TutorialServer::SetIPAddress(int& iSocketHandler, const sockaddr_in& socketAddr)
{
    return(bind(iSocketHandler, reinterpret_cast<const sockaddr *>(&socketAddr), sizeof(socketAddr)));
}

int TutorialServer::ListenForClientRequest(int& iServerSocketHandler)
{
    sockaddr_in clientSocketAddr = {};
    socklen_t clientAddrLength = sizeof(clientSocketAddr);
    int iClientSocketHandler = 0;
    if(listen(iServerSocketHandler, SOMAXCONN) < 0)
    {
        cout << "Error while listening to socket " << iServerSocketHandler << endl;
    }

    iClientSocketHandler = accept(iServerSocketHandler, reinterpret_cast<sockaddr*>(&clientSocketAddr), &clientAddrLength);

    switch (clientSocketAddr.sin_family)
    {
    case AF_INET:
        clientSocketInfo.domainType = IPV4;
        break;

    case AF_INET6:
        clientSocketInfo.domainType = IPV6;
        break;
    
    default:
        break;
    }
 
    clientSocketInfo.connectionType = serverSocketInfo.connectionType;

    inet_ntop(clientSocketAddr.sin_family, &clientSocketAddr.sin_addr, &clientSocketInfo.sIPAddress.at(0), sizeof(clientSocketAddr.sin_addr));

    clientSocketInfo.iPort = ntohs(clientSocketAddr.sin_port);

    return iClientSocketHandler;
}


SocketInfo TutorialServer::getClientSocketInfo()
{
    return clientSocketInfo;
}

void TutorialServer::RunService(int& iClientSocket)
{
    string sData("");
    int iBytesReceived = 0, iBytesSent = 0;

    for(;;)
    {
        iBytesReceived = recv(iClientSocket, reinterpret_cast<void*>(&sData), sizeof(string), 0);

        if(iBytesReceived == 0)
        {
            cout << "Connection with client lost!" << endl;
            break;
        }
        else if(iBytesReceived > 0)
        {
            iBytesSent = send(iClientSocket, sData.c_str(), iBytesReceived + 1, 0);
        }
    }
}

int TutorialServer::CloseSocket(int& iSocketHandler)
{
    return(shutdown(iSocketHandler, SHUT_RDWR));
}