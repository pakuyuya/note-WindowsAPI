#pragma once
#include "stdafx.h"

#include "App.hpp"
#include <Windows.h>

int cnt_callback = 0;
void callback(int id) {
	char msgbuf[64];
	sprintf_s(msgbuf, "%d", cnt_callback++);
	MessageBoxA(NULL, msgbuf, "alert", MB_OK);
}

void App::AddHotkeyBind(int id){
	hotkeys.Bind(id, MOD_ALT, 0x30, callback);
}
void App::AcceptHotkey(int id) {
	hotkeys.Fire(id);
}