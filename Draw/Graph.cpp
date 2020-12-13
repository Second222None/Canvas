#include "pch.h"
#include "Graph.h"

IMPLEMENT_SERIAL(Graph, CObject, 1)

/* 构造函数 */
Graph::Graph(CPoint m_ptOrigin, CPoint m_ptEnd, UINT m_DrawType, COLORREF m_clr) {
    this->m_ptOrigin = m_ptOrigin;
    this->m_ptEnd = m_ptEnd;
    this->m_DrawType = m_DrawType;
    this->m_clr = m_clr;
}
/* 析构函数 */
Graph::~Graph(void) {

}

Graph::Graph() {

}

void Graph::Draw(CDC* pDC)
{
    CPen pen(PS_SOLID, 1, m_clr);
    CPen* oldPen = pDC->SelectObject(&pen);
//    CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
//    CBrush* pOldBrush = pDC->SelectObject(pBrush);
    switch (m_DrawType)
    {
    case 1:
        pDC->SetPixel(m_ptEnd, m_clr);
        //dc.SetPixel(m_ptEnd, RGB(0, 0, 0));
        break;
    case 5:
    case 2:
        pDC->MoveTo(m_ptOrigin);
        pDC->LineTo(m_ptEnd);
        //dc.MoveTo(m_ptOrigin);
        //dc.LineTo(m_ptEnd);
        break;
    case 3:
        pDC->Rectangle(CRect(m_ptOrigin, m_ptEnd));
        //dc.Rectangle(CRect(m_ptOrigin, m_ptEnd));
        break;
    case 4:
        pDC->Ellipse(CRect(m_ptOrigin, m_ptEnd));
        //dc.Ellipse(CRect(m_ptOrigin, m_ptEnd));
        break;
    }
    pDC->SelectObject(oldPen);
}

void Graph::Serialize(CArchive& ar) {
    /* 继承基类的Serialize函数 */
    CObject::Serialize(ar);
    if (ar.IsStoring())
    {
        ar << m_ptOrigin << m_ptEnd << m_DrawType << m_clr;
    }
    else
    {
        ar >> m_ptOrigin >> m_ptEnd >> m_DrawType >> m_clr;
    }
}