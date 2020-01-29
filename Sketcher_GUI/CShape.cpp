//===========================================================
// CShape.cpp
// Implementation file for parent class for all shapes to be 
//   drawn in Sketcher
// Author: Dr. Rick Coleman
//===========================================================
// If you are using Visual Studio 2012 or later you may have
//  to use the stdafx.h #include and comment out the StdAfx.h
//  #include.

#include "stdafx.h"	// For VS 2012
#include "CShape.h"

//----------------------------------------
// Default constructor
//----------------------------------------
CShape::CShape(void)
{
	m_PenColor = COLOR_BLACK;
	m_iPenPattern = PS_SOLID;
	m_iPenWidth = 1;
	m_BrushColor = COLOR_WHITE; 
	m_iBrushPattern = BRUSH_PATTERN_SOLID;
	m_EnclosingRect.left = 0;
	m_EnclosingRect.top = 0;
	m_EnclosingRect.right = 0;
	m_EnclosingRect.bottom = 0;
}

//----------------------------------------
// Default destructor
//----------------------------------------
CShape::~CShape(void)
{
}

//----------------------------------------
// Draw(): all subclasses must override.
//----------------------------------------
void CShape::Draw(CDC *pDC)
{
}

//----------------------------------------
// Get the pen color
//----------------------------------------
COLORREF CShape::getPenColor()
{
	return m_PenColor;
}

//----------------------------------------
// Set the pen color
//----------------------------------------
void CShape::setPenColor(COLORREF pCol)
{
	m_PenColor = pCol;
}

//----------------------------------------
// Get the pen pattern
//----------------------------------------
int CShape::getPenPattern()
{
	return m_iPenPattern;
}

//----------------------------------------
// Set the pen pattern
//----------------------------------------
void CShape::setPenPattern(int pPat)
{
	m_iPenPattern = pPat;
}

//----------------------------------------
// Get the pen width
//----------------------------------------
int CShape::getPenWidth()
{
	return m_iPenWidth;
}

//----------------------------------------
// Set the pen width
//----------------------------------------
void CShape::setPenWidth(int pWd)
{
	m_iPenWidth = pWd;
}

//----------------------------------------
// Get the brush color
//----------------------------------------
COLORREF CShape::getBrushColor()
{
	return m_BrushColor;
}

//----------------------------------------
// Set the brush color
//----------------------------------------
void CShape::setBrushColor(COLORREF bCol)
{
	m_BrushColor = bCol;
}

//----------------------------------------
// Get the brush pattern
//----------------------------------------
int CShape::getBrushPattern()
{
	return m_iBrushPattern;
}

//----------------------------------------
// Set the brush pattern
//----------------------------------------
void CShape::setBrushPattern(int bPat)
{
	m_iBrushPattern = bPat;
}

//----------------------------------------
// Get the enclosing rectangle
//----------------------------------------
CRect CShape::getEnclosingRect()
{
	return m_EnclosingRect;
}

//---------------------------------------------------
// Set the enclosing rectangle from another rectangle
//---------------------------------------------------
void CShape::setEnclosingRect(CRect rect)
{
	m_EnclosingRect.left = rect.left;
	m_EnclosingRect.top = rect.top;
	m_EnclosingRect.right = rect.right;
	m_EnclosingRect.bottom = rect.bottom;
}

//--------------------------------------------------
// Set the enclosing rectangle from X,Y coordinates
//--------------------------------------------------
void CShape::setEnclosingRect(int left, int top, int right, int bottom)
{
	m_EnclosingRect.left = left;
	m_EnclosingRect.top = top;
	m_EnclosingRect.right = right;
	m_EnclosingRect.bottom = bottom;
}

//-----------------------------------------------------
// Set the enclosing rectangle from two CPoint objects
//-----------------------------------------------------
void CShape::setEnclosingRect(CPoint ul, CPoint lr)
{
	m_EnclosingRect.left = ul.x;
	m_EnclosingRect.top = ul.y;
	m_EnclosingRect.right = lr.x;
	m_EnclosingRect.bottom = lr.y;
}
