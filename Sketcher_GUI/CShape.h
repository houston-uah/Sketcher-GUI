//===========================================================
// CShape.h
// Class definition file for parent class for all shapes to 
//   be drawn in Sketcher
// Author: Dr. Rick Coleman
//===========================================================
#pragma once

#include "Constants.h"

class CShape
{
	protected:
		COLORREF m_PenColor;	// Reference the one in Constants.h
		int m_iPenPattern;
		int m_iPenWidth;
		COLORREF m_BrushColor; // Reference the one in Constants.h
		int m_iBrushPattern;
		CRect m_EnclosingRect;

	public:
		CShape(void);
		~CShape(void);
		virtual void Draw(CDC *pDC); // Force all sub-classes to implement

		// Get and set functions for all properties
		COLORREF getPenColor();
		void setPenColor(COLORREF pCol);
		int getPenPattern();
		void setPenPattern(int pPat);
		int getPenWidth();
		void setPenWidth(int pWd);
		COLORREF getBrushColor();
		void setBrushColor(COLORREF bCol);
		int getBrushPattern();
		void setBrushPattern(int bPat);
		CRect getEnclosingRect();
		void setEnclosingRect(CRect pRect);
		void setEnclosingRect(int left, int top, int right, int bottom);
		void setEnclosingRect(CPoint ul, CPoint lr);
};