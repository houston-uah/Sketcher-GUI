//===========================================================
// COval.cpp
// Class implementation file for an Oval shape
// Author: Dr. Rick Coleman
//===========================================================
#include "stdafx.h"
#include "COval.h"

//---------------------------------
// Default constructor
//---------------------------------
COval::COval()
{
}

//---------------------------------
// Default destructor
//---------------------------------
COval::~COval()
{
}

//------------------------------------------------
// Implement the draw function for Ovals
//------------------------------------------------
void COval::Draw(CDC *pDC)
{
	// Create a pen for drawing
	CPen pen, *oldPen;
	// Create a brush for filling
	CBrush brush, *oldBrush = NULL;
	// If creating a transparent pen use PS_NULL style
	if(this->m_PenColor == COLOR_CLEAR)
		pen.CreatePen(PS_NULL, this->m_iPenWidth, COLOR_BLACK);
	else
		pen.CreatePen(this->m_iPenPattern, this->m_iPenWidth, this->m_PenColor);

	// If creating a transparent fill use a NULL_BRUSH
	if(this->m_BrushColor != COLOR_CLEAR)
	{
		if(this->m_iBrushPattern == BRUSH_PATTERN_SOLID)
			brush.CreateSolidBrush(this->m_BrushColor);
		else
			brush.CreateHatchBrush(this->m_iBrushPattern, this->m_BrushColor);
		oldBrush = pDC->SelectObject(&brush);
	}
	else
		pDC->SelectStockObject(NULL_BRUSH);

	// Set the drawing pen and hold the current pen
	oldPen = pDC->SelectObject(&pen);
	// Draw the shape
	pDC->Ellipse(this->m_EnclosingRect);
	// Reset the current pen
	pDC->SelectObject(oldPen);
	// Reset the current brush
	if(oldBrush != NULL)
		pDC->SelectObject(oldBrush);
	// Delete the pen we created to avoid memory leaks
	pen.DeleteObject();
	// Delete the brush we created if we did create one
	if(this->m_BrushColor != COLOR_CLEAR)
		brush.DeleteObject();
	else
		pDC->SelectStockObject(WHITE_BRUSH);
}
