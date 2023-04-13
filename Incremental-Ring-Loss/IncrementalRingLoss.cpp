// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "IniFile.hpp"

TaskFunc(Tobitiri, 0x44FD10);

int numRings; // maximum number of rings to lose (read from config)

void __cdecl DamegeRingScatter_custom(unsigned __int8 pno)
{
    int rings; // edi
    int v2; // ebp
    int v3; // ebx
    task* v4; // eax
    taskwk* v5; // esi
    float v6; // [esp+0h] [ebp-4h]

    v6 = (double)rand() * 0.000030517578 * 360.0;
    rings = GetRings();
    if (!pno)
    {
        if (rings > numRings) // compare current lost rings to maximum lost rings
        {
            rings = numRings;
        LABEL_4:


            if (ssNumRing > rings)
                ssNumRing -= rings;
            else
                Set0Rings();

            if (rings > 0)
            {
                v2 = 0;
                v3 = rings;


                do
                {
                    v4 = CreateElementalTask(LoadObj_UnknownB | LoadObj_Data1, 2, Tobitiri);
                    if (v4)
                    {
                        v5 = v4->twp;
                        if (EntityData1Ptrs[0])
                        {
                            v5->pos = EntityData1Ptrs[0]->Position;
                        }
                        else
                        {
                            v5->pos.z = 0.0;
                            v5->pos.x = 0.0;
                        }
                        v5->ang.y = (unsigned __int64)(((double)(v2 / rings) + v6) * 65536.0 * 0.002777777777777778);
                    }
                    v2 += 360;
                    --v3;
                } while (v3);
            }
            PlaySound(0, 0, 0, 0);
            return;
        }
        if (rings)
        {
            goto LABEL_4;
        }
        KillHimP(0);
        if (GetCurrentCharacterID() == Characters_Gamma)
        {
            PlaySound(1431, 0, 0, 0);
        }
        else
        {
            PlaySound(23, 0, 0, 0);
        }
    }
}


extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
	const IniFile* config = new IniFile(std::string(path) + "\\config.ini"); // read the config file
	numRings = config->getInt("", "NumRings", 20); // get the number of rings to lose
	WriteJump((int*)0x4506F0, DamegeRingScatter_custom); // write jump to the original function pointer fixes a crash with newer bettersadx versions
	delete config;
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };

}

