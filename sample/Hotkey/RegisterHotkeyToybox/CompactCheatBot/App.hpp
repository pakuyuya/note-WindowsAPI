#pragma once
#include "HotkeyCallbackRegistory.hpp"

class App {
private:
	HotkeyCallbackRegistory hotkeys;
public:
	inline void Init(HWND hWnd) {
		hotkeys.Init(hWnd);
	}

	void AddHotkeyBind(int id);
	void AcceptHotkey(int id);
};

