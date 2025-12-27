#include<Windows.h>

int Width = 1280;
int Height = 720;
HBRUSH Hbr = (HBRUSH)GetStockObject(BLACK_BRUSH);
HWND Hwnd;
bool Full = false;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (uMsg == WM_DESTROY)
	{
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = L"Dx12Wnd";
	wc.hInstance = GetModuleHandle(NULL);
	wc.hbrBackground = Hbr;

	DWORD style = WS_OVERLAPPEDWINDOW;
	int width = Width;
	int	height = Height;
	if (Full) {
		style = WS_POPUP;
		width = GetSystemMetrics(SM_CXSCREEN);
		height = GetSystemMetrics(SM_CYSCREEN);
	}

	RegisterClassEx(&wc);
	RECT rect = { 0, 0, width, height };
	AdjustWindowRect(&rect, style, FALSE);

	Hwnd = CreateWindowEx(
		0,
		wc.lpszClassName,
		L"DirectX 12 Window",
		style,
		CW_USEDEFAULT, CW_USEDEFAULT,
		rect.right - rect.left,
		rect.bottom - rect.top,
		NULL,
		NULL,
		wc.hInstance,
		NULL
	);

	ShowWindow(Hwnd, SW_SHOW);


	MSG msg = {};
	while (true) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (msg.message == WM_QUIT) break;
	}
	return static_cast<int>(msg.wParam);
}