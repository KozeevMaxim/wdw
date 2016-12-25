// ForDZ2.cpp: ÓÔÂ‰ÂÎˇÂÚ ÚÓ˜ÍÛ ‚ıÓ‰‡ ‰Îˇ ÔËÎÓÊÂÌËˇ.
//

#include "stdafx.h"
#include "ForDZ2.h"

#define MAX_LOADSTRING 100

// √ÎÓ·‡Î¸Ì˚Â ÔÂÂÏÂÌÌ˚Â:
HINSTANCE hInst;								// ÚÂÍÛ˘ËÈ ˝ÍÁÂÏÔÎˇ
TCHAR szTitle[MAX_LOADSTRING];					// “ÂÍÒÚ ÒÚÓÍË Á‡„ÓÎÓ‚Í‡
TCHAR szWindowClass[MAX_LOADSTRING];			// ËÏˇ ÍÎ‡ÒÒ‡ „Î‡‚ÌÓ„Ó ÓÍÌ‡

// ŒÚÔ‡‚ËÚ¸ Ó·˙ˇ‚ÎÂÌËˇ ÙÛÌÍˆËÈ, ‚ÍÎ˛˜ÂÌÌ˚ı ‚ ˝ÚÓÚ ÏÓ‰ÛÎ¸ ÍÓ‰‡:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK MyDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: ‡ÁÏÂÒÚËÚÂ ÍÓ‰ Á‰ÂÒ¸.
	MSG msg;
	HACCEL hAccelTable;

	// »ÌËˆË‡ÎËÁ‡ˆËˇ „ÎÓ·‡Î¸Ì˚ı ÒÚÓÍ
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_FORDZ2, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ¬˚ÔÓÎÌËÚ¸ ËÌËˆË‡ÎËÁ‡ˆË˛ ÔËÎÓÊÂÌËˇ:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_FORDZ2));

	// ÷ËÍÎ ÓÒÌÓ‚ÌÓ„Ó ÒÓÓ·˘ÂÌËˇ:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  ‘”Õ ÷»ﬂ: MyRegisterClass()
//
//  Õ¿«Õ¿◊≈Õ»≈: Â„ËÒÚËÛÂÚ ÍÎ‡ÒÒ ÓÍÌ‡.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_FORDZ2));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_FORDZ2);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ‘”Õ ÷»ﬂ: InitInstance(HINSTANCE, int)
//
//   Õ¿«Õ¿◊≈Õ»≈: ÒÓı‡ÌˇÂÚ Ó·‡·ÓÚÍÛ ˝ÍÁÂÏÔÎˇ‡ Ë ÒÓÁ‰‡ÂÚ „Î‡‚ÌÓÂ ÓÍÌÓ.
//
//    ŒÃÃ≈Õ“¿–»»:
//
//        ¬ ‰‡ÌÌÓÈ ÙÛÌÍˆËË ‰ÂÒÍËÔÚÓ ˝ÍÁÂÏÔÎˇ‡ ÒÓı‡ÌˇÂÚÒˇ ‚ „ÎÓ·‡Î¸ÌÓÈ ÔÂÂÏÂÌÌÓÈ, ‡ Ú‡ÍÊÂ
//        ÒÓÁ‰‡ÂÚÒˇ Ë ‚˚‚Ó‰ËÚÒˇ Ì‡ ˝Í‡Ì „Î‡‚ÌÓÂ ÓÍÌÓ ÔÓ„‡ÏÏ˚.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // —Óı‡ÌËÚ¸ ‰ÂÒÍËÔÚÓ ˝ÍÁÂÏÔÎˇ‡ ‚ „ÎÓ·‡Î¸ÌÓÈ ÔÂÂÏÂÌÌÓÈ

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

// –‡ÁÏÂ Ó·‡·‡Ú˚‚‡ÂÏÓ„Ó ·ÎÓÍ‡ ‚ ÙÛÌÍˆËË Ò‰‚Ë„‡ Î˛·ÓÈ ‰Ó 4 ·‡ÈÚ
unsigned sdvigright(unsigned a, int n, int L) // —‰‚Ë„ ‚Ô‡‚Ó Ì‡ L ·ËÚ, n - ‡ÁÏÂ ·ÎÓÍ‡ ‚ ·ËÚ‡ı
{
	// a- ËÒıÓ‰ÌÓÂ ÁÌ‡˜ÂÌËÂ
	unsigned maska = 0; // Ã‡ÒÍ‡ ‰Îˇ ÔÓÎÛ˜ÂÌËˇ Ô‡‚˚ı L ·ËÚÓ‚ (ÏÎ‡‰¯ËÂ L ‡Áˇ‰Ó‚ ‰ÓÎÊÌ˚ ·˚Ú¸ 1)
	for (int i = 0; i<L; i++)
	{
		maska <<= 1; // —‰‚Ë„ ‚ÎÂ‚Ó Ì‡ 1 ·ËÚ
		maska += 1; // ÃÎ‡‰¯ËÈ ·ËÚ ‚ 1
	}
	unsigned b = a & maska; // —Óı‡ÌËÎ ÏÎ‡‰˘ËÂ L ·ËÚ ‚ b
	b <<= (n - L); // —‰‚Ë„‡ÂÏ ÏÎ‡‰¯ËÂ ·ËÚ˚ ‚ Ì‡˜‡ÎÓ ·ÎÓÍ‡
	a >>= L; // —‰‚Ë„ ‚Ô‡‚Ó Ì‡ L ·ËÚ
	return a | b; // œÓÎÛ˜‡ÂÏ ÂÁÛÎ¸Ú‡Ú
}

unsigned sdvigleft(unsigned a, int n, int L) // —‰‚Ë„ ‚ÎÂ‚Ó Ì‡ L ·ËÚ, n - ‡ÁÏÂ ·ÎÓÍ‡ ‚ ·ËÚ‡ı
{
	// a- ËÒıÓ‰ÌÓÂ ÁÌ‡˜ÂÌËÂ
	unsigned maska = 0; // Ã‡ÒÍ‡ ‰Îˇ ÔÓÎÛ˜ÂÌËˇ ÎÂ‚˚ı L ·ËÚÓ‚ (ÒÚ‡¯ËÂ L ‡Áˇ‰Ó‚ ‰ÓÎÊÌ˚ ·˚Ú¸ 1)
	for (int i = 0; i<L; i++)
	{
		maska <<= 1; // —‰‚Ë„ ‚ÎÂ‚Ó Ì‡ 1 ·ËÚ
		maska += 1; // ÃÎ‡‰¯ËÈ ·ËÚ ‚ 1
	}
	maska <<= (n - L); // ÃÎ‡‰¯ËÂ ·ËÚ˚ Ò‰‚Ë„‡ÂÏ ‚ ÒÚ‡¯Û˛ ˜‡ÒÚ¸ ·ÎÓÍ‡

	unsigned b = a & maska; // —Óı‡ÌËÎ ÒÚ‡¯ËÂ L ·ËÚ ‚ b
	b >>= (n - L); // —‰‚Ë„‡ÂÏ ÒÚ‡¯ËÂ ·ËÚ˚ ‚ ÏÎ‡‰¯Û˛ ˜‡ÒÚ¸
	a <<= L; // —‰‚Ë„ ‚ÎÂ‚Ó Ì‡ L ·ËÚ
	return a | b; // œÓÎÛ˜‡ÂÏ ÂÁÛÎ¸Ú‡Ú
}

// Œ‰Ì‡ ÙÛÌÍˆËˇ ¯ËÙÛÂÚ Ë ‰Â¯ËÙÛÂÚ (‡·ÓÚ‡ÂÚ Ò ·ÎÓÍ‡ÏË ÔÓ 2 ·‡ÈÚ‡)
void shifrDeshifr(char *in, char *out, int n, int key, int reg)
{
	// œË ¯ËÙÓ‚‡ÌËË Ò‰‚Ë„‡ÂÏ Ì‡ 2 ·ËÚ‡ ‚ÎÂ‚Ó 
	/* in - ‚ıÓ‰ÌÓÈ Ï‡ÒÒË‚
	out - ‚˚ıÓ‰ÌÓÈ Ï‡ÒÒË‚
	n - ‡ÁÏÂÌÓÒÚË Ï‡ÒÒË‚Ó‚
	key - ÒÂÍÂÚÌ˚È ÍÎ˛˜
	reg - ÂÊËÏ ‡·ÓÚ˚ ÙÛÌÍˆËË 1 - ÂÊËÏ ¯ËÙÓ‚‡ÌËˇ 2 - ÂÊËÏ ‡Ò¯ËÙÓ‚‡ÌËˇ
	*/
	srand(key); // »ÌËˆË‡ÎËÁ‡ˆËˇ „ÂÌÂ‡ÚÓ‡ ÒÂÍÂÚÌ˚Ï ÍÎ˛˜ÓÏ ‰Îˇ ÔÓÎÛ˜ÂÌËˇ „‡ÏÏ˚
	// –‡·ÓÚ‡ÂÏ Ò ·ÎÓÍ‡ÏË ÔÓ 2 ·‡ÈÚ‡
	unsigned short a, b, gamma; // ¬ıÓ‰ÌÓÂ Ë ‚˚ıÓ‰ÌÓÂ ÁÌ‡˜ÂÌËˇ
	int l; // –‡ÁÏÂ ·ÎÓÍ‡ ‚ ·‡ÈÚ‡ı
	for (int i = 0; i < n; i += 2)
	{
		if (n % 2 != 0 && i == n - 1) // ”ÒÎÓ‚ËÂ ÔÓÒÎÂ‰ÌËÈ ·ÎÓÍ ÌÂ ÔÓÎÌ˚È - 1 ·‡ÈÚ
		{
			a = 0;
			l = 1;

		}
		else l = 2;
		memcpy(&a, in + i, l); //  ÓÔËÛÂÏ l ·‡ÈÚ‡ ËÁ ‚ıÓ‰ÌÓ„Ó Ï‡ÒÒË‚‡
		if (reg == 2) // –ÂÊËÏ ‰Â¯ËÙÓ‚‡ÌËˇ
			a = sdvigright(a, l * 8, 2); // —‰‚Ë„‡ÂÏ Ì‡ 2 ·ËÚ‡ ‚Ô‡‚Ó
		gamma = rand();
		b = gamma ^ a;
		if (reg == 1) b = sdvigleft(b, l * 8, 2); // —‰‚Ë„‡ÂÏ Ì‡ 2 ·ËÚ‡ ‚ÎÂ‚Ó ÔË ¯ËÙÓ‚‡ÌËË
		memcpy(out + i, &b, l); //  ÓÔËÛÂÏ l ·‡ÈÚ‡ ‚ ‚˚ıÓ‰ÌÓÈ Ï‡ÒÒË‚

	}
}

char Str[512];
int len = 0;
int key; // —Û‰‡ Á‡ÔË¯ÂÏ ÁÌ‡˜ÂÌËÂ ÒÂÍÂÚÌÓ„Ó ÍÎ˛˜‡

OPENFILENAME ofn; // —ÚÛÍÚÛ‡ ‰Îˇ ÒÚ‡Ì‰‡ÚÌ˚ı ÓÍÓÌ "ŒÚÍ˚Ú¸ Ù‡ÈÎ" Ë "—Óı‡ÌËÚ¸"
TCHAR NameFile[256] = "MyFile.shf"; // —˛‰‡ ·Û‰ÂÚ Á‡ÔËÒ‡ÌÓ ËÏˇ Ù‡ÈÎ‡



//
//  ‘”Õ ÷»ﬂ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Õ¿«Õ¿◊≈Õ»≈:  Ó·‡·‡Ú˚‚‡ÂÚ ÒÓÓ·˘ÂÌËˇ ‚ „Î‡‚ÌÓÏ ÓÍÌÂ.
//
//  WM_COMMAND	- Ó·‡·ÓÚÍ‡ ÏÂÌ˛ ÔËÎÓÊÂÌËˇ
//  WM_PAINT	-«‡Í‡ÒËÚ¸ „Î‡‚ÌÓÂ ÓÍÌÓ
//  WM_DESTROY	 - ‚‚ÂÒÚË ÒÓÓ·˘ÂÌËÂ Ó ‚˚ıÓ‰Â Ë ‚ÂÌÛÚ¸Òˇ.
//
//


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	
	switch (message)
	{
	case WM_CHAR: // —ÓÓ·˘ÂÌËÂ ‚‚Ó‰ ÒËÏ‚ÓÎ‡
		// «‡ÔËÒ˚‚‡ÂÏ ÒËÏ‚ÓÎ ‚ ÒÚÓÍÛ
		Str[len] = wParam;
		len++; // ƒÎËÌ‡ ÒÚÓÍË Û‚ÂÎË˜Ë‚‡ÂÚÒˇ Ì‡ 1
		Str[len] = 0; // —ÚÓÍ‡ Á‡Í‡Ì˜Ë‚‡ÂÚÒˇ ÒËÏ‚ÓÎÓÏ Ò ÍÓ‰ÓÏ 0
		// ¬˚‚Ó‰ ÒÚÓÍË Ì‡ ˝Í‡Ì
		hdc = GetDC(hWnd); // œÓÎÛ˜‡ÂÏ ÍÓÌÚÂÍÒÚ ÛÒÚÓÈÒÚ‚‡
		SetTextColor(hdc, RGB(0, 0, 255));
		TextOut(hdc, 40, 40, Str, len); // ¬˚‚Ó‰ ÒÚÓÍË
		ReleaseDC(hWnd, hdc); // ŒÒ‚Ó·ÓÊ‰‡ÂÏ ÍÓÌÚÂÍÒÚ ÛÒÚÓÈÒÚ‚‡
		break;
	case WM_COMMAND: // —ÓÓ·˘ÂÌËÂ ÓÚ ‚˚·Ó‡ ˝ÎÂÏÂÌÚ‡ ÏÂÌ˛
		wmId    = LOWORD(wParam); // œÓÎÛ˜‡ÂÏ Ë‰ÂÌÚËÙËÍ‡ÚÓ (ÌÓÏÂ) ˝ÎÂÏÂÌÚ‡ ÏÂÌ˛
		wmEvent = HIWORD(wParam);
		// –‡ÁÓ·‡Ú¸ ‚˚·Ó ‚ ÏÂÌ˛:
		switch (wmId) // Œ·‡·ÓÚÍ‡ ÓÚ‰ÂÎ¸Ì˚ı ˝ÎÂÏÂÌÚÓ‚ ÏÂÌ˛
		{
		case IDM_ABOUT: // Œ ÔÓ„‡ÏÏÂ 
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT: // ¬˚ıÓ‰
			DestroyWindow(hWnd);
			break;
		case ID_32771: // ŒÚÍ˚Ú¸ Ù‡ÈÎ
			ZeroMemory(&ofn, sizeof(ofn));
			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = hWnd;
			ofn.lpstrFile = NameFile; // —˛‰‡ ·Û‰ÂÚ Á‡ÔËÒ‡ÌÓ ËÏˇ Ù‡ÈÎ‡
			// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
			// use the contents of szFile to initialize itself.
			ofn.lpstrFile[0] = '\0';
			ofn.nMaxFile = 255;
			ofn.lpstrFilter = "ÿËÙÓ‚‡ÌÌ˚Â Ù‡ÈÎ˚ (*.shf)\0*.shf\0¬ÒÂ Ù‡ÈÎ˚\0*.*\0"; // ‘ËÎ¸Ú ‰Îˇ ÓÚÓ·‡ÊÂÌËˇ Ù‡ÈÎÓ‚
			ofn.nFilterIndex = 0;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrInitialDir = NULL;
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
			ofn.lpstrDefExt = "shf"; // —ÚÓÍ‡ ‡Ò¯ËÂÌËÂ ÔÓ ÛÏÓÎ˜‡ÌË˛

			if (GetOpenFileName(&ofn)) // œÓˇ‚ÎˇÂÚÒˇ ÓÍÌÓ "ŒÚÍ˚Ú¸", ÙÛÌÍˆËˇ ‚ÓÁ‚‡˘‡ÂÚ ËÒÚËÌÌÓ, ÂÒÎË Ì‡Ê‡Ú‡ ÍÌÓÔÍ‡ ŒÚÍ˚Ú¸
			{
				// ŒÚÓ·‡Ê‡ÂÏ ÓÍÌÓ ‰Îˇ ‚‚Ó‰‡ ÍÎ˛˜‡
				if (DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, MyDialog) == IDOK)
				{
					FILE *pF1;
					char Shifr[512]; // «‡¯ËÙÓ‚‡ÌÌ˚È ÚÂÍÒÚ
					pF1 = fopen(NameFile, "rb"); // ŒÚÍ˚‚‡ÂÏ Ù‡ÈÎ ‰Îˇ ˜ÚÂÌËˇ ‚ ‰‚ÓË˜ÌÓÏ ÂÊËÏÂ
					if (pF1 == 0)
					{
						MessageBox(hWnd, "Œ¯Ë·Í‡ ÓÚÍ˚ÚËˇ Ù‡ÈÎ‡. ¬ÓÁÏÓÊÌÓ Ù‡ÈÎ ÌÂ ÒÛ˘ÂÒÚ‚ÛÂÚ", "—ÓÓ·˘ÂÌËÂ Ó· Ó¯Ë·ÍÂ", MB_OK | MB_ICONHAND);
						return TRUE;
					}
					fread(&len, sizeof(int), 1, pF1); // ◊ËÚ‡ÂÏ –‡ÁÏÂ ‰‡ÌÌ˚ı ‚ ·‡ÈÚ‡ı
					fread(Shifr, sizeof(char), len, pF1); // ◊ËÚ‡ÂÏ ‰‡ÌÌ˚Â ËÁ Ù‡ÈÎ
					fclose(pF1);
					shifrDeshifr(Shifr, Str, len, key, 2); // –‡Ò¯ËÙÓ‚˚‚‡ÂÏ
					Str[len] = 0; // —ÚÓÍ‡ Á‡Í‡Ì˜Ë‚‡ÂÚÒˇ 0
					InvalidateRect(hWnd, 0, TRUE); // œÂÂËÒÓ‚Í‡ ÓÍÌ‡
				}
				else MessageBox(hWnd, "ƒ‡ÌÌ˚Â ÌÂ ÔÓ˜ËÚ‡Ì˚.  Î˛˜ ÌÂ ‚‚Â‰ÂÌ!!", "—ÓÓ·˘ÂÌËÂ", MB_OK | MB_ICONHAND);
			}


			break;
		case ID_32772: // —Óı‡ÌËÚ¸ Ù‡ÈÎ
			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = hWnd; // Ó‰ËÚÂÎ¸ÒÍÓÂ ÓÍÌÓ 
			ofn.lpstrFilter = "ÿËÙÓ‚‡ÌÌ˚Â Ù‡ÈÎ˚ (*.shf)\0*.shf\0¬ÒÂ Ù‡ÈÎ˚\0*.*\0"; // Ã‡ÒÍ‡ (ÙËÎ¸Ú) ‰Îˇ ÓÚÓ·‡Ê‡ÂÏ˚ı Ù‡ÈÎÓ‚
			ofn.lpstrFile = NameFile;  // —˛‰‡ ·Û‰ÂÚ Á‡ÔËÒ‡ÌÓ ÔÓÎÌÓÂ ËÏˇ Ù‡ÈÎ‡
			ofn.nMaxFile = 255;
			ofn.lpstrFileTitle = NULL;//
			ofn.nMaxFileTitle = 0;
			ofn.lpstrInitialDir = NULL;
			ofn.Flags = OFN_SHOWHELP | OFN_OVERWRITEPROMPT;
			ofn.lpstrTitle = NULL;
			ofn.lpstrDefExt = "shf"; // —ÚÓÍ‡ ‡Ò¯ËÂÌËÂ ÔÓ ÛÏÓÎ˜‡ÌË˛
			if (GetSaveFileName(&ofn)) // œÓˇ‚ÎˇÂÚÒˇ ÓÍÌÓ "—Óı‡ÌËÚ¸", ÙÛÌÍˆËˇ ‚ÓÁ‚‡˘‡ÂÚ ËÒÚËÌÌÓ, ÂÒÎË Ì‡Ê‡Ú‡ ÍÌÓÔÍ‡ Ok
			{
				// ŒÚÓ·‡Ê‡ÂÏ ÓÍÌÓ ‰Îˇ ‚‚Ó‰‡ ÍÎ˛˜‡
				if (DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, MyDialog) == IDOK)
				{
					char Shifr[512]; // «‡¯ËÙÓ‚‡ÌÌ˚È ÚÂÍÒÚ
					shifrDeshifr(Str, Shifr, len, key, 1); // ÿËÙÓ‚‡ÌËÂ ‰‡ÌÌ˚ı

					FILE *pF1;  // ‘‡ÈÎ ‰Îˇ ÒÓı‡ÌÂÌËˇ
					pF1 = fopen(NameFile, "wb"); // ƒÎˇ Á‡¯ËÙÓ‚‡ÌÌ˚ı ‰‡ÌÌ˚ı Ù‡ÈÎ ‚ ‰‚ÓË˜ÌÓÏ ÂÊËÏÂ
					if (pF1 == 0)
					{
						MessageBox(hWnd, "Œ¯Ë·Í‡ ÓÚÍ˚ÚËˇ Ù‡ÈÎ‡.", "—ÓÓ·˘ÂÌËÂ Ó· Ó¯Ë·ÍÂ", MB_OK | MB_ICONHAND);
						return TRUE;
					}
					fwrite(&len, sizeof(int), 1, pF1); // –‡ÁÏÂ ‰‡ÌÌ˚ı ‚ ·‡ÈÚ‡ı
					fwrite(Shifr, sizeof(char), len, pF1); // «‡ÔËÒ˚‚‡ÂÏ ‰‡ÌÌ˚Â ‚ Ù‡ÈÎ
					fclose(pF1);
					MessageBox(hWnd, "ƒ‡ÌÌ˚Â ÛÒÔÂ¯ÌÓ ÒÓı‡ÌÂÌ˚.", "—ÓÓ·˘ÂÌËÂ", MB_OK | MB_ICONINFORMATION);
				}
				else MessageBox(hWnd, "ƒ‡ÌÌ˚Â ÌÂ ÒÓı‡ÌÂÌ˚.  Î˛˜ ÌÂ ‚‚Â‰ÂÌ!!", "—ÓÓ·˘ÂÌËÂ", MB_OK | MB_ICONHAND);
			}

			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT: // œÂÂËÒÓ‚Í‡ ÓÍÌ‡
		hdc = BeginPaint(hWnd, &ps);
		// TODO: ‰Ó·‡‚¸ÚÂ Î˛·ÓÈ ÍÓ‰ ÓÚËÒÓ‚ÍË...
		SetTextColor(hdc, RGB(0, 0, 255));
		TextOut(hdc, 40, 40, Str, len); // ¬˚‚Ó‰ ÒÚÓÍË
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Œ·‡·ÓÚ˜ËÍ ÒÓÓ·˘ÂÌËÈ ‰Îˇ ÓÍÌ‡ "Œ ÔÓ„‡ÏÏÂ".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

// Œ·‡·ÓÚ˜ËÍ ÒÓÓ·˘ÂÌËÈ ‰Îˇ ÓÍÌ‡ "¬‚Ó‰ ÒÂÍÂÚÌÓ„Ó ÍÎ˛˜‡.
INT_PTR CALLBACK MyDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			if (LOWORD(wParam) == IDOK) // ◊ËÚ‡ÂÏ ÒÂÍÂÚÌ˚È ÍÎ˛˜ ËÁ ÚÂÍÒÚÓ‚Ó„Ó ÔÓÎˇ
			{
				char Str[32];
				SendDlgItemMessage(hDlg, IDC_EDIT1, WM_GETTEXT, 31, (LPARAM)Str); // œÓ˜ËÚ‡ÎË ÚÂÍÒÚ ËÁ ÚÂÍÒÚÓ‚Ó„Ó ÔÓÎˇ Ë Á‡ÔËÒ‡ÎË ‚ ÒÚÛÍÛ Str
				// ◊ËÚ‡ÂÏ ‰‡ÌÌ˚Â ËÁ ÒÚÓÍË
				if (sscanf(Str, "%d", &key) < 1) // ÷ÂÎÓÂ ÁÌ‡˜ÂÌËÂ ÌÂ ÔÓ˜ËÚ‡ÌÓ ËÁ ÒÚÓÍË
				{
					MessageBox(hDlg, "ÕÂ‚ÂÌ˚È ÙÓÏ‡Ú ÍÎ˛˜‡.  Î˛˜ ‰ÓÎÊÂÌ ·˚Ú¸ ˆÂÎ˚Ï ˜ËÒÎÓÏ", "—ÓÓ·˘ÂÌËÂ Ó ÌÂ‚ÂÌÓÏ ÙÓÏ‡ÚÂ ÍÎ˛˜‡", MB_OK | MB_ICONHAND);
					return (INT_PTR)TRUE; // ¬˚ıÓ‰ ·ÂÁ Á‡Í˚ÚËˇ ‰Ë‡ÎÓ„Ó‚Ó„Ó ÓÍÌ‡

				}

			}
			EndDialog(hDlg, LOWORD(wParam)); // «‡Í˚ÚËÂ ‰Ë‡ÎÓ„Ó‚Ó„Ó ÓÍÌ‡
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

