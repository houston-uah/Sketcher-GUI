//===========================================================
// CLine.h
// Class definition file for a line shape
// Author: Dr. Rick Coleman
//===========================================================
#pragma once

#include "Constants.h"
#include "CShape.h"

class CLine : public CShape
{
	public:
		CLine();
		~CLine();
		void Draw(CDC *pDC);
};