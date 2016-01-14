// BrightIdeasWindowsNative.cpp : 定義 DLL 應用程式的匯出函式。
//

#include "BrightIdeasWindowsNative.h"
#include <stdlib.h>
#include <windows.h>

extern "C"
{

	FREObject setMousePosition(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
	{
		//AS3傳來的參數會存在argv[]裡
		int32_t x, y;

		//將AS3數據轉成C++
		FREGetObjectAsInt32(argv[0], &x);
		FREGetObjectAsInt32(argv[1], &y);

		//設定系統的座標,為Windows.h裡的方法
		SetCursorPos(x, y);

		//如果不在意回傳數值就回傳第一個參數
		//如果需要回傳經計算過的數值請記得利用FRE Object轉成AS3看得懂的數據
		return argv[0];
	}

	FREObject mouseClick(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
	{
		//觸發滑鼠事件,click事件其實就是mousedown跟mouseup的組合
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		return argv[0];
	}

	FREObject mouseDown(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
	{
		//觸發滑鼠事件
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		return argv[0];
	}

	FREObject mouseUp(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
	{
		//觸發滑鼠事件
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		return argv[0];
	}

	FREObject keyDown(FREContext ctx, void* funcData, uint32_t argc, FREObject argv[])
	{
		//觸發鍵盤事件
		int32_t keyNum;
		FREGetObjectAsInt32(argv[0], &keyNum);

		keybd_event(keyNum, 0, 0, 0);
		return argv[0];
	}

	void ContextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctions, const FRENamedFunction** functions)
	{
		//在初始化時宣告可以被AS3調用的方法
		*numFunctions = 5;
		FRENamedFunction* func = (FRENamedFunction*)malloc(sizeof(FRENamedFunction)*(*numFunctions));


		func[0].name = (const uint8_t*)"setMousePosition";
		func[0].functionData = NULL;
		func[0].function = &setMousePosition;

		func[1].name = (const uint8_t*)"mouseClick";
		func[1].functionData = NULL;
		func[1].function = &mouseClick;

		func[2].name = (const uint8_t*)"mouseDown";
		func[2].functionData = NULL;
		func[2].function = &mouseDown;

		func[3].name = (const uint8_t*)"mouseUp";
		func[3].functionData = NULL;
		func[3].function = &mouseUp;

		func[4].name = (const uint8_t*)"keyDown";
		func[4].functionData = NULL;
		func[4].function = &keyDown;
		
		*functions = func;
	}


	void ContextFinalizer(FREContext ctx)
	{
		return;
	}

	void ExtInitializer(void** extData, FREContextInitializer* ctxInitializer, FREContextFinalizer* ctxFinalizer)
	{

		*ctxInitializer = &ContextInitializer;
		*ctxFinalizer = &ContextFinalizer;
	}

	void ExtFinalizer(void* extData)
	{
		return;
	}
}


