
// SketcherDoc.cpp : implementation of the CSketcherDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Sketcher.h"
#endif

#include "SketcherDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSketcherDoc

IMPLEMENT_DYNCREATE(CSketcherDoc, CDocument)

BEGIN_MESSAGE_MAP(CSketcherDoc, CDocument)
	ON_COMMAND(ID_SHAPE_LINE, &CSketcherDoc::OnShapeLine)
	ON_COMMAND(ID_SHAPE_RECTANGLE, &CSketcherDoc::OnShapeRectangle)
	ON_COMMAND(ID_SHAPE_OVAL, &CSketcherDoc::OnShapeOval)
	ON_COMMAND(ID_SHAPE_CURVE, &CSketcherDoc::OnShapeCurve)
	ON_COMMAND(ID_PENCOLOR_CLEAR, &CSketcherDoc::OnPencolorClear)
	ON_COMMAND(ID_PENCOLOR_BLACK, &CSketcherDoc::OnPencolorBlack)
	ON_COMMAND(ID_PENCOLOR_WHITE, &CSketcherDoc::OnPencolorWhite)
	ON_COMMAND(ID_PENCOLOR_RED, &CSketcherDoc::OnPencolorRed)
	ON_COMMAND(ID_PENCOLOR_ORANGE, &CSketcherDoc::OnPencolorOrange)
	ON_COMMAND(ID_PENCOLOR_YELLOW, &CSketcherDoc::OnPencolorYellow)
	ON_COMMAND(ID_PENCOLOR_GREEN, &CSketcherDoc::OnPencolorGreen)
	ON_COMMAND(ID_PENCOLOR_BLUE, &CSketcherDoc::OnPencolorBlue)
	ON_COMMAND(ID_PENCOLOR_VIOLET, &CSketcherDoc::OnPencolorViolet)
	ON_COMMAND(ID_PENWIDTH_1PIXEL, &CSketcherDoc::OnPenwidth1pixel)
	ON_COMMAND(ID_PENWIDTH_2, &CSketcherDoc::OnPenwidth2)
	ON_COMMAND(ID_PENWIDTH_5, &CSketcherDoc::OnPenwidth5)
	ON_COMMAND(ID_PENWIDTH_10PIXELS, &CSketcherDoc::OnPenwidth10pixels)
	ON_COMMAND(ID_PENPATTERN_SOLID, &CSketcherDoc::OnPenpatternSolid)
	ON_COMMAND(ID_PENPATTERN_DASH, &CSketcherDoc::OnPenpatternDash)
	ON_COMMAND(ID_PENPATTERN_DOT, &CSketcherDoc::OnPenpatternDot)
	ON_COMMAND(ID_PENPATTERN_DASHDOT, &CSketcherDoc::OnPenpatternDashdot)
	ON_COMMAND(ID_PENPATTERN_DASHDOTDOT, &CSketcherDoc::OnPenpatternDashdotdot)
	ON_COMMAND(ID_BRUSHCOLOR_CLEAR, &CSketcherDoc::OnBrushcolorClear)
	ON_COMMAND(ID_BRUSHCOLOR_BLACK, &CSketcherDoc::OnBrushcolorBlack)
	ON_COMMAND(ID_BRUSHCOLOR_WHITE, &CSketcherDoc::OnBrushcolorWhite)
	ON_COMMAND(ID_BRUSHCOLOR_RED, &CSketcherDoc::OnBrushcolorRed)
	ON_COMMAND(ID_BRUSHCOLOR_ORANGE, &CSketcherDoc::OnBrushcolorOrange)
	ON_COMMAND(ID_BRUSHCOLOR_YELLOW, &CSketcherDoc::OnBrushcolorYellow)
	ON_COMMAND(ID_BRUSHCOLOR_GREEN, &CSketcherDoc::OnBrushcolorGreen)
	ON_COMMAND(ID_BRUSHCOLOR_BLUE, &CSketcherDoc::OnBrushcolorBlue)
	ON_COMMAND(ID_BRUSHCOLOR_VIOLET, &CSketcherDoc::OnBrushcolorViolet)
	ON_COMMAND(ID_BRUSHPATTERN_SOLID, &CSketcherDoc::OnBrushpatternSolid)
	ON_COMMAND(ID_BRUSHPATTERN_HORI, &CSketcherDoc::OnBrushpatternHori)
	ON_COMMAND(ID_BRUSHPATTERN_VERTICALHATCHING, &CSketcherDoc::OnBrushpatternVerticalhatching)
	ON_COMMAND(ID_BRUSHPATTERN_DIAGONALDOWNHATCHING, &CSketcherDoc::OnBrushpatternDiagonaldownhatching)
	ON_COMMAND(ID_BRUSHPATTERN_DIAGONALUPHATCHING, &CSketcherDoc::OnBrushpatternDiagonaluphatching)
	ON_COMMAND(ID_BRUSHPATTERN_CROSSHATCHING, &CSketcherDoc::OnBrushpatternCrosshatching)
	ON_COMMAND(ID_BRUSHPATTERN_DIAGONALCROSSHATCHING, &CSketcherDoc::OnBrushpatternDiagonalcrosshatching)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_LINE, &CSketcherDoc::OnUpdateShapeLine)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_RECTANGLE, &CSketcherDoc::OnUpdateShapeRectangle)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_OVAL, &CSketcherDoc::OnUpdateShapeOval)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_CURVE, &CSketcherDoc::OnUpdateShapeCurve)
	ON_UPDATE_COMMAND_UI(ID_PENCOLOR_CLEAR, &CSketcherDoc::OnUpdatePencolorClear)
	ON_UPDATE_COMMAND_UI(ID_PENCOLOR_BLACK, &CSketcherDoc::OnUpdatePencolorBlack)
	ON_UPDATE_COMMAND_UI(ID_PENCOLOR_WHITE, &CSketcherDoc::OnUpdatePencolorWhite)
	ON_UPDATE_COMMAND_UI(ID_PENCOLOR_RED, &CSketcherDoc::OnUpdatePencolorRed)
	ON_UPDATE_COMMAND_UI(ID_PENCOLOR_ORANGE, &CSketcherDoc::OnUpdatePencolorOrange)
	ON_UPDATE_COMMAND_UI(ID_PENCOLOR_YELLOW, &CSketcherDoc::OnUpdatePencolorYellow)
	ON_UPDATE_COMMAND_UI(ID_PENCOLOR_GREEN, &CSketcherDoc::OnUpdatePencolorGreen)
	ON_UPDATE_COMMAND_UI(ID_PENCOLOR_BLUE, &CSketcherDoc::OnUpdatePencolorBlue)
	ON_UPDATE_COMMAND_UI(ID_PENCOLOR_VIOLET, &CSketcherDoc::OnUpdatePencolorViolet)
	ON_UPDATE_COMMAND_UI(ID_PENWIDTH_1PIXEL, &CSketcherDoc::OnUpdatePenwidth1pixel)
	ON_UPDATE_COMMAND_UI(ID_PENWIDTH_2, &CSketcherDoc::OnUpdatePenwidth2)
	ON_UPDATE_COMMAND_UI(ID_PENWIDTH_5, &CSketcherDoc::OnUpdatePenwidth5)
	ON_UPDATE_COMMAND_UI(ID_PENWIDTH_10PIXELS, &CSketcherDoc::OnUpdatePenwidth10pixels)
	ON_UPDATE_COMMAND_UI(ID_PENPATTERN_SOLID, &CSketcherDoc::OnUpdatePenpatternSolid)
	ON_UPDATE_COMMAND_UI(ID_PENPATTERN_DASH, &CSketcherDoc::OnUpdatePenpatternDash)
	ON_UPDATE_COMMAND_UI(ID_PENPATTERN_DOT, &CSketcherDoc::OnUpdatePenpatternDot)
	ON_UPDATE_COMMAND_UI(ID_PENPATTERN_DASHDOT, &CSketcherDoc::OnUpdatePenpatternDashdot)
	ON_UPDATE_COMMAND_UI(ID_PENPATTERN_DASHDOTDOT, &CSketcherDoc::OnUpdatePenpatternDashdotdot)
	ON_UPDATE_COMMAND_UI(ID_BRUSHCOLOR_CLEAR, &CSketcherDoc::OnUpdateBrushcolorClear)
	ON_UPDATE_COMMAND_UI(ID_BRUSHCOLOR_BLACK, &CSketcherDoc::OnUpdateBrushcolorBlack)
	ON_UPDATE_COMMAND_UI(ID_BRUSHCOLOR_WHITE, &CSketcherDoc::OnUpdateBrushcolorWhite)
	ON_UPDATE_COMMAND_UI(ID_BRUSHCOLOR_RED, &CSketcherDoc::OnUpdateBrushcolorRed)
	ON_UPDATE_COMMAND_UI(ID_BRUSHCOLOR_ORANGE, &CSketcherDoc::OnUpdateBrushcolorOrange)
	ON_UPDATE_COMMAND_UI(ID_BRUSHCOLOR_YELLOW, &CSketcherDoc::OnUpdateBrushcolorYellow)
	ON_UPDATE_COMMAND_UI(ID_BRUSHCOLOR_GREEN, &CSketcherDoc::OnUpdateBrushcolorGreen)
	ON_UPDATE_COMMAND_UI(ID_BRUSHCOLOR_BLUE, &CSketcherDoc::OnUpdateBrushcolorBlue)
	ON_UPDATE_COMMAND_UI(ID_BRUSHCOLOR_VIOLET, &CSketcherDoc::OnUpdateBrushcolorViolet)
	ON_UPDATE_COMMAND_UI(ID_BRUSHPATTERN_SOLID, &CSketcherDoc::OnUpdateBrushpatternSolid)
	ON_UPDATE_COMMAND_UI(ID_BRUSHPATTERN_HORI, &CSketcherDoc::OnUpdateBrushpatternHori)
	ON_UPDATE_COMMAND_UI(ID_BRUSHPATTERN_VERTICALHATCHING, &CSketcherDoc::OnUpdateBrushpatternVerticalhatching)
	ON_UPDATE_COMMAND_UI(ID_BRUSHPATTERN_DIAGONALDOWNHATCHING, &CSketcherDoc::OnUpdateBrushpatternDiagonaldownhatching)
	ON_UPDATE_COMMAND_UI(ID_BRUSHPATTERN_DIAGONALUPHATCHING, &CSketcherDoc::OnUpdateBrushpatternDiagonaluphatching)
	ON_UPDATE_COMMAND_UI(ID_BRUSHPATTERN_CROSSHATCHING, &CSketcherDoc::OnUpdateBrushpatternCrosshatching)
	ON_UPDATE_COMMAND_UI(ID_BRUSHPATTERN_DIAGONALCROSSHATCHING, &CSketcherDoc::OnUpdateBrushpatternDiagonalcrosshatching)
END_MESSAGE_MAP()


// CSketcherDoc construction/destruction

CSketcherDoc::CSketcherDoc()
{
	// TODO: add one-time construction code here
	m_iCurShape = LINE;
	m_CurPenColor = COLOR_BLACK;
	m_iCurPenWidth = 1;
	m_iCurPenPattern = PS_SOLID;
	m_CurBrushColor = COLOR_WHITE;
	m_iCurBrushPattern = BRUSH_PATTERN_SOLID;
	m_vShapes = new vector<CShape *>();

}

CSketcherDoc::~CSketcherDoc()
{
}

BOOL CSketcherDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CSketcherDoc serialization

void CSketcherDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CSketcherDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CSketcherDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CSketcherDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSketcherDoc diagnostics

#ifdef _DEBUG
void CSketcherDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSketcherDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSketcherDoc commands


void CSketcherDoc::OnShapeLine()
{
	// TODO: Add your command handler code here
	m_iCurShape = LINE;
}


void CSketcherDoc::OnShapeRectangle()
{
	// TODO: Add your command handler code here
	m_iCurShape = RECTANGLE;
}


void CSketcherDoc::OnShapeOval()
{
	// TODO: Add your command handler code here
	m_iCurShape = OVAL;
}


void CSketcherDoc::OnShapeCurve()
{
	// TODO: Add your command handler code here
	m_iCurShape = CURVE;
}


void CSketcherDoc::OnPencolorClear()
{
	// TODO: Add your command handler code here
	m_CurPenColor = COLOR_CLEAR;
}


void CSketcherDoc::OnPencolorBlack()
{
	// TODO: Add your command handler code here
	m_CurPenColor = COLOR_BLACK;
}


void CSketcherDoc::OnPencolorWhite()
{
	// TODO: Add your command handler code here
	m_CurPenColor = COLOR_WHITE;
}


void CSketcherDoc::OnPencolorRed()
{
	// TODO: Add your command handler code here
	m_CurPenColor = COLOR_RED;
}


void CSketcherDoc::OnPencolorOrange()
{
	// TODO: Add your command handler code here
	m_CurPenColor = COLOR_ORANGE;
}


void CSketcherDoc::OnPencolorYellow()
{
	// TODO: Add your command handler code here
	m_CurPenColor = COLOR_YELLOW;
}


void CSketcherDoc::OnPencolorGreen()
{
	// TODO: Add your command handler code here
	m_CurPenColor = COLOR_GREEN;
}


void CSketcherDoc::OnPencolorBlue()
{
	// TODO: Add your command handler code here
	m_CurPenColor = COLOR_BLUE;
}


void CSketcherDoc::OnPencolorViolet()
{
	// TODO: Add your command handler code here
	m_CurPenColor = COLOR_VIOLET;
}


void CSketcherDoc::OnPenwidth1pixel()
{
	// TODO: Add your command handler code here
	m_iCurPenWidth = 1;
}


void CSketcherDoc::OnPenwidth2()
{
	// TODO: Add your command handler code here
	m_iCurPenWidth = 2;
}


void CSketcherDoc::OnPenwidth5()
{
	// TODO: Add your command handler code here
	m_iCurPenWidth = 5;
}


void CSketcherDoc::OnPenwidth10pixels()
{
	// TODO: Add your command handler code here
	m_iCurPenWidth = 10;
}


void CSketcherDoc::OnPenpatternSolid()
{
	// TODO: Add your command handler code here
		m_iCurPenPattern = PS_SOLID;

}


void CSketcherDoc::OnPenpatternDash()
{
	// TODO: Add your command handler code here
	m_iCurPenPattern = PS_DASH;
}


void CSketcherDoc::OnPenpatternDot()
{
	// TODO: Add your command handler code here
	m_iCurPenPattern = PS_DOT;
}


void CSketcherDoc::OnPenpatternDashdot()
{
	// TODO: Add your command handler code here
	m_iCurPenPattern = PS_DASHDOT;
}


void CSketcherDoc::OnPenpatternDashdotdot()
{
	// TODO: Add your command handler code here
	m_iCurPenPattern = PS_DASHDOTDOT;
}


void CSketcherDoc::OnBrushcolorClear()
{
	// TODO: Add your command handler code here
	m_CurBrushColor = COLOR_CLEAR;
}


void CSketcherDoc::OnBrushcolorBlack()
{
	// TODO: Add your command handler code here
	m_CurBrushColor = COLOR_BLACK;
}


void CSketcherDoc::OnBrushcolorWhite()
{
	// TODO: Add your command handler code here
	m_CurBrushColor = COLOR_WHITE;
}


void CSketcherDoc::OnBrushcolorRed()
{
	// TODO: Add your command handler code here
	m_CurBrushColor = COLOR_RED;
}


void CSketcherDoc::OnBrushcolorOrange()
{
	// TODO: Add your command handler code here
	m_CurBrushColor = COLOR_ORANGE;
}


void CSketcherDoc::OnBrushcolorYellow()
{
	// TODO: Add your command handler code here
	m_CurBrushColor = COLOR_YELLOW;
}


void CSketcherDoc::OnBrushcolorGreen()
{
	// TODO: Add your command handler code here
	m_CurBrushColor = COLOR_GREEN;
}


void CSketcherDoc::OnBrushcolorBlue()
{
	// TODO: Add your command handler code here
	m_CurBrushColor = COLOR_BLUE;
}


void CSketcherDoc::OnBrushcolorViolet()
{
	// TODO: Add your command handler code here
	m_CurBrushColor = COLOR_VIOLET;
}


void CSketcherDoc::OnBrushpatternSolid()
{
	// TODO: Add your command handler code here
	m_iCurBrushPattern = BRUSH_PATTERN_SOLID;
}


void CSketcherDoc::OnBrushpatternHori()
{
	// TODO: Add your command handler code here
	m_iCurBrushPattern = HS_HORIZONTAL;
}


void CSketcherDoc::OnBrushpatternVerticalhatching()
{
	// TODO: Add your command handler code here
	m_iCurBrushPattern = HS_VERTICAL;
}


void CSketcherDoc::OnBrushpatternDiagonaldownhatching()
{
	// TODO: Add your command handler code here
	m_iCurBrushPattern = HS_BDIAGONAL;
}


void CSketcherDoc::OnBrushpatternDiagonaluphatching()
{
	// TODO: Add your command handler code here
	m_iCurBrushPattern = HS_FDIAGONAL;
}


void CSketcherDoc::OnBrushpatternCrosshatching()
{
	// TODO: Add your command handler code here
	m_iCurBrushPattern = HS_CROSS;
}


void CSketcherDoc::OnBrushpatternDiagonalcrosshatching()
{
	// TODO: Add your command handler code here
	m_iCurBrushPattern = HS_DIAGCROSS;
}

//---------------------------------------------------
// Get the current shape
//---------------------------------------------------
int CSketcherDoc::getCurrentShape()
{
	return m_iCurShape;
}

//---------------------------------------------------
// Get the current pen color
//---------------------------------------------------
COLORREF CSketcherDoc::getCurrentPenColor()
{
	return m_CurPenColor;
}

//---------------------------------------------------
// Get the current pen width
//---------------------------------------------------
int CSketcherDoc::getCurrentPenWidth()
{
	return m_iCurPenWidth;
}

//---------------------------------------------------
// Get the current pen pattern
//---------------------------------------------------
int CSketcherDoc::getCurrentPenPattern()
{
	return m_iCurPenPattern;
}

//---------------------------------------------------
// Get the current brush color
//---------------------------------------------------
COLORREF CSketcherDoc::getCurrentBrushColor()
{
	return m_CurBrushColor;
}

//---------------------------------------------------
// Get the current brush pattern
//---------------------------------------------------
int CSketcherDoc::getCurrentBrushPattern()
{
	return m_iCurBrushPattern;
}

void CSketcherDoc::OnUpdateShapeLine(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurShape == LINE);
}


void CSketcherDoc::OnUpdateShapeRectangle(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurShape == RECTANGLE);
}


void CSketcherDoc::OnUpdateShapeOval(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurShape == OVAL);
}


void CSketcherDoc::OnUpdateShapeCurve(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurShape == CURVE);
}


void CSketcherDoc::OnUpdatePencolorClear(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurPenColor == COLOR_CLEAR);
}


void CSketcherDoc::OnUpdatePencolorBlack(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurPenColor == COLOR_BLACK);
}


void CSketcherDoc::OnUpdatePencolorWhite(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurPenColor == COLOR_WHITE);
}


void CSketcherDoc::OnUpdatePencolorRed(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurPenColor == COLOR_RED);
}


void CSketcherDoc::OnUpdatePencolorOrange(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurPenColor == COLOR_ORANGE);
}


void CSketcherDoc::OnUpdatePencolorYellow(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurPenColor == COLOR_YELLOW);
}


void CSketcherDoc::OnUpdatePencolorGreen(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurPenColor == COLOR_GREEN);
}


void CSketcherDoc::OnUpdatePencolorBlue(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurPenColor == COLOR_BLUE);
}


void CSketcherDoc::OnUpdatePencolorViolet(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurPenColor == COLOR_VIOLET);
}


void CSketcherDoc::OnUpdatePenwidth1pixel(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurPenWidth = 1);
}


void CSketcherDoc::OnUpdatePenwidth2(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurPenWidth = 2);
}


void CSketcherDoc::OnUpdatePenwidth5(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurPenWidth = 5);
}


void CSketcherDoc::OnUpdatePenwidth10pixels(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurPenWidth = 10);
}


void CSketcherDoc::OnUpdatePenpatternSolid(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurPenPattern = PS_SOLID);
}


void CSketcherDoc::OnUpdatePenpatternDash(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurPenPattern = PS_DASH);
}


void CSketcherDoc::OnUpdatePenpatternDot(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurPenPattern = PS_DOT);
}


void CSketcherDoc::OnUpdatePenpatternDashdot(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurPenPattern = PS_DASHDOT);
}


void CSketcherDoc::OnUpdatePenpatternDashdotdot(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurPenPattern = PS_DASHDOTDOT);
}


void CSketcherDoc::OnUpdateBrushcolorClear(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurBrushColor = COLOR_CLEAR);
}


void CSketcherDoc::OnUpdateBrushcolorBlack(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurBrushColor = COLOR_BLACK);
}


void CSketcherDoc::OnUpdateBrushcolorWhite(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurBrushColor = COLOR_WHITE);
}


void CSketcherDoc::OnUpdateBrushcolorRed(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurBrushColor = COLOR_RED);
}


void CSketcherDoc::OnUpdateBrushcolorOrange(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurBrushColor = COLOR_ORANGE);
}


void CSketcherDoc::OnUpdateBrushcolorYellow(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurBrushColor = COLOR_YELLOW);
}


void CSketcherDoc::OnUpdateBrushcolorGreen(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurBrushColor = COLOR_GREEN);
}


void CSketcherDoc::OnUpdateBrushcolorBlue(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurBrushColor = COLOR_BLUE);
}


void CSketcherDoc::OnUpdateBrushcolorViolet(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_CurBrushColor = COLOR_VIOLET);
}


void CSketcherDoc::OnUpdateBrushpatternSolid(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurBrushPattern = BRUSH_PATTERN_SOLID);
}


void CSketcherDoc::OnUpdateBrushpatternHori(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurBrushPattern = HS_HORIZONTAL);
}


void CSketcherDoc::OnUpdateBrushpatternVerticalhatching(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurBrushPattern = HS_VERTICAL);
}


void CSketcherDoc::OnUpdateBrushpatternDiagonaldownhatching(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurBrushPattern = HS_BDIAGONAL);
}


void CSketcherDoc::OnUpdateBrushpatternDiagonaluphatching(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurBrushPattern = HS_FDIAGONAL);
}


void CSketcherDoc::OnUpdateBrushpatternCrosshatching(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurBrushPattern = HS_CROSS);
}


void CSketcherDoc::OnUpdateBrushpatternDiagonalcrosshatching(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_iCurBrushPattern = HS_DIAGCROSS);
}

//-----------------------------------------------------
// Get the first shape in the vector
//-----------------------------------------------------
CShape *CSketcherDoc::getFirstShape()
{
	if(m_vShapes->size() == 0)
		return NULL;
	m_Itr = m_vShapes->begin();
	
	return (CShape *)(*m_Itr); // Remember m_Itr is a pointer to a pointer so
	                           //  we must dereference it to get the pointer to
	                           //  a CShape object.
}
//-----------------------------------------------------
// Get the next shape in the vector
//-----------------------------------------------------
CShape *CSketcherDoc::getNextShape()
{
	m_Itr++;
	if(m_Itr != m_vShapes->end())
	{
		return (CShape *)(*m_Itr); // Remember m_Itr is a pointer to a pointer so
					   //  we must dereference it to get the pointer to
					   //  a CShape object.
	}
	else
	{
		return NULL;
	}
	
}

//-----------------------------------------------------
// Add a shape to the vector for this drawing
//-----------------------------------------------------
void CSketcherDoc::AddShape(CShape *s)
{
	m_vShapes->push_back(s);
}