#include <Windows.h>

#define W_WIDTH 640
#define W_HEIGHT 480

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow)
{
	UNREFERENCED_PARAMETER(prevInstance);
	UNREFERENCED_PARAMETER(cmdLine);

	WNDCLASSEX wndClass = { 0 };
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hInstance = hInstance;
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = "DXSample01";
	wndClass.hIcon = LoadIcon(hInstance, IDI_WINLOGO);

	if (!RegisterClassEx(&wndClass))
	{
		return -1;
	}

	RECT rect = { 0, 0, W_WIDTH, W_HEIGHT };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	HWND hwnd = CreateWindow("DXSample01", "DX11 Sample Base", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 
							  (rect.right - rect.left), (rect.bottom - rect.top), NULL, NULL, hInstance, NULL);

	DWORD error = GetLastError();


	if (!hwnd)
		return -1;

	ShowWindow(hwnd, cmdShow);

	MSG msg = { 0 };

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//Update
			//Draw
		}
	}


	return static_cast<int>(msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT paintStruct;
	HDC hdc;

 	switch (msg)
	{
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &paintStruct);
			EndPaint(hwnd, &paintStruct);
			break;

		case WM_DESTROY:
			PostQuitMessage(NULL);
			break;

		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
			break;

	}

	return 0;
}