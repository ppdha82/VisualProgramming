#pragma once
class CPoint3D
{
public:
	CPoint3D(void);
	~CPoint3D(void);
	CPoint3D(int x, int y, int z);

public:
	int x;
	int y;
	int z;

	void Prn();
	void Prn2();
};

