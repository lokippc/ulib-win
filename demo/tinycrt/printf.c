 #include <windows.h>
//#include <stdio.h>
#include <stdarg.h>

#ifndef __BORLANDC__
// Force the linker to include USER32.LIB
#pragma comment(linker, "/defaultlib:user32.lib")
#endif

int __cdecl printf(const char * format, ...)
{
    char szBuff[1024];
    int retValue;
    DWORD cbWritten;
    va_list argptr;

    va_start( argptr, format );
    retValue = wvsprintf( szBuff, format, argptr );
    va_end( argptr );

    WriteFile(  GetStdHandle(STD_OUTPUT_HANDLE), szBuff, retValue,
                &cbWritten, 0 );

    return retValue;
}
