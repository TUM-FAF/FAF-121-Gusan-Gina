
#include <windows.h>
#include "resource.h"


LRESULT CALLBACK WndProc      (HWND, UINT, WPARAM, LPARAM) ;
BOOL    CALLBACK AboutDlgProc (HWND, UINT, WPARAM, LPARAM) ;
BOOL    CALLBACK ColorScrDlg  (HWND, UINT, WPARAM, LPARAM) ;

HWND hDlgModeless = NULL;

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
     static TCHAR szClassName[] = TEXT ("Laboratory Work Nr.2") ;
     MSG            msg ;
     HWND           hwnd ;
     WNDCLASSEX     wincl ;

    wincl.hInstance = hInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WndProc;
    wincl.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (NULL, IDI_INFORMATION);
    wincl.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_IC1));
    wincl.hCursor = LoadCursor (hInstance, MAKEINTRESOURCE(IDC_CUR1));
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = CreateSolidBrush(0) ;

     if (!RegisterClassEx (&wincl))
     {
          MessageBox (NULL, TEXT ("The class wasn't registered!"),
                      szClassName, MB_ICONERROR) ;
          return 0 ;
     }

     hwnd = CreateWindow (szClassName, TEXT ("Laboratory Work Nr.2"),
                          WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          600, 400,
                          NULL, NULL, hInstance, NULL) ;

     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;

    while (GetMessage (&msg, NULL, 0, 0))
     {
         if(hDlgModeless == 0 || !IsDialogMessage (hDlgModeless, &msg))
         {
             TranslateMessage (&msg) ;
            DispatchMessage (&msg) ;
         }
     }
     return msg.wParam ;
}

LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND hwndHeightScroll;
    static HWND hwndWidthScroll;
    static HWND hwndListBox;
    static HWND hwndInput;
    static HWND hwndAddBtn;
    static HWND hwndClearBtn;
    static HWND hwndRemoveBtn;
    static HINSTANCE hInstance ;

    char szInputName[10];
    char szListName[9];
    char*            szText;

    HDC              hdc;
    RECT             rect;
    PAINTSTRUCT      ps ;
    SCROLLINFO       scrinf;

    int              iTextLength;
    int cxChar, cyChar;
    int iSysWidth, iSysHeight;
    int iWinWidth, iWinHeight;
    int iWidth, iHeight;
    int x, y, i;

     switch (message)
     {
     case WM_CREATE :

            hwndListBox = CreateWindowEx(
                (DWORD)NULL,
                TEXT("ListBox"),
                NULL,
                WS_CHILD | WS_VISIBLE | WS_BORDER | LBS_NOTIFY | LBS_WANTKEYBOARDINPUT | WS_VSCROLL,
                300, 40, 250, 100,
                hwnd,
                (HMENU)IDC_LIST_BOX,
                hInstance,
                NULL);

            hwndInput = CreateWindowEx(
                (DWORD)NULL,
                TEXT("Edit"),
                TEXT("Add text here.."),
                WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL,
                20, 40, 250, 100,
                hwnd,
                (HMENU)IDC_INPUT,
                hInstance,
                NULL);

            hwndAddBtn=CreateWindowEx(
                (DWORD)NULL,
                TEXT("button"),
                TEXT("Add item"),
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                60, 180, 100, 30,
                hwnd,
                (HMENU)IDC_ADD_BTN,
                hInstance,
                NULL);

            hwndClearBtn=CreateWindowEx(
                (DWORD)NULL,
                TEXT("button"),
                TEXT("Clear all"),
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                400, 180, 100, 30,
                hwnd,
                (HMENU)IDC_CLEAR_BTN,
                hInstance,
                NULL);

            hwndRemoveBtn=CreateWindowEx(
                (DWORD)NULL,
                TEXT("button"),
                TEXT("Remove item"),
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                230, 180, 100, 30,
                hwnd,
                (HMENU)IDC_REMOVE_BTN,
                hInstance,
                NULL);

            hwndWidthScroll = CreateWindow(
                "Scrollbar",
                NULL,
                WS_CHILD | WS_VISIBLE | SBS_HORZ | SBS_BOTTOMALIGN,
                20, 220, 550, 30, hwnd,
                (HMENU)IDC_WSCROLL,
                hInstance,
                NULL);
            SetScrollRange(hwndWidthScroll, SB_CTL, 0, 100, TRUE);

            hwndHeightScroll = CreateWindow(
                "Scrollbar",
                NULL,
                WS_CHILD | WS_VISIBLE | SBS_HORZ | SBS_BOTTOMALIGN,
                20, 260, 550, 30, hwnd,
                (HMENU)IDC_HSCROLL,
                hInstance,
                NULL);
            SetScrollRange(hwndHeightScroll, SB_CTL, 0, 100, TRUE);


            HMENU hMenu;
            HMENU hSubMenu;

            hMenu = CreateMenu();

            hSubMenu = CreatePopupMenu();
            AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&File");
            AppendMenu(hSubMenu, MF_STRING, IDC_FILE, "&Exit");

            hSubMenu = CreatePopupMenu();
            AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&View");
            AppendMenu(hSubMenu, MF_STRING, IDC_BACKGROUND, "&Properties");

            hSubMenu = CreatePopupMenu();
            AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)hSubMenu, "&Help");
            AppendMenu(hSubMenu, MF_STRING, IDC_HELP, "&About");

            SetMenu(hwnd, hMenu);
            hInstance = ((LPCREATESTRUCT) lParam)->hInstance ;
            break;

      case WM_PAINT:

            strcpy(szInputName, "Input Box");
            strcpy(szListName, "List Box");

            GetClientRect(hwnd, &rect);
            iWinWidth = rect.right - rect.left;
            iWinHeight = rect.bottom - rect.top;

            hdc = BeginPaint(hwnd, &ps);
            SetTextColor(hdc, RGB(0, 0, 255));
            TextOut (hdc, iWinWidth * 20/100, iWinHeight* 5/100, szInputName, 9);
            TextOut (hdc, iWinWidth * 66/100, iWinHeight * 5/100, szListName, 8);
            EndPaint(hwnd, &ps);
            break;

     case WM_SIZE:

            iWidth  = LOWORD(lParam);
            iHeight = HIWORD(lParam);

            GetWindowRect(hwnd, &rect);
            iWinWidth = rect.right - rect.left;
            iWinHeight = rect.bottom - rect.top;
            iSysWidth = GetSystemMetrics(SM_CXSCREEN);
            iSysHeight = GetSystemMetrics(SM_CYSCREEN);

            MoveWindow(hwndWidthScroll,
                        iWinWidth * 5/100,
                        iWinHeight * 58/100,
                        iWinWidth * 86/100,
                        iWinHeight * 7/100,
                        TRUE);

            MoveWindow(hwndHeightScroll,
                        iWinWidth * 5/100,
                        iWinHeight * 70/100,
                        iWinWidth * 86/100,
                        iWinHeight * 7/100,
                        TRUE);

            MoveWindow(hwndAddBtn,
                        iWinWidth * 5/100,
                        iWinHeight * 40/100,
                        iWinWidth * 25/100,
                        iWinHeight * 6/100,
                        TRUE);

            MoveWindow(hwndClearBtn,
                       iWinWidth * 65/100,
                       iWinHeight * 40/100,
                       iWinWidth * 25/100,
                       iWinHeight * 6/100,
                       TRUE);

            MoveWindow(hwndRemoveBtn,
                       iWinWidth * 35/100,
                       iWinHeight * 40/100,
                       iWinWidth * 25/100,
                       iWinHeight * 6/100,
                       TRUE);

            MoveWindow(hwndInput,
                       iWinWidth * 5/100,
                       iWinHeight * 10/100,
                       iWinWidth * 40/100,
                       iWinHeight * 20/100,
                       TRUE);

            MoveWindow(hwndListBox,
                       iWinWidth * 50/100,
                       iWinHeight * 10/100,
                       iWinWidth * 40/100,
                       iWinHeight * 21/100,
                       TRUE);

            SetScrollPos(hwndWidthScroll, SB_CTL, (iWinWidth * 100 / iSysWidth), TRUE);
            SetScrollPos(hwndHeightScroll, SB_CTL, (iWinHeight * 100 / iSysHeight), TRUE);

            break;

        case WM_VSCROLL:

            scrinf.cbSize = sizeof(scrinf);
            scrinf.fMask = SIF_ALL;
            GetScrollInfo(hwnd, SB_VERT, &scrinf);
            y = scrinf.nPos;

            switch(LOWORD(wParam)) {
                case SB_TOP:
                    scrinf.nPos = scrinf.nMin;
                    break;

                case SB_BOTTOM:
                    scrinf.nPos = scrinf.nMax;
                    break;

                case SB_LINEUP:
                    scrinf.nPos -= 1;
                    break;

                case SB_LINEDOWN:
                    scrinf.nPos += 1;
                    break;

                case SB_PAGEUP:
                    scrinf.nPos -= scrinf.nPage;
                    break;

                case SB_PAGEDOWN:
                    scrinf.nPos += scrinf.nPage;
                    break;

                case SB_THUMBTRACK:
                    scrinf.nPos = scrinf.nTrackPos;
                    break;

                default:
                    break;
            }

            scrinf.fMask = SIF_POS;
            SetScrollInfo(hwnd, SB_VERT, &scrinf, TRUE);
            GetScrollInfo(hwnd, SB_VERT, &scrinf);

            if(scrinf.nPos != y) {
                ScrollWindow(hwnd, 0, cyChar * (y - scrinf.nPos), NULL, NULL);
                UpdateWindow(hwnd);
            }
            break;

        case WM_HSCROLL:

            GetWindowRect(hwnd, &rect);
            iWinWidth = rect.right - rect.left;
            iWinHeight = rect.bottom - rect.top;
            iSysWidth = GetSystemMetrics(SM_CXSCREEN);
            iSysHeight = GetSystemMetrics(SM_CYSCREEN);

            if(GetWindowLong((HWND)lParam, GWL_ID) == IDC_WSCROLL) {
                scrinf.cbSize = sizeof(scrinf);
                scrinf.fMask = SIF_ALL;
                GetScrollInfo(hwndWidthScroll, SB_CTL, &scrinf);
                x = scrinf.nPos;

                switch(LOWORD(wParam)) {
                    case SB_LINELEFT:
                        scrinf.nPos -= 1;
                        break;
                    case SB_LINERIGHT:
                        scrinf.nPos += 1;
                        break;
                    case SB_THUMBPOSITION:
                        scrinf.nPos = scrinf.nTrackPos;
                        break;
                    default:
                        break;
                }
                scrinf.fMask = SIF_POS;
                SetScrollInfo(hwndWidthScroll, SB_CTL, &scrinf, TRUE);
                GetScrollInfo(hwndWidthScroll, SB_CTL, &scrinf);
                if(scrinf.nPos != x) {
                    SetScrollPos(hwndWidthScroll, SB_CTL, scrinf.nPos, TRUE);
                }

                MoveWindow(hwnd, rect.left, rect.top, (scrinf.nPos * iSysWidth / 100), iWinHeight, TRUE);
                break;
            }

            if(GetWindowLong((HWND)lParam, GWL_ID) == IDC_HSCROLL) {
                scrinf.cbSize = sizeof(scrinf);
                scrinf.fMask = SIF_ALL;
                GetScrollInfo(hwndHeightScroll, SB_CTL, &scrinf);
                x = scrinf.nPos;
                switch(LOWORD(wParam)) {
                    case SB_LINELEFT:
                        scrinf.nPos -= 1;
                        break;
                    case SB_LINERIGHT:
                        scrinf.nPos += 1;
                        break;
                    case SB_THUMBPOSITION:
                        scrinf.nPos = scrinf.nTrackPos;
                        break;
                    default:
                        break;
                }
                scrinf.fMask = SIF_POS;
                SetScrollInfo(hwndHeightScroll, SB_CTL, &scrinf, TRUE);
                GetScrollInfo(hwndHeightScroll, SB_CTL, &scrinf);
                if(scrinf.nPos != x) {
                    SetScrollPos(hwndHeightScroll, SB_CTL, scrinf.nPos, TRUE);
                }

                MoveWindow(hwnd, rect.left, rect.top, iWinWidth, (scrinf.nPos * iSysHeight / 100), TRUE);
                break;
            }

            scrinf.cbSize = sizeof(scrinf);
            scrinf.fMask = SIF_ALL;
            GetScrollInfo(hwnd, SB_HORZ, &scrinf);
            x = scrinf.nPos;

            switch(LOWORD(wParam)) {
                case SB_LINELEFT:
                    scrinf.nPos -= 1;
                    break;

                case SB_LINERIGHT:
                    scrinf.nPos += 1;
                    break;

                case SB_PAGELEFT:
                    scrinf.nPos -= scrinf.nPage;
                    break;

                case SB_PAGERIGHT:
                    scrinf.nPos += scrinf.nPage;
                    break;

                case SB_THUMBPOSITION:
                    scrinf.nPos = scrinf.nTrackPos;
                    break;

                default:
                    break;
            }

            scrinf.fMask = SIF_POS;
            SetScrollInfo(hwnd, SB_HORZ, &scrinf, TRUE);
            GetScrollInfo(hwnd, SB_HORZ, &scrinf);

            if(scrinf.nPos != x) {
                ScrollWindow(hwnd, cxChar * (x - scrinf.nPos), 0, NULL, 0);
                UpdateWindow(hwnd);
            }
            break;


     case WM_COMMAND :
          switch (LOWORD (wParam))
          {

          case IDC_FILE:
              SendMessage(hwnd, WM_DESTROY, 0, 0);

          case IDC_HELP :
            return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)AboutDlgProc);

          case IDC_BACKGROUND:
            return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG2), NULL, (DLGPROC)ColorScrDlg);

          case IDC_ADD_BTN:
                    iTextLength = SendMessage(hwndInput, WM_GETTEXTLENGTH, 0, 0);
                    szText = (char*)malloc(iTextLength+1);
                    SendMessage(hwndInput, WM_GETTEXT, iTextLength+1, (LPARAM)szText);
                    SendMessage(hwndListBox, LB_ADDSTRING, 0, (LPARAM)szText);
                    SendMessage(hwndInput, WM_SETTEXT, 0, (LPARAM)"");
                    free(szText);
                    break;

          case IDC_CLEAR_BTN:
                    SendMessage(hwndListBox, LB_RESETCONTENT, 0, 0);
                    break;

          case IDC_REMOVE_BTN:
                    i = SendMessage(hwndListBox, LB_GETCURSEL, 0, 0);
                    if(i != LB_ERR) {
                        SendMessage(hwndListBox, LB_DELETESTRING, i, 0);
                    }
                    break;

          case IDC_LIST_BOX:
                    switch (HIWORD(wParam)) {
                        case LBN_DBLCLK:
                            MessageBox(NULL, TEXT("ListBox Double-Clicked!"), TEXT(""), MB_OK);
                            break;
                    }
                    break;

          }
             break ;

          case WM_KEYDOWN:
            GetWindowRect(hwnd, &rect);
            iWinWidth = rect.right - rect.left;
            iWinHeight = rect.bottom - rect.top;
            iSysWidth = GetSystemMetrics(SM_CXSCREEN);
            iSysHeight = GetSystemMetrics(SM_CYSCREEN);

            // Move window right
            if((wParam == VK_F1)&&(HIBYTE(GetKeyState(VK_CONTROL)) > 1)) {
                if(rect.left >= iSysWidth - iWinWidth) {
                    MoveWindow(hwnd, iSysWidth - iWinWidth, rect.top, iWinWidth, iWinHeight, TRUE);
                }
                else {
                    MoveWindow(hwnd, rect.left + 10, rect.top, iWinWidth, iWinHeight, TRUE);
                }
                break;
            }
            // Move window left
            if((wParam == VK_F2)&&(HIBYTE(GetKeyState(VK_CONTROL)) > 1)) {
                if(rect.left <= 0) {
                    MoveWindow(hwnd, 0, rect.top, iWinWidth, iWinHeight, TRUE);
                }
                else {
                    MoveWindow(hwnd, rect.left - 10, rect.top, iWinWidth, iWinHeight, TRUE);
                }
                break;
            }
            // Move window down
            if((wParam == VK_F3)&&(HIBYTE(GetKeyState(VK_CONTROL)) > 1)) {
                if(rect.top >= iSysHeight - iWinHeight) {
                    MoveWindow(hwnd, rect.left, iSysHeight - iWinHeight, iWinWidth, iWinHeight, TRUE);
                }
                else {
                    MoveWindow(hwnd, rect.left, rect.top + 10, iWinWidth, iWinHeight, TRUE);
                }
                break;
            }
            // Move window up
            if((wParam == VK_F4)&&(HIBYTE(GetKeyState(VK_CONTROL)) > 1)) {
                if(rect.top <= 0) {
                    MoveWindow(hwnd, rect.left, 0, iWinWidth, iWinHeight, TRUE);
                }
                else {
                    MoveWindow(hwnd, rect.left, rect.top - 10, iWinWidth, iWinHeight, TRUE);
                }
                break;
            }
            return DefWindowProc (hwnd, WM_PAINT, wParam, lParam);


        case WM_DESTROY :
          DeleteObject ((HGDIOBJ) SetClassLong (hwnd, GCL_HBRBACKGROUND,
                              (LONG) GetStockObject (WHITE_BRUSH))) ;
          PostQuitMessage (0) ;
          break;

     }
     return DefWindowProc (hwnd, message, wParam, lParam) ;
}

BOOL CALLBACK AboutDlgProc (HWND hDlg, UINT message,
                            WPARAM wParam, LPARAM lParam)

{
     switch (message)
     {
     case WM_INITDIALOG :
          return TRUE ;

     case WM_COMMAND :
          switch (LOWORD (wParam))
          {
          case IDOK :
          case IDCANCEL :
               EndDialog (hDlg, 0) ;
               return TRUE ;
          }
          break ;
     }
     return FALSE ;
}

BOOL CALLBACK ColorScrDlg (HWND hDialog, UINT message,
                           WPARAM wParam, LPARAM lParam)
{
     static int iColor[3] ;
     HWND       hwndParent, hCtrl ;
     int        iCtrlID, iIndex ;

     switch (message)
     {
     case WM_INITDIALOG :
          for (iCtrlID = 10 ; iCtrlID < 13 ; iCtrlID++)
          {
               hCtrl = GetDlgItem (hDialog, iCtrlID) ;
               SetScrollRange (hCtrl, SB_CTL, 0, 255, FALSE) ;
               SetScrollPos   (hCtrl, SB_CTL, 0, FALSE) ;
          }
          return TRUE ;

    case WM_COMMAND :
          switch (LOWORD (wParam))
          {
          case IDOK :
          case IDCANCEL :
               EndDialog (hDialog, 0) ;
               return TRUE ;
          }
          break ;

     case WM_VSCROLL :
          hCtrl   = (HWND) lParam ;
          iCtrlID = GetWindowLong (hCtrl, GWL_ID) ;
          iIndex  = iCtrlID - 10 ;
          hwndParent = GetParent (hDialog) ;

          switch (LOWORD (wParam))
          {
          case SB_PAGEDOWN :
               iColor[iIndex] += 15 ;
          case SB_LINEDOWN :
               iColor[iIndex] = min (255, iColor[iIndex] + 1) ;
               break ;
          case SB_PAGEUP :
               iColor[iIndex] -= 15 ;
          case SB_LINEUP :
               iColor[iIndex] = max (0, iColor[iIndex] - 1) ;
               break ;
          case SB_TOP :
               iColor[iIndex] = 0 ;
               break ;
          case SB_BOTTOM :
               iColor[iIndex] = 255 ;
               break ;
          case SB_THUMBPOSITION :
          case SB_THUMBTRACK :
               iColor[iIndex] = HIWORD (wParam) ;
               break ;

          default :
               return FALSE ;
          }
          SetScrollPos  (hCtrl, SB_CTL,      iColor[iIndex], TRUE) ;
          SetDlgItemInt (hDialog,  iCtrlID + 3, iColor[iIndex], FALSE) ;

          DeleteObject ((HGDIOBJ) SetClassLong (hwndParent, GCL_HBRBACKGROUND,
                              (LONG) CreateSolidBrush (
                                   RGB (iColor[0], iColor[1], iColor[2])))) ;

          InvalidateRect (hwndParent, NULL, TRUE) ;
          return TRUE ;
     }
     return FALSE ;
}


