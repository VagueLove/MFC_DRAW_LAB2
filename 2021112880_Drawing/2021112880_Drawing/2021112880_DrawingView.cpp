﻿
// 2021112880_DrawingView.cpp: CMy2021112880DrawingView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "2021112880_Drawing.h"
#endif

#include "2021112880_DrawingDoc.h"
#include "2021112880_DrawingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <iostream>

CSlist m_link_list;
CLine* m_pline;
CQuare* m_psquare;
CCircle* m_pcircle;

Curve* m_pcurve = nullptr;
PolyLine* m_polyline = nullptr;
CDrawVerLine* m_ver_line = NULL;
CGetIntersection* m_intersection = NULL;

//鼠标光标
HCURSOR hCursor = LoadCursor(NULL, IDC_PERSON);

// CMy2021112880DrawingView

IMPLEMENT_DYNCREATE(CMy2021112880DrawingView, CView)

BEGIN_MESSAGE_MAP(CMy2021112880DrawingView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_Line, &CMy2021112880DrawingView::OnLine)
	ON_COMMAND(ID_Circle, &CMy2021112880DrawingView::OnCircle)
	ON_COMMAND(ID_Rectangle, &CMy2021112880DrawingView::OnRectangle)
	ON_WM_CONTEXTMENU()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_Blue, &CMy2021112880DrawingView::OnBlue)
	ON_COMMAND(ID_Red, &CMy2021112880DrawingView::OnRed)
	ON_COMMAND(ID_Green, &CMy2021112880DrawingView::OnGreen)
	ON_COMMAND(ID_Select, &CMy2021112880DrawingView::OnSelect)
	ON_COMMAND(ID_Curve, &CMy2021112880DrawingView::OnCurve)
	ON_COMMAND(ID_Poly_Line, &CMy2021112880DrawingView::OnPolyLine)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_Clear, &CMy2021112880DrawingView::OnClear)
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DrawVerLine, &CMy2021112880DrawingView::OnDrawVerLine)
	ON_COMMAND(ID_GetCenter, &CMy2021112880DrawingView::OnGetCenter)
	ON_COMMAND(ID_GetIntersection, &CMy2021112880DrawingView::OnGetIntersection)
//	ON_MESSAGE(OnSetMouseCursor, &CMy2021112880DrawingView::OnOnsetmousecursor)
ON_WM_SETCURSOR()
ON_COMMAND(ID_Black, &CMy2021112880DrawingView::OnBlack)
END_MESSAGE_MAP()

// CMy2021112880DrawingView 构造/析构

CMy2021112880DrawingView::CMy2021112880DrawingView() noexcept
{
	// TODO: 在此处添加构造代码

	type = 0;
	start = false;
	what_RGB = 0;
	what_line = 1;
	go = false;
	function = 0;
	IsSelected = false;
	IsOpenSelect = false;
}

CMy2021112880DrawingView::~CMy2021112880DrawingView()
{
}

BOOL CMy2021112880DrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy2021112880DrawingView 绘图

void CMy2021112880DrawingView::OnDraw(CDC* /*pDC*/)
{
	CMy2021112880DrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int i, len;
	len = m_link_list.Length();
	if (len)
	{
		for (i = 1; i <= len; i++)
		{
			CDC* pDC = GetDC();
			//避免图形重叠
			pDC->SelectStockObject(NULL_BRUSH);
			Node* paint = m_link_list.GetElement(i);
			DataDraw* ddraw = DataDraw::Get_Draw(paint->now_type);
			if (ddraw)
			{
				ddraw->Draw(paint, pDC);
				delete ddraw;
			}
			ReleaseDC(pDC);
		}
	}

	
}


// CMy2021112880DrawingView 打印

BOOL CMy2021112880DrawingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy2021112880DrawingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy2021112880DrawingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy2021112880DrawingView 诊断

#ifdef _DEBUG
void CMy2021112880DrawingView::AssertValid() const
{
	CView::AssertValid();
}

void CMy2021112880DrawingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2021112880DrawingDoc* CMy2021112880DrawingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2021112880DrawingDoc)));
	return (CMy2021112880DrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy2021112880DrawingView 消息处理程序


void CMy2021112880DrawingView::OnLine()
{
	// TODO: 在此添加命令处理程序代码
	type = 1;
	function = 0;
}


void CMy2021112880DrawingView::OnRectangle()
{
	// TODO: 在此添加命令处理程序代码
	type = 2;
	function = 0;

}

void CMy2021112880DrawingView::OnCircle()
{
	// TODO: 在此添加命令处理程序代码
	type = 3;
	function = 0;

}

void CMy2021112880DrawingView::OnCurve()
{
	// TODO: 在此添加命令处理程序代码
	type = 4;
	function = 0;

}

void CMy2021112880DrawingView::OnPolyLine()
{
	// TODO: 在此添加命令处理程序代码
	type = 5;
	function = 0;

}


void CMy2021112880DrawingView::OnSelect()
{
	// TODO: 在此添加命令处理程序代码
	IsOpenSelect = true;
}

void CMy2021112880DrawingView::OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/)
{
	// TODO: 在此处添加消息处理程序代码
}

void CMy2021112880DrawingView::LButtonDown_Set_RGB()
{
	switch (what_RGB)
	{
	case 1:
		what_RGB = 1;
		break;
	case 2:
		what_RGB = 2;
		break;
	case 3:
		what_RGB = 3;
		break;
	case 0:
		what_RGB = 0;
		break;
	}
}
void CMy2021112880DrawingView::LButtonDown_Set_Type(CPoint point)
{
	switch (type)
	{
	case 1:
	{
		m_pline = new CLine;
		m_pline->Set_start_point(point);

	}break;

	case 2:
	{
		m_psquare = new CQuare;
		m_psquare->Set_first_point(point);
	}break;

	case 3:
	{
		m_pcircle = new CCircle;
		m_pcircle->Set_CenPoint(point);
	}break;

	case 4:
	{
		if (m_pcurve == NULL)
			m_pcurve = new Curve;
	}break;

	case 5:
	{
		if (m_polyline == nullptr)
		{
			m_polyline = new PolyLine;
		}
		//设置第一个点
		if (!m_polyline->firstset)
			m_polyline->Set_point(point);
	}break;
	default:
		break;
	}
}
void CMy2021112880DrawingView::LButtonDown_Set_Function(CPoint point)
{
	switch (function)
	{
	case 1:
	{
		if (m_ver_line == NULL)
		{
			m_ver_line = new CDrawVerLine;
			//设置过垂线的点
			if (!m_ver_line->IsPointSet)
				m_ver_line->SetPoint(point);
		}
		else
		{
			//设置直线
			if (!m_ver_line->IsLineSet && m_ver_line->IsPointSet)
			{
				int i, len = m_link_list.Length();
				if (len)
				{
					for (i = 1; i <= len; i++)
					{
						Node* selectLine;
						selectLine = m_link_list.GetElement(i);
						if (selectLine->now_type == 1)
						{
							if (((CLine*)selectLine->data)->Selected(point))
							{
								m_ver_line->SetLine((CLine*)selectLine->data);
								break;
							}
						}
					}
				}
			}
		}
	}break;
	case 2:
	{
		if (m_intersection == NULL)
		{
			m_intersection = new CGetIntersection;
			int i, len = m_link_list.Length();
			if (len)
			{
				for (i = 1; i <= len; i++)
				{
					Node* selectObj = m_link_list.GetElement(i);
					if (selectObj->now_type == 1)
					{
						if (((CLine*)selectObj->data)->Selected(point))
						{
							m_intersection->Set_GraphicsPos_List_1(i);
							m_intersection->type_1 = 1;
							break;
						}
					}
					if (selectObj->now_type == 3)
					{
						if (((CCircle*)selectObj->data)->Selected(point))
						{
							m_intersection->Set_GraphicsPos_List_1(i);
							m_intersection->type_1 = 3;
							break;
						}
					}
				}
			}
		}
		else
		{
			int i, len = m_link_list.Length();
			if (len)
			{
				for (i = 1; i <= len; i++)
				{
					Node* selectObj = m_link_list.GetElement(i);
					if (selectObj->now_type == 1)
					{
						if (((CLine*)selectObj->data)->Selected(point))
						{
							m_intersection->Set_GraphicsPos_List_2(i);
							m_intersection->type_2 = 1;
							break;
						}
					}
					if (selectObj->now_type == 3)
					{
						if (((CCircle*)selectObj->data)->Selected(point))
						{
							m_intersection->Set_GraphicsPos_List_2(i);
							m_intersection->type_2 = 3;
							break;
						}
					}
				}
			}
		}
	}break;
	case 3:
	{
		int i, len = m_link_list.Length();
		if (len)
		{
			CDC* pDC = GetDC();
			for (i = 1; i <= len; i++)
			{
				Node* PoC = m_link_list.GetElement(i);
				if (PoC->now_type == 3)
				{
					CPoint Cen = ((CCircle*)PoC->data)->GetCenter();
					CPen pen;
					if (((CCircle*)PoC->data)->Selected(point))
					{
						pen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
					}
					else
					{
						pen.CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
					}
					pDC->SelectObject(&pen);
					pDC->Ellipse(Cen.x - 2, Cen.y - 2, Cen.x + 2, Cen.y + 2);
				}
			}
			ReleaseDC(pDC);
		}
	}break;
	}
}

void CMy2021112880DrawingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	LButtonDown_Set_RGB();
	LButtonDown_Set_Type(point);
	LButtonDown_Set_Function(point);
	start = true;
	CView::OnLButtonDown(nFlags, point);
}

void CMy2021112880DrawingView::LButtonUp_Set_RGB_Type(CPoint point)
{
	Node* newPoint = new Node;
	switch (what_RGB)
	{
	case 1:
		newPoint->now_RGB = 1;
		break;

	case 2:
		newPoint->now_RGB = 2;
		break;

	case 3:
		newPoint->now_RGB = 3;
		break;

	case 0:
		newPoint->now_RGB = 0;
		break;
	}

	switch (type)
	{
	case 1:
	{
		newPoint->now_type = 1;
		newPoint->data = m_pline;
		m_link_list.InputFront(newPoint);
	}
	break;

	case 2:
	{
		newPoint->now_type = 2;
		newPoint->data = m_psquare;
		m_link_list.InputFront(newPoint);
	}
	break;

	case 3:
	{
		newPoint->now_type = 3;
		newPoint->data = m_pcircle;
		m_link_list.InputFront(newPoint);
	}
	break;

	case 4:
		break;

	case 5:
	{
		if (m_polyline)
			m_polyline->Set_point(point);
	}
	break;

	}
}
void CMy2021112880DrawingView::LButtonUp_Set_Function()
{
	switch (function)
	{
	case 1:
	{
		CDC* pDC = GetDC();
		CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
		pDC->SelectObject(&pen);
		if (m_ver_line->IsLineSet && m_ver_line->IsPointSet)
		{
			m_ver_line->SetVerFoot();
			m_ver_line->Draw(pDC, m_link_list);
			m_ver_line = NULL;
		}
		ReleaseDC(pDC);
	}break;
	case 2:
	{
		if (m_intersection->IsSet_Node_Pos_1 && m_intersection->IsSet_Node_Pos_2)
		{
			CString str;
			if (m_intersection->type_1 == 1 && m_intersection->type_2 == 1)
			{
				m_intersection->CalcLL(m_link_list);
				if ((m_intersection->Intersection_1).x >= 0)
				{
					str.Format(_T("两直线交点为(%d,%d))"), (m_intersection->Intersection_1).x, (m_intersection->Intersection_1).y);
				}
				else
				{
					str.Format(_T("无交点"));
				}
				GetParent()->GetDescendantWindow(AFX_IDW_STATUS_BAR)->SetWindowTextW(str);
			}
			else if (m_intersection->type_1 == 3 && m_intersection->type_2 == 3)
			{
				m_intersection->CalcCC(m_link_list);
				if ((m_intersection->Intersection_1).x >= 0 && (m_intersection->Intersection_2).x >= 0)
				{
					str.Format(_T("两圆的交点为(%d,%d) (%d,%d)"), (m_intersection->Intersection_1).x, (m_intersection->Intersection_1).y, (m_intersection->Intersection_2).x, (m_intersection->Intersection_2).y);
				}
				else if ((m_intersection->Intersection_1).x >= 0)
				{
					str.Format(_T("两圆的交点为(%d,%d) "), (m_intersection->Intersection_1).x, (m_intersection->Intersection_1).y);
				}
				else if ((m_intersection->Intersection_2).x >= 0)
				{
					str.Format(_T("两圆的交点为(%d,%d) "), (m_intersection->Intersection_2).x, (m_intersection->Intersection_2).y);
				}
				else
				{
					str.Format(_T("无交点"));
				}
				GetParent()->GetDescendantWindow(AFX_IDW_STATUS_BAR)->SetWindowTextW(str);
			}
			else if (m_intersection->type_1 == 3 && m_intersection->type_2 == 1)
			{
				m_intersection->CalcCL(m_link_list);
				if ((m_intersection->Intersection_1).x >= 0 && (m_intersection->Intersection_2).x >= 0)
				{
					str.Format(_T("直线与圆的交点为(%d,%d) (%d,%d)"), (m_intersection->Intersection_1).x, (m_intersection->Intersection_1).y, (m_intersection->Intersection_2).x, (m_intersection->Intersection_2).y);
				}
				else if ((m_intersection->Intersection_1).x >= 0)
				{
					str.Format(_T("直线与圆的交点为(%d,%d) "), (m_intersection->Intersection_1).x, (m_intersection->Intersection_1).y);
				}
				else if ((m_intersection->Intersection_2).x >= 0)
				{
					str.Format(_T("直线与圆的交点为(%d,%d) "), (m_intersection->Intersection_2).x, (m_intersection->Intersection_2).y);
				}
				else
				{
					str.Format(_T("无交点"));
				}
				GetParent()->GetDescendantWindow(AFX_IDW_STATUS_BAR)->SetWindowTextW(str);
			}
			else if (m_intersection->type_1 == 1 && m_intersection->type_2 == 3)
			{
				m_intersection->CalcLC(m_link_list);
				if ((m_intersection->Intersection_1).x >= 0 && (m_intersection->Intersection_2).x >= 0)
				{
					str.Format(_T("直线与圆的交点为(%d,%d) (%d,%d)"), (m_intersection->Intersection_1).x, (m_intersection->Intersection_1).y, (m_intersection->Intersection_2).x, (m_intersection->Intersection_2).y);
				}
				else if ((m_intersection->Intersection_1).x >= 0)
				{
					str.Format(_T("直线与圆的交点为(%d,%d) "), (m_intersection->Intersection_1).x, (m_intersection->Intersection_1).y);
				}
				else if ((m_intersection->Intersection_2).x >= 0)
				{
					str.Format(_T("直线与圆的交点为(%d,%d) "), (m_intersection->Intersection_2).x, (m_intersection->Intersection_2).y);
				}
				else
				{
					str.Format(_T("无交点"));
				}
				GetParent()->GetDescendantWindow(AFX_IDW_STATUS_BAR)->SetWindowTextW(str);

			}

			m_intersection = NULL;
		}
	}break;

	case 3:
	{}break;
	default:
		break;
	}
}
void CMy2021112880DrawingView::LButtionDbCLK_For_Type(CPoint point)
{
	switch (type)
	{
	case 4:
	{
		m_pcurve->flag = false;
		//双击设置起点和终点
		if (!m_pcurve->point1set)
		{
			Draw_Point(point);
			m_pcurve->Set_start_point(point);
		}
		else if (!m_pcurve->point2set)
		{
			Draw_Point(point);
			m_pcurve->Set_end_point(point);
		}
	}break;
	}
}

void CMy2021112880DrawingView::Draw_Point(CPoint point)
{
	CDC* pDC = GetDC();
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	pDC->SelectObject(&pen);
	pDC->Ellipse(point.x - 2, point.y - 2, point.x + 2, point.y + 2);
	ReleaseDC(pDC);
}

void CMy2021112880DrawingView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	LButtonUp_Set_RGB_Type(point);
	LButtonUp_Set_Function();


	go = false;
	start = false;
	CView::OnLButtonUp(nFlags, point);
}

void CMy2021112880DrawingView::MouseMove_Draw(CPoint point, int color)
{
	CDC* pDC = GetDC();
	pDC->SelectStockObject(NULL_BRUSH);
	CPen pen;

	switch (color)
	{
	case 1:
	{
		pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));//red
	}break;	
	case 2:
	{
		pen.CreatePen(PS_SOLID, 1, RGB(0, 255, 0));//green
	}break;
	case 3:
	{
		pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));//blue
	}break;
	case 0:
	{
		pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));//black
	}break;

	default:
		break;
	}
	CPen* pOldPen = (CPen*)pDC->SelectObject(&pen);

	switch (type)
	{
	case 1:
	{
		if (go)
		{
			pDC->SetROP2(R2_NOTXORPEN);
			m_pline->Draw(pDC);
		}
		else
			go = true;
		m_pline->Set_end_point(point);
		m_pline->Draw(pDC);
	}break;	
	case 2:
	{
		if (go)
		{
			pDC->SetROP2(R2_NOTXORPEN);
			m_psquare->Draw(pDC);
		}
		else
			go = true;
		m_psquare->Set_end_point(point);
		m_psquare->Draw(pDC);
	}break;	
	case 3:
	{
		if (go)
		{
			pDC->SetROP2(R2_NOTXORPEN);
			m_pcircle->Draw(pDC);
		}
		else
			go = true;
		m_pcircle->Get_Radius(point);
		m_pcircle->Draw(pDC);
	}break;	
	case 4:
	{
		if (m_pcurve->point2set)
		{
			if (go)
			{
				pDC->SetROP2(R2_NOTXORPEN);
				m_pcurve->Draw(pDC);
			}
			else
				go = true;
			m_pcurve->Set_direc_point(point);
			m_pcurve->Draw(pDC);
		}
	}break;	
	case 5:
	{
		if (!m_polyline->over)
		{
			if (go)
			{
				pDC->SetROP2(R2_NOTXORPEN);
				m_polyline->Draw(pDC);
			}
			else
				go = true;
			m_polyline->Get_point(point);
			m_polyline->Draw(pDC);
		}
	}break;
	default:
		break;
	}

	ReleaseDC(pDC);
}

void CMy2021112880DrawingView::MouseMove_IsSelect(CPoint point)
{
	int i, len;
	len = m_link_list.Length();
	if (len)
	{
		for (i = 1; i <= len; i++)
		{
			Node* select;
			select = m_link_list.GetElement(i);
			if (select->now_type == 1)
			{
				if (((CLine*)select->data)->Selected(point))
				{
					IsSelected = true;
					break;
				}
				else
					IsSelected = false;
			}
			else if (select->now_type == 2)
			{
				if (((CQuare*)select->data)->Selected(point))
				{
					IsSelected = true;
					break;
				}
				else
					IsSelected = false;
			}
			else if (select->now_type == 3)
			{
				if (((CCircle*)select->data)->Selected(point))
				{
					IsSelected = true;
					break;
				}
				else
					IsSelected = false;
			}
			else if (select->now_type == 4)
			{
				if (((Curve*)select->data)->Selected(point))
				{
					IsSelected = true;
					break;
				}
				else
					IsSelected = false;
			}
			else if (select->now_type == 5)
			{
				if (((PolyLine*)select->data)->Selected(point))
				{
					IsSelected = true;
					break;
				}
				else
					IsSelected = false;
			}
		}
	}

}

void CMy2021112880DrawingView::MouseMove_Draw_Basic_Graphics(CPoint point)
{
	if (start == true)
	{
		//根据不同颜色，绘制相应的图形
		switch (what_RGB)
		{
		case 1:
		{
			MouseMove_Draw(point,what_RGB);
		}break;
		case 2: 
		{
			MouseMove_Draw(point, what_RGB);

		}break;
		case 3: 
		{
			MouseMove_Draw(point, what_RGB);

		}break;
		case 0: 
		{
			MouseMove_Draw(point, what_RGB);

		}break;
		default:
			break;
		}
	}
}

void CMy2021112880DrawingView::OnMouseMove(UINT nFlags, CPoint point)
{
	//实时在屏幕上打印鼠标坐标
	CString str;
	str.Format(_T("(%d,%d) "), point.x, point.y);
	CDC* pDC = GetDC();
	pDC->TextOutW(0, 0, str);
	
	MouseMove_Draw_Basic_Graphics(point);
	MouseMove_IsSelect(point);
	
	CView::OnMouseMove(nFlags, point);

}


void CMy2021112880DrawingView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	LButtionDbCLK_For_Type(point);

	CView::OnLButtonDblClk(nFlags, point);
}


void CMy2021112880DrawingView::OnClear()
{
	// TODO: 在此添加命令处理程序代码
	m_link_list.MakeEmpty();
	CDC* pDC = GetDC();
	CRect rc;
	GetClientRect(&rc);
	pDC->FillSolidRect(&rc, RGB(255, 255, 255));
	ReleaseDC(pDC);
}


void CMy2021112880DrawingView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (type == 4)
	{
		if (m_pcurve && m_pcurve->point2set)
		{
			Node* newPoint = new Node;
			newPoint->now_type = 4;
			newPoint->now_RGB = what_RGB;
			newPoint->data = m_pcurve;
			m_link_list.InputFront(newPoint);
			m_pcurve = nullptr;
		}
	}
	if (type == 5)
	{
		m_polyline->over = true;
		Node* newPoint = new Node;
		newPoint->now_type = 5;
		newPoint->now_RGB = what_RGB;
		newPoint->data = m_polyline;
		m_link_list.InputFront(newPoint);
		m_polyline = NULL;
	}

	IsOpenSelect = false;
	CView::OnRButtonUp(nFlags, point);
}

//颜色设置
void CMy2021112880DrawingView::OnBlue()
{
	// TODO: 在此添加命令处理程序代码
	what_RGB = 3;
}
void CMy2021112880DrawingView::OnRed()
{
	// TODO: 在此添加命令处理程序代码
	what_RGB = 1;
}
void CMy2021112880DrawingView::OnGreen()
{
	// TODO: 在此添加命令处理程序代码
	what_RGB = 2;
}
void CMy2021112880DrawingView::OnBlack()
{
	// TODO: 在此添加命令处理程序代码
	what_RGB = 0;
}

void CMy2021112880DrawingView::OnDrawVerLine()
{
	// TODO: 在此添加命令处理程序代码
	function = 1;
	type = 0;
}

void CMy2021112880DrawingView::OnGetCenter()
{
	// TODO: 在此添加命令处理程序代码
	function = 3;
	type = 0;
}

void CMy2021112880DrawingView::OnGetIntersection()
{
	// TODO: 在此添加命令处理程序代码
	function = 2;
	type = 0;
}

BOOL CMy2021112880DrawingView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	if (IsSelected && IsOpenSelect)
	{
		SetCursor(hCursor);
		return TRUE;
	}
	return CView::OnSetCursor(pWnd, nHitTest, message);
}