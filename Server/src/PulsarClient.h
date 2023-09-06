#pragma once
#include <pulsar/Client.h>
#include <atomic>

using namespace pulsar;

class PulsarClient {

public:
    void Init();
    void static SendAsyncCallback(Result code, const MessageId& msgId, std::string msgContent);
    void Consume();
private:

};


