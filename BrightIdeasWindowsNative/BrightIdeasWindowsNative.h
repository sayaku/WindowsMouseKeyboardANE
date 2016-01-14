
#include "FlashRuntimeExtensions.h"  
//用 extern "C"將C++指令轉換成C語言 
//原因是防止C++名稱重整器造成函數名稱的錯位
extern "C"
{
	__declspec(dllexport) void ExtInitializer(void** extDataToSet, FREContextInitializer* ctxInitializerToSet, FREContextFinalizer* ctxFinalizerToSet);

	__declspec(dllexport) void ExtFinalizer(void* extData);

	__declspec(dllexport) FREObject setMousePosition(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);

	__declspec(dllexport) FREObject mouseClick(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);

	__declspec(dllexport) FREObject mouseDown(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);

	__declspec(dllexport) FREObject mouseUp(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);

	__declspec(dllexport) FREObject keyDown(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[]);
}