// DirectXLearning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <windows.h> //<- WinMain
#include <windowsx.h> 
#include <DirectXLearning.h>


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		} break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

void InitWindowClass(WNDCLASSEX& wc, HINSTANCE hInstance)
{
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;

	wc.lpfnWndProc = WindowProc;

	wc.hInstance = hInstance;

	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;

	wc.lpszClassName = L"WindowClass1";

	RegisterClassEx(&wc);
}

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	WNDCLASSEX wc;

	//Init/Prepare the WND Class
	InitWindowClass(wc, hInstance);

	// Use the WND class to Create Window
	HWND hWnd; // Not just app, window also has a handle, we should store this h.
	RECT wr = { 0, 0, 500, 400 }; 
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);
	hWnd = CreateWindowEx(NULL, wc.lpszClassName, L"Our First Windowed Program", WS_OVERLAPPEDWINDOW, 
		300, // x 
		300, // y 
		wr.right - wr.left, // w
		wr.bottom - wr.top, // h
		NULL, 
		NULL,
		hInstance, // handle from windows
		NULL
	);

	// Show Window
	ShowWindow(hWnd, nShowCmd);

	// Of course we need Main Loop
	MSG msg;

	while (TRUE) { 
		// Code for every frame
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg); //->wc.lpfnWndProc = WindowProc, We need complete this WindowProc

			// Quit?
			if (msg.message == WM_QUIT)
				break;
		}
	}

	return msg.wParam;
}
