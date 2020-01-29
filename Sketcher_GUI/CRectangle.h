//===========================================================
// CRectangle.h
// Class definition file for a Rectangle shape
// Author: Dr. Rick Coleman
//===========================================================
#pragma once

#include "Constants.h"
#include "CShape.h"

class CRectangle : public CShape
{
	public:
		CRectangle();
		~CRectangle();
		void Draw(CDC *pDC);
};