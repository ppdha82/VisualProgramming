#pragma once

extern "C"
{
#include "libavformat/avformat.h"
}

typedef enum
{
	VLT_FFMPEG = 0
} VIDEO_LIB_TYPE;

typedef enum
{
	VCT_H264 = 0,
	VCT_JPEG
} VIDEO_CODEC_TYPE;

typedef enum
{
	VF_YUV422 = 0,
	VF_YUV411,
	VF_YUVRGB
} VIDEO_FORMAT;

// video decompress
typedef struct tagVideoDecompressInit
{
	VIDEO_CODEC_TYPE	codectype;
} ST_VIDEO_DECOMPRESS_INIT, * PST_VIDEO_DECOMPRESS_INIT;

typedef struct tagVideoDecompressResult
{
	CSize				dimention;
	VIDEO_FORMAT		videoformat;
	unsigned char *		pImageBuffer[4];
	int					image_linesize[4];
	int					nBufferSize;
} ST_VIDEO_DECOMPRESS_RESULT, * PST_VIDEO_DECOMPRESS_RESULT;

class IVideoDecompress
{
public:
	virtual BOOL	InitDecompress(ST_VIDEO_DECOMPRESS_INIT * pDecInit) = 0;
	virtual BOOL	ReleaseDecompress(void) = 0;
	virtual BOOL	Decompress(unsigned char * pBuffer, int nSize, ST_VIDEO_DECOMPRESS_RESULT * pDecResult) = 0;

	virtual VIDEO_CODEC_TYPE
					GetCodecType(void) = 0;
};

extern BOOL VideoDecompressCreate(VIDEO_LIB_TYPE libtype, IVideoDecompress ** ppDecompress);
extern BOOL VideoDecompressDestroy(IVideoDecompress * pDecompress);

class CVideoDecompressFFMpeg :
	public IVideoDecompress
{
public:
	CVideoDecompressFFMpeg(void);
	virtual ~CVideoDecompressFFMpeg(void);

	virtual BOOL	InitDecompress(ST_VIDEO_DECOMPRESS_INIT * pDecInit);
	virtual BOOL	ReleaseDecompress(void);
	virtual BOOL	Decompress(unsigned char * pBuffer, int nSize, ST_VIDEO_DECOMPRESS_RESULT * pDecResult);

	virtual VIDEO_CODEC_TYPE GetCodecType(void)	{ return m_init.codectype; }

protected:
	AVCodecContext *avcCtx;
	AVCodec *avCodec;
	AVFrame *avFrm;

	ST_VIDEO_DECOMPRESS_INIT	m_init;
};
