// CG_xView.cpp : implementation of the CCG_xView class
//

#include "stdafx.h"
#include "CG_x.h"

#include "CG_xDoc.h"
#include "CG_xView.h"

#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCG_xView

IMPLEMENT_DYNCREATE(CCG_xView, CView)

BEGIN_MESSAGE_MAP(CCG_xView, CView)
	//{{AFX_MSG_MAP(CCG_xView)
	ON_WM_LBUTTONDOWN()
	ON_WM_CANCELMODE()
	ON_WM_MOUSEMOVE()
	ON_WM_CAPTURECHANGED()
	ON_COMMAND(ID_MENU_33_MouseSprint, OnMENU33MouseSprint)
	ON_COMMAND(ID_MENU_341_DDAOnDraw, OnMENU341DDAOnDraw)
	ON_COMMAND(ID_MENU_342_FangDa10, OnMENU342FangDa10)
	ON_COMMAND(ID_MENU_343_MouseLine, OnMENU343MouseLine)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_CHAR()
	ON_COMMAND(ID_MENU_CLEARALL, OnMenuClearall)
	ON_COMMAND(ID_MENU_35_PEN, OnMenu35Pen)
	ON_COMMAND(ID_MENU_461_MidpointCircle, OnMENU461MidpointCircle)
	ON_COMMAND(ID_MENU_462_MidpointEllise, OnMENU462MidpointEllise)
	ON_COMMAND(ID_MENU_COLOR, OnMenuColor)
	ON_COMMAND(ID_MENU_51_SpeedFill, OnMENU51SpeedFill)
	ON_COMMAND(ID_MENU_52_SpeedFill_Zhongzi, OnMENU52SpeedFillZhongzi)
	ON_WM_LBUTTONUP()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_MENU_611_LINE, OnMenu611Line)
	ON_COMMAND(ID_MENU_612_CRICLE, OnMenu612Cricle)
	ON_COMMAND(ID_MENU_621_LINE, OnMenu621Line)
	ON_COMMAND(ID_MENU_622_CRICLE, OnMenu622Cricle)
	ON_COMMAND(ID_MENU_37_DOTLINE, OnMenu37Dotline)
	ON_COMMAND(ID_MENU_71_Mouse_Code_Clip, OnMENU71MouseCodeClip)
	ON_COMMAND(ID_MENU_81_Par, OnMENU81Par)
	ON_COMMAND(ID_MENU_82_Hermite, OnMENU82Hermite)
	ON_COMMAND(ID_MENU_83_Bezier, OnMENU83Bezier)
	ON_COMMAND(ID_MENU_84_Bezier3, OnMENU84Bezier3)
	ON_COMMAND(ID_MENU_85_3ByangtaoLine, OnMENU853ByangtaoLine)
	ON_COMMAND(ID_MENU_CHANGE_pingyi, OnMENUCHANGEpingyi)
	ON_COMMAND(ID_MENU_CHANGE_XUANXZHUAN, OnMenuChangeXuanxzhuan)
	ON_COMMAND(ID_MENU_CHANGE_FANGDASUOXIAO, OnMenuChangeFangdasuoxiao)
	ON_COMMAND(ID_MENU_Other_Flowers, OnMENUOtherFlowers)
	ON_COMMAND(ID_MENU_OTHERS_JIAOHUSHIYIDONGTUXING, OnMenuOthersJiaohushiyidongtuxing)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCG_xView construction/destruction

CCG_xView::CCG_xView()
{
	// TODO: add construction code here
	m_bO.x = 0;
	m_bO.y = 0; //Բ��
	m_bR.x = 0;
	m_bR.y = 0; //Բ�ϵĵ�
	m_ist = 0; //Բ����Բ�ϵĵ�����
	m_p1.x = 0; m_p1.y = 0; //���
	m_p2.x = 0; m_p2.y = 0; //�յ�
	m_ist = 0; //0,��1�㣬 1�� �ڶ��� //���ڽ���ʽ��ֱ�ߡ���Բ��
	m_r = 0; //Բ�İ뾶

	//����ʽ����Բ
	LeftTop.x = 0;
	LeftTop.y = 0;//���Ͻ������ֵ
	RightBottom.x = 0;
	RightBottom.y = 0;//���½������ֵ
	CenterPoint.x = 0;
	CenterPoint.y = 0;//���������ֵ
	a = 0; b = 0;//����Ͷ��᳤��
	
	//���캯������ʼ������
	stack_top = 0;

	//���ʵ�ֽ���ʽ�����߶�Ч��
	WL = 100;
	WR = 400;
	WB = 100;
	WT = 300;

	// �������ʵ�ֽ���ʽ�ƶ�ͼ��
	// ֱ�߶γ�ʼ��
	p1.x=0;p1.y=0;
	p2.x=0;p2.y=0;
	mp1.x=0;mp1.y=0;
	mp2.x=0;mp2.y=0;
    m_ist=0;//0,����һ�㣬1������2��
}

CCG_xView::~CCG_xView()
{
}

BOOL CCG_xView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCG_xView drawing

void CCG_xView::OnDraw(CDC* pDC)
{
	CCG_xDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
//	pDC->TextOut( 30, 30, "hello, worle!");

		
	


}

/////////////////////////////////////////////////////////////////////////////
// CCG_xView printing

BOOL CCG_xView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCG_xView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCG_xView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCG_xView diagnostics

#ifdef _DEBUG
void CCG_xView::AssertValid() const
{
	CView::AssertValid();
}

void CCG_xView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCG_xDoc* CCG_xView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCG_xDoc)));
	return (CCG_xDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCG_xView message handlers

void CCG_xView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//���pDC
	CDC *pDC = GetDC();
	//��Ƥ�����Բ
	if(m_Type == 1){
		//pDC->TextOut(30, 50, "LButtonDown!");
		pDC->SelectStockObject(NULL_BRUSH);
		if(!m_ist)
		{
			m_bO = m_bR = point;//��¼��һ�ε�Բ��λ��
			m_ist++;
		}
		else
		{
			m_bR = point; //��¼�ڶ��εĵ������λ�ã���Բ��
			m_ist--;
			DrawCircle(pDC, m_bO, m_bR);//��Բ
		}
		ReleaseDC(pDC);
	}else if(m_Type == 2){
		//����ʽ��ֱ�ߡ�
		pDC->SelectStockObject(NULL_BRUSH);
		if(!m_ist) //�����
		{
			m_p1 = m_p2 = point;//��¼��һ�ε�����λ�ã������
			m_ist++;
		}else{
			m_p2 = point; //��¼�ڶ��ε�������λ�ã����յ�
			m_ist--; //Ϊ�»�ͼ��׼��
			DDAMouseLine(pDC, m_p1.x, m_p1.y, m_p2.x, m_p2.y, RGB(255, 0, 0));//������ֱ��
		}
		ReleaseDC(pDC); //�ͷ��豸����
	}else if(m_Type == 3){
		//Ǧ�ʹ��ܣ�ͽ�ֻ��ߣ�
/*		m_isButtondown = true;
		SetCapture();
		CPenpen(PS_SOLID, m_penwidth, m_FontColor);
		CPen *pOldPen = pDC->SelectObject(&pen);
		pDC->MoveTo(point);
		pDC->SelectObject(pOldPen);
		m_oldpoint = point;
*/		
		
	}else if(m_Type == 4){
		//4���е㷨����ʽ��Բ
		pDC->SelectStockObject(NULL_BRUSH);
		if(!m_ist) //����Բ
		{
			m_bO = m_bR = point; //��¼��һ�ε������λ�ã�ȷ��Բ��
			m_ist++;
		}else{
			m_bR = point; //��¼�ڶ��ε�������λ�ã���Բ���ϵĵ�
			m_ist--;
			m_r = ComputeRadius(m_bO, m_bR);
			MidpointCircle(pDC, m_bO.x, m_bO.y, m_r, RGB(255, 0, 0));
		}
		ReleaseDC(pDC); //�ͷ��豸����
	}else if(m_Type == 5){
		//5���е㷨����ʽ����Բ
		pDC->SelectStockObject(NULL_BRUSH);
		if(!m_ist) //��һ���㣬���Ͻ�
		{
			LeftTop = RightBottom = point; //��¼��һ�ε������λ��
			m_ist++;
		}else{
			RightBottom = point; //��¼�ڶ��ε�������λ��
			m_ist--;
			CenterPoint.x = (LeftTop.x + RightBottom.x)/2;
			CenterPoint.y = (LeftTop.y + RightBottom.y)/2;
			a = (int)abs(RightBottom.x - LeftTop.x)/2;
			b = (int)abs(RightBottom.y - LeftTop.y)/2;
			MidpointEllise(pDC, CenterPoint.x, CenterPoint.y, a, b, RGB(255, 0, 0));
		}
		ReleaseDC(pDC); //�ͷ��豸����
	}else if(m_Type == 6){

	}else if(m_Type == 7){

	}else if(m_Type == 8){
		//8���㻮��
		pDC->SelectStockObject(NULL_BRUSH);
		if(!m_ist) //�����
		{
			m_p1 = m_p2 = point;//��¼��һ�ε�����λ�ã������
			m_ist++;
		}else{
			m_p2 = point; //��¼�ڶ��ε�������λ�ã����յ�
			m_ist--; //Ϊ�»�ͼ��׼��
			DDAMouseLine(pDC, m_p1.x, m_p1.y, m_p2.x, m_p2.y, RGB(255, 0, 0));//������ֱ��
		}
		ReleaseDC(pDC); //�ͷ��豸����
	}else if(m_Type == 10){
		//10������ʽ��������㷨�����߶� 
		pDC->SelectStockObject(NULL_BRUSH);
		if(!m_ist) //���
		{
			m_p1 = m_p2 = point; //��¼��һ�ε������λ�ã������
			m_ist++;
		}else{
			m_p2 = point; //��¼�ڶ��ε�������λ�ã����յ�
			m_ist --;
			pDC->MoveTo(m_p1.x, m_p1.y); //������ֱ��
			pDC->LineTo(m_p2.x, m_p2.y);
		}
		//ʹ�����ʽ������ֱ��

		//��������ͼģʽ��������ԭ����ͼģʽ
		int nDrawmode = pDC->SetROP2(R2_NOT);
		pDC->MoveTo(m_p1.x, m_p1.y); 
		pDC->MoveTo(m_p2.x, m_p2.y);
		pDC->SetROP2(nDrawmode); //�ظ���ͼģ

		//�ú�ɫ���������߶�
		CPen PenRed(PS_SOLID, 1, RGB(255, 0, 0)); //�����ɫ��
		pDC->SelectObject(&PenRed);
		C_S_Line(pDC, m_p1.x, m_p1.y, m_p2.x, m_p2.y);
		ReleaseDC(pDC); //�ͷ��豸����
	}else if(m_Type == 11){
		// �������ʵ�ֽ���ʽ�ƶ�ͼ��
		pDC->SelectStockObject(NULL_BRUSH);
		if (!m_ist)
		{
		  mp1=mp2=point;
		  m_ist++;
		}
		else
		{
			mp2=point;  //��¼�ڶ��ε�������λ��
			m_ist--;   // Ϊ��һ���ƶ���׼��
	    }
	}
	CView::OnLButtonDown(nFlags, point);
}

void CCG_xView::OnCancelMode() 
{
	CView::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CCG_xView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CDC *pDC = GetDC();

	//****************************************����ƶ�***********************************************//
	char tbuf[80];
	sprintf(tbuf, "Mouse Position:(%3d, %3d)      ", point.x, point.y);
	//������ƶ�ʱ�����ǰλ��
	pDC->TextOut(700, 10, tbuf);
		
	if(m_Type == 1){
		//mouse Over
		int nDrawmode = pDC->SetROP2(R2_NOT); //��������ͼģʽ��������ԭ���Ļ�ͼģʽ
		pDC->SelectStockObject(NULL_BRUSH);
		if(m_ist == 1)
		{
			CPoint prePnt, curPnt;
			prePnt = m_bR; //��ȡ������ڵ�ǰһλ��
			curPnt = point;
			//������Ƥ����
			DrawCircle(pDC, m_bO, prePnt);
			DrawCircle(pDC, m_bO, curPnt);
			m_bR = point;
		}
		pDC->SetROP2(nDrawmode);
		ReleaseDC(pDC);
	}else if(m_Type == 2){ //����ƶ���ֱ��
		int nDrawmode = pDC->SetROP2(R2_NOT); //��������ͼģʽ��������ԭ���Ļ�ͼģʽ
		pDC->SelectStockObject(NULL_BRUSH);
		if(m_ist == 1)
		{
			CPoint prePnt, curPnt;
			prePnt = m_p2; //���������ڵ�ǰһλ��
			curPnt = point;
			//������Ƥ����
			DDAMouseLine(pDC, m_p1.x, m_p1.y, m_p2.x, m_p2.y, RGB(255,0,0));
			//ʹ�����ģʽ�ظ���ֱ�ߣ���������ֱ��
			DDAMouseLine(pDC, m_p1.x, m_p1.y, curPnt.x, curPnt.y, RGB(255, 0, 0));
			//�õ�ǰλ����Ϊֱ�ߵ��յ�
			m_p2 = point;
		}
		//�ָ�Ԫ��ͼģʽ
		pDC->SetROP2(nDrawmode);
		ReleaseDC(pDC);
	}else if(m_Type == 3){


	}else if(m_Type == 4){
		//4���е㷨����ʽ��Բ
		int nDrawmode = pDC->SetROP2(R2_NOT); //��������ͼģʽ��������ԭ����ͼģʽ
		pDC->SelectStockObject(NULL_BRUSH);
		if(m_ist == 1){
			CPoint prePnt, curPnt;
			prePnt = m_bR; //��ȡ������ڵ�ǰһλ��
			curPnt = point;
			//������Ƥ����
			m_r = ComputeRadius(m_bO, prePnt);
			MidpointCircle(pDC, m_bO.x, m_bO.y, m_r, RGB(255, 0, 0));//�����ģʽ�ظ���Բ������������Բ
			m_r = ComputeRadius(m_bO, curPnt);
			MidpointCircle(pDC, m_bO.x, m_bO.y, m_r, RGB(255, 0, 0));//�õ�ǰλ����ΪԲ���ϵĵ㻭Բ
			m_bR = point;
		}
		pDC->SetROP2(nDrawmode); //�ָ�ԭ��ͼģʽ

		ReleaseDC(pDC);
	}else if(m_Type == 5){
		//5���е㷨����ʽ����Բ
		int nDrawmode = pDC->SetROP2(R2_NOT); //��������ͼģʽ��������ԭ����ͼģʽ
		pDC->SelectStockObject(NULL_BRUSH);
		if(m_ist == 1){
			CPoint prePnt, curPnt;
			prePnt = RightBottom; //��ȡ������ڵ�ǰһλ��
			curPnt = point;
			//������Ƥ����
			CenterPoint.x = (LeftTop.x+prePnt.x)/2;
			CenterPoint.y = (LeftTop.y+prePnt.y)/2;
			a = (int)abs(prePnt.x-LeftTop.x)/2;
			b = (int)abs(prePnt.y-LeftTop.y)/2;
			MidpointEllise(pDC, CenterPoint.x, CenterPoint.y, a, b, RGB(255, 0, 0));//�����ģʽ�ظ���tuoԲ������������tuoԲ
			//�õ�ǰ����Ϊ���½ǵ㣬����Բ
			CenterPoint.x = (LeftTop.x+curPnt.x)/2;
			CenterPoint.y = (LeftTop.y+curPnt.y)/2;
			a = (int)abs(curPnt.x-LeftTop.x)/2;
			b = (int)abs(curPnt.y-LeftTop.y)/2;
			MidpointEllise(pDC, CenterPoint.x, CenterPoint.y, a, b, RGB(255, 0, 0));
			RightBottom = point;
		}
		pDC->SetROP2(nDrawmode); //�ָ�ԭ��ͼģʽ

		ReleaseDC(pDC);
	}else if(m_Type == 10){
		//10������ʽ��������㷨�����߶� 
		int nDrawmode = pDC->SetROP2(R2_NOT); //��������ͼģʽ��������ԭ����ͼģʽ
		pDC->SelectStockObject(NULL_BRUSH);
		if(m_ist == 1)
		{
			CPoint prePnt, curPnt;
			prePnt = m_p2; //���������ڵ�ǰһλ��
			curPnt = point;
			//������Ƥ����
			pDC->MoveTo(m_p1.x, m_p1.y);
			pDC->LineTo(prePnt.x, prePnt.y);

			//�����ģʽ�ظ���ֱ�ߣ�����������ֱ��
			pDC->MoveTo(m_p1.x, m_p1.y);
			pDC->LineTo(curPnt.x, curPnt.y);
			//�õ�ǰλ�û�ֱ��
			m_p2 = point;
		}
		pDC->SetROP2(nDrawmode); //�ָ�ԭ��ͼģʽ
		ReleaseDC(pDC);
	}else if(m_Type == 11){
		int nDrawmode=pDC->SetROP2(R2_NOT); //��������ͼģʽ��������ԭ����ͼģʽ
		pDC->SelectStockObject(NULL_BRUSH);
		if(m_ist==1)
		{
			CPoint prePnt,curPnt;
			int dx,dy;
			prePnt=mp2;  //���������ڵ�ǰһλ��
			curPnt=point;
			//������Ƥ����
			pDC->MoveTo(p1);pDC->LineTo(p2);//�����ģʽ����������ֱ��
			dx=curPnt.x-prePnt.x;dy=curPnt.y-prePnt.y;
			p1.x=p1.x+dx;p1.y=p1.y+dy;
			p2.x=p2.x+dx;p2.y=p2.y+dy;
			pDC->MoveTo(p1);pDC->LineTo(p2);  //�õ�ǰλ�û��ֱ��
			mp2=point;
		}	
		pDC->SetROP2(nDrawmode);  //�ָ�ԭ��ͼģʽ
		ReleaseDC(pDC);  //�ͷ��豸����
	}
	CView::OnMouseMove(nFlags, point);
}

void CCG_xView::OnCaptureChanged(CWnd *pWnd) 
{
	// TODO: Add your message handler code here
	
	CView::OnCaptureChanged(pWnd);
}


void CCG_xView::DrawCircle(CDC *pDC, CPoint cenp, CPoint arbp)
{
	//��Բ
	int radius = ComputeRadius(cenp, arbp);
	//��Բ��ȷ������Բ����������
	CRect rc(cenp.x - radius, cenp.y - radius, cenp.x + radius, cenp.y + radius);
	pDC->Ellipse(rc);
}


int CCG_xView::ComputeRadius(CPoint cenp, CPoint ardp)
{
	int dx = cenp.x - ardp.x;
	int dy = cenp.y - ardp.y;
	return (int)sqrt(dx*dx + dy*dy);

}

void CCG_xView::OnMENU33MouseSprint() 
{
	// TODO: Add your command handler code here
	//��ʼ�����
	m_Type = 1;
	l_Type = 0;
	//��Ƥ�����Բ
	CDC *pDC = GetDC();
	pDC->SelectStockObject(NULL_BRUSH);
	//��ʼ��Բ��(0, 0) Բ�ϵĵ�(0, 0)
	m_bO.x = 0;
	m_bO.y = 0;
	m_bR.x = 0;
	m_bR.y = 0;

	DrawCircle(pDC, m_bO, m_bR);
}

//DEL void CCG_xView::ddaline(CDC *pDC, int x0, int y0, int x1, int y1, COLORREF color)
//DEL {
//DEL 	//ʵ��DDA���߳���
//DEL 	int length, i;
//DEL 	float x, y, dx, dy;
//DEL 	length = abs(x1 - x0);
//DEL 	if(abs(y1-y0)>length)
//DEL 	{
//DEL 		length=abs(y1-y0);
//DEL 		dx=(x1-x0)/length;
//DEL 		dy=(y1-y0)/length;
//DEL 		x=x0+0.5;
//DEL 		y=y0+0.5;
//DEL 		for(i=1; i<=length; i++)
//DEL 		{
//DEL 			pDC->SetPixel((int)x, (int)y, color);
//DEL 			x = x+dx;
//DEL 			y = y+dy;
//DEL 		}
//DEL 	}
//DEL }

void CCG_xView::ddaline(CDC *pDC, int x0, int y0, int x1, int y1, COLORREF color)
{
	//ʵ��DDA���߳���
	int length, i;
	double x, y, dx, dy;
	length = abs(x1 - x0);
	if(abs(y1-y0)>length)
	{
		length=abs(y1-y0);
		dx=(double)(x1-x0)/length;
		dy=(double)(y1-y0)/length;
		x=x0+0.5;
		y=y0+0.5;
		for(i=1; i<=length; i++)
		{
			pDC->SetPixel((int)x, (int)y, color);
			x = x+dx;
			y = y+dy;
		}
	}
	else
	{
		length=abs(x1-x0);
		dx=(x1-x0)/length;
		dy=(y1-y0)/length;
		x=x0+0.5;
		y=y0+0.5;
		for(i=1; i<=length; i++)
		{
			pDC->SetPixel((int)x, (int)y, color);
			x = x+dx;
			y = y+dy;
		}
	}
}

void CCG_xView::OnMENU341DDAOnDraw() 
{
	// TODO: Add your command handler code here
	//ʵ��DDA���߳���
	CDC *pDC = GetDC();
	ddaline(pDC, 100, 100, 400, 100, RGB(255, 0, 0));
	ddaline(pDC, 400, 100, 400, 400, RGB(0, 255, 0));
	ddaline(pDC, 400, 400, 100, 400, RGB(0, 0, 255));
	ddaline(pDC, 100, 400, 100, 100, RGB(255, 255, 0));
	ddaline(pDC, 100, 100, 400, 400, RGB(255, 0, 255));
	ddaline(pDC, 100, 400, 400, 100, RGB(0, 255, 255));
}

void CCG_xView::OnMENU342FangDa10() 
{
	// TODO: Add your command handler code here
	//�Ŵ�10������㷨
	CDC *pDC = GetDC();
	//������
	int gi, gj;
	//������
	pDC->TextOut(90, 90, "(100, 100)");
	pDC->MoveTo(100, 100);
	for(gj = 100; gj<=400; gj=gj+10)
	{
		pDC->MoveTo(100, gj);
		pDC->LineTo(600, gj);
	}
	//������
	pDC->MoveTo(100, 100);
	for(gi = 100; gi<=600; gi=gi+10)
	{
		pDC->MoveTo(gi, 100);
		pDC->LineTo(gi, 400);
	}
	pDC->TextOut(590, 410, "(600, 400)");

	//�����񽹵�
	DDA2Line(pDC, 100, 100, 600, 400, RGB(255, 0, 0));
	
}

void CCG_xView::DDA2Line(CDC *pDC, int x0, int y0, int x1, int y1, COLORREF color)
{
	//DDA2Line()����
	int length, i, tx, ty;
	double x, y, dx, dy;
	length = abs(x1 - x0);
	if(abs(y1-y0)>length)
	{
		length = abs(y1 - y0);
		dx = (float)(x1 - x0)/length;
		dy = (float)(y1 - y0)/length;
		x = x0;
		y = y0;
		for( i = 0; i<=length; i=i+10)
		{
			tx = (int)((x+5)/10)*10;
			ty = (int)((y+5)/10)*10;

			pDC->SetPixel(tx, ty, color);
			pDC->Ellipse(tx -5, ty - 5, tx+5, ty+5);
			x = x +dx*10;
			y = y + dy*10;
		}
	}
	else{
		length = abs(x1 - x0);
		dx = (float)(x1 - x0)/length;
		dy = (float)(y1 - y0)/length;
		x = x0;
		y = y0;
		for( i = 0; i<=length; i=i+10)
		{
			tx = (int)((x+5)/10)*10;
			ty = (int)((y+5)/10)*10;

			pDC->SetPixel(tx, ty, color);
			pDC->Ellipse(tx -5, ty - 5, tx+5, ty+5);
			x = x + dx*10;
			y = y + dy*10;
		}

	}
}


void CCG_xView::OnMENU343MouseLine() 
{
	// TODO: Add your command handler code here
	//��ʼ���������
	m_Type = 2;
	//ʵ�ֽ���ʽ��ֱ��
	CDC *pDC = GetDC();
	pDC->SelectStockObject(NULL_BRUSH);
	//��ʼ��ֱ�����(0, 0) �յ�(0, 0)
	m_p1.x = 0;
	m_p1.y = 0;
	m_p2.x = 0;
	m_p2.y = 0;
	//�����Զ���ĳ�Ա����������껭ֱ��
	DDAMouseLine(pDC, m_p1.x, m_p1.y, m_p2.x, m_p2.y, RGB(255, 0, 0));
}

void CCG_xView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDblClk(nFlags, point);
}

void CCG_xView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CCG_xView::DDAMouseLine(CDC *pDC, int x0, int y0, int x1, int y1, COLORREF color)
{
	//�������飬��־�Ƿ���   �㻮��
	int array1[35] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
	int count = 0;
	//p42��7��
	int length, i;
	double x, y, dx, dy;
	length = abs(x1-x0);
	if(abs(y1-y0)>length)
	{
		length = abs(y1 - y0);
		dx = (double)(x1- x0)/length;
		dy = (double)(y1 - y0)/length;
		x = x0+0.5;
		y = y0+0.5;

		//ʵ��
		
		for(i = 1; i<=length; i++)
		{
			if(m_Type == 8 && array1[(count++)%35]==0){
				//ʲô������
				count = count%35;
			}else{
				count++;
				pDC->SetPixel((int)x, (int)y, color);
				if(l_Type == 1){
					//��ˢ�Ӽ�����ֱ��
					pDC->SetPixel((int)x, (int)y-1, color);
					pDC->SetPixel((int)x, (int)y+1, color);
					pDC->SetPixel((int)x, (int)y-2, color);
					pDC->SetPixel((int)x, (int)y+2, color);
				}else if(l_Type == 2){
					//��ˢ�Ӽ�����ֱ��
					pDC->SetPixel((int)x, (int)y-1, color);
					pDC->SetPixel((int)x, (int)y+1, color);
					pDC->SetPixel((int)x-1, (int)y, color);
					pDC->SetPixel((int)x+1, (int)y, color);

					pDC->SetPixel((int)x-1, (int)y-1, color);
					pDC->SetPixel((int)x-1, (int)y+1, color);
					pDC->SetPixel((int)x+1, (int)y-1, color);
					pDC->SetPixel((int)x+1, (int)y+1, color);
				}
			}
			x = x+dx;
			y = y+dy;
		}
	}else{
	//	length = abs(y1 - y0);
		dx = (double)(x1- x0)/length;
		dy = (double)(y1 - y0)/length;
		x = x0+0.5;
		y = y0+0.5;
		for(i = 1; i<=length; i++)
		{
			if(m_Type == 8 && array1[(count++)%35]==0){
				//ʲô������
				count = count%35;
			}else{
				count++;
				pDC->SetPixel((int)x, (int)y, color);
				if(l_Type == 1){
					//��ˢ�Ӽ�����ֱ��
					pDC->SetPixel((int)x, (int)y-1, color);
					pDC->SetPixel((int)x, (int)y+1, color);
					pDC->SetPixel((int)x, (int)y-2, color);
					pDC->SetPixel((int)x, (int)y+2, color);
				}else if(l_Type == 2){
					//��ˢ�Ӽ�����ֱ��
					pDC->SetPixel((int)x, (int)y-1, color);
					pDC->SetPixel((int)x, (int)y+1, color);
					pDC->SetPixel((int)x-1, (int)y, color);
					pDC->SetPixel((int)x+1, (int)y, color);

					pDC->SetPixel((int)x-1, (int)y-1, color);
					pDC->SetPixel((int)x-1, (int)y+1, color);
					pDC->SetPixel((int)x+1, (int)y-1, color);
				}
			}
			x = x+dx;
			y = y+dy;
		}
	}
}

void CCG_xView::OnMenuClearall() 
{
	// TODO: Add your command handler code here
	///ʵ����������  p34ҳ
//	key = 0;
	RedrawWindow();
	m_Type = 0;
	l_Type = 0;
}

void CCG_xView::OnMenu35Pen() 
{
	// TODO: Add your command handler code here
	//p33ҳ��Ǧ�ʹ���
	//�����������Ϊ3��Ǧ�ʹ��ܣ�ͽ�ֻ��ߣ�
	m_Type = 3;
	l_Type = 0;
	m_FontColor = RGB(0, 255, 0);
	m_penwidth = 1;
	
}

void CCG_xView::OnMENU461MidpointCircle() 
{
	// TODO: Add your command handler code here
	//p44����ʽ��Բ
	//�����������Ϊ���е㷨����ʽ��Բ
	m_Type = 4;
	l_Type = 0;
	
}

void CCG_xView::MidpointCircle(CDC *pDC, int x0, int y0, int r, COLORREF color)
{
	//�е㷨ɨ��ת���㷨--��Բ
	int x, y;
	double d;
	x = 0;
	y = r;
	d = 1.25 - r;
	CirPot(pDC, x0, y0, x, y, color);
	while(x<=y){
		if(d<0){
			d+=2*x+3;
			x++;
		}else{
			d+=2*(x-y)+5;
			x++;
			y--;
		}
		CirPot(pDC, x0, y0, x, y, color);
	}//while
}

void CCG_xView::CirPot(CDC *pDC, int x0, int y0, int x, int y, COLORREF color)
{
	//��1/8Բ
	pDC->SetPixel((x0+x), (y0+y), color);
	pDC->SetPixel((x0+y), (y0+x), color);
	pDC->SetPixel((x0+y), (y0-x), color);
	pDC->SetPixel((x0+x), (y0-y), color);
	pDC->SetPixel((x0-x), (y0-y), color);
	pDC->SetPixel((x0-y), (y0-x), color);
	pDC->SetPixel((x0-y), (y0+x), color);
	pDC->SetPixel((x0-x), (y0+y), color);
	if(l_Type == 1){
		for(int k = 1; k<4; k++){
			pDC->SetPixel((x0+x), (y0+y)-k, color);
			pDC->SetPixel((x0+x), (y0+y)+k, color);

			pDC->SetPixel((x0+y), (y0+x)-k, color);
			pDC->SetPixel((x0+y), (y0+x)+k, color);

			pDC->SetPixel((x0+y), (y0-x)-k, color);
			pDC->SetPixel((x0+y), (y0-x)+k, color);

			pDC->SetPixel((x0+x), (y0-y)-k, color);
			pDC->SetPixel((x0+x), (y0-y)+k, color);

			pDC->SetPixel((x0-x), (y0-y)-k, color);
			pDC->SetPixel((x0-x), (y0-y)+k, color);

			pDC->SetPixel((x0-y), (y0-x)-k, color);
			pDC->SetPixel((x0-y), (y0-x)+k, color);

			pDC->SetPixel((x0-y), (y0+x)-k, color);
			pDC->SetPixel((x0-y), (y0+x)+k, color);

			pDC->SetPixel((x0-x), (y0+y)-k, color);
			pDC->SetPixel((x0-x), (y0+y)+k, color);
		}

	}else if(l_Type == 2){
		for(int k = 1; k<4; k++){
			pDC->SetPixel((x0+x), (y0+y)-k, color);
			pDC->SetPixel((x0+x), (y0+y)+k, color);
			pDC->SetPixel((x0+x)-k, (y0+y), color);
			pDC->SetPixel((x0+x)+k, (y0+y), color);


			pDC->SetPixel((x0+y), (y0+x)-k, color);
			pDC->SetPixel((x0+y), (y0+x)+k, color);
			pDC->SetPixel((x0+y)-k, (y0+x), color);
			pDC->SetPixel((x0+y)+k, (y0+x), color);

			pDC->SetPixel((x0+y), (y0-x)-k, color);
			pDC->SetPixel((x0+y), (y0-x)+k, color);
			pDC->SetPixel((x0+y)-k, (y0-x), color);
			pDC->SetPixel((x0+y)+k, (y0-x), color);


			pDC->SetPixel((x0+x), (y0-y)-k, color);
			pDC->SetPixel((x0+x), (y0-y)+k, color);
			pDC->SetPixel((x0+x)-k, (y0-y), color);
			pDC->SetPixel((x0+x)+k, (y0-y), color);

			pDC->SetPixel((x0-x), (y0-y)-k, color);
			pDC->SetPixel((x0-x), (y0-y)+k, color);
			pDC->SetPixel((x0-x)-k, (y0-y), color);
			pDC->SetPixel((x0-x)+k, (y0-y), color);

			pDC->SetPixel((x0-y), (y0-x)-k, color);
			pDC->SetPixel((x0-y), (y0-x)+k, color);
			pDC->SetPixel((x0-y)-k, (y0-x), color);
			pDC->SetPixel((x0-y)+k, (y0-x), color);

			pDC->SetPixel((x0-y), (y0+x)-k, color);
			pDC->SetPixel((x0-y), (y0+x)+k, color);
			pDC->SetPixel((x0-y)-k, (y0+x), color);
			pDC->SetPixel((x0-y)+k, (y0+x), color);

			pDC->SetPixel((x0-x), (y0+y)-k, color);
			pDC->SetPixel((x0-x), (y0+y)+k, color);
			pDC->SetPixel((x0-x)-k, (y0+y), color);
			pDC->SetPixel((x0-x)+k, (y0+y), color);
		}

	}

}

void CCG_xView::OnMENU462MidpointEllise() 
{
	// TODO: Add your command handler code here
	//p48����ʽ����Բ
	//�����������Ϊ���е㷨����ʽ����Բ
	m_Type = 5;
}

void CCG_xView::MidpointEllise(CDC *pDC, int x0, int y0, int a, int b, COLORREF color)
{
	//�е㷨ɨ��ת���㷨--��Բ
	int x, y;
	double d1, d2;
	x = 0;
	y =b;
	d1 = b*b+a*a*(-b+0.25);
	pDC->SetPixel(x+x0, y+y0, color);
	while(b*b*(x+1)<a*a*(y-0.5)){
		if(d1<0){
			d1 += b*b*(2*x+3);
			x++;
		}else{
			d1 += (b*b*(2*x+3)+a*a*(-2*y+2));
			x++;
			y--;
		}
		ElisePot(pDC, x0, y0, x, y, color);
	}//while �ϰ벿��
	d2 = (b*(x+0.5))*(b*(x+0.5))+(a*(y-1))*(a*(y-1))-(a*b)*(a*b);
	while(y>0){
		if(d2<0){
			d2 += b*b*(2*x+2)+a*a*(-2*y+3);
			x++;
			y--;
		}else{
			d2 += a*a*(-2*y+3);
			y--;
		}
		ElisePot(pDC, x0, y0, x, y, color);
	}//while �°벿��

}

void CCG_xView::ElisePot(CDC *pDC, int x0, int y0, int x, int y, COLORREF color)
{
	//��1/4��Բ
	pDC->SetPixel((x0+x), (y0+y), color);
	pDC->SetPixel((x0+x), (y0-y), color);
	pDC->SetPixel((x0-x), (y0-y), color);
	pDC->SetPixel((x0-x), (y0+y), color);
}

void CCG_xView::OnMenuColor() 
{
	// TODO: Add your command handler code here
	//ʵ����ɫ��ѡ����ɫ
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_RGBINIT | CC_FULLOPEN;
	dlg.m_cc.rgbResult = m_PenColor;

	//m_PenColor��һ����Ա�������������浱ǰ��ɫ
	if(IDOK == dlg.DoModal()){
		m_PenColor = dlg.m_cc.rgbResult;
	}
	
}

void CCG_xView::OnMENU51SpeedFill() 
{
	// TODO: Add your command handler code here
		//ɨ��������㷨
	//m_Type:6��ɨ��������㷨
	m_Type = 6;
	l_Type = 0;
	//���廭����ɫ
	CPen PenRed(PS_SOLID, 1, RGB(255, 0, 0)); //�����ɫ��
	CPen PenBlue(PS_SOLID, 1, RGB(0, 0, 255)); //������ɫ��
	int x, y;
	//����ɫ���ʻ�������еı߽�
	CDC* pDC = GetDC();
	pDC->SelectObject(&PenBlue);
	POINT polygon[5] = {{300, 120}, {390, 160}, {430, 320}, {180, 300}, {150, 240}};
	pDC->Polygon(polygon, 5);
	//��������λ�ã�����ɫoldcolor�����ɫnewcolor
	x = 300;
	y = 200;
	COLORREF newcolor = RGB(255, 0, 0);
	COLORREF oldcolor = RGB(255, 255, 255);
	//����ɨ��������㷨
	floodfill4(x, y, oldcolor, newcolor);
	
}

int CCG_xView::stackpop()
{
	//�����ջ
	int val;
	val = stack[stack_top];
	stack_top = stack_top-1;
	return val;
}

void CCG_xView::stackpush(int p_xy)
{
	//������ջ
	stack_top += 1;
	stack[stack_top] = p_xy;

}

void CCG_xView::setstackempty()
{
	//���ջ
	int i;
	for(i = 0; i<=stack_top; i++){
		stack[i] = 0;
		stack_top = 0;
	}

}

int CCG_xView::isstackempty()
{
	//�ж�ջ�Ƿ�Ϊ��ջ
	if(stack_top>0){
		return 1;
	}else{
		return 0;
	}

}

void CCG_xView::floodfill4(int x, int y, COLORREF oldcolor, COLORREF newcolor)
{

	int yy = y;
	int xx = x;
	//����ͨ�㷨
	CDC* pDC = GetDC();
	int xl, xr, x0, xnextspan;
	bool spanNeedFill;
	//��ջ���
	setstackempty();
	//������ջ
	stackpush(x);
	stackpush(y);
	while(isstackempty()!=0){
		//ջ����ջ��ע���ջ˳��
		y = stackpop();
		x = stackpop();
		pDC->SetPixel(x, y, newcolor);
		x0 = x+1;
		while(pDC->GetPixel(x0, y) == oldcolor){
			//�������
			pDC->SetPixel(x0, y, newcolor);
			x0++;
		}
		xr = x0-1; //����Ԫ��
		x0 = x-1;
		while(pDC->GetPixel(x0, y) == oldcolor){ //�������
			if(y>120){
				pDC->SetPixel(x0, y, newcolor);
				x0--;
			}else{
				break;
			}
		}
		xl = x0+1; //����Ԫ��
		/*xl                                           xr*/
		//���������һ��ɨ����
		x0 = xl;
		y = y+1;
		while(x0<=xr){
			spanNeedFill = false;
			while(pDC->GetPixel(x0, y) == oldcolor){
				if(spanNeedFill == false)
					spanNeedFill = true;
				x0++;
			}
			if(spanNeedFill){
				if(x0 == xr){
					stackpush(x0);
					stackpush(y);
				}else{
					stackpush(x0-1);
					stackpush(y);
				}
				spanNeedFill = false;
			}//end if
			xnextspan = x0;
			while(pDC->GetPixel(x, y)!=oldcolor && x0<xr)
				x0++;
			if(xnextspan == x0)
				x0++;
		}//end of while(x0<=xr)

	}//end of while(!isstackempty())

///////////////////�����ϱߵ���
	y = yy;
	x = xx;
	//��ջ���
	setstackempty();
	//������ջ
	stackpush(x);
	stackpush(y);
	while(isstackempty()!=0){
		//ջ����ջ��ע���ջ˳��
		y = stackpop();
		x = stackpop();
	//	pDC->SetPixel(x, y, newcolor);
		x0 = x;
		while(pDC->GetPixel(x0, y) == oldcolor){ //�������
			if(y>120){
				pDC->SetPixel(x0, y, newcolor);
				x0++;
			}else{
				return ;
			}

		}
		xr = x0-1; //����Ԫ��
		x0 = x-1;
		while(pDC->GetPixel(x0, y) == oldcolor){ //�������
			pDC->SetPixel(x0, y, newcolor);
			x0--;
		}
		xl = x0+1; //����Ԫ��
		if(xl == xr){
			setstackempty();
		}
		/*xl                                           xr*/
		//���������һ��ɨ����
		x0 = (int)(xr+xl)/2;

		y = y-1;
		while(x0<=xr){
			spanNeedFill = false;
			while(pDC->GetPixel(x0, y) == oldcolor){
				if(spanNeedFill == false)
					spanNeedFill = true;
				x0++;
			} //
/*			if(spanNeedFill){
				if(x0 == xr){
					stackpush(x0);
					stackpush(y);
				}else{*/
					stackpush(x0-1);
					stackpush(y);
					break;
	//			}
				spanNeedFill = false;
	//		}//end if
			xnextspan = x0;
			while(pDC->GetPixel(x, y)!=oldcolor && x0<xr)
				x0++;


		}//end of while(x0<=xr)

	}//end of while(!isstackempty())


}

void CCG_xView::SeedFill(int xe, int ye, COLORREF newcolor, COLORREF oldcolor)
{
	//ʵ����������㷨
	CClientDC dc(this);
	//�����ӵ�Ϊ����ɫ
	if(dc.GetPixel(xe, ye) == oldcolor){
		SeedFill(xe-1, ye, newcolor, oldcolor);
		SeedFill(xe+1, ye, newcolor, oldcolor);
		SeedFill(xe, ye-1, newcolor, oldcolor);
		SeedFill(xe, ye+1, newcolor, oldcolor);
	}//�ݹ�
}

void CCG_xView::OnMENU52SpeedFillZhongzi() 
{
	// TODO: Add your command handler code here
	//������������㷨
	m_Type = 7;
	l_Type = 0;
	
}

void CCG_xView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if( m_Type== 7){
		//7����������㷨
		int xe = point.x;
		int ye = point.y;
//		printf("(%d, %d)", xe, ye);
		int newcolor = RGB(255, 0, 0);
		int oldcolor = RGB(255, 255, 255);
		SeedFill(xe, ye, newcolor, oldcolor);

	}
	
	CView::OnLButtonUp(nFlags, point);
}

void CCG_xView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	
}

void CCG_xView::OnMenu611Line() 
{
	// TODO: Add your command handler code here
	//��ˢ�ӽ���ʽ��ֱ��
	m_Type = 2;
	l_Type = 1;
	
}

void CCG_xView::OnMenu612Cricle() 
{
	// TODO: Add your command handler code here
	//��ˢ�ӽ���ʽ��Բ
	m_Type = 4;
	l_Type = 1;
	
}

void CCG_xView::OnMenu621Line() 
{
	// TODO: Add your command handler code here
	//��ˢ�Ӽ�����ֱ��
	m_Type = 2;
	l_Type = 2;
}

void CCG_xView::OnMenu622Cricle() 
{
	// TODO: Add your command handler code here
	//��ˢ�ӽ���ʽ��Բ
	m_Type = 4;
	l_Type = 2;
}

void CCG_xView::OnMenu37Dotline() 
{
	// TODO: Add your command handler code here
	//�㻮��
	m_Type = 8;
	
}

void CCG_xView::OnMENU71MouseCodeClip() 
{
	// TODO: Add your command handler code here
	//p60�����ʵ�ֽ���ʽ����Ч��
	m_Type = 10;
	l_Type = 0;
	//���廭��
	CPen PenRed(PS_SOLID, 1, RGB(255, 0, 0)); //������
	CPen PenBlue(PS_SOLID, 1, RGB(0, 0, 255));//������ɫ��

	CDC *pDC = GetDC();
	//�Ȼ������ڣ�������
	pDC->SelectObject(&PenBlue);
	pDC->Rectangle(WL, WB, WR, WT);
	
}

void CCG_xView::encode(int x, int y, int *code)
{
	//ͼ�μ����㷨��ʵ������9������
	int c = 0;
	if(x<WL){
		c = c | LEFT;
	}else if(x>WR){
		c = c | RIGHT;
	}
	if(y<WB){
		c = c | BOTTOM;
	}else if(y>WT){
		c = c | TOP;
	}
	*code = c;

}

int CCG_xView::C_S_Line(CDC *pDC, int x1, int y1, int x2, int y2)
{
	//p60�����ʵ�ֽ���ʽ����Ч��
	
	int code1, code2, code, x, y;
	encode(x1, y1, &code1); //(x1, y1)���ı���
	encode(x2, y2, &code2); //(x2, y2)���ı���
	while(code1 != 0 || code2 != 0) //��code1������0 �� code2������0
	{
		//��code1��code2������0,��ͬ��
		if((code1&code2)!=0)
			return 0;
		if(code1 ==0)
			code = code2;
		//�󽻵�
		if((LEFT&code)!=0){
			x = WL;
			y = y1+(y2-y2)*(WL-x1)/(x2-x1);
		}else if((RIGHT&code)!=0){
			x = WR;
			y = y1+(y2-y1)*(WR-x1)/(x2-x1);
		}else if((BOTTOM&code)!=0){
			y = WB;
			x = x1+(x2-x1)*(WR-y1)/(y2-y1);
		}else if((TOP&code)!=0){
			y = WT;
			x = x1+(x2-x1)*(WT-y1)/(y2-y1);
		}
		if(code == code1){
			x1 = x;
			y1 = y;
			encode(x, y, &code1);
		}else{
			x2 = x;
			y2 = y;
			encode(x, y, &code2);
		}
	}// end while, ��ʾcode1, code2��Ϊ0�����е��߶�Ϊ���Ӳ���

	pDC->MoveTo(x1, y1);
	pDC->LineTo(x2, y2);

	return 0;
}

void CCG_xView::OnMENU81Par() 
{
	// p74�����߳������
	Par(100, 700, 300, 100, 500, 600);
	
}

// ��֪��㡢�е���յ��������Ƶ������
void CCG_xView::Par(int xs, int ys, int xm, int ym, int xe, int ye)
{
	// ʵ���������㷨
	CDC *pDC = GetDC();
	// ����
	pDC->MoveTo(xs, ys);
	pDC->LineTo(xm, ym);
	pDC->MoveTo(xm, ym);
	pDC->LineTo(xe, ye);
	double n, t, dt, ax, ay, bx, by, cx, cy;
	int i;
	ax = xe - 2 * xm + xs;
	ay = ye - 2 * ym + ys;
	bx = 2.0 * (xm - xs);
	by = 2.0 * (ym - ys);
	cx = xs;
	cy = ys;
	n = sqrt(ax * ax + ay * ay);
	n = sqrt(n * 100.0);
	pDC->MoveTo(xs, ys);
	dt = 1.0/n;
	t = 0;
	for(i = 0; i<=n; i++){
		pDC->LineTo((int)(ax * t * t + bx * t + cx), (int)(ay * t * t + by * t + cy));
		t = t+dt;
	}
	pDC->LineTo(xe, ye);

}

void CCG_xView::OnMENU82Hermite() 
{
	// TODO: Add your command handler code here
	// p75Hermite�������
	CDC *pDC = GetDC();
	int i,px0,py0,px1,py1,curx,cury,k0,k1;
	double t,dt,rx0,ry0,rx1,ry1;
	k0=300;
	k1=10;
	px0=40;
	py0=40;
	px1=240;
	py1=40;
	rx0=k0*0.8320;
	ry0=k0*0.5547;
	rx1=k1*0.8320;
	ry1=-0.5547;
    //����������
	pDC->MoveTo(20, 20);
	pDC->LineTo(300,20);
	pDC->MoveTo(20, 20);
	pDC->LineTo(20,150);
    //������
	dt=0.01;
	t=0;
	pDC->MoveTo(px0,py0);
    for(i=0;i<=100;i++)
	{
		curx=(int)(h03(t)*px0+h13(t)*px1+h23(t)*rx0+h33(t)*rx1);
        cury=(int)(h03(t)*py0+h13(t)*py1+h23(t)*ry0+h33(t)*ry1);
        pDC->LineTo(curx,cury);
		t=t+dt;
	} 
	getchar();
//	closegraph();
//	restorecrtmode();
}

void CCG_xView::OnMENU83Bezier() 
{
	// TODO: Add your command handler code here
	CDC *pDC = GetDC();
	int i, j, n=2;  //n=2 ��ʾ����Bezier����
	double curx,cury,t,b;
    double  dt=0.01;
    int array[4][2]={{30,100},{100,30},{50,150},{200,40}};
    CPen PenRed(PS_SOLID,1,RGB(255,0,0));//�����ɫ��
    CPen PenBlue(PS_SOLID,1,RGB(0,0,255));//������ɫ��
    //���Ȼ�����������
    pDC->SelectObject(&PenBlue);
    pDC->MoveTo(array[0][0],array[0][1]);
    for (i=0;i<=n;i++)
	{
        pDC->LineTo(array[i][0],array[i][1]);
        //����Bezier����
        pDC->MoveTo(array[0][0],array[0][1]); //�ص����
        pDC->SelectObject(&PenRed);
        t=0.0;
		for (i=0;i<=(int)1/dt;i++)
        {
           curx=0; cury=0;
           for(j=0;j<=n;j++)
           {  
              b=Bernstein(j,n,t);
              curx=curx+array[j][0]*b;
              cury=cury+array[j][1]*b;
   	       }
           pDC->LineTo((int)curx,(int)cury);
           t=t+dt;
        }
	}

}

// 1
int CCG_xView::Multiply_n(int m, int n)
{
	int i,j,a;
	if (m!=0)
	{
		a=1;
		for (i=m+1;i<=n;i++)   //��m+1��(m+2)��(n-1).n
			a=a*i;
		for (j=1;j<=n-m;j++)   //��(n-m)!��C mn
			a=a/j;
		return a;
	}
	else
		return 1;
}
// 2
double CCG_xView::Bernstein(int m, int n, double t)
{
	int i,j;
	double sum;
	sum=Multiply_n(m,n);  //��C mn
	for (i=1;i<=m;i++)
		sum=sum*t;          // C mn tm
	for (j=1;j<=n-m;j++)
		sum=sum*(1-t);     // C mn tm(1-t)n-m
	return sum;
}

void CCG_xView::OnMENU84Bezier3() 
{
	// TODO: Add your command handler code here
	CDC *pDC = GetDC();
	// 3��Bezier����
	int i;
	int x0,y0,x1,y1,x2,y2,x3,y3,curx,cury;
	double t,dt;
	// ����������ͬ��ɫ�Ļ���
	CPen PenRed(PS_SOLID,1,RGB(255,0,0));
	CPen PenBlue(PS_SOLID,1,RGB(0,0,255));

	// ���ÿ��Ƶ㣬������������
	x0=220;y0=10;x1=410;y1=10;x2=225;y2=150;x3=410;y3=100;
	pDC->SelectObject(PenBlue); //ʹ����ɫ����
	pDC->MoveTo(x0,y0);
	pDC->LineTo(x1,y1);
	pDC->LineTo(x2,y2);
	pDC->LineTo(x3,y3);
	//����Bezier����
	pDC->MoveTo(x0,y0);
	t=0; dt=0.01;  //t��0��1��ÿ������0.01,ȡ100����
	pDC->SelectObject(PenRed); //ʹ�ú�ɫ����
	for (i=0;i<=100;i++)
	{
		curx=(int)(b03(t)*x0+b13(t)*x1+b23(t)*x2+b33(t)*x3);
		cury=(int)(b03(t)*y0+b13(t)*y1+b23(t)*y2+b33(t)*y3);
		pDC->LineTo(curx,cury);
		t=t+dt;
	}
}

double CCG_xView::b03(double t)
{
	return(pow(1-t,3));
}

double CCG_xView::b13(double t)
{
	return(3*t*pow(1-t,2));
}

double CCG_xView::b23(double t)
{
	return(3*(1-t)*t*t);
}

double CCG_xView::b33(double t)
{
	return(t*t*t);
}

double CCG_xView::h03(double t)
{
	return (2*pow(t,3)-3*t*t+1);
}

double CCG_xView::h13(double t)
{
	return (-2*pow(t,3)+3*t*t);
}

double CCG_xView::h23(double t)
{
	return (pow(t,3)-2*t*t+t);
}


double CCG_xView::h33(double t)
{
	return (pow(t,3)-2*t*t);
}	

void CCG_xView::OnMENU853ByangtaoLine() 
{
	// TODO: Add your command handler code here
	CDC *pDC = GetDC();
	//����B��������
	int n,m,pointnum,i,j;
	int x[10],y[10];
	double curx,cury; //(x[i],y[i])Ϊ��������
	double t,dt;
	 
	n=3; pointnum=5; //5�����㣬����ƣ�5-3��=2��B��������
	x[1]=10;y[1]=200;x[2]=40;y[2]=100;x[3]=100;y[3]=100;
	x[4]=150;y[4]=150;x[5]=150;y[5]=200;
	//������������
	pDC->MoveTo(x[1],y[1]);
	for (i=2;i<=pointnum;i++)
		pDC->LineTo(x[i],y[i]);
	//����B��������
	m=pointnum-n;  dt=0.01;
	for (i=1;i<=m;i++)    //����m��B��������
	{
		t=0;
		for (j=0;j<=100;j++) // ����ÿһ��B��������
		{
			curx=f03(t)*x[i]+f13(t)*x[i+1]+f23(t)*x[i+2]+f33(t)*x[i+3];
			cury=f03(t)*y[i]+f13(t)*y[i+1]+f23(t)*y[i+2]+f33(t)*y[i+3];
			if (j==0)
				pDC->MoveTo((int)curx,(int)cury);
			else
			{
				pDC->LineTo((int)curx,(int)cury);
				t+=dt;
			}
		}
	}

}

double CCG_xView::f03(double t)
{
	return ((-pow(t,3)+3*pow(t,2)-3*t+1)/6);
}

double CCG_xView::f13(double t)
{
	return ((3*pow(t,3)-6*pow(t,2)+4)/6);
}

double CCG_xView::f23(double t)
{
	return ((-3*pow(t,3)+3*pow(t,2)+3*t+1)/6);
}

double CCG_xView::f33(double t)
{
	return (pow(t,3)/6);
}

void CCG_xView::OnMENUCHANGEpingyi() 
{
	// ƽ�Ʊ任
	CDC *pDC=GetDC();
	int x,y,px,py,xx,yy,dx,dy;
	dx=80;
	dy=-50;
	double hx;
	CPoint tp;
	for (xx=-50;xx<=50;xx=xx+10) 
	{
		for (yy=-50;yy<=50;yy=yy+10)
		{
			for(x=-180;x<=180;x++)
			{
				hx=x*3.1415926/180;
				y=(int)(100*sin(hx));  
				px=320+x+xx;
				py=240-y-yy;
				tp.x=px;tp.y=py;
				pDC->SetPixel(tp,RGB(255,0,0));
			}
		}
	}
}

void CCG_xView::OnMenuChangeXuanxzhuan() 
{
	// ��ת���
	CDC *pDC=GetDC();
	int x, y, ang;
	double hx, hd, px, py;
	CPoint tp;
	for (ang=0;ang<=180;ang=ang+10)
	{
	    hd=ang*3.1415926/180;
		for(x=-180;x<=180;x++)
		{
			hx=x*3.1415926/180;
			y=(int)(100*sin(hx));  //��������
			px=320+(x*cos(hd)-y*sin(hd));
			py=240-(x*sin(hd)+y*cos(hd)); //��ת�������
			tp.x=(long)px;
			tp.y=(long)py;
			pDC->SetPixel(tp,RGB(255,0,0));
		}
	}
}

void CCG_xView::OnMenuChangeFangdasuoxiao() 
{
	// �Ŵ���С���
	CDC *pDC=GetDC();
	int x, y;
	double px, py;
    double hx, sx, sy;
    CPoint tp;
    sx=1.5;sy=0.5;     //���ȱ�������
	//����ǰ
    for(x=-180;x<=180;x++)
	{
		hx=x*3.1415926/180;
		y=(int)(100*sin(hx));  //��������
		px=320+x;
		py=240-y;
		tp.x=(long)px;
		tp.y=(long)py;
		pDC->SetPixel(tp,RGB(255,0,0));
	}
	//������
	for(x=-180;x<=180;x++)
	{
		hx=x*3.1415926/180;
		y=(int)(100*sin(hx));  //��������
		px=320+(int)x*sx;
		py=240-(int)y*sy;  //�����任
		tp.x=(long)px;
		tp.y=(long)py;
		pDC->SetPixel(tp,RGB(0,0,255));
	}
}

void CCG_xView::OnMENUOtherFlowers() 
{
	// ��
	CDC *pDC=GetDC();
	ASSERT_VALID(pDC);
	MidpointEllise(pDC, 430, 220, 100, 40, RGB(255,0,0));
	MidpointEllise(pDC, 430, 220, 40, 100, RGB(255,0,0));
	PositiveNegativeParabola(pDC, -0.7, -20, 3, RGB(255,0,0));
	PositiveNegativeParabola(pDC, -0.1, -20, 3, RGB(255,0,0));
}

void CCG_xView::PositiveNegativeParabola(CDC *pDC, double a, double b, double c, int color)
{
	// ����ʵ��
	int x, y;
	double d;
    x=0;
    y=0;
    pDC->SetPixel((int)(x+450+b), (int)(y+225+c), color);
    if(a>0)
	{   
		y=1;
		pDC->SetPixel((int)(x+450+b), (int)(y+225+c), color);
		d=1;
		while(y<=30)
		{
			if(d>=0)
			{
				d=d-2*a*x-a;
				x++;
			}
			else
			{
				d=d+1;
                y++;
			}
            pDC->SetPixel((int)(-x+450+b), (int)(y+225+c), color);
            pDC->SetPixel((int)(x+450+b), (int)(y+225+c), color);
		}
	}
    else if(a<0)
	{
		x=1;
        pDC->SetPixel((int)(x+450+b), (int)(y+225+c), color);
        d=1;
        while(y>=-35)
		{
            if(d>=0)
			{
                d=d-1;
                y--;
			}
            else
			{
                d=d-2*a*x-a;
                x++;
			}
            pDC->SetPixel((int)(-x+450+b), (int)(y+225+c), color);
			pDC->SetPixel((int)(x+450+b), (int)(y+225+c), color);
		}
	}
}

void CCG_xView::OnMenuOthersJiaohushiyidongtuxing() 
{
	// ����ʽ�ƶ�ͼ��
	CDC *pDC=GetDC();
	m_Type = 11; 	
	//���һ��ֱ��
	p1.x=200;p1.y=100;
	p2.x=550;p2.y=300;
	pDC->MoveTo(p1);
	pDC->LineTo(p2);

}
