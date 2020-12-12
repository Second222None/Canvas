
// DrawView.cpp: CDrawView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Draw.h"
#endif

#include "DrawDoc.h"
#include "DrawView.h"
#include "Graph.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_LINE, &CDrawView::OnLine)
	ON_COMMAND(ID_BAR_LINE, &CDrawView::OnLine)
	ON_COMMAND(ID_RECTANGLE, &CDrawView::OnRectangle)
	ON_COMMAND(ID_BAR_RECTANGLE, &CDrawView::OnRectangle)
END_MESSAGE_MAP()

// CDrawView 构造/析构

CDrawView::CDrawView() noexcept
{
	// TODO: 在此处添加构造代码
	m_ptOrigin = 0;
	m_ptEnd = 0;
	m_DrawType = 0;
}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDrawView 绘图

void CDrawView::OnDraw(CDC* pDC)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	
	int count;

	count = pDoc->m_obArray.GetSize();

	for (int i = 0; i < count; i++)

	{
		//((Graph*)m_obArray.GetAt(i))->Draw(pDC);
		((Graph*)pDoc->m_obArray.GetAt(i))->Draw(pDC);
	}
}


// CDrawView 打印

BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CDrawView 诊断

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawView 消息处理程序


void CDrawView::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	m_DrawType = 2;
}

void CDrawView::OnRectangle()
{
	// TODO: 在此添加命令处理程序代码
	m_DrawType = 3;
}


void CDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_ptOrigin = point;
	CView::OnLButtonDown(nFlags, point);
}


void CDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CPen pen(PS_SOLID, 1, RGB(255,255,255));

	switch (m_DrawType) {
	case 1:
		dc.SetPixel(point, RGB(255, 255, 255));
	case 2:
		dc.MoveTo(m_ptOrigin);
		dc.LineTo(point);
		break;
	case 3:
		dc.Rectangle(CRect(m_ptOrigin, point));
		break;
	default:
		break;
	}
	/* 将图形信息保存起来 */
	Graph* pGraph = new Graph(m_ptOrigin, point, m_DrawType);
	CDrawDoc* pDoc = GetDocument();
	pDoc->m_obArray.Add(pGraph);

	CView::OnLButtonUp(nFlags, point);
}






