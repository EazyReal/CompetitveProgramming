#include "packet_receiver.h"
#include <cstdio>
#include <bits/stdc++.h>

int main()
{
    PacketReceiver rec;
    rec.StartPacket();
    rec.ReceivePart(1, std::hash<std::string>{}("World"), "World"); // wrong check sum
    rec.ReceivePart(2, std::hash<std::string>{}("!"), "!");
    rec.ReceivePart(0, std::hash<std::string>{}("Hello "), "Hello ");

    rec.StartPacket();
    rec.ReceivePart(100, std::hash<std::string>{}("Packet"), "Packet");
    rec.ReceivePart(101, 0, "");
    rec.ReceivePart(102, std::hash<std::string>{}("Receiver"), "Receiver");

    auto packets = rec.GetCollectedPackets();
    cout << packets.size() << endl;
    cout << packets[0] << endl;
    cout << packets[1] << endl;
    cout << rec.GetNumOfFailedParts() << endl;
    // packet.size() should be 1
    // packets[0] should be "Hello World!"
    // rec.GetNumOfFailedParts() should return 0

    return 0;
}
// packet.size() should be 2
// packets[0] should be ""
// packets[1] should be ""