#include "pch.h"
#include "ServerApp.h"
#include <spdlog/spdlog.h>
#include "Session.h"
#include "DBConnection.h"
#include "PostgresDB.h"
#include "PulsarClient.h"

void ServerApp::Start()
{
    spdlog::info("Server is starting....!");
    sptr<Session> session = std::make_shared<Session>();
    session->DoConnect();
    session->DoSend();

    //sptr<DBConnection> db = std::make_shared<DBConnection>();
    sptr<PostgresDB> db = std::make_shared<PostgresDB>();
    db->Init();

    sptr<PulsarClient> pulsarClient = std::make_shared<PulsarClient>();
    pulsarClient->Init();
}