// Project1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "framework.h"
#include "Project1.h"

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
			/*CString str;
			str.LoadStringW(IDS_test);
			_tprintf(_T("안녕 Hello From %s!\n"), str);
			_tprintf(_T("\n"));*/
			////////////////////

			//CString str1;
			//str1 = _T("안녕하세요");
			//CString str2(_T("오늘은")); // 문자열을 생성자 인자로 전달한다.
			//	CString str3(str2); // CString 객체를 생성자 인자로 전달한다.
			//	// CString 객체와 문자열을 붙인다.
			//CString str4 = str1 + _T(" ") + str2 + _T(" 즐거운 날입니다.");
			//_tprintf(_T("%s\n"), str1); //_tprintf(_T("%s\n"), (LPCTSTR)str1);
			//_tprintf(_T("%s\n"), str2);
			//_tprintf(_T("%s\n"), str3);
			//_tprintf(_T("%s\n"), str4);
			//// + = 새로운 문자열을 덧붙인다.
			//str4 += _T(" 하하하");
			//_tprintf(_T("%s\n"), str4);
		///////////


			/*CString str22;
			str22.LoadString(IDS_test);
			str22.Insert(0, _T("Hello from"));
			str22.Append(_T("!"));
			MessageBox(NULL, str22, _T("CString::LoadString() 연습"), MB_OK);*/
			////////////


			//CPoint pt1(10, 20); // x, y 좌표를 생성자 인자로 전달한다.
			//POINT pt = { 30, 40 };
			//CPoint pt2(pt); // POINT 타입 변수를 생성자 인자로 전달한다.
			//_tprintf(_T("%d, %d\n"), pt1.x, pt1.y);
			//_tprintf(_T("%d, %d\n"), pt2.x, pt2.y);
			//pt1.Offset(40, 30); // x, y 좌표에 각각 40, 30을 더한다.
			//pt2.Offset(20, 10); // x, y 좌표에 각각 20, 10을 더한다.
			//_tprintf(_T("%d, %d\n"), pt1.x, pt1.y);
			//_tprintf(_T("%d, %d\n"), pt2.x, pt2.y);
			//if (pt1 == pt2) // 두 객체의 내용이 같은지 확인한다.
			//	_tprintf(_T("두 점의 좌표가 같습니다.\n"));
			//else
			//	_tprintf(_T("두 점의 좌표가 다릅니다.\n"));
			//////////


			//CRect rect1(0, 0, 200, 100); // 직사각형의 좌표를 생성자의 인자로 전달한다.
			//CRect rect2;
			//rect2.SetRect(0, 0, 200, 100); // 직사각형의 좌표를 실행 중에 설정한다.
			//if (rect1 == rect2) // 두 객체의 내용이 같은지 확인한다.
			//	_tprintf(_T("두 직사각형의 좌표가 같습니다.\n"));
			//else
			//	_tprintf(_T("두 직사각형의 좌표가 다릅니다.\n"));
			//RECT rect = { 100, 100, 300, 200 };
			//CRect rect3(rect); // RECT 타입 변수를 생성자 인자로 전달한다.
			//_tprintf(_T("%d, %d\n"), rect3.Width(), rect3.Height());

			//CPoint pt3(200, 150);
			//if(rect3.PtInRect(pt3)) // 점이 직사각형 내부에 있는지 판단한다.
			//	_tprintf(_T("점이 직사각형 내부에 있습니다.\n"));
			//else
			//	_tprintf(_T("점이 직사각형 외부에 있습니다.\n"));
			/////////////

			//CSize size1(100, 200); // 폭과 높이를 생성자 인자로 전달한다.
			//SIZE size = { 100, 200 };
			//CSize size2(size); // SIZE 타입 변수를 생성자 인자로 전달한다.
			//_tprintf(_T("%d, %d\n"), size2.cx, size2.cy);
			//	if (size1 == size2) // 두 객체의 내용이 같은지 확인한다.
			//		-_tprintf(_T("크기가 같습니다.\n"));
			//	else
			//			_tprintf(_T("크기가 다릅니다.\n"));
			///////////////////////


			//CTime tm;
			//tm = CTime::GetCurrentTime();
			//// 여러 형식으로 화면에 출력한다.
			//CString str_time = tm.Format(_T("%A, %B, %d, %Y")); //요일, 월, 일,년도
			//	_tprintf(_T("오늘은 %s\n"), str_time);
			//str_time.Format(_T("현재 시각은 %d시 %d분 %d초입니다."),
			//	tm.GetHour(), tm.GetMinute(), tm.GetSecond());
			//_tprintf(_T("%s\n"), tm);
			///////////////////


			//CTime startTime = CTime::GetCurrentTime();
			//Sleep(2000); // 2000밀리초 지연
			//CTime endTime = CTime::GetCurrentTime();
			//CTimeSpan elapsedTime = endTime - startTime;
			//CString str_time;
			//str_time.Format(_T("%d초 지남!"), elapsedTime.GetTotalSeconds());
			//	_tprintf(_T("%s\n"), str_time);
			//////////////////



			//CUIntArray array; // 객체를 생성한다.
			//array.SetSize(10); // 배열 크기를 설정한다.
			//for (int i = 0; i < 10; i++)
			//	array[i] = i * 10; // 값을 대입한다.
			//for (int i = 0; i < 10; i++)
			//	_tprintf(_T("%d "), array[i]); // 값을 출력한다.
			//_tprintf(_T("\n"));
			////////////////////////////


			//CUIntArray array; // 객체를 생성한다.
			//array.SetSize(10); // 배열 크기를 설정한다.
			//for (int i = 0; i < 10; i++)
			//	array[i] = i * 10; // 값을 대입한다.
			//for (int i = 0; i < 10; i++)
			//	_tprintf(_T("%d "), array[i]); // 값을 출력한다.
			//_tprintf(_T("\n"));


			//CStringArray array2; // 객체를 생성한다.
			//array2.SetSize(5); // 배열 크기를 설정한다.
			//for (int i = 0; i < 5; i++) 
			//{
			//	CString string11;
			//	string11.Format("%d년이 지났습니다. ", (i + 1) * 10);
			//	array2[i] = string11; // 값을 대입한다.
			//}
			//for (int i = 0; i < 5; i++)
			//	_tprintf(_T("%s"), array2[i]); // 값을 출력한다.
			////////////



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
