#include "stdafx.h"
#include "Point3D.h"


CPoint3D::CPoint3D(void)
	: x(0), y(0), z(0)
{
}


CPoint3D::~CPoint3D(void)
{
}

CPoint3D::CPoint3D(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void CPoint3D::Prn()
{
	CString str;

	str.Format(_T("(%d), , (%d)"), this->x, this->z);
	AfxMessageBox(str);
}

void CPoint3D::Prn2()
{
	CString str;

	str.Format(_T("(%d), (%d), (%d)"), this->x, this->y, this->z);
	AfxMessageBox(str);
}