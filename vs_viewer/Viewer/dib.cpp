#include "stdafx.h"
#include "dib.h"

CDib::CDib(void)
{
	m_hGlobalDIB	= NULL;

	m_hlpBitInfo	= NULL;
	m_pDib			= NULL;
	m_hDib			= NULL;
	m_lpBitInfo		= NULL;

	CloseBMP();
}

CDib::~CDib(void)
{
	CloseBMP();
}

BOOL CDib::LoadBMP( LPCTSTR sBMPFile )
{
	CloseBMP();

	CFile file;
	if( !file.Open( sBMPFile, CFile::modeRead) )
		return FALSE;

	BITMAPFILEHEADER bmfHeader;
	long nFileLen;

	nFileLen = (long)file.GetLength();

	// Read file header
	if (file.Read((LPSTR)&bmfHeader, sizeof(bmfHeader)) != sizeof(bmfHeader))
		return FALSE;

	// File type should be 'BM'
	if (bmfHeader.bfType != ((WORD) (_T('M') << 8) | _T('B')))
		return FALSE;

	HGLOBAL hDIB = ::GlobalAlloc(GMEM_FIXED, nFileLen);
	if (hDIB == 0)
		return FALSE;

	// Read the remainder of the bitmap file.
	if (file.Read/*Huge*/((LPSTR)hDIB, nFileLen - sizeof(BITMAPFILEHEADER)) !=
		nFileLen - sizeof(BITMAPFILEHEADER) )
	{
		::GlobalFree(hDIB);
		return FALSE;
	}
	
	BITMAPINFO bmInfo = *(LPBITMAPINFO)hDIB ;

	int nColors = bmInfo.bmiHeader.biClrUsed ? bmInfo.bmiHeader.biClrUsed : 
						1 << bmInfo.bmiHeader.biBitCount;

	// Create the palette
	if( nColors <= 256 )
	{
		UINT nSize = sizeof(LOGPALETTE) + (sizeof(PALETTEENTRY) * nColors);
		LOGPALETTE *pLP = (LOGPALETTE *) new BYTE[nSize];

		pLP->palVersion = 0x300;
		pLP->palNumEntries = nColors;

		for( int i=0; i < nColors; i++)
		{
			pLP->palPalEntry[i].peRed = bmInfo.bmiColors[i].rgbRed;
			pLP->palPalEntry[i].peGreen = bmInfo.bmiColors[i].rgbGreen;
			pLP->palPalEntry[i].peBlue = bmInfo.bmiColors[i].rgbBlue;
			pLP->palPalEntry[i].peFlags = 0;
		}

		m_Palette.CreatePalette( pLP );

		delete[] pLP;
	}

	m_hGlobalDIB = hDIB;

	return TRUE;
}

BOOL CDib::LoadBMP( UINT nIDResource )
{
	CBitmap BMP;

	if( m_hGlobalDIB )
	{
		ASSERT(0);
		return FALSE;
	}

	if( BMP.LoadBitmap(nIDResource) )
	{
		BITMAP	bm;
		HDC		hdc;

		if( BMP.GetBitmap(&bm) == 0 )
			return FALSE;

		m_hDib=GlobalAlloc(GHND, bm.bmWidth*bm.bmHeight*3);
        m_pDib=(LPTSTR)GlobalLock(m_hDib);
        m_hlpBitInfo=GlobalAlloc(GHND, sizeof(BITMAPINFO));
        m_lpBitInfo=(LPBITMAPINFO)GlobalLock(m_hlpBitInfo);

		//BITMAPINFO
        m_lpBitInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        m_lpBitInfo->bmiHeader.biWidth = bm.bmWidth;
        m_lpBitInfo->bmiHeader.biHeight = bm.bmHeight;
        m_lpBitInfo->bmiHeader.biPlanes = 1;
        m_lpBitInfo->bmiHeader.biBitCount = 24;
        m_lpBitInfo->bmiHeader.biCompression = BI_RGB;
        m_lpBitInfo->bmiHeader.biSizeImage = bm.bmWidth*bm.bmHeight*3;
        m_lpBitInfo->bmiHeader.biXPelsPerMeter = 0;
        m_lpBitInfo->bmiHeader.biYPelsPerMeter = 0;
        m_lpBitInfo->bmiHeader.biClrUsed = 0;
        m_lpBitInfo->bmiHeader.biClrImportant = 0;         
        ////BITMAPINFO  

		hdc = ::CreateCompatibleDC(NULL);

        int rtn = GetDIBits(hdc, (HBITMAP)BMP, 0, bm.bmHeight,m_pDib, m_lpBitInfo, DIB_RGB_COLORS);

		::DeleteDC(hdc);

		if( rtn == 0 )
		{
			::GlobalFree(m_hlpBitInfo);
			::GlobalFree(m_hDib);
			m_hlpBitInfo = NULL;
			m_hDib = NULL;
			m_pDib = NULL;
			m_lpBitInfo = NULL;

			return FALSE;
		}

		return TRUE;
	}

	return FALSE;
}

BOOL CDib::Create(int width, int height, int bits)
{
	CloseBMP();
	BYTE * pBuffT = NULL;
	LPBITMAPINFO	pbmi = NULL;

	HGLOBAL hDIB = ::GlobalAlloc(GMEM_FIXED, sizeof(BITMAPINFO) + width*height*(bits/8));
	if (hDIB == 0)
		return FALSE;

	pBuffT	= (BYTE*)hDIB;
	pbmi = (LPBITMAPINFO)hDIB;

	//BITMAPINFO
    pbmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    pbmi->bmiHeader.biWidth = width;
    pbmi->bmiHeader.biHeight = height;
    pbmi->bmiHeader.biPlanes = 1;
    pbmi->bmiHeader.biBitCount = bits;
    pbmi->bmiHeader.biCompression = BI_RGB;
    pbmi->bmiHeader.biSizeImage = width*height*(bits/8);
    pbmi->bmiHeader.biXPelsPerMeter = 0;
    pbmi->bmiHeader.biYPelsPerMeter = 0;
    pbmi->bmiHeader.biClrUsed = 0;
    pbmi->bmiHeader.biClrImportant = 0;         
    ////BITMAPINFO 

	m_hGlobalDIB = hDIB;

	return TRUE;
}

void CDib::CloseBMP()
{
	if(m_hGlobalDIB)
	{
		::GlobalFree(m_hGlobalDIB);
		m_hGlobalDIB = NULL;
	}

	if( m_hlpBitInfo )
	{
		::GlobalFree(m_hlpBitInfo);
		m_hlpBitInfo = NULL;
		m_lpBitInfo = NULL;
	}

	if( m_hDib )
	{
		::GlobalFree(m_hDib);
		m_hDib = NULL;
		m_pDib = NULL;
	}

	m_Palette.DeleteObject();
}

void CDib::DrawDIBWholeImage(CDC* pDC)
{
	if( !m_hGlobalDIB )	return;

	BOOL	bSuccess=FALSE; 	// Success/fail flag

	if( m_Palette.m_hObject && (pDC->GetDeviceCaps(RASTERCAPS) & RC_PALETTE) )
	{
		pDC->SelectPalette(&m_Palette, FALSE);
		pDC->RealizePalette();
	}

	CSize sizeImage = GetBitmapSize();

	::SetDIBitsToDevice(pDC->m_hDC, 				// hDC
				   0,								// DestX
				   0,								// DestY
				   sizeImage.cx,					// nDestWidth
				   sizeImage.cy,					// nDestHeight
				   0,								// SrcX
				   0,								// SrcY
				   0,								// nStartScan
				   sizeImage.cy,					// nNumScans
				   GetBitmapImage(),				// lpBits
				   (LPBITMAPINFO)m_hGlobalDIB,		// lpBitsInfo
				   DIB_RGB_COLORS); 				// wUsage
}

BOOL CDib::StretchDIBits( CDC* pDC,
						int XDest,           
						int YDest,         
						int nDestWidth,    
						int nDestHeight,   
						int XSrc,          
						int YSrc,          
						int nSrcWidth,     
						int nSrcHeight)             
{
	BOOL	bSuccess=FALSE; 	// Success/fail flag

	if( m_Palette.m_hObject && (pDC->GetDeviceCaps(RASTERCAPS) & RC_PALETTE) )
	{
		pDC->SelectPalette(&m_Palette, FALSE);
		pDC->RealizePalette();
	}

	::SetStretchBltMode(pDC->m_hDC, STRETCH_DELETESCANS);
	if (!::StretchDIBits(pDC->m_hDC, XDest, YDest, nDestWidth, nDestHeight,
		XSrc, GetBitmapSize().cy-YSrc-nSrcHeight, nSrcWidth, nSrcHeight,
		GetBitmapImage(), GetBitmapInfo(), DIB_RGB_COLORS, SRCCOPY)) {
		return FALSE;
    }

	return TRUE;
}

BOOL CDib::BitBlt( CDC* pDC,
						int XDest,           
						int YDest,         
						int nWidth,    
						int nHeight,   
						int XSrc,
						int YSrc)
{
	BOOL	bSuccess=FALSE; 	// Success/fail flag

	if( m_Palette.m_hObject && (pDC->GetDeviceCaps(RASTERCAPS) & RC_PALETTE) )
	{
		pDC->SelectPalette(&m_Palette, FALSE);
		pDC->RealizePalette();
	}

	::SetStretchBltMode(pDC->m_hDC, STRETCH_DELETESCANS);
	if (!::StretchDIBits(pDC->m_hDC, XDest, YDest, nWidth, nHeight,
		XSrc, GetBitmapSize().cy-YSrc-nHeight, nWidth, nHeight,
		GetBitmapImage(), GetBitmapInfo(), DIB_RGB_COLORS, SRCCOPY)) {
		return FALSE;
    }

	return TRUE;
}

LPBITMAPINFO CDib::GetBitmapInfo()
{
	if( m_hGlobalDIB )
		return (LPBITMAPINFO)m_hGlobalDIB;	
	else if( m_lpBitInfo )
		return m_lpBitInfo;

	return NULL;
}

CSize CDib::GetBitmapSize()
{
	BITMAPINFO * pBmInfo = GetBitmapInfo();

	if( pBmInfo )
		return CSize(pBmInfo->bmiHeader.biWidth, pBmInfo->bmiHeader.biHeight);
	return CSize(0, 0);
}

LPVOID CDib::GetBitmapImage()
{
	LPVOID	lpDIBBits = NULL;		// Pointer to DIB bits

	if( m_hGlobalDIB )
	{
		LPBITMAPINFO pBmInfo = GetBitmapInfo();

		if( !pBmInfo ) return NULL;
			
		int nColors = pBmInfo->bmiHeader.biClrUsed ? pBmInfo->bmiHeader.biClrUsed : 
							1 << pBmInfo->bmiHeader.biBitCount;

		if( pBmInfo->bmiHeader.biBitCount > 8 )
			lpDIBBits = (LPVOID)((LPDWORD)(pBmInfo->bmiColors +
				pBmInfo->bmiHeader.biClrUsed) +
				((pBmInfo->bmiHeader.biCompression == BI_BITFIELDS) ? 3 : 0));
		else
			lpDIBBits = (LPVOID)(pBmInfo->bmiColors + nColors);
	}
	else if(  m_pDib )
		lpDIBBits = (LPVOID) m_pDib;

	return lpDIBBits;
}

CRect CDib::GetRect()
{
	CRect	rect(0, 0, 0, 0);
	LPBITMAPINFO pBmInfo = GetBitmapInfo();
	
	if( pBmInfo )
	{
		rect.right = pBmInfo->bmiHeader.biWidth;
		rect.bottom = pBmInfo->bmiHeader.biHeight;
	}

	return rect;
}