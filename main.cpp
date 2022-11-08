#include "head.h"
#include<tchar.h>

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
    if(message==WM_DESTROY)
        PostQuitMessage(0);
    else if(message==WM_QUIT)
        DestroyWindow(hwnd);
    return DefWindowProc(hwnd,message,wParam,lParam);
}
BOOL RegisterWindow(HINSTANCE hInstance)
{
    WNDCLASSEX wnd;
    wnd.hbrBackground=(HBRUSH)COLOR_WINDOW;
    wnd.lpfnWndProc=WndProc;
    wnd.style=CS_HREDRAW|CS_VREDRAW;
    wnd.lpszClassName=_T("WindowClass");
    wnd.hInstance=hInstance;
    wnd.hIcon=LoadIcon(hInstance,IDI_APPLICATION);
    wnd.hIconSm=LoadIcon(hInstance,IDI_APPLICATION);
    wnd.hCursor=LoadCursor(hInstance,IDC_ARROW);
    wnd.cbSize=sizeof(WNDCLASSEX);
    wnd.lpszMenuName=nullptr;
    wnd.cbClsExtra=0;
    wnd.cbWndExtra=0;
    return RegisterClassEx(&wnd);
}
BOOL DisplayWindow(HWND& hwnd,HINSTANCE hInstance,HMENU hMenu,int nCmdShow)
{
    hwnd=CreateWindow(_T("WindowClass"),_T("TweeChaice"),WS_OVERLAPPEDWINDOW,0,0,800,800,
                      nullptr,nullptr,hInstance,nullptr
    );
    ShowWindow(hwnd,nCmdShow);
    return hwnd?TRUE:FALSE;
}
 
HWND hwnd;
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
    if(!RegisterWindow(hInstance))
    {
        MessageBox(nullptr,_T("Error register!"),_T("Error"),MB_ICONERROR|MB_OK);
        return -1;
    }
    if(!DisplayWindow(hwnd,hInstance,nullptr,nCmdShow))
    {
        MessageBox(nullptr,_T("Error creating window!"),_T("Error"),MB_ICONERROR|MB_OK);
        return -1;
    }
    MSG msg;
    while(GetMessage(&msg,0,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}


class A{
    A(){
        
    }
}