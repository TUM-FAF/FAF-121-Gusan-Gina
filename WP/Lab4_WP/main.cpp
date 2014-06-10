#include <iostream>
#include <windows.h>
#include <cmath>

#define ID_TIMER 001

using namespace std;

class animObj{

protected:
    COLORREF clr;
public:
    POINT center;
    int xSpeed,ySpeed;

    animObj(POINT center,const int &speed);
    bool Accelerate(const int& deltaSpeedX,const int& deltaSpeedY);
    bool Color(const COLORREF &clr);
    bool Collision(const RECT &rect);
    virtual bool Move(const HDC &hdc,const RECT& rect,HBRUSH &hBrush)=0;
};

class Circle : public animObj {
public:
    Circle(POINT center,const int &speed): animObj(center,speed)
    {
        cout<<" Another ball! ";
    }
    bool Move(const HDC &hdc,const RECT& rect,HBRUSH &hBrush);
};
    bool Interaction(animObj &alfa,animObj &beta);


LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

static animObj *obj[50];
char szClassName[ ] = "Lab4_WP";

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nCmdShow)
{
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;

    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;         // Catching double-clicks
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);


    if (!RegisterClassEx (&wincl))
        return 0;

       hwnd = CreateWindowEx (
           0,
           szClassName,
           "Laboratory Work Nr.4",
           WS_OVERLAPPEDWINDOW,
           CW_USEDEFAULT,
           CW_USEDEFAULT,
           700,
           700,
           HWND_DESKTOP,
           NULL,
           hThisInstance,
           NULL
           );

    ShowWindow (hwnd, nCmdShow);

    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}


LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HDC hdc;
    static HDC hdcMem;
    static PAINTSTRUCT ps;
    static RECT rect;
    static HBRUSH hBrush;
    static HBITMAP hndbmMem;
    static HANDLE hndOld;
    static int timerSpeed=50;
    static int nrObj=0;


    switch (message)
    {
          case WM_CREATE:

            hdc=GetDC(hwnd);
            GetClientRect(hwnd,&rect);
            hdcMem=CreateCompatibleDC(hdc);
            hndbmMem=CreateCompatibleBitmap(hdc,rect.right,rect.bottom);
            hndOld = SelectObject(hdcMem,hndbmMem);
            SetTimer(hwnd,ID_TIMER,timerSpeed,NULL);
            break;


        case WM_SIZE:

            SelectObject(hdcMem,hndOld);
            DeleteObject(hndbmMem);
            DeleteDC(hdcMem);
            hdc=GetDC(hwnd);
            GetClientRect(hwnd,&rect);
            hdcMem=CreateCompatibleDC(hdc);
            hndbmMem=CreateCompatibleBitmap(hdc,rect.right,rect.bottom);
            hndOld = SelectObject(hdcMem,hndbmMem);
            break;


        case WM_LBUTTONDOWN:

            POINT newCenter;
            newCenter.x=LOWORD(lParam);
            newCenter.y=HIWORD(lParam);

            obj[nrObj]=new Circle(newCenter,5+newCenter.x%5);
            obj[nrObj]->Color(RGB(newCenter.x%255,newCenter.x%125+newCenter.y%125,newCenter.y%255));
            nrObj++;
            break;


        case WM_MOUSEWHEEL:
            //Checks if the mousewheel was scrolled down and decreases the speed and increases otherwise
            if((short)HIWORD(wParam)<0) {
                timerSpeed+=10;
            }else {
                timerSpeed-=10;
            //Checks to see if the delay time isn't negative
                if (timerSpeed<0) timerSpeed=1;
            }
            //Resets the timer
            KillTimer(hwnd,ID_TIMER);
            SetTimer(hwnd,ID_TIMER,timerSpeed,NULL);
            break;


        case WM_PAINT:

            hdc=BeginPaint(hwnd,&ps);
            GetClientRect(hwnd,&rect);

            //Checks for interaction between all the objects in the array
            for(int i=0;i<nrObj-1;i++) {
                for(int j=i+1;j<nrObj;j++) {
                    Interaction(*obj[i],*obj[j]);
                }
            }

            FillRect(hdcMem,&rect,(HBRUSH)GetStockObject(GRAY_BRUSH));

            //Redraws all the objects in the array
            for(int i=0;i<nrObj;i++) {
                obj[i]->Move(hdcMem,rect,hBrush);
            }

            //Bit-block transfer of the color data
            BitBlt(hdc,0,0,rect.right,rect.bottom,hdcMem,0,0,SRCCOPY);
            EndPaint(hwnd,&ps);
            break;


        case WM_TIMER:

            InvalidateRect(hwnd,NULL,FALSE);
            break;


        case WM_DESTROY:


            SelectObject(hdcMem,hndOld);
            DeleteObject(hndbmMem);
            DeleteDC(hdcMem);
            KillTimer(hwnd,ID_TIMER);

            PostQuitMessage (0);
            break;

        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}


//The constructor for the objects class instances
animObj::animObj(POINT center,const int &speed) {

    this->center=center;
    this->xSpeed=speed;
    this->ySpeed=speed;
    clr=RGB(0,0,0);

}

//The function what will change the speed of the balls when needed
bool animObj::Accelerate(const int& deltaSpeedX,const int& deltaSpeedY) {
    xSpeed=deltaSpeedX;
    ySpeed=deltaSpeedY;
    return TRUE;
}

//The function that sets the color
bool animObj::Color(const COLORREF &clr) {
    this->clr=clr;
    return TRUE;
}

//The function that redraws the circle in a new position
bool Circle::Move(const HDC &hdc,const RECT& rect,HBRUSH &hBrush) {

    hBrush=CreateSolidBrush(clr);
    SelectObject(hdc,hBrush);
    Collision(rect);     //The check for collision
    center.x+=xSpeed;   //The increment of the position
    center.y+=ySpeed;
    Ellipse(hdc,center.x-40,center.y-40,center.x+40,center.y+40);   // Drawing process
    SelectObject(hdc,GetStockObject(WHITE_BRUSH));
    DeleteObject(hBrush);
    return TRUE;

}
//The function that checks for collision and changes the direction in case it happened
bool animObj::Collision(const RECT &rect) {

    if(center.x+20>rect.right-1)
        {
            xSpeed=-abs(xSpeed);
                }

    if(center.x-20<rect.left+1)
        {
            xSpeed=abs(xSpeed);
                }

    if(center.y+20>rect.bottom-1)
        {
            ySpeed=-abs(ySpeed);
                }

    if(center.y-20<rect.top+1)
        {
            ySpeed=abs(ySpeed);
                }

    return TRUE;
}

//Function that checks if there was a interaction between 2 balls
bool Interaction(animObj &alfa,animObj &beta) {

    float distance;
    POINT totalSpeed;

    //Checks the distance between the balls
    distance=sqrt( pow(alfa.center.x-beta.center.x,2)+ pow(alfa.center.y-beta.center.y,2) );

    //If the distance is smaller than twice the diameter changes direction of the balls
    if ( distance < 85 ) {

    //Calculates total speed and divides it equaly between the balls
    totalSpeed.x=(abs(alfa.xSpeed)+abs(beta.xSpeed))/2;
    totalSpeed.y=(abs(alfa.ySpeed)+abs(beta.ySpeed))/2;

    //Gives the balls a new direction and speed
    alfa.Accelerate(-alfa.xSpeed*totalSpeed.x/abs(alfa.xSpeed),-alfa.ySpeed*totalSpeed.y/abs(alfa.ySpeed));
    beta.Accelerate(-beta.xSpeed*totalSpeed.x/abs(beta.xSpeed),-beta.ySpeed*totalSpeed.y/abs(beta.ySpeed));

    //Changes the color of one of the balls on interaction
    alfa.Color(RGB(totalSpeed.x*20%255,totalSpeed.x*50%255,totalSpeed.x%255));
    }

    return TRUE;
}

