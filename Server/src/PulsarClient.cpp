#include <iostream>
#include "PulsarClient.h"
#include <thread>
namespace{
    std::atomic<uint32_t> acksReceived;
}

void PulsarClient::SendAsyncCallback(Result code, const MessageId& msgId, std::string msgContent) {
    // message processing logic here
    std::cout << "Received ack for msg: " << msgContent << " with code: "
              << code << " -- MsgID: " << msgId << std::endl;
    acksReceived++;
}

void PulsarClient::Init() {

    Client client("pulsar://localhost:6650");

    ProducerConfiguration producerConf;
    producerConf.setBlockIfQueueFull(true);
    Producer producer;
    Result result = client.createProducer("persistent://public/default/my-topic",
                                          producerConf, producer);
    if (result != ResultOk) {
        std::cout << "Error creating producer: " << result << std::endl;
        return;
    }

    // Send 100 messages asynchronously
    int ctr = 0;
    while (ctr < 3) {
        std::string content = "msg" + std::to_string(ctr);
        Message msg = MessageBuilder().setContent(content).setProperty("x", "1").build();
        producer.sendAsync(msg, std::bind(SendAsyncCallback,
                                          std::placeholders::_1, std::placeholders::_2, content));

        //std::this_thread::sleep_for(std::chrono::milliseconds(100));
        ctr++;
    }

    // wait for 100 messages to be acked
//    while (acksReceived < 100) {
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    }
    while(true){
        std::cout << "Finished producing asynchronously!" << std::endl;
    }

    //client.close();
}

void PulsarClient::Consume() {
    Client client("pulsar://localhost:6650");

    Consumer consumer;
    ConsumerConfiguration config;
    config.setSubscriptionInitialPosition(InitialPositionEarliest);
    Result result = client.subscribe("persistent://public/default/my-topic", "consumer-1", config, consumer);
    if (result != ResultOk) {
        std::cout << "Failed to subscribe: " << result << std::endl;
        return;
    }

    Message msg;
    int ctr = 0;
    // consume 100 messages
    while (ctr < 100) {
        consumer.receive(msg);
        std::cout << "Received: " << msg
                  << "  with payload '" << msg.getDataAsString() << "'" << std::endl;

        consumer.acknowledge(msg);
        ctr++;
    }

    std::cout << "Finished consuming synchronously!" << std::endl;

    client.close();
    return;
}
