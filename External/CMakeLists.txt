project(Atlas-Dependencies)

#Projects with CMake Support
add_subdirectory(ASSIMP)
add_subdirectory(Doxygen)
add_subdirectory(GLFW)
add_subdirectory(GoogleTest)
add_subdirectory(OpenAL-Soft)
add_subdirectory(TinyXML2)



project(Lua)

set(LUA_RUNTIME_SOURCES 
"Lua/lapi.c"
"Lua/lapi.h"
"Lua/lauxlib.c"
"Lua/lauxlib.h"
"Lua/lbaselib.c"
"Lua/lcode.c"
"Lua/lcode.h"
"Lua/lcorolib.c"
"Lua/lctype.c"
"Lua/lctype.h"
"Lua/ldblib.c"
"Lua/ldebug.c"
"Lua/ldebug.h"
"Lua/ldo.c"
"Lua/ldo.h"
"Lua/ldump.c"
"Lua/lfunc.c"
"Lua/lfunc.h"
"Lua/lgc.c"
"Lua/lgc.h"
"Lua/linit.c"
"Lua/liolib.c"
"Lua/ljumptab.h"
"Lua/llex.c"
"Lua/llex.h"
"Lua/llimits.h"
"Lua/lmathlib.c"
"Lua/lmem.c"
"Lua/lmem.h"
"Lua/loadlib.c"
"Lua/lobject.c"
"Lua/lobject.h"
"Lua/lopcodes.c"
"Lua/lopcodes.h"
"Lua/lopnames.h"
"Lua/loslib.c"
"Lua/lparser.c"
"Lua/lparser.h"
"Lua/lprefix.h"
"Lua/lstate.c"
"Lua/lstate.h"
"Lua/lstring.c"
"Lua/lstring.h"
"Lua/lstrlib.c"
"Lua/ltable.c"
"Lua/ltable.h"
"Lua/ltablib.c"
"Lua/ltests.c"
"Lua/ltests.h"
"Lua/ltm.c"
"Lua/ltm.h"
"Lua/luaconf.h"
"Lua/lualib.h"
"Lua/lundump.c"
"Lua/lundump.h"
"Lua/lutf8lib.c"
"Lua/lvm.c"
"Lua/lvm.h"
"Lua/lzio.c"
"Lua/lzio.h"
)

add_library(Lua ${LUA_RUNTIME_SOURCES})

target_include_directories(Lua PUBLIC "${PROJECT_SOURCE_DIR}/Lua/")
