#include "packet_receiver.h"
#include <iostream>

void PacketReceiver::StartPacket()
{
    parts.push_back(map<int, string>());
}

bool PacketReceiver::ReceivePart(uint16_t id, size_t controlSum, const std::string &data)
{
    if (std::hash<std::string>{}(data) != controlSum)
    {
        failedCnt++;
        return false;
    }
    auto &curPacket = parts.back();
    curPacket[id] = data;
    return true;
}

std::vector<std::string> PacketReceiver::GetCollectedPackets() const
{
    vector<string> ret;
    for (auto &packet : parts)
    {
        string cur;
        for (auto &part : packet)
            cur += part.second;
        ret.push_back(cur);
    }
    return ret;
}

size_t PacketReceiver::GetNumOfFailedParts() const
{
    return failedCnt;
}