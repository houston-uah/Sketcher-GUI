
// SketcherView.cpp : implementation of the CSketcherView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Sketcher.h"
#endif

#include "SketcherDoc.h"
#include "SketcherView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSketcherView

IMPLEMENT_DYNCREATE(CSketcherView, CView)

BEGIN_MESSAGE_MAP(CSketcherView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSketcherView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CSketcherView construction/destruction

CSketcherView::CSketcherView()
	: m_StartPoint(0, 0)
	, m_EndPoint(0, 0)
	, m_pTempShape(NULL)
{
	// TODO: add construction code here

}

CSketcherView::~CSketcherView()
{
}

BOOL CSketcherView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSketcherView drawing

void CSketcherView::OnDraw(CDC* pDC)
{
	CSketcherDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// Draw all the shapes
	CShape *s;
	s = pDoc->getFirstShape();
	while(s != NULL)
	{
		s->Draw(pDC);
		s = pDoc->getNextShape();
	}

	// Beginning of code from part 1
	/*
	CSketcherDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	// Demonstration drawing lines with default pen
	pDC->MoveTo(10, 10);
	POINT pt1;
	pt1.x = 50;
	pt1.y = 100;
	pDC->LineTo(pt1);
	CPoint pt2;
	pt2.x = 100;
	pt2.y = 50;
	pDC->LineTo(pt2);
	
	// Define some pens and draw lines.  Note: we save and
	//  restore the default pen.  You should also delete any
	//  pen you create, BUT NOT WHILE IT IS SELECTED IN THE DC.
	// Pen Styles: PS_SOLID, PS_DASH, PS_DOT, PS_DASHDOT, 
	// PS_DASHDOTDOT, PS_NULL, PS_INSIDEFRAME 
	CPen redPen(PS_SOLID, 1, RGB(255, 0, 0)); // Create solid red pen in one setp
	CPen* pOldPen = pDC->SelectObject(&redPen); // Set the pen to draw with
	pDC->MoveTo(10, 10);
	pDC->LineTo(50, 50);
	pDC->LineTo(100, 10);
	// Create dash green pen, 2 pixels wide, in 2 steps
	CPen greenPen;		
	greenPen.CreatePen(PS_DASH, 2, RGB(0, 255, 0));
	pDC->SelectObject(&greenPen);
	pDC->LineTo(250, 50);
	pDC->LineTo(400, 10);
	// Create a dotted, 5 pixels wide blue pen
	CPen bluePen(PS_DOT, 5, RGB(0, 0, 255));
	pDC->SelectObject(&bluePen);
	pDC->LineTo(400, 100);
	pDC->LineTo(450, 10);
	// Restore default pen
	pDC->SelectObject(pOldPen);
	// Delete the pens used. DO NOT DO THIS WHILE A PEN IS STILL
	//  SELECTED IN THE DC
	redPen.DeleteObject();
	greenPen.DeleteObject();
	bluePen.DeleteObject();

	// Create a brush for filling shapes
	// Styles: HS_HORIZONTAL, HS_VERTICAL, HS_BDIAGONAL, HS_FDIAGONAL, 
	// HS_CROSS, HS_DIAGCROSS
	// To create an empty brush use...
	// CBrush nBrush; // = pDC->CreateStockObject(NULL_BRUSH);
	// nBrush.CreateStockObject(NULL_BRUSH);
	// pDC->SelectObject(nBrush);

	// Create a solid red brush and fill 2 rectangles with it.
	// The outline is drawn with the currently set pen.  
	// Note: We save the default brush for later resetting
	CBrush redBrush(RGB(255, 0, 0));
	CBrush *pOldBrush = pDC->SelectObject(&redBrush);
	LPCRECT rect = new CRect(10, 100, 35, 125); 
	// Note: LPCRECT is a pointer and the rectangle args define
	// left, top, right, bottom coordinates.
	pDC->Rectangle(rect);
	// Create a blue brush with Diagonal Cross Hatching
	CBrush blueBrush(HS_DIAGCROSS, RGB(0, 0, 255));
	pDC->SelectObject(&blueBrush);
	pDC->Rectangle(10, 150, 60, 200);
	delete rect; // Get rid of the rectangle object

	// Reset to redBrush
	pDC->SelectObject(&redBrush);
	blueBrush.DeleteObject();  // Get rid of the blue brush

	// Draw a couple of ellipses (ovals). Note if width and
	//  height are equal the ellipse will be a circle
	pDC->Ellipse(50, 100, 100, 150);
	LPCRECT rect2 = new CRect(150, 150, 350, 200); 
	pDC->Ellipse(rect2);
	delete rect2;

	// Draw a couple of arcs, one filled with the red brush
	//  another filled with the default brush and lines drawn
	//  from the center to the defining points
	//BOOL Arc (LPCRECT rect, POINT StartPt, POINT EndPt);
	//BOOL Arc (LPCRECT rect, CPoint StartPt, CPoint EndPt);
	//BOOL Arc (int left, int top, int right, int bottom,
	//           int startX, int startY, int endX, int endY);
	LPCRECT rect3 = new CRect(250, 250, 350, 350);
	CPoint pt3, pt4;
	pt3.x = 350;
	pt3.y = 300;
	pt4.x = 350;
	pt4.y = 350;
	pDC->Arc(rect3, pt3, pt4);
	pDC->Arc(400, 400, 450, 500, 425, 375, 475, 600);
	// Note these lines show where the actual start and end points
	//  are by drawing lines from the center of the arc to the points.
	// Drawing is done in a counter-clockwise direction
	pDC->MoveTo(425, 450);
	pDC->LineTo(425, 375);
	pDC->MoveTo(425, 450);
	pDC->LineTo(475, 600);
	delete rect3;

	// Create a bitmap brush
	CBrush bmpBrush;

	// Put a .bmp file in the same directory as the source for this
	//   file and change the name in the line below.
	HBITMAP hBmp = (HBITMAP)LoadImage(NULL,"DukeBrush.bmp",IMAGE_BITMAP,0,0,
		LR_LOADFROMFILE|LR_DEFAULTSIZE);
	if(hBmp != NULL)
	{
		CBitmap Bmp;
		Bmp.Attach(hBmp);
		bmpBrush.CreatePatternBrush(&Bmp);
		pDC->SelectObject(bmpBrush);
	}
	// If creation of bitmap brush failed we will just use
	//  the previously set brush.

	// Draw a rectangle and an oval with the bitmap brush
	pDC->Rectangle(500, 400, 600, 500);
	pDC->Ellipse(600, 400, 700, 500);

	// Clean up
	pDC->SelectObject(pOldBrush); // Restore default brush, already did pen
	redBrush.DeleteObject();
	bmpBrush.DeleteObject();
	*/
	//Ending of code from part 1
}


// CSketcherView printing


void CSketcherView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSketcherView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSketcherView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSketcherView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSketcherView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSketcherView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSketcherView diagnostics

#ifdef _DEBUG
void CSketcherView::AssertValid() const
{
	CView::AssertValid();
}

void CSketcherView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSketcherDoc* CSketcherView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSketcherDoc)));
	return (CSketcherDoc*)m_pDocument;
}
#endif //_DEBUG


// CSketcherView message handlers


void CSketcherView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	m_StartPoint = point;

	CView::OnLButtonDown(nFlags, point);
}


void CSketcherView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(nFlags & MK_LBUTTON)  // Check to see if the left button is down
	{
		// Define a Device Contest object for this vies
		CClientDC aDC(this);
		aDC.SetROP2(R2_NOTXORPEN);		// Set the XOR drawing mode

		m_EndPoint = point;  // If so save the current point

		// Test for a previous temporary CShape object
		if(m_pTempShape != NULL)
		{
			// Check to see if we are drawing a curve and need to save points
			if(GetDocument()->getCurrentShape() == CURVE)
			{
				// We are drawing a curve so add a point
				static_cast<CCurve*>(m_pTempShape)->addPoint(&m_EndPoint);
				aDC.SetROP2(R2_COPYPEN); // Draw normal if curve
				this->m_pTempShape->Draw(&aDC); // Draw it
				return;	// Done
			}
			// Redraw the old element so it disappears
			this->m_pTempShape->Draw(&aDC);
			delete m_pTempShape;	// Delete the old one
			m_pTempShape = NULL;	// Reset the pointer to NULL
		}

		// Create a new temporary CShape object
		this->m_pTempShape = CreateShape();
		// Draw the temporary CShape object
		this->m_pTempShape->Draw(&aDC);
	}

	CView::OnMouseMove(nFlags, point);
}


void CSketcherView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	// If the user double clickes in the client area m_pTempShape
	//   will be Null so check for this first.
	if(m_pTempShape == NULL) return;

	// Comment out the next line till we finish the document class 
	GetDocument()->AddShape(m_pTempShape); 
	m_pTempShape = NULL; // Remove the pointer from this shape

	// Note: Do not delete m_pTempShape as the shape object is
	//   now in the Document's vector

	// Force a redraw after we finish creating a shape
	InvalidateRect(NULL, TRUE);

	CView::OnLButtonUp(nFlags, point); // Pass event to super for
	                                   //  any further processing
}

CShape *CSketcherView::CreateShape(void)
{
	// Make sure we have a valid document just to be safe
	CSketcherDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);			// Crash and burn if it is not good

	// Select the shape type to create
	switch(pDoc->getCurrentShape())
	{
		case LINE : // Create a LINE object and return it
		{
			CLine *newLine = new CLine();
			newLine->setEnclosingRect(this->m_StartPoint, this->m_EndPoint);
			newLine->setPenColor(pDoc->getCurrentPenColor());
			newLine->setPenWidth(pDoc->getCurrentPenWidth());
			newLine->setPenPattern(pDoc->getCurrentPenPattern());
			return newLine;
			break;
		}
		case RECTANGLE : // Create a RECTANGLE object and return it
		{
			CRectangle *newRect = new CRectangle();
			newRect->setEnclosingRect(this->m_StartPoint, this->m_EndPoint);
			newRect->setPenColor(pDoc->getCurrentPenColor());
			newRect->setPenWidth(pDoc->getCurrentPenWidth());
			newRect->setPenPattern(pDoc->getCurrentPenPattern());
			newRect->setBrushColor(pDoc->getCurrentBrushColor());
			newRect->setBrushPattern(pDoc->getCurrentBrushPattern());
			return newRect;
			break;
		}
		case OVAL : // Create a OVAL object and return it
		{
			COval *newOval = new COval();
			newOval->setEnclosingRect(this->m_StartPoint, this->m_EndPoint);
			newOval->setPenColor(pDoc->getCurrentPenColor());
			newOval->setPenWidth(pDoc->getCurrentPenWidth());
			newOval->setPenPattern(pDoc->getCurrentPenPattern());
			newOval->setBrushColor(pDoc->getCurrentBrushColor());
			newOval->setBrushPattern(pDoc->getCurrentBrushPattern());
			return newOval;
			break;
		}
		case CURVE : // Create a CURVE object and return it
		{
			CCurve *newCurve = new CCurve();
			newCurve->setEnclosingRect(this->m_StartPoint, this->m_EndPoint);
			newCurve->setPenColor(pDoc->getCurrentPenColor());
			newCurve->setPenWidth(pDoc->getCurrentPenWidth());
			newCurve->setPenPattern(pDoc->getCurrentPenPattern());
			return newCurve;
			break;
		}
		default :   // Oops! something is wrong.
			AfxMessageBox(_T("Bad Shape code"), MB_OK);
			AfxAbort(); // Crash and burn
			return NULL;
	}
	return NULL;
}