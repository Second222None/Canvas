#pragma once
#include <afx.h>

/*
 生成一个可串行化的类的步骤

(1) Derive your class from CObject. （定义一个基类为CObject的类）

(2) Override the Serialize member function.（重写串行化函数）

(3) Use the DECLARE_SERIAL macro in the class declaration.（在类声明文件中使用DECLARE_SERIAL宏）

(4) Define a constructor with no arguments (a default constructor).（定义一个无参数的构造函数）

(5) Use the IMPLEMENT_SERIAL macro in the class implementation file.（在实现文件中使用IMPLEMENT_SERIAL宏）
*/

class Graph :
    public CObject
{
public:
    DECLARE_SERIAL(Graph) //(3)使用DECLARE_SERIAL宏
    Graph::Graph(void); //(4)一个无参数的构造函数
    Graph::Graph(CPoint m_ptOrigin, CPoint m_ptEnd, UINT m_DrawType);
    Graph::~Graph();
    void Draw(CDC* pDC);
    void Serialize(CArchive& ar);


public:
    /* 下面三个变量用于描述一个图形 */
    CPoint m_ptOrigin;
    CPoint m_ptEnd;
    UINT m_DrawType;
};


