
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "조욱래.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	//AfxMessageBox(_T("안녕하세요?"));5-1

	dc.Rectangle(0, 0, 200, 100);//4-1 실습
	dc.Ellipse(200, 100, 500, 200);//4-1 실습
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);//
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//AfxMessageBox(_T("조욱래")); // 5-1
	//dc.TextOutW(point.x, point.y, _T("조욱래")); // 5-2

	dc.Rectangle(point.x - 20, point.y - 20, point.x + 20, point.y + 20);//4-2 실습

	CWnd::OnLButtonDown(nFlags, point);
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//AfxMessageBox(_T("부산 주례로 34번길"));//5-1
	//dc.TextOutW(point.x, point.y, _T("부산 주례로 34번길"));5-2

	dc.Ellipse(point.x - 20, point.y - 20, point.x + 20, point.y + 20);//4-2 실습
	CWnd::OnRButtonDown(nFlags, point);
}
