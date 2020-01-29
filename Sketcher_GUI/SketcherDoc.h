
// SketcherDoc.h : interface of the CSketcherDoc class
//


#pragma once
#include "Constants.h"
#include "CShape.h"
#include <vector>

using namespace std;

class CSketcherDoc : public CDocument
{
protected: // create from serialization only
	CSketcherDoc();
	DECLARE_DYNCREATE(CSketcherDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CSketcherDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnShapeLine();
	afx_msg void OnShapeRectangle();
	afx_msg void OnShapeOval();
	afx_msg void OnShapeCurve();
	afx_msg void OnPencolorClear();
	afx_msg void OnPencolorBlack();
	afx_msg void OnPencolorWhite();
	afx_msg void OnPencolorRed();
	afx_msg void OnPencolorOrange();
	afx_msg void OnPencolorYellow();
	afx_msg void OnPencolorGreen();
	afx_msg void OnPencolorBlue();
	afx_msg void OnPencolorViolet();
	afx_msg void OnPenwidth1pixel();
	afx_msg void OnPenwidth2();
	afx_msg void OnPenwidth5();
	afx_msg void OnPenwidth10pixels();
	afx_msg void OnPenpatternSolid();
	afx_msg void OnPenpatternDash();
	afx_msg void OnPenpatternDot();
	afx_msg void OnPenpatternDashdot();
	afx_msg void OnPenpatternDashdotdot();
	afx_msg void OnBrushcolorClear();
	afx_msg void OnBrushcolorBlack();
	afx_msg void OnBrushcolorWhite();
	afx_msg void OnBrushcolorRed();
	afx_msg void OnBrushcolorOrange();
	afx_msg void OnBrushcolorYellow();
	afx_msg void OnBrushcolorGreen();
	afx_msg void OnBrushcolorBlue();
	afx_msg void OnBrushcolorViolet();
	afx_msg void OnBrushpatternSolid();
	afx_msg void OnBrushpatternHori();
	afx_msg void OnBrushpatternVerticalhatching();
	afx_msg void OnBrushpatternDiagonaldownhatching();
	afx_msg void OnBrushpatternDiagonaluphatching();
	afx_msg void OnBrushpatternCrosshatching();
	afx_msg void OnBrushpatternDiagonalcrosshatching();

	private:
	int m_iCurShape;
	COLORREF m_CurPenColor;
	int m_iCurPenWidth;
	int m_iCurPenPattern;
	COLORREF m_CurBrushColor;
	int m_iCurBrushPattern;

	public:
	int getCurrentShape();
	COLORREF getCurrentPenColor();
	int getCurrentPenWidth();
	int getCurrentPenPattern();
	COLORREF getCurrentBrushColor();
	int getCurrentBrushPattern();
	afx_msg void OnUpdateShapeLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShapeRectangle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShapeOval(CCmdUI *pCmdUI);
	afx_msg void OnUpdateShapeCurve(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePencolorClear(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePencolorBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePencolorWhite(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePencolorRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePencolorOrange(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePencolorYellow(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePencolorGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePencolorBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePencolorViolet(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenwidth1pixel(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenwidth2(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenwidth5(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenwidth10pixels(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenpatternSolid(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenpatternDash(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenpatternDot(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenpatternDashdot(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePenpatternDashdotdot(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushcolorClear(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushcolorBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushcolorWhite(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushcolorRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushcolorOrange(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushcolorYellow(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushcolorGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushcolorBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushcolorViolet(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushpatternSolid(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushpatternHori(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushpatternVerticalhatching(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushpatternDiagonaldownhatching(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushpatternDiagonaluphatching(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushpatternCrosshatching(CCmdUI *pCmdUI);
	afx_msg void OnUpdateBrushpatternDiagonalcrosshatching(CCmdUI *pCmdUI);

private:
	vector<CShape *> *m_vShapes;		// This is new
	vector<CShape *>::iterator m_Itr;	// This is new


public:
	void AddShape(CShape *s);	// This is new
	CShape *getFirstShape();	// This is new
	CShape *getNextShape();		// This is new
};
