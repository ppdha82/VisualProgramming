/**
 *      Project Name : Standalone DVR
 *
 *      Copyright 2010 by Samsung Techwin Co., Ltd
 *
 *      Copyright Description :
 *      This software is the confidential and proprietary information
 *      of Samsung Techwin Co., Ltd. ("Confidential Information").
 *      You shall not disclose such Confidential Information and shall
 *      use it only in accordance with the terms of the license agreement
 *      you entered into with Samsung.
 */

/**
 *      @file:	pes_header.h
 *      @brief:
 *      @author: Park, YoungJoon (yj71.park@samsung.com)
 *      	 Network R&D Group 2, SS R&D Team 1
 *      @date: 	Mar 10, 2010
 *      @version:	1.0.0
 */



#ifndef PES_HEADER_H_
#define PES_HEADER_H_

//#include "system.h"
#include "pes_bigendian.h"
/*
#if defined(__cplusplus)
extern "C"
{
#endif
#include <sys/types.h>
*/
#define PES_AUDIO_HEADER_SIZE	32
#define PES_VIDEO_HEADER_SIZE	48
#ifdef DEF_META_SUPPORT
#define PES_META_HEADER_SIZE	32
#endif
#define	MAX_PES_HEADER_SIZE		PES_VIDEO_HEADER_SIZE
//#define MAX_DEMUX_BUF_NUM	(10)

#ifdef DEF_SRN4000 /* StreamReader 재생 성능 부족으로 인한 limit (성능 향상시 재조정 필요) */
#define MAX_DECODE_DATA_RATE    ( 32 << 17 )       // 32Mbps 
#else  /* 16Ch x 10Mbps - Decoder의 DataRate 성능 제약이 없을 때 Stream Reader 최대 재생 성능. */
#define MAX_DECODE_DATA_RATE    ( 160 << 17 )      // 160 Mbps
#endif //DEF_SRN4000

typedef unsigned long             ulong;


/**
 *
 * @enum 
 * @brief 
 */
typedef enum
{
	A_FRAME = 0,
	I_FRAME = 1,
	P_FRAME,
	B_FRAME,
	ALL_FRAME
} pict_type_t;

// jwwon (+)   2010.08.30

/**
 *
 * @enum 
 * @brief 
 */
typedef enum
{
	NONE_IDR_NAL = 1,
	IDR_NAL = 5,
	SPS_NAL = 7,
	PPS_NAL = 8
} H264_pict_type_t;
// (-)


/**
 *
 * @enum 
 * @brief 
 */
typedef enum
{
	// Pulse code modulation (PCM) of voice frequencies
	ACODEC_G711,		// DVR SHR-516x 계열
	// adaptive differential pulse code modulation to 24 and 40 kbit/s
	ACODEC_G723,		// DVR SHR-6,7,8 / SRD 계열
	// Dual rate speech coder for multimedia communications transmitting at 5.3 and 6.3 kbit/s
	ACODEC_G723_1,		// DVR SVR-1670
	ACODEC_G711_IPCAM,	// VNP Network Camera SNB-5000 계열
	ACODEC_IMA_ADPCM,	// SSNP Network Camera SNP-3750 계열
	ACODEC_MPEG4_GENERIC,
	ACODEC_G726_16,
	ACODEC_G726_24,
	ACODEC_G726_32,
	ACODEC_G726_40,
	ACODEC_G726_VER,
	ACODEC_UNKNOWN
} audio_codec_t;


/**
 *
 * @enum 
 * @brief 
 */
typedef enum
{
	A_UNKNOWN = 0,
	A_MONO,
	A_STREO
} audio_channel_t;


/**
 *
 * @enum 
 * @brief 
 */
typedef enum
{
	A_8KHz = 0,
	A_16KHz,
	A_32KHz,
	A_64KHz
} audio_sampling_t;


/**
 *
 * @enum 
 * @brief 
 */
typedef enum
{
	A_1_BITS = 0,
	A_2_BITS,
	A_3_BITS,
	A_4_BITS,
	A_5_BITS
} audio_bits_t;


/**
 *
 * @enum 
 * @brief 
 */
typedef enum
{
	SVNP_AUDIO_UNKNOWN = 0,
	SVNP_AUDIO_MONO = 1,
	SVNP_AUDIO_STREO = 2
} SVNP_AUDIO_CHANNEL;


/**
 *
 * @enum 
 * @brief 
 */
typedef enum
{
	SVNP_AUDIO_8KHz = 8,
	SVNP_AUDIO_16KHz = 16,
	SVNP_AUDIO_32KHz = 32,
	SVNP_AUDIO_64KHz = 64
} SVNP_AUDIO_SAMPLING;


/**
 *
 * @enum 
 * @brief 
 */
typedef enum
{
	SVNP_AUDIO_1BITS = 1,
	SVNP_AUDIO_2BITS = 2,
	SVNP_AUDIO_3BITS = 3,
	SVNP_AUDIO_4BITS = 4,
	SVNP_AUDIO_5BITS = 5,
} SVNP_AUDIO_BITS;


/**
 *
 * @enum 
 * @brief 
 */
typedef enum
{
	SVNP_AAC_8K		=	1,
	SVNP_AAC_16K		=	2,
	SVNP_AAC_24K		=	3,
	SVNP_AAC_32K		=	4,
	SVNP_AAC_40K		=	5,
	SVNP_AAC_48K		=	6,
	SVNP_AAC_56K		=	7,
	SVNP_AAC_64K		=	8,
	SVNP_AAC_96K		=	9,
	SVNP_AAC_128K	=	10
} SVNP_AAC_BITRATE;

/**
 * audio/video pes header 여부 확인
 */
static inline int pes_is_av_frame(const unsigned char* pes)
{
	unsigned long code = packet_start_code(pes) & ~0x0000000F;
	return ((code == VIDEO_PACKET_CODE) || (code == AUDIO_PACKET_CODE));
}

/**
 * audio/video pes header 여부 확인
 */
#ifdef DEF_META_SUPPORT

/**
 *
 * @param pes 
 * @return 
 */
static inline int pes_is_avm_frame(const unsigned char* pes)
{
	unsigned long code = packet_start_code(pes) & ~0x0000000F;
	return ((code == VIDEO_PACKET_CODE) || (code == AUDIO_PACKET_CODE) || (code == META_PACKET_CODE));
}
#endif

/**
 * video pes header 여부 확인
 */
static inline int pes_is_video_frame(const unsigned char* pes)
{
	unsigned long code = packet_start_code(pes) & ~0x0000000F;
	return (code == VIDEO_PACKET_CODE);
}

/**
 * audio pes header 여부 확인
 */
static inline int pes_is_audio_frame(const unsigned char* pes)
{
	unsigned long code = packet_start_code(pes) & ~0x0000000F;
	return (code == AUDIO_PACKET_CODE);
}

/**
 * meta pes header 여부 확인
 */
#ifdef DEF_META_SUPPORT

/**
 *
 * @param pes 
 * @return 
 */
static inline int pes_is_meta_frame(const unsigned char* pes)
{
	unsigned long code = packet_start_code(pes) & ~0x0000000F;
	return (code == META_PACKET_CODE);
}
#endif

/**
 * End code 값 써주기
 */
static inline void insert_end_code(unsigned char* buf)
{
	buf[0] = (STREAM_END_CODE >> 24) & 0xFF;
	buf[1] = (STREAM_END_CODE >> 16) & 0xFF;
	buf[2] = (STREAM_END_CODE >> 8) & 0xFF;
	buf[3] = STREAM_END_CODE & 0xFF;
}

/**
 * End code 여부 확인
 */
static inline int pes_is_end_code(const unsigned char* buf)
{
	unsigned long code = (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
	return (code == STREAM_END_CODE);
}

/**
 * 채널 id 설정
 */
static inline void set_pes_channel_id(unsigned char* pes, int ch)
{
	pes[3] &= 0xF0;
	pes[3] |= (ch & 0x0F);
	pes[21] &= 0x8F;
	pes[21] |= (ch & 0x70);
}

/**
 * 채널 id 반환
 */
static inline unsigned int packet_channel_id(const unsigned char* pes)
{
	return 	(pes[3] & 0x0F) | ((pes[21] & 0x70));
}

/**
 * pes header 크기를 반환.
 */
static inline unsigned int pes_header_size(const unsigned char* pes)
{
	return (pes[8] + 9);
}

/**
 * 90kHz 33bit PTS 정보를 읽어서 상,하위 32비트를 나누어 반환한다.
 */
static inline void packet_pts(unsigned char* pes, unsigned long* low, unsigned long* high)
{
	*low = pes[13] >> 1;
	*low |= (pes[12] << 7);
	*low |= ((pes[11] & 0xFE) << 14);
	*low |= (pes[10] << 22);
	*low |= ((pes[9] & 0x06) << 29);
	if(high)
	{
		*high = ((pes[9] & 0x08) != 0);
	}
}

/**
 * 90kHz 33bit DTS 정보를 읽어서 상,하위 32비트를 나누어 반환한다.
 */
static inline void packet_dts(unsigned char* pes, unsigned long* low, unsigned long* high)
{
	*low = pes[18] >> 1;
	*low |= (pes[17] << 7);
	*low |= ((pes[16] & 0xFE) << 14);
	*low |= (pes[15] << 22);
	*low |= ((pes[14] & 0x06) << 29);
	if(high)
	{
		*high = ((pes[14] & 0x08) != 0);
	}
}

#if	0	// 전체 33비트 중 상위 32비트 이용
/**
 * 90kHz 33bit PTS 정보를 읽어서 상위 32bit 값만 반환
 */
static inline unsigned long packet_pts32(const unsigned char* pes)
{
	unsigned long	low;

	low = pes[13] >> 2;
	low |= (pes[12] << 6);
	low |= ((pes[11] & 0xFE) << 13);
	low |= (pes[10] << 21);
	low |= ((pes[9] & 0x0E) << 28);
	return low;
}

/**
 * 90kHz 33bit DTS 정보를 읽어서 상위 32bit 값만 반환
 */
static inline unsigned long packet_dts32(const unsigned char* pes)
{
	unsigned long	low;

	low = pes[18] >> 2;
	low |= (pes[17] << 6);
	low |= ((pes[16] & 0xFE) << 13);
	low |= (pes[15] << 21);
	low |= ((pes[14] & 0x0E) << 28);
	return low;
}
#else	// 0, 전체 33비트 중 하위 32비트 이용
/**
 * 90kHz 33bit PTS 정보를 읽어서 하위 32bit 값만 반환
 */
static inline unsigned long packet_pts32(const unsigned char* pes)
{
	unsigned long	low;

	low = pes[13] >> 1;
	low |= (pes[12] << 7);
	low |= ((pes[11] & 0xFE) << 14);
	low |= (pes[10] << 22);
	low |= ((pes[9] & 0x06) << 29);
	return low;
}

/**
 * 90kHz 33bit DTS 정보를 읽어서 하위 32bit 값만 반환
 */
static inline unsigned long packet_dts32(const unsigned char* pes)
{
	unsigned long	low;

	low = pes[18] >> 1;
	low |= (pes[17] << 7);
	low |= ((pes[16] & 0xFE) << 14);
	low |= (pes[15] << 22);
	low |= ((pes[14] & 0x06) << 29);
	return low;
}
#endif	// 0

/**
 * dts 정보를 이용 초단위 time stamp 를 반환
 */
static inline time_t pes_timestamp_sec(const unsigned char* pes)
{
	return packet_dts32(pes) / 90000;
}

/**
 * dts 정보를 이용 백만분의 1초 단위 time stamp 를 반환
 */
static inline int pes_timestamp_usec(const unsigned char* pes)
{
	return ((packet_dts32(pes) % 90000) * 100 / 9);
}

/**
 * codec 종류 설정 (video_codec_t, audio_codec_t 상수 활용)
 */
static inline void set_pes_codec_type(unsigned char* pes, int type)
{
	pes[21] &= 0xF0;
	pes[21] |= (type & 0x0F);
}

/**
 * codec 종류 반환 (video_codec_t, audio_codec_t 상수 활용)
 */
static inline int pes_codec_type(const unsigned char* pes)
{
	return (pes[21] & 0x0F);
}

/**
 * pes header 를 포함하는 packet 길이 반환
 */
static inline int current_packet_length(const unsigned char* pes)
{
	int	packet_length;

	packet_length = pes[22] << 18;
	packet_length |= ((((pes[23] & 0xF0) >> 1) | (pes[23] & 0x07)) << 11);
	packet_length |= (pes[24] & 0x7F) << 4;
	packet_length |= ((pes[25] & 0xF0) >> 4);
	return packet_length;
}

/**
 * 초 단위 엔코딩 시점 설정
 */
static inline void set_packet_time_code(unsigned char* pes, time_t t)
{
	pes[27] = (t >> 24) & 0xFF;
	pes[28] = ((t >> 16) & 0xFF) | 0x01;
	pes[29] = ((t >> 9) & 0xFF) | 0x01;
	pes[30] = (t >> 2) & 0xFF;
	pes[31] &= 0xF9;
	pes[31] |= (t << 1) & 0x06;
}

/**
 * 초 단위 엔코딩 시점 반환
 */
static inline time_t packet_time_code(const unsigned char* pes)
{
	time_t t = (pes[27] << 24) |
			   ((pes[28] & 0xFE) << 16) |
			   ((pes[29] & 0xFE) << 9) |
			   (pes[30] << 2) |
			   ((pes[31] & 0x06) >> 1);
	return t;
}

/**
 * 엔코딩 시점 usec 정보 설정
 */
static inline void set_packet_time_usec(unsigned char* pes, int usec)
{
	usec /= 1000;	// millisecond 로 변환
	pes[25] &= 0xF8;
	pes[25] |= (0x08 | ((usec >> 7) & 0x07));
	pes[26] = ((usec << 1) & 0xFE) | 0x01;
}

/**
 * 엔코딩 시점 usec 정보 반환
 */
static inline int packet_time_usec(const unsigned char* pes)
{
	int	msec;

	msec = (pes[25] & 0x07) << 7;
	msec |= ((pes[26] & 0xFE) >> 1);
	return msec*1000;
}


/****************************************************************************************
 * video frame only functions
 ****************************************************************************************/

/**
 * 영상 프레임 타입과 전송방식(NTSC,PAL) 설정
 */
static inline void set_vop_type_vstd(unsigned char *pes,int vop_type,int isPal)
{
	pes[31] &= 0x37;
	pes[31] |= ((vop_type << 6) & 0xC0);
	if(isPal)
	{
		pes[31] |= 0x08;
	}
}

/**
 * 영상 프레임 타입 반환
 */
static inline int packet_pict_type(const unsigned char* pes)
{
	if(pes_is_audio_frame(pes))
	{
		return A_FRAME;
	}

	/*
	 * 1 -> I-frame
	 * 2 -> P-frame
	 * 3 -> B-frame
	 */
	return ((pes[31] >> 6) & 0x03);
}

/**
 * I frame 여부 반환
 */
static inline int packet_is_i(const unsigned char* pes)
{
	// check is video packet
	if(!pes_is_video_frame(pes))
	{
		return 0;
	}
	// check is I frame
	return (packet_pict_type(pes) == I_FRAME);
}

/**
 * 현재 구간에 오디오 데이터가 있는지 여부 설정
 */
static inline void set_chk_pes_audio_existence(unsigned char* pes, int on)
{
	if(on)
	{
		pes[31] |= 0x20;
	}
	else
	{
		pes[31] &= 0xDF;
	}
}

/**
 * 현재 구간에 오디오 데이터가 있는지 여부 반환
 */
static inline int chk_pes_audio_existence(const unsigned char* pes)
{
	return ((pes[31] & 0x20) != 0);
}

/**
 * pal 인지 반환 (0: NTSC, 1: PAL)
 */
static inline int packet_is_pal(const unsigned char* pes)
{
	return ((pes[38] & 0x08) != 0);
}

/**
 * frame interval 설정
 */
static inline void set_packet_frame_interval(unsigned char* pes, int interval)
{
	// fps=0
	pes[31] &= 0xEF;
	pes[32] = 0x80 | (interval & 0x7F);
}

/**
 * fps 형식의 frame rate 기록
 */
static inline void set_pes_fps(unsigned char* pes, int fps)
{
	pes[31] |= 0x10;
	pes[32] = 0x80 | (fps & 0x7F);
}

/**
 * 몇 장마다 샘플링 하나? 30fps:interval=1, 15fps:interval=2
 */
static inline int packet_frame_interval(const unsigned char* pes)
{
	return (pes[32] & 0x7F);
}

/**
 * fps 단위의 frame rate 반환
 */
static inline int packet_frame_rate(const unsigned char* pes)
{
	int	fps;

	if(pes[31] & 0x10)
	{
		// fps 플래그가 on 이면 frame interval 위치의 값이 그대로 fps 값이 된다.
		return packet_frame_interval(pes);
	}
	else
	{
		// fps 플래그가 off 이면 frame interval 값으로부터 fps 를 구한다.
		fps = packet_is_pal(pes) ? 50 : 60;
		return ((fps / packet_frame_interval(pes)) >> 1);
	}
}

/**
 * Byte per second 단위의 데이터 속도 설정
 * @param pes
 * @param rate
 */
static inline void set_packet_data_rate(unsigned char* pes, int rate)
{
	pes[33] = ((rate >> 15) & 0xFF);
	pes[34] = 0x80 | ((rate >> 8) & 0x7F);
	pes[35] = rate & 0xFF;
}

/**
 * Byte per second 단위의 데이터 속도 반환 (최대 8MBps, 64Mpbs)
 */
static inline int packet_data_rate(const unsigned char* pes)
{
	return ((pes[33] << 15) | ((pes[34] & 0x7F) << 8) | pes[35]);
}

/**
 * GOP 크기 설정 (0~127)
 */
static inline void set_packet_gop_size(unsigned char* pes, int gop)
{
	pes[36] = 0x80 | (gop & 0x7F);
}

/**
 * GOP 크기 반환
 */
static inline int packet_gop_size(const unsigned char* pes)
{
	return (pes[36] & 0x7F);
}

/**
 * 모션발생 여부 설정
 */
static inline void set_packet_motion_flag(unsigned char* pes,int on)
{
	if(on)
	{
		pes[38] |= 0x80;
	}
	else
	{
		pes[38] &= 0x7F;
	}
}

/**
 * 모션발생 여부 반환
 */
static inline int packet_motion_flag(const unsigned char* pes)
{
	return ((pes[38] & 0x80) != 0);
}

/**
 * 영상소스의 Progressive 여부 설정
 */
static inline void set_pes_progress_flag(unsigned char* pes,int on)
{
	if(on)
	{
		pes[38] |= 0x40;
	}
	else
	{
		pes[38] &= 0xBF;
	}
}

/**
 * 영상소스의 Progressive 여부 반환
 * @return (0:Interlaced, 1:Progressive)
 */
static inline int pes_progress_flag(const unsigned char* pes)
{
	return ((pes[38] & 0x40) != 0);
}

/**
 * 영상 화면크기 설정
 * @warning 영상의 폭, 높이는 반드시 16의 배수여야 한다.
 */
static inline void set_pes_frame_resolution(unsigned char* pes, int width, int height)
{
	width >>= 3;	// 저장은 8의 배수형태로 저장
	pes[38] &= 0xF8;
	pes[38] |= ((width >> 7) & 0x07);
	pes[39] = 0x80 | (width & 0x7F);

	height >>= 3;	// 저장은 8의 배수형태로 저장
	pes[38] &= 0xC7;
	pes[38] |= ((height >> 4) & 0x38);
	pes[37] = 0x80 | (height & 0x7F);
}

/**
 * 영상의 화면크기 반환
 */
static inline void pes_frame_resolution(const unsigned char* pes, int* width, int* height)
{
	// 저장은 8의 배수형태로 저장
	*width = ((pes[39] & 0x7F) | ((pes[38] & 0x07) << 7)) << 3;
	*height= ((pes[37] & 0x7F) | ((pes[38] & 0x38) << 4)) << 3;
}


/****************************************************************************************
 * audio frame only functions
 ****************************************************************************************/

/**
 * audio sampling rate 기록
 */
static inline void set_pes_audio_sampling_rate(unsigned char* pes, int rate)
{
	pes[31] &= 0x1F;
	pes[31] |= (rate << 5) & 0xE0;
}

/**
 * audio sampling rate 반환
 */
static inline int pes_audio_sampling_rate(const unsigned char* pes)
{
	return ((pes[31] >> 5) & 0x07);
}

#if 0
/**
 * audio sampling 크기 (bits) 기록
 * (8bit, 16bit, 24bit)
 */
static inline void set_pes_audio_sampling_amplitude(unsigned char* pes, int value)
{
	value >>= 3;	// 8의 배수값만 저장
	pes[31] &= 0xE7;
	pes[31] |= (value << 3) & 0x18;
}

/**
 * audio sampling rate 반환
 */
static inline int pes_audio_sampling_amplitude(const unsigned char* pes)
{
	// 8을 곱해서 반환
	return (((pes[31] >> 3) & 0x03) << 3);
}
#else
/**
 * audio sampling 크기 (bits) 기록
 * (8bit, 16bit, 24bit)
 */
static inline void set_pes_audio_sampling_amplitude(unsigned char* pes, int value)
{
	pes[31] &= 0xE7;
	pes[31] |= ((value & 0x03) << 3);
	pes[14] &= 0x1F;
	pes[14] |= ((value & 0x1C) << 3);
}

/**
 * audio sampling rate 반환
 */
static inline int pes_audio_sampling_amplitude(const unsigned char* pes)
{
	return (((pes[31] >> 3) & 0x03) | ((pes[14] & 0xE0) >> 3));
}
#endif

/**
 *
 * @param pes 
 * @param value 
 */
static inline void set_pes_audio_channel(unsigned char* pes, int value)
{
	pes[9] &= 0xC0;
	pes[9] |= ((value & 0x03) << 6);
}


/**
 *
 * @param pes 
 * @return 
 */
static inline int pes_audio_channel(unsigned char* pes)
{
	return ((pes[9] >> 6) & 0x03);
}


/****************************************************************************************
 * 일반함수 구현부
 ****************************************************************************************/

/**
 *
 */
extern void swap_endian_copy(unsigned char* dst, const unsigned char* src, int size);

/*
 * pes 헤더 초기화 함수들
 * 다음의 세 함수를 호출하면 PES 기본헤더부 초기화 완료
 */

/**
 * 디폴트 필드 초기화
 * @param pes		초기화할 버퍼주소
 * @param isAudio	audio frame 인지 여부
 * @param ch		논리적 채널 id
 */
extern void init_pes_header(unsigned char* pes, int isAudio, int ch);

/**
 * 디폴트 필드 초기화
 * @param pes		초기화할 버퍼주소
 * @param ch		논리적 채널 id
 */
#ifdef DEF_META_SUPPORT
extern void init_meta_pes_header(unsigned char* pes, int ch);
#endif

/**
 * frame 데이터 크기 초기화
 * @param pes		초기화할 버퍼주소
 * @param length	pes 헤더 크기가 포함되지 않은 순수 데이터만의 크기
 */
extern void set_pes_length(unsigned char* pes, int length);

/**
 * time-stamp 초기화
 * @param pes	초기화할 버퍼주소
 * @param sec	초단위 time stamp
 * @param usec	백만분의 1초 단위 time stamp
 */
extern void set_pes_timestamp(unsigned char* pes, int sec, int usec);

/*
 * 원본 time-stamp 가 90kHz 기반의 값이거나 pts와 dts 가 다를 경우에는
 * 시간 설정을 위해 set_pes_timestamp() 대신 다음의 두 함수를 사용한다.
 */
extern void set_pes_pts(unsigned char* pes, unsigned long low, unsigned long high);
extern void set_pes_dts(unsigned char* pes, unsigned long low, unsigned long high);

extern void codec_init(int video_standard, int v_channels, int a_channels, int num_codecs, int enc_cifcaps, int mem_size);

extern pict_type_t is_h264_key_frame(const unsigned char* nal);

#endif /* PES_HEADER_H_ */
