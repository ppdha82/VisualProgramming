#pragma once

#define MAX_NUM_OF_EVENTS  (15)

class CFrame
{
public:
	CFrame(void);
	~CFrame(void);

	BOOL	CreateBuffer(unsigned long lSize);
	BOOL	DestroyBuffer(void);

	BOOL	CloneFrame(CFrame * pFrame);

	BOOL	GetStream(unsigned char ** ppBuffer, unsigned long * pLength);

public:
	unsigned char *	m_pData;
	unsigned long	m_lDataSize;
	unsigned long	time;
	unsigned long	millitm;

	unsigned int	framecnt;

	CRect  m_dspTable[MAX_NUM_OF_EVENTS];
};

class IMedia
{
public:
	typedef enum
	{
		MEDIA_H264 = 0,
		MEDIA_SSF,
		MEDIA_VS
	} MEDIATYPE;

	virtual MEDIATYPE GetMediaType(void) = 0;
	virtual BOOL SetMediaFile(CString strMediaFile) = 0;
	virtual BOOL GetNextStream(CFrame ** ppFrame) = 0;
};

extern BOOL CreateMedia(const CString strFName, IMedia ** ppMedia);
extern BOOL DestroyMedia(IMedia ** ppMedia);

class CMediaH264 : public IMedia
{
public:
	CMediaH264(void);
	~CMediaH264(void);

	virtual MEDIATYPE GetMediaType(void)  { return MEDIA_H264; }
	virtual BOOL SetMediaFile(CString strMediaFile);
	virtual BOOL GetNextStream(CFrame ** ppFrame);

protected:
	CString _m_strMediaFileName;
	CFile	_m_fMedia;
	FILE *	_m_fMediaTxt;
};

class CMediaSSF : public IMedia
{
public:
	CMediaSSF(void);
	~CMediaSSF(void);

	virtual MEDIATYPE GetMediaType(void)  { return MEDIA_SSF; }
	virtual BOOL SetMediaFile(CString strMediaFile);
	virtual BOOL GetNextStream(CFrame ** ppFrame);

protected:
	CString _m_strMediaFileName;
	CFile	_m_fMedia;
};

class CMediaVS : public IMedia
{
public:
	CMediaVS(void);
	~CMediaVS(void);

	virtual MEDIATYPE GetMediaType(void)  { return MEDIA_VS; }
	virtual BOOL SetMediaFile(CString strMediaFile);
	virtual BOOL GetNextStream(CFrame ** ppFrame);

protected:
	CString _m_strMediaFileName;
	CFile	_m_fMedia;
};