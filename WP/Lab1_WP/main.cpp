#include <windows.h>
#include <stdlib.h>

#define IDC_FONT1_BUTTON 101
#define IDC_FONT2_BUTTON 102
#define IDC_FONT3_BUTTON 105
#define IDC_INPUT_EDIT	 103
#define IDC_OUTPUT_EDIT  104
#define IDC_SPB_BUTTON   106

LRESULT CALLBACK WinProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);

HINSTANCE hProgramInstance;

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR lpCmdLine,int nShowCmd)
{
    MSG msg;
	WNDCLASSEX wClass;

	wClass.cbClsExtra=0;
	wClass.cbSize=sizeof(WNDCLASSEX);
	wClass.cbWndExtra=0;
	wClass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
	wClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	wClass.hIcon=NULL;
	wClass.hIconSm=NULL;
	wClass.hInstance=hInst;
	wClass.lpfnWndProc=(WNDPROC)WinProc;
	wClass.lpszClassName="Window Class";
	wClass.lpszMenuName=NULL;
	wClass.style=CS_HREDRAW|CS_VREDRAW;

	if(!RegisterClassEx(&wClass))
	return 0;

	HWND hWnd=CreateWindowEx(NULL,
			"Window Class",
			"Laboratory Work Nr.1",
			WS_OVERLAPPEDWINDOW,
			300,
			100,
			400,
			450,
			NULL,
			NULL,
			hProgramInstance,
			0);

    ShowWindow(hWnd,nShowCmd);


	while(GetMessage(&msg,NULL,0,0))
    {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
    }

	return 0;
}

LRESULT CALLBACK WinProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{   const char * maxim = "MAXIMIZE";
    const char * restore = "RESTORE";
    const char * minim = "MINIMIZE";
    const char * close = "CLOSE";
    char szInputName[10], szOutputName[11];
    static int cxChar, cyChar;
    static HWND hwndInputText,hwndOutputText;
    static HWND hwndDefaultButton,hwndComicButton;
    static HWND hwndChaparralButton,hwndSpecialButton;
    int iScreenW,iScreenH;
    int iClientW,iClientH;
    int iTextLength;
    char * szText;
    HDC hdc;
    HFONT hfFont;
    RECT rct;
    PAINTSTRUCT ps;
    HGDIOBJ hfDefault,hfButtons,hfSButton;


	switch(msg)
	{
		case WM_CREATE:

		    cxChar = LOWORD (GetDialogBaseUnits ());
            cyChar = HIWORD (GetDialogBaseUnits ());

            iScreenW = GetSystemMetrics(SM_CXSCREEN);
            iScreenH = GetSystemMetrics(SM_CYSCREEN);

            GetClientRect(hWnd, &rct);
            iClientW = rct.right - rct.left;
            iClientH = rct.bottom - rct.top;


			hwndInputText=CreateWindowEx(
                (DWORD)NULL,
				TEXT("EDIT"),
                TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE,
				iClientW * 10/100,
				iClientH * 15/100,
				iClientW * 70/100,
				iClientH * 30/100,
				hWnd,
				(HMENU)IDC_INPUT_EDIT,
				hProgramInstance,
				NULL);

			hfDefault = CreateFont(14,0,0,0,0,0,0,0,0,0,0,0,0,TEXT("Consolas"));
            SendMessage(hwndInputText,WM_SETFONT,(WPARAM)hfDefault,MAKELPARAM(FALSE,0));
            SendMessage(hwndInputText,WM_SETTEXT,NULL,(LPARAM)"Insert text here...");


            hwndOutputText=CreateWindowEx(
                (DWORD)NULL,
				TEXT("EDIT"),
				TEXT(""),
				WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | ES_READONLY | ES_MULTILINE,
				iClientW * 10/100,
                iClientH * 45/100,
                iClientW * 80/100,
                iClientH *60/100,
				hWnd,
				(HMENU)IDC_OUTPUT_EDIT,
				hProgramInstance,
				NULL);


			hwndDefaultButton=CreateWindowEx(
                (DWORD)NULL,
                TEXT("button"),
                TEXT("Default"),
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                50, 300,
                60, 20,
                hWnd,
                (HMENU)IDC_FONT1_BUTTON,
                hProgramInstance,
                NULL);

            hfButtons = CreateFont(16,0,0,0,0,0,0,0,0,0,0,0,0,TEXT("CASTELLAR"));
            SendMessage(hwndDefaultButton,WM_SETFONT,(WPARAM)hfButtons,MAKELPARAM(FALSE,0));

            hwndComicButton=CreateWindowEx(
                (DWORD)NULL,
                TEXT("button"),
                TEXT("Comic"),
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                150, 300,
                60, 20,
                hWnd,
                (HMENU)IDC_FONT2_BUTTON,
                hProgramInstance,
                NULL);

            SendMessage(hwndComicButton,WM_SETFONT,(WPARAM)hfButtons,MAKELPARAM(FALSE,0));


            hwndChaparralButton=CreateWindowEx(
                (DWORD)NULL,
                TEXT("button"),
                TEXT("Chaparral"),
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                250, 300,
                70, 20,
                hWnd,
                (HMENU)IDC_FONT3_BUTTON,
                hProgramInstance,
                NULL);

            SendMessage(hwndChaparralButton,WM_SETFONT,(WPARAM)hfButtons,MAKELPARAM(FALSE,0));


            hwndSpecialButton=CreateWindowEx(
                (DWORD)NULL,
                TEXT("button"),
                TEXT("Special button"),
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                125, 350,
                110, 30,
                hWnd,
                (HMENU)IDC_SPB_BUTTON,
                hProgramInstance,
                NULL);

            hfSButton = CreateFont(18,0,0,0,0,0,0,0,0,0,0,0,0,TEXT("Broadway"));
            SendMessage(hwndSpecialButton,WM_SETFONT,(WPARAM)hfSButton,MAKELPARAM(FALSE,0));

            break;


        case WM_PAINT:

            strcpy(szInputName, "Input Box");
            strcpy(szOutputName, "Output Box");

            GetClientRect(hWnd, &rct);
            iClientW = rct.right - rct.left;
            iClientH = rct.bottom - rct.top;

            hdc = BeginPaint(hWnd, &ps);
            SetTextColor(hdc, RGB(59,79,250));
            TextOut (hdc, iClientW * 40/100, iClientH * 8/100, szInputName, 9);
            TextOut (hdc, iClientW * 40/100, iClientH * 39/100, szOutputName, 10);
            EndPaint(hWnd, &ps);
            break;


        case WM_CTLCOLOREDIT:

            hdc = (HDC)wParam;
            SetTextColor(hdc, RGB(200,40,40));
            break;


        case WM_SIZE:
            GetClientRect(hWnd, &rct);
            iClientW = rct.right - rct.left;
            iClientH = rct.bottom - rct.top;

            MoveWindow(hwndInputText,
                iClientW * 1/10,
                iClientH * 15/100,
                iClientW * 8/10,
                iClientH * 15/100,
                TRUE);

            MoveWindow(hwndOutputText,
                iClientW * 1/10,
                iClientH * 45/100,
                iClientW * 8/10,
                iClientH * 20/100,
                TRUE);

            MoveWindow(hwndDefaultButton,
                iClientW * 6/100,
                iClientH * 70/100,
                iClientW * 25/100,
                iClientH * 8/100,
                TRUE);

            MoveWindow(hwndComicButton,
                       iClientW * 38/100,
                       iClientH * 7/10,
                       iClientW * 25/100,
                       iClientH * 8/100,
                       TRUE);

            MoveWindow(hwndChaparralButton,
                       iClientW * 7/10,
                       iClientH * 7/10,
                       iClientW * 25/100,
                       iClientH * 8/100,
                       TRUE);

            MoveWindow(hwndSpecialButton,
                       iClientW * 33/100,
                       iClientH * 82/100,
                       iClientW * 35/100,
                       iClientH * 10/100,
                       TRUE);

        case WM_GETMINMAXINFO:

                LPMINMAXINFO pMMInfo;
                POINT minSize;
                pMMInfo = (LPMINMAXINFO)lParam;
                rct.left = 0;
                rct.top = 0;
                rct.right = 400;
                rct.bottom = 450;

                AdjustWindowRectEx(&rct, WS_OVERLAPPEDWINDOW, FALSE, WS_EX_OVERLAPPEDWINDOW);

                minSize.x = rct.right - rct.left;
                minSize.y = rct.bottom - rct.top;

                pMMInfo->ptMinTrackSize = minSize;

		case WM_COMMAND:

			switch(LOWORD(wParam))
            {
				case IDC_FONT1_BUTTON:

				    hfFont = CreateFont(20,0,0,0,0,0,0,0,0,0,0,0,20,TEXT("Consolas"));
                    SendMessage(hwndOutputText, WM_SETFONT, (WPARAM)hfFont, 1);

					iTextLength = SendMessage(hwndInputText, WM_GETTEXTLENGTH, 0, 0);
                    szText = (char*)malloc(iTextLength+1);
                    SendMessage(hwndInputText, WM_GETTEXT, iTextLength+1, (LPARAM)szText);
                    SendMessage(hwndOutputText, WM_SETTEXT, 0, (LPARAM)szText);
                    free(szText);
                    break;

                case IDC_FONT2_BUTTON:

                    hfFont = CreateFont(0,0,0,0,0,0,0,0,0,0,0,0,0,TEXT("Comic Sans MS"));
                    SendMessage(hwndOutputText, WM_SETFONT, (WPARAM)hfFont, 1);

                    iTextLength = SendMessage(hwndInputText, WM_GETTEXTLENGTH, 0, 0);
                    szText = (char*)malloc(iTextLength+1);
                    SendMessage(hwndInputText, WM_GETTEXT, iTextLength+1, (LPARAM)szText);
                    SendMessage(hwndOutputText, WM_SETTEXT, 0, (LPARAM)szText);
                    free(szText);
                    break;

                case IDC_FONT3_BUTTON:

                    hfFont = CreateFont(0,0,0,0,0,0,0,0,0,0,0,0,0,TEXT("Chaparral Pro Light"));
                    SendMessage(hwndOutputText, WM_SETFONT, (WPARAM)hfFont, 1);

                    iTextLength = SendMessage(hwndInputText, WM_GETTEXTLENGTH, 0, 0);
                    szText = (char*)malloc(iTextLength+1);
                    SendMessage(hwndInputText, WM_GETTEXT, iTextLength+1, (LPARAM)szText);
                    SendMessage(hwndOutputText, WM_SETTEXT, 0, (LPARAM)szText);
                    free(szText);
                    break;

                case IDC_SPB_BUTTON:

                    iTextLength = SendMessage(hwndInputText, WM_GETTEXTLENGTH, 0, 0);
                    szText = (char*)malloc(iTextLength+1);
                    SendMessage(hwndInputText, WM_GETTEXT, iTextLength+1, (LPARAM)szText);

                    if ( strcmp( maxim,szText ) == 0 )
                    ShowWindow (hWnd, SW_MAXIMIZE);

                    if ( strcmp( restore,szText ) == 0 )
                    ShowWindow (hWnd, SW_RESTORE);

                    if ( strcmp( minim,szText ) == 0 )
                    ShowWindow (hWnd, SW_MINIMIZE);

                    if ( strcmp( close,szText ) == 0 )
                    ShowWindow (hWnd, SW_HIDE);
                    break;


    default:return DefWindowProc(hWnd,msg,wParam,lParam);
            }
            break;

        case WM_DESTROY:

			PostQuitMessage(0);
            break;

    default:return DefWindowProc(hWnd,msg,wParam,lParam);
	}
}
