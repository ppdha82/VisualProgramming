/**
 *      Project Name : Realtime Four-channel DVR (SHR-2040)
 *
 *      Copyright 2004 by Samsung Electronics Co., Ltd
 *
 *      Project Description :
 *      This software is the confidential and proprietary information
 *      of Samsung Electronics Co., Ltd. ("Confidential Information").
 *      You shall not disclose such Confidential Information and shall
 *      use it only in accordance with the terms of the license agreement
 *      you entered into with Samsung.
 */

/**
 *      File name       : pes_bigendian.h
 *
 *      File Description: codec header file.
 *
 *      Author          : Park, YoungJoon (yj71.park@samsung.com)
 *      Dept            : VSS R&D Group, Digital AV Division
 *      Created Date    : 2008/04/11
 *      Version         : 1.0.0
 *
 */

#ifndef __PES_BIGENDIAN_H
#define __PES_BIGENDIAN_H

#define	STREAM_END_CODE		0x000001B7
#define	VIDEO_PACKET_CODE		0x000001E0
#define	AUDIO_PACKET_CODE	0x000001C0
#define	META_PACKET_CODE		0x000001F0
#define	POS_DATA_CODE			0x000001B0

#define	R_STREAM_END_CODE	STREAM_END_CODE	//big endian, 0xB7010000

/**
 * pes header 앞 부분의 스타트 코드값 반환
 * @warning	이 함수를 직접 호출해서 사용하지 말것.
 */
static inline unsigned long packet_start_code(const unsigned char* pes)
{
	return ((pes[0] << 24) | (pes[1] << 16) | (pes[2] << 8) | pes[3]);
}

#endif /* __PES_BIGENDIAN_H */
