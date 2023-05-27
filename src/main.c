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
#include <stdbool.h>

// ----- Lua Header -----

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

// ----- Platform Header -----

#if defined SYSTEM_WINDOWS
#define NOMINMAX
#include <Windows.h>
#endif

#if defined SYSTEM_POSIX

#endif

// ----- Function -----

void get_system_name(char* str)
{
#if defined SYSTEM_NAME
    strcpy(str, SYSTEM_NAME);
#endif
}

void log_info(void)
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

void lua_test(const char* lua_script)
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    int r = luaL_dostring(L, lua_script);
    if (r != LUA_OK)
    {
        const char* err_msg = lua_tostring(L, -1);
        printf("!Lua Error Message: %s", err_msg);
    }
    lua_close(L);
}

int main(int argc, char** argv)
{
    log_info();
    lua_test("print('Hello, World!')");
    return 0;
}