
// stdafx.cpp : ǥ�� ���� ���ϸ� ��� �ִ� �ҽ� �����Դϴ�.
// Viewer.pch�� �̸� �����ϵ� ����� �˴ϴ�.
// stdafx.obj���� �̸� �����ϵ� ���� ������ ���Ե˴ϴ�.

#include "stdafx.h"
#include "yuv2rgb.h"

void YUV2RGB_INIT(UINT bpp)
{
	yuv2rgb_init((uint_32) bpp, MODE_RGB);
}

void YUV2RGB(BYTE * image, const BYTE * py,
                              const BYTE * pu, const BYTE * pv,
                              const UINT h_size, const UINT v_size,
                              const UINT rgb_stride, const UINT y_stride, const UINT uv_stride)
{
	return yuv2rgb((uint_8 *)image, (const uint_8 *) py,
                   (const uint_8 *) pu, (const uint_8 *) pv,
                   (const uint_32) h_size, (const uint_32) v_size,
                   (const uint_32) rgb_stride, (const uint_32) y_stride, (const uint_32) uv_stride);
}

