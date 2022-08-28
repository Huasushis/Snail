#pragma once
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;
#ifndef QQ_H
#define QQ_H
class qq
{
private:
	HWND windowHandle;

	void copy(string word)
	{
		HWND hWnd = NULL;
		OpenClipboard(hWnd);
		EmptyClipboard();
		HANDLE hHandle = GlobalAlloc(GMEM_FIXED, 1000);
		char* pData = (char*)GlobalLock(hHandle);
		strcpy_s(pData, strlen(word.c_str()) + 1, word.c_str());
		SetClipboardData(CF_TEXT, hHandle);
		GlobalUnlock(hHandle);
		CloseClipboard();
	}
public:
	void init(string win){
		
		if (FindWindow(NULL, win.c_str()))
		{
			windowHandle = FindWindow(NULL, win.c_str());
		}
		else
		{
			MessageBox(NULL, "Can't Find The Window!!!\nErrorCode:1001", "Error", MB_OK | MB_ICONERROR);
			throw 1001;
		}
	}

	~qq() = default;

	void send(string word)
	{
		copy(word);
		SendMessage(windowHandle, WM_PASTE, 0, 0);
		SendMessage(windowHandle, WM_KEYDOWN, VK_RETURN, 0);
	}
};
#endif