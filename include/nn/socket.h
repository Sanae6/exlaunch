#pragma once

#include "../types.h"
#include "errno.h"

struct in_addr
{
    u32 data;           // 0
};

struct sockaddr
{
    u8 _0;              // 0
    u8 family;          // 1
    u16 port;           // 2
    in_addr address;    // 4
    u8 _8[8];           // 8
};


namespace nn { namespace socket {

Result Initialize(void* pool, ulong poolSize, ulong allocPoolSize, int concurLimit);

s32 SetSockOpt(s32 socket, s32 socketLevel, s32 option, void const*, u32 len);
s32 Fcntl(s32 socket, s32 cmd, ...);

s32 Socket(s32 domain, s32 type, s32 protocol);
s32 Connect(s32 socket,	const sockaddr* address, u32 addressLen);
s32 Bind(s32 socket, const sockaddr* address, u32 addressLen);
s32 Listen(s32 socket, s32 backlog);
s32 Accept(s32 socket, const sockaddr* address, u32 addressLen);
void Close(s32 socket);

s32 Send(s32 socket, const void* data, ulong dataLen, s32 flags);
s32 Recv(s32 socket, void* out, ulong outLen, s32 flags);

u16 InetHtons(u16 val);
s32 InetAton(const char* addressStr, in_addr* addressOut);

} }
