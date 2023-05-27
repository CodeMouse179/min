// ----- Min Text Editor -----

#define MIN_TEXT_EDITOR_NAME "Min Text Editor"
#define MIN_TEXT_EDITOR_VERSION "dev 1"

// ----- Platform -----

#if defined _WIN32
#define SYSTEM_WINDOWS 1
#endif

#if defined __APPLE__
#define SYSTEM_MACOS 1
#endif

#if defined __linux__
#define SYSTEM_LINUX 1
#endif

#if defined SYSTEM_MACOS || defined SYSTEM_LINUX
#define SYSTEM_POSIX 1
#endif

// ----- SYSTEM_NAME -----

#if defined SYSTEM_WINDOWS
#define SYSTEM_NAME "Windows"
#endif

#if defined SYSTEM_MACOS
#define SYSTEM_NAME "macOS"
#endif

#if defined SYSTEM_LINUX
#define SYSTEM_NAME "Linux"
#endif

#if !defined SYSTEM_WINDOWS && !defined SYSTEM_MACOS && !defined SYSTEM_LINUX
#define SYSTEM_NAME "Unknown"
#endif

// ----- Util Macro -----

#define LEN(arr) (sizeof(arr) / sizeof(arr[0]))

// ----- Header -----

#include <string.h>
#include <stdio.h>

// ----- Function -----

void get_system_name(char* str)
{
#if defined SYSTEM_NAME
    strcpy(str, SYSTEM_NAME);
#endif
}

void log_info()
{
#if defined MIN_TEXT_EDITOR_NAME
    printf("%s\n", MIN_TEXT_EDITOR_NAME);
#endif
#if defined MIN_TEXT_EDITOR_VERSION
    printf("Version : %s\n", MIN_TEXT_EDITOR_VERSION);
#endif
    char system_name[99];
    get_system_name(system_name);
    printf("System  : %s\n", system_name);
}

int main(int argc, char** argv)
{
    log_info();
    return 0;
}