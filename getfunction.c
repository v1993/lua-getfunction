#include "lua.h"
#include "lauxlib.h"

static int l_getfunction(lua_State *L) {
	lua_Debug ar;
	int level = luaL_checkinteger(L, 1);
	if (level < 0) luaL_error(L, "invalid stack level");
	if (lua_getstack(L, level, &ar) != 1) return 0; // слишком глубоко
	if (lua_getinfo(L, "f", &ar) == 0) luaL_error(L, "failed to get function");
	return 1;
}

int luaopen_getfunction(lua_State *L) {
	lua_pushcfunction(L, l_getfunction); // require вернёт нашу функцию
	return 1;
}
