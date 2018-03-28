#pragma once

#include <map>
#include <utility>
#include <Windows.h>

typedef void(*HotkeyCallback)(int id);

class HotkeyCallbackRegistory {
private:
	bool initialized = false;
	HWND _hWnd = NULL;
	std::map<int, HotkeyCallback> _hotkeyMap;
public:
	HotkeyCallbackRegistory()
	{
		
	}
	~HotkeyCallbackRegistory() {
		ReleaseAll();
	}

	inline void Init(HWND &hWnd) {
		if (initialized) {
			return;
		}
		initialized = true;
		_hWnd = hWnd;
	}

	inline bool Has(int id) {
		return _hotkeyMap.count(id);
	}

	inline bool Bind(int id, int fl, int vk, HotkeyCallback cb) {
		if (!initialized) {
			return false;
		}

		Release(id);
		RegisterHotKey(_hWnd, id, fl, vk);
		_hotkeyMap.insert(std::pair<int, HotkeyCallback>(id, cb));
		return true;
	}

	inline bool Release(int id) {
		if (!initialized) {
			return false;
		}

		if (!Has(id)) {
			return false;
		}
		UnregisterHotKey(_hWnd, id);
		_hotkeyMap.erase(id);
		return true;
	}

	inline bool ReleaseAll() {
		for each(auto it in _hotkeyMap) {
			Release(it.first);
		}
		_hotkeyMap.clear();

		return true;
	}

	inline bool Fire(int id) {
		if (!initialized) {
			return false;
		}

		if (!Has(id)) {
			return false;
		}

		(_hotkeyMap.at(id))(id);

		return true;
	}
};