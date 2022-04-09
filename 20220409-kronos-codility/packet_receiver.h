#ifndef PACKET_RECEIVER_H
#define PACKET_RECEIVER_H

#include <vector>
#include <string>
#include <map>

using namespace std;

class PacketReceiver
{
public:
    PacketReceiver()
    {
        failedCnt = 0;
    }

    void StartPacket();

    bool ReceivePart(uint16_t id, size_t controlSum, const std::string &data);

    std::vector<std::string> GetCollectedPackets() const;

    size_t GetNumOfFailedParts() const;

private:
    int failedCnt;
    vector<map<int, string>> parts;
};

#endif // PACKET_RECEIVER_H
