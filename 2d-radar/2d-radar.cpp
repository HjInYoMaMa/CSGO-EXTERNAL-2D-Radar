#include <Windows.h>
#include "MemMan.h"
#include "Console.h"

MemMan MemClass;
namespace con = JadedHoboConsole;

//Offsets
struct offsets
{
    DWORD entityList = 0x4DDB92C;
    DWORD isSpotted = 0x93D;
} offset;

//Variables
struct variables
{
    DWORD gameModule;
} val;

int main()
{
    SetConsoleTitleA(""); //Console title
    int procID = MemClass.getProcess("csgo.exe"); //processid
    val.gameModule = MemClass.getModule(procID, "client.dll"); //module

    //Output
    std::cout << con::fg_white << "[" << con::fg_green << "+" << con::fg_white << "]" << con::fg_magenta << " Candy, everything I see it's painted candy\n" << con::fg_white;
    std::cout << "[" << con::fg_green << "+" << con::fg_white << "]" << con::fg_magenta << " 2D Radar - Activated!\n\n" << con::fg_white;

    std::cout << "[" << con::fg_green << "+" << con::fg_white << "]" << con::fg_magenta << " Build: July 3\n" << con::fg_white;
    std::cout << "[" << con::fg_green << "+" << con::fg_white << "]" << con::fg_magenta << " Made by hj.#0010\n" << con::fg_white;

    //loop
    while (true)
    {
        for (short int i = 0; i < 64; i++)
        {
            DWORD entity = MemClass.readMem<DWORD>(val.gameModule + offset.entityList + i * 0x10);
            if (entity != NULL)
                MemClass.writeMem<bool>(entity + offset.isSpotted, true);
        }
        Sleep(1);
    }
    return 0;
}