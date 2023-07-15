#include "pch.h"
#include <iostream>
#include <util/Util.h>
#include "ServerApp.h"

int main(){
    sptr<ServerApp> serverApp = std::make_shared<ServerApp>();
    serverApp->Start();
    return 0;
}