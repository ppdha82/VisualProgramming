#pragma once

class CDib
{
public:
	CDib(void);
	~CDib(void);

	LPVOID GetBitmapImage();
	CSize GetBitmapSize();
	LPBITMAPINFO GetBitmapInfo();

	BOOL Create(int width, int height, int bits);
	BOOL LoadBMP( UINT nIDResource );
	BOOL LoadBMP( LPCTSTR sBMPFile );
	void CloseBMP();

	void DrawDIBWholeImage( CDC* pDC );
	BOOL StretchDIBits( CDC* pDC,
						int XDest,           
						int YDest,         
						int nDestWidth,    
						int nDestHeight,   
						int XSrc,          
						int YSrc,          
						int nSrcWidth,     
						int nSrcHeight);
	BOOL BitBlt( CDC* pDC,
						int XDest,           
						int YDest,         
						int nWidth,    
						int nHeight,   
						int XSrc,
						int YSrc);

	CRect				GetRect();

protected:

	HGLOBAL				m_hGlobalDIB;
	CPalette			m_Palette;

	HANDLE m_hDib;
	LPTSTR m_pDib;
    LPBITMAPINFO m_lpBitInfo;
    HANDLE m_hlpBitInfo;
};
