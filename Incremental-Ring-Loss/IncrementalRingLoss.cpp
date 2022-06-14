// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"


TaskFunc(Tobitiri, 0x44FD10);

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
        if (rings > 20)
        {
            rings = 20;
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
	__declspec(dllexport) void Init()
	{
		WriteCall((int*)0x45E664, DamegeRingScatter_custom);
		WriteCall((int*)0x4780D3, DamegeRingScatter_custom);
		WriteCall((int*)0x481519, DamegeRingScatter_custom);
		WriteCall((int*)0x48892E, DamegeRingScatter_custom);
		WriteCall((int*)0x48E70D, DamegeRingScatter_custom);
		WriteCall((int*)0x496FFE, DamegeRingScatter_custom);
		WriteCall((int*)0x799D24, DamegeRingScatter_custom);


	}



	__declspec(dllexport) ModInfo SADXModInfo = { 11 };

}

