#include <iostream>

#include "SocketCommons.hpp"
#include "TutorialServer.hpp"

using namespace std;
using namespace SocketCommons;

int main()
{
    TutorialServer Server;

    SocketInfo serverSocketInfo = {};
    SocketInfo clientSocketInfo = {};

    serverSocketInfo.connectionType = TCP;
    serverSocketInfo.domainType = IPV4;
    serverSocketInfo.sIPAddress = SERVER_IP;
    serverSocketInfo.iPort = SERVER_PORT;

    int iServerSocket = Server.CreateSocket(serverSocketInfo);
    int iClientSocket = Server.ListenForClientRequest(iServerSocket);

    clientSocketInfo = Server.getClientSocketInfo();

    cout << "Client Socket Address:" << clientSocketInfo.sIPAddress << endl;
    cout << "Client Socket Port:" << clientSocketInfo.iPort << endl;

    Server.RunService(iClientSocket);

    if(Server.CloseSocket(iServerSocket) != 0)
    {
        cout << "Unable to close server socket: " << errno << endl;
    }

    if(Server.CloseSocket(iClientSocket) != 0)
    {
        cout << "Unable to close client socket: " << errno << endl;
    }

    return 0;
}
