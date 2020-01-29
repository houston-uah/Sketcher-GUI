//===========================================================
// CCurve.h
// Class definition file for a Curve shape
// Author: Dr. Rick Coleman
//===========================================================
#pragma once

#include "Constants.h"
#include "CShape.h"
#include <vector>

using namespace std;

class CCurve : public CShape
{
	private:
		vector<CPoint> *m_vPoints;  // Points defining the curve

	public:
		CCurve();
		~CCurve();
		void Draw(CDC *pDC);
		void addPoint(CPoint *pPt);
		void addPoint(int X, int Y);
		void setEnclosingRect(CRect pRect);
		void setEnclosingRect(int left, int top, int right, int bottom);
		void setEnclosingRect(CPoint ul, CPoint lr);
};
