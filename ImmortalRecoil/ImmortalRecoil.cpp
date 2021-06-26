#include <iostream>
#include <windows.h>

bool activated = false;
bool run = true;
float cps = 0;
float tim = 50;
RECT rect = { 0 };
POINT lp;

bool test() {

    if ((GetKeyState(VK_INSERT) & 0x8000) != 0) {
        if (activated == false) {
            activated = true;

            std::cout << "activated = true\n";
            Sleep(100);
            return true;
        }
        else if (activated == true) {
            activated = false;

            std::cout << "activated = false\n";
            Sleep(100);
            return false;
        }
    }
}

int main()
{
    SetConsoleTitle(TEXT("Spotify"));

    std::cout << "Hello World!\n";
    std::cout << "Base cps is 8cps\n";
    std::cout << "Enter your max cps : ";
    std::cin >> cps;
    
    if (cps != 0){
        tim = 1 / cps;
        tim = tim * 1000;
        tim = floor(tim);
        tim = tim / 2;
        tim = tim - 5;
    }

    DWORD dt = (DWORD)tim;

    std::cout << "Press insert to activate / disactivate";
    while (run) {
        Sleep(dt);
        
        GetCursorPos(&lp);

        rect.right = lp.x;
        rect.bottom = lp.y;

        if (test() && (GetKeyState(VK_LBUTTON) & 0x8000) != 0) { 
            Sleep(dt);
            std::cout << "lbutton pressed\n";
            /*SetCursorPos(rect.right, rect.bottom + 2);*/
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
    }
}



