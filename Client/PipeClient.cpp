// PipeClient.cpp : Defines the entry point for the console application.
//

#include <string>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include "CPipeClient.h"

int main(int argc, char** argv[])
{
    _setmode(_fileno(stdout), _O_U8TEXT);
    std::wcout << TEXT("---------------------Pipe Client--------------------") << std::endl;
    std::wstring sPipeName(PIPENAME);
    CPipeClient* pClient = new CPipeClient(sPipeName);
    ::WaitForSingleObject(pClient->GetThreadHandle(), INFINITE);
    delete pClient;
    pClient = NULL;
    return 0;
}

