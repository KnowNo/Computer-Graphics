// CG_xView.h : interface of the CCG_xView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CG_XVIEW_H__F72D42E9_AC98_4D09_90FB_5E3195335114__INCLUDED_)
#define AFX_CG_XVIEW_H__F72D42E9_AC98_4D09_90FB_5E3195335114__INCLUDED_

//��������꽻��ʽ��ֱ���㷨����
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCG_xView : public CView
{
protected: // create from serialization only
	CCG_xView();
	DECLARE_DYNCREATE(CCG_xView)

// Attributes
public:
	CCG_xDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCG_xView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	CPoint mp2;
	CPoint mp1;
	CPoint p2;
	CPoint p1;
	void PositiveNegativeParabola(CDC *pDC, double a, double b, double c, int color);
	double f33(double t);
	double f23(double t);
	double f13(double t);
	double f03(double t);
	double h33(double t);
	double h23(double t);
	double h13(double t);
	double h03(double t);
	double b33(double t);
	double b23(double t);
	double b13(double t);
	double b03(double t);
	double Bernstein(int m, int n, double t);
	int Multiply_n(int m, int n);
	void computeCoefficients(int n, int *c);
	void Par(int xs, int ys, int xm, int ym, int xe, int ye);
	COLORREF m_PenColor;  //��ɫ
	int C_S_Line(CDC* pDC, int x1, int y1, int x2, int y2);
	void encode(int x, int y, int *code);
	//���ڵ��ϡ��¡����ұ߽�
	int WT;
	int WB;
	int WR;
	int WL;
	void SeedFill(int xe, int ye, COLORREF newcolor, COLORREF oldcolor);
	void floodfill4(int x, int y, COLORREF oldcolor, COLORREF newcolor);
	int isstackempty();
	void setstackempty();
	void stackpush(int p_xy);
	int stackpop();
	void ElisePot(CDC *pDC, int x0, int y0, int x, int y, COLORREF color);
	void MidpointEllise(CDC *pDC, int x0, int y0, int a, int b, COLORREF color);
	void CirPot(CDC *pDC, int x0, int y0, int x, int y, COLORREF color);
	void MidpointCircle(CDC *pDC, int x0, int y0, int r, COLORREF color);
	COLORREF m_FontColor;
	int m_penwidth;
	bool m_isButtondown;
	void DDAMouseLine(CDC *pDC, int x0, int y0, int x1, int y1, COLORREF color);
	int m_Type;//������� 0����ʼֵ 1����Ƥ�����Բ 2������ʽ��ֱ�� 3��Ǧ�ʹ��ܣ�ͽ�ֻ��ߣ� 4���е㷨����ʽ��Բ
					//				5���е㷨����ʽ����Բ 6��ɨ��������㷨 7����������㷨 8���㻮�� 9������
					//				10������ʽ��������㷨�����߶� 11���������ʵ�ֽ���ʽ�ƶ�ͼ��
	int l_Type;//�������� 0����ʼֵ��Ĭ�ϣ� 1����ˢ��  2����ˢ��
	void DDA2Line(CDC * pDC, int x0, int y0, int x1, int y1, COLORREF color);
	void ddaline(CDC *pDC, int x0, int y0, int x1, int y1, COLORREF color);
	int ComputeRadius(CPoint cenp, CPoint ardp);
	void DrawCircle(CDC *pDC, CPoint cenp, CPoint arbp);
	virtual ~CCG_xView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:

	int stack_top; //����ջ����λ��
	int stack[10000]; //����ջ
	CPoint LeftTop;
	CPoint RightBottom;
	CPoint CenterPoint;
	int b;
	int a;
	int m_r; //�뾶
	int m_istm;
	CPoint m_p2;
	CPoint m_p1;
	int m_ist;
	CPoint m_bR;
	CPoint m_bO;
	//{{AFX_MSG(CCG_xView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnCancelMode();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnCaptureChanged(CWnd *pWnd);
	afx_msg void OnMENU33MouseSprint();
	afx_msg void OnMENU341DDAOnDraw();
	afx_msg void OnMENU342FangDa10();
	afx_msg void OnMENU343MouseLine();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMenuClearall();
	afx_msg void OnMenu35Pen();
	afx_msg void OnMENU461MidpointCircle();
	afx_msg void OnMENU462MidpointEllise();
	afx_msg void OnMenuColor();
	afx_msg void OnMENU51SpeedFill();
	afx_msg void OnMENU52SpeedFillZhongzi();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnMenu611Line();
	afx_msg void OnMenu612Cricle();
	afx_msg void OnMenu621Line();
	afx_msg void OnMenu622Cricle();
	afx_msg void OnMenu37Dotline();
	afx_msg void OnMENU71MouseCodeClip();
	afx_msg void OnMENU81Par();
	afx_msg void OnMENU82Hermite();
	afx_msg void OnMENU83Bezier();
	afx_msg void OnMENU84Bezier3();
	afx_msg void OnMENU853ByangtaoLine();
	afx_msg void OnMENUCHANGEpingyi();
	afx_msg void OnMenuChangeXuanxzhuan();
	afx_msg void OnMenuChangeFangdasuoxiao();
	afx_msg void OnMENUOtherFlowers();
	afx_msg void OnMenuOthersJiaohushiyidongtuxing();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CG_xView.cpp
inline CCG_xDoc* CCG_xView::GetDocument()
   { return (CCG_xDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CG_XVIEW_H__F72D42E9_AC98_4D09_90FB_5E3195335114__INCLUDED_)
