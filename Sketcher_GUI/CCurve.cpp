//===========================================================
// CCurve.cpp
// Class implementation file for a Curve shape
// Author: Dr. Rick Coleman
//===========================================================
#include "stdafx.h"
#include "CCurve.h"

//---------------------------------
// Default constructor
//---------------------------------
CCurve::CCurve()
{
	m_vPoints = new vector<CPoint>();
}

//---------------------------------
// Default destructor
//---------------------------------
CCurve::~CCurve()
{
	m_vPoints->clear();
	delete m_vPoints;
}

//------------------------------------------------
// Implement the draw function for Curves
//------------------------------------------------
void CCurve::Draw(CDC *pDC)
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
	// Draw the curve
	pDC->MoveTo(m_vPoints->begin()->x, m_vPoints->begin()->y);
	for(vector<CPoint>::iterator itr = m_vPoints->begin();
			itr != m_vPoints->end(); itr++)
	{
		pDC->LineTo(itr->x, itr->y);
	}
	// Reset the current pen
	pDC->SelectObject(oldPen);
	// Delete the pen we created to avoid memory leaks
	pen.DeleteObject();
}

//------------------------------------------------
// Add a point to the vector
//------------------------------------------------
void CCurve::addPoint(CPoint *pPt)
{
	// Copy the point
	CPoint *newPt = new CPoint(pPt->x, pPt->y);
	m_vPoints->push_back(*newPt);
}

//------------------------------------------------
// Add a point to the vector
//------------------------------------------------
void CCurve::addPoint(int X, int Y)
{
	// Copy the point
	CPoint *newPt = new CPoint(X, Y);
	m_vPoints->push_back(*newPt);
}

// Override all the setEnclosingRectangle functions to
//  add the two points as the first points in the curve

//---------------------------------------------------
// Set the enclosing rectangle from another rectangle
//---------------------------------------------------
void CCurve::setEnclosingRect(CRect rect)
{
	this->addPoint(rect.left, rect.top);
	this->addPoint(rect.right, rect.bottom);
}

//--------------------------------------------------
// Set the enclosing rectangle from X,Y coordinates
//--------------------------------------------------
void CCurve::setEnclosingRect(int left, int top, int right, int bottom)
{
	this->addPoint(left, top);
	this->addPoint(right, bottom);
}

//-----------------------------------------------------
// Set the enclosing rectangle from two CPoint objects
//-----------------------------------------------------
void CCurve::setEnclosingRect(CPoint ul, CPoint lr)
{
	this->addPoint(ul.x, ul.y);
	this->addPoint(lr.x, lr.y);
}
