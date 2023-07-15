#include "pch.h"
#include "ServerApp.h"
#include <spdlog/spdlog.h>
#include "Session.h"

void ServerApp::Start()
{
    spdlog::info("Server is starting...");

    sptr<Session> session = std::make_shared<Session>();
    session->DoConnect();
}