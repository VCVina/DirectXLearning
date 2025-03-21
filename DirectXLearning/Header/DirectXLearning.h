#pragma once

LRESULT CALLBACK WindowProc(HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam);

void InitWindowClass(WNDCLASSEX& wc, HINSTANCE hInstance);

void InitD3D(HWND hWnd);

void SetViewport();

void RenderFrame();

void CleanD3D();