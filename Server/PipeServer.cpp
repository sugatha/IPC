// PipeServer.cpp : Defines the entry point for the console application.
//

#include <io.h>
#include <fcntl.h>
#include "PipeConst.h"
#include "CPipeServer.h"

int main(int argc, char** argv[])
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    std::wcout << TEXT("---------------------Pipe Server--------------------") << std::endl;
    std::wstring sPipeName(PIPENAME);
    CPipeServer* pServer = new CPipeServer(sPipeName);
    ::WaitForSingleObject(pServer->GetThreadHandle(), INFINITE);
    delete pServer;
    pServer = NULL;

    return 0;
}

