﻿
// DrawDoc.h: CDrawDoc 类的接口
//


#pragma once


class CDrawDoc : public CDocument
{
protected: // 仅从序列化创建
	CDrawDoc() noexcept;
	DECLARE_DYNCREATE(CDrawDoc)

// 特性
public:

// 操作
public:
	
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CDrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	/* 用于保存图形信息（起点、终点、类型）的数组 */
	CObArray m_obArray;
	virtual void DeleteContents();
};
