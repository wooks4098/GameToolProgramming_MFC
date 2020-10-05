// 실습.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "framework.h"
#include "실습.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 유일한 애플리케이션 개체입니다.

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // MFC를 초기화합니다. 초기화하지 못한 경우 오류를 인쇄합니다.
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: 여기에 애플리케이션 동작을 코딩합니다.
            wprintf(L"심각한 오류: MFC 초기화 실패\n");
            nRetCode = 1;
        }
        else
        {
			_tsetlocale(LC_ALL, _T(""));
			/*CMapStringToString map;
			map[_T("사과")] = _T("APPLE");
			map[_T("딸기")] = _T("STRAWBERRY");
			map[_T("포토")] = _T("GRAPE");
			map[_T("우유")] = _T("MILK");
			CString str;
			if (map.Lookup(_T("딸기"), str))
				_tprintf(_T("딸기 -> %s\n"), str);
			POSITION pos = map.GetStartPosition();

			while (pos != NULL)
			{
				CString strKey, strValue;
				map.GetNextAssoc(pos, strKey, strValue);
				_tprintf(_T("%s -> %s\n"), strKey, strValue);
			}*/
			CMap<CString, LPCTSTR, UINT, UINT&>map;
			map[_T("사과")] = 10;
			map[_T("딸기")] = 20;
			map[_T("포토")] = 30;
			map[_T("수박")] = 40;
			

			UINT nCount;
			if(map.Lookup(_T("수박"),nCount))
				_tprintf(_T("수박 %d상자가 남아 있습니다\n"),nCount	);

			POSITION pos = map.GetStartPosition();
			while (pos != NULL)
			{
				CString strKey ;
				UINT iValue;
				map.GetNextAssoc(pos, strKey, iValue);
				_tprintf(_T("%s -> %s\n"), strKey, iValue);

			}
		
            // TODO: 여기에 애플리케이션 동작을 코딩합니다.
        }
    }
    else
    {
        // TODO: 오류 코드를 필요에 따라 수정합니다.
        wprintf(L"심각한 오류: GetModuleHandle 실패\n");
        nRetCode = 1;
    }

    return nRetCode;
}
