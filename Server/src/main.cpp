#include "pch.h"
#include <iostream>
#include <util/Util.h>
#include "ServerApp.h"




void Test()
{

}

int main(){
    sptr<ServerApp> serverApp = std::make_shared<ServerApp>();
    serverApp->Start();
    Test();
    return 0;
}