#include <windows.h>
#include <iostream>
using namespace std;

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}

int main()
{
	char definest;
	int win_col;
	int num_1;
	int num_2;
	int num_3;
	int num_4;
	int num_list[10005];
	cout << "welcome to the cauculator!" <<endl; 
	cout << "press i to check the instructions." <<endl;
	while (true)
	{
		cin >> definest;
		if (definest == 'i') cout << "press p for plus, s for subtract, m for multiple, d for divition, r for sevral multipules, c for color" <<endl; 
		if (definest == 'c')
		{
			char defc; 
			cout << "press w to check the further instructions, o to continue" <<endl;
			cin >> defc;
			if (defc == 'o')
			{
				cout << "please input the color number" <<endl;
				cin >> win_col;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),win_col);
			}
		}
		if (definest == 'p')
		{
			cout << "please input the numbers" <<endl;
			cin >> num_1;
			cin >> num_2;
			cout << num_1 + num_2 <<endl;
		}
		if (definest == 's')
		{
			cout << "please input the numbers" <<endl;
			cin >> num_1;
			cin >> num_2;
			cout << num_1 - num_2 <<endl;
		}
		if (definest == 'm')
		{
			cout << "please input the numbers" <<endl;
			cin >> num_1;
			cin >> num_2;
			cout << num_1 * num_2 <<endl;
		}
		if (definest == 'd')
		{
			cout << "please input the numbers" <<endl;
			cin >> num_1;
			cin >> num_2;
			cout << num_1 / num_2 <<endl;
		}
		if (definest == 'r')
		{
			cout << "please input the numbers" <<endl;
			cin >> num_1;
			cin >> num_2;
			cout << "how many times?" <<endl;
			cin >> num_3;
			for (int i = 0; i <= num_3; i++)
			{
				num_4 = num_1 * num_2;
			}
			cout << num_4 <<endl;
		}
		if 
	}
}
