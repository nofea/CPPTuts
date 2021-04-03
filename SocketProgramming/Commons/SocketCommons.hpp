#ifndef _SOCKET_COMMONS_HPP_
#define _SOCKET_COMMONS_HPP_

#include <string>
#include "errno.h"

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080 

namespace SocketCommons
{
    enum DomainType
    {
        DomainType_NONE,
        IPV4,
        IPV6,
        DomainType_MAX
    };

    enum ConnectionType
    {
        ConnectionType_NONE,
        UDP,
        TCP,
        ConnectionType_MAX
    };

    struct SocketInfo
    {
        DomainType domainType;
        ConnectionType connectionType;
        std::string sIPAddress;
        int iPort;
    };
}

#endif
