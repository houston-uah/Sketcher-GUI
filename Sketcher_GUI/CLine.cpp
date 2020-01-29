//===========================================================
// CLine.cpp
// Class implementation file for a line shape
// Author: Dr. Rick Coleman
//===========================================================
#include "stdafx.h"
#include "CLine.h"

//------------------------------------------------
// Default constructor
//------------------------------------------------
CLine::CLine()
{
}

//------------------------------------------------
// Default destructor
//------------------------------------------------
CLine::~CLine()
{
}

//------------------------------------------------
// Implement the draw function for lines
//------------------------------------------------
void CLine::Draw(CDC *pDC)
{
	// Create a pen for drawing
	CPen pen, *oldPen;
	// If creating a transparent pen use PS_NULL style
	if(this->m_PenColor == COLOR_CLEAR)
		pen.CreatePen(PS_NULL, this->m_iPenWidth, COLOR_BLACK);
	else
		pen.CreatePen(this->m_iPenPattern, this->m_iPenWidth, this->m_PenColor);

	// Set the drawing pen and hold the current pen
	oldPen = pDC->SelectObject(&pen);
	// Draw the line with the upper left and lower right corner
	//  of the enclosing rectangle defining the start and end
	//  points of the line.
	pDC->MoveTo(this->m_EnclosingRect.left, this->m_EnclosingRect.top);
	pDC->LineTo(this->m_EnclosingRect.right, this->m_EnclosingRect.bottom);
	// Reset the current pen
	pDC->SelectObject(oldPen);
	// Delete the pen we created to avoid memory leaks
	pen.DeleteObject();
}