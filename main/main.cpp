#include "FileManager.h"
#include <windows.h>
#include <iostream>
#include <assert.h>

int main() 
{
    FileManager fm;
    int result = fm.LoadFile("index.txt");
    if (result == -1) {
        assert(0);
    }

    Sleep(5000);
    for (size_t i = 0; i < fm.st.size(); ++i) {
        for (char c : fm.st[i]) {
            INPUT ip;
            ip.type = INPUT_KEYBOARD;
            ip.ki.wScan = c;
            ip.ki.time = 0;
            ip.ki.dwExtraInfo = 0;
            ip.ki.wVk = 0;
            ip.ki.dwFlags = KEYEVENTF_UNICODE;
            SendInput(
                1,
                &ip,
                sizeof(INPUT));
            Sleep(20);
        }
        INPUT ip;
        ip.type = INPUT_KEYBOARD;
        ip.ki.wScan = 0;
        ip.ki.time = 0;
        ip.ki.dwExtraInfo = 0;
        ip.ki.wVk = VK_RETURN;
        ip.ki.dwFlags = 0;
        SendInput(
            1,
            &ip,
            sizeof(INPUT));
        Sleep(100);
    }
    
    return 0;
}