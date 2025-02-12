#include "logger.hpp"
#include "nn/util.h"
#include "nn/nifm.h"
#include "nn/socket.h"

SocketLogState socketLogState = SOCKET_LOG_UNINITIALIZED;
s32 socket;

bool tryInitSocket()
{
    in_addr hostAddress = {0};
    sockaddr serverAddress = {0};

    if (socketLogState != SOCKET_LOG_UNINITIALIZED)
        return false;

    nn::nifm::Initialize();
    nn::nifm::SubmitNetworkRequest();

    while (nn::nifm::IsNetworkRequestOnHold())
    {
    }

    if (!nn::nifm::IsNetworkAvailable())
    {
        socketLogState = SOCKET_LOG_UNAVAILABLE;
        return false;
    }

    if ((socket = nn::socket::Socket(2, 1, 0)) < 0)
    {
        socketLogState = SOCKET_LOG_UNAVAILABLE;
        return false;
    }

    nn::socket::InetAton(LOGGER_IP, &hostAddress);

    serverAddress.address = hostAddress;
    serverAddress.port = nn::socket::InetHtons(LOGGER_PORT);
    serverAddress.family = 2;

    if (nn::socket::Connect(socket, &serverAddress, sizeof(serverAddress)) != 0)
    {
        socketLogState = SOCKET_LOG_UNAVAILABLE;
        return false;
    }

    socketLogState = SOCKET_LOG_CONNECTED;
    return true;
}

u64 strlen(const char *str)
{
    u64 len = 0;
    while (str[len++])
        ;
    return len;
}
namespace exl::logger
{
    void send(const char *data)
    {
        if (socketLogState != SOCKET_LOG_CONNECTED && !tryInitSocket())
            return;

        if (nn::socket::Send(socket, data, strlen(data), 0) < 0)
        {
            if (tryInitSocket())
                nn::socket::Send(socket, data, strlen(data), 0);
        }
    }

    void log(const char *fmt, ...)
    {
        va_list args;
        va_start(args, fmt);

        char buf[0x500];

        if (nn::util::VSNPrintf(buf, sizeof(buf), fmt, args) > 0)
        {
            send(buf);
        }

        va_end(args);
    }

    void log(const char *fmt, va_list args)
    {
        char buf[0x500];
        if (nn::util::VSNPrintf(buf, sizeof(buf), fmt, args) > 0)
        {
            send(buf);
        }
    }
};