#include "stdafx.h"

#include <windows.h> 
LRESULT CALLBACK WinFun(HWND, UINT, WPARAM, LPARAM);
char WinName[] = "My window";
int WINAPI WinMain(HINSTANCE hIns, HINSTANCE hPrevIns, LPSTR arg, int WinMode)
{
	HWND hwnd;
	MSG msg;
	WNDCLASSEX wcl;
	wcl.hInstance = hIns;
	wcl.lpszClassName = WinName;
	wcl.lpfnWndProc = WinFun;
	wcl.style = 0;
	wcl.cbSize = sizeof(WNDCLASSEX);
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.lpszMenuName = NULL;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	if (!RegisterClassEx(&wcl)) return 0;
	hwnd = CreateWindow(
		WinName,
		"lab8",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		HWND_DESKTOP,
		NULL,
		hIns,
		NULL);
	ShowWindow(hwnd, WinMode);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

struct ell
{
	int x, y;
};

struct ellList
{
	ell L;
	ellList *pNext;
};

ellList *pFirst = 0, *p;

void add(ellList *&pF, ellList *p)
{
	p->pNext = pF;
	pF = p;
}


HPEN pen = CreatePen(PS_DASHDOT, 1, RGB(255, 0, 0));;
HBRUSH br = CreateHatchBrush(HS_CROSS, RGB(0, 0, 255));


LRESULT CALLBACK WinFun(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	switch (message)
	{
	case WM_MOUSEMOVE:
		if (wParam & MK_RBUTTON)
		{
			int x, y;
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			hdc = GetDC(hwnd);
			SelectObject(hdc, pen);
			SelectObject(hdc, br);
			Ellipse(hdc, x - 50, y - 50, x + 50, y + 50);
			ReleaseDC(hwnd, hdc);
			p = new ellList;
			p->L.x = x;
			p->L.y = y;
			add(pFirst, p);
		}
		EndPaint(hwnd, &ps);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		p = pFirst;
		while (p)
		{
			hdc = GetDC(hwnd);
			SelectObject(hdc, pen);
			SelectObject(hdc, br);
			Ellipse(hdc, p->L.x - 50, p->L.y - 50, p->L.x + 50, p->L.y + 50);
			p = p->pNext;
		}
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
