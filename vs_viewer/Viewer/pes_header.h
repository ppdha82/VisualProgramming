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

#ifdef DEF_SRN4000 /* StreamReader ��� ���� �������� ���� limit (���� ���� ������ �ʿ�) */
#define MAX_DECODE_DATA_RATE    ( 32 << 17 )       // 32Mbps 
#else  /* 16Ch x 10Mbps - Decoder�� DataRate ���� ������ ���� �� Stream Reader �ִ� ��� ����. */
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
	ACODEC_G711,		// DVR SHR-516x �迭
	// adaptive differential pulse code modulation to 24 and 40 kbit/s
	ACODEC_G723,		// DVR SHR-6,7,8 / SRD �迭
	// Dual rate speech coder for multimedia communications transmitting at 5.3 and 6.3 kbit/s
	ACODEC_G723_1,		// DVR SVR-1670
	ACODEC_G711_IPCAM,	// VNP Network Camera SNB-5000 �迭
	ACODEC_IMA_ADPCM,	// SSNP Network Camera SNP-3750 �迭
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
 * audio/video pes header ���� Ȯ��
 */
static inline int pes_is_av_frame(const unsigned char* pes)
{
	unsigned long code = packet_start_code(pes) & ~0x0000000F;
	return ((code == VIDEO_PACKET_CODE) || (code == AUDIO_PACKET_CODE));
}

/**
 * audio/video pes header ���� Ȯ��
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
 * video pes header ���� Ȯ��
 */
static inline int pes_is_video_frame(const unsigned char* pes)
{
	unsigned long code = packet_start_code(pes) & ~0x0000000F;
	return (code == VIDEO_PACKET_CODE);
}

/**
 * audio pes header ���� Ȯ��
 */
static inline int pes_is_audio_frame(const unsigned char* pes)
{
	unsigned long code = packet_start_code(pes) & ~0x0000000F;
	return (code == AUDIO_PACKET_CODE);
}

/**
 * meta pes header ���� Ȯ��
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
 * End code �� ���ֱ�
 */
static inline void insert_end_code(unsigned char* buf)
{
	buf[0] = (STREAM_END_CODE >> 24) & 0xFF;
	buf[1] = (STREAM_END_CODE >> 16) & 0xFF;
	buf[2] = (STREAM_END_CODE >> 8) & 0xFF;
	buf[3] = STREAM_END_CODE & 0xFF;
}

/**
 * End code ���� Ȯ��
 */
static inline int pes_is_end_code(const unsigned char* buf)
{
	unsigned long code = (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
	return (code == STREAM_END_CODE);
}

/**
 * ä�� id ����
 */
static inline void set_pes_channel_id(unsigned char* pes, int ch)
{
	pes[3] &= 0xF0;
	pes[3] |= (ch & 0x0F);
	pes[21] &= 0x8F;
	pes[21] |= (ch & 0x70);
}

/**
 * ä�� id ��ȯ
 */
static inline unsigned int packet_channel_id(const unsigned char* pes)
{
	return 	(pes[3] & 0x0F) | ((pes[21] & 0x70));
}

/**
 * pes header ũ�⸦ ��ȯ.
 */
static inline unsigned int pes_header_size(const unsigned char* pes)
{
	return (pes[8] + 9);
}

/**
 * 90kHz 33bit PTS ������ �о ��,���� 32��Ʈ�� ������ ��ȯ�Ѵ�.
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
 * 90kHz 33bit DTS ������ �о ��,���� 32��Ʈ�� ������ ��ȯ�Ѵ�.
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

#if	0	// ��ü 33��Ʈ �� ���� 32��Ʈ �̿�
/**
 * 90kHz 33bit PTS ������ �о ���� 32bit ���� ��ȯ
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
 * 90kHz 33bit DTS ������ �о ���� 32bit ���� ��ȯ
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
#else	// 0, ��ü 33��Ʈ �� ���� 32��Ʈ �̿�
/**
 * 90kHz 33bit PTS ������ �о ���� 32bit ���� ��ȯ
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
 * 90kHz 33bit DTS ������ �о ���� 32bit ���� ��ȯ
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
 * dts ������ �̿� �ʴ��� time stamp �� ��ȯ
 */
static inline time_t pes_timestamp_sec(const unsigned char* pes)
{
	return packet_dts32(pes) / 90000;
}

/**
 * dts ������ �̿� �鸸���� 1�� ���� time stamp �� ��ȯ
 */
static inline int pes_timestamp_usec(const unsigned char* pes)
{
	return ((packet_dts32(pes) % 90000) * 100 / 9);
}

/**
 * codec ���� ���� (video_codec_t, audio_codec_t ��� Ȱ��)
 */
static inline void set_pes_codec_type(unsigned char* pes, int type)
{
	pes[21] &= 0xF0;
	pes[21] |= (type & 0x0F);
}

/**
 * codec ���� ��ȯ (video_codec_t, audio_codec_t ��� Ȱ��)
 */
static inline int pes_codec_type(const unsigned char* pes)
{
	return (pes[21] & 0x0F);
}

/**
 * pes header �� �����ϴ� packet ���� ��ȯ
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
 * �� ���� ���ڵ� ���� ����
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
 * �� ���� ���ڵ� ���� ��ȯ
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
 * ���ڵ� ���� usec ���� ����
 */
static inline void set_packet_time_usec(unsigned char* pes, int usec)
{
	usec /= 1000;	// millisecond �� ��ȯ
	pes[25] &= 0xF8;
	pes[25] |= (0x08 | ((usec >> 7) & 0x07));
	pes[26] = ((usec << 1) & 0xFE) | 0x01;
}

/**
 * ���ڵ� ���� usec ���� ��ȯ
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
 * ���� ������ Ÿ�԰� ���۹��(NTSC,PAL) ����
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
 * ���� ������ Ÿ�� ��ȯ
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
 * I frame ���� ��ȯ
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
 * ���� ������ ����� �����Ͱ� �ִ��� ���� ����
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
 * ���� ������ ����� �����Ͱ� �ִ��� ���� ��ȯ
 */
static inline int chk_pes_audio_existence(const unsigned char* pes)
{
	return ((pes[31] & 0x20) != 0);
}

/**
 * pal ���� ��ȯ (0: NTSC, 1: PAL)
 */
static inline int packet_is_pal(const unsigned char* pes)
{
	return ((pes[38] & 0x08) != 0);
}

/**
 * frame interval ����
 */
static inline void set_packet_frame_interval(unsigned char* pes, int interval)
{
	// fps=0
	pes[31] &= 0xEF;
	pes[32] = 0x80 | (interval & 0x7F);
}

/**
 * fps ������ frame rate ���
 */
static inline void set_pes_fps(unsigned char* pes, int fps)
{
	pes[31] |= 0x10;
	pes[32] = 0x80 | (fps & 0x7F);
}

/**
 * �� �帶�� ���ø� �ϳ�? 30fps:interval=1, 15fps:interval=2
 */
static inline int packet_frame_interval(const unsigned char* pes)
{
	return (pes[32] & 0x7F);
}

/**
 * fps ������ frame rate ��ȯ
 */
static inline int packet_frame_rate(const unsigned char* pes)
{
	int	fps;

	if(pes[31] & 0x10)
	{
		// fps �÷��װ� on �̸� frame interval ��ġ�� ���� �״�� fps ���� �ȴ�.
		return packet_frame_interval(pes);
	}
	else
	{
		// fps �÷��װ� off �̸� frame interval �����κ��� fps �� ���Ѵ�.
		fps = packet_is_pal(pes) ? 50 : 60;
		return ((fps / packet_frame_interval(pes)) >> 1);
	}
}

/**
 * Byte per second ������ ������ �ӵ� ����
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
 * Byte per second ������ ������ �ӵ� ��ȯ (�ִ� 8MBps, 64Mpbs)
 */
static inline int packet_data_rate(const unsigned char* pes)
{
	return ((pes[33] << 15) | ((pes[34] & 0x7F) << 8) | pes[35]);
}

/**
 * GOP ũ�� ���� (0~127)
 */
static inline void set_packet_gop_size(unsigned char* pes, int gop)
{
	pes[36] = 0x80 | (gop & 0x7F);
}

/**
 * GOP ũ�� ��ȯ
 */
static inline int packet_gop_size(const unsigned char* pes)
{
	return (pes[36] & 0x7F);
}

/**
 * ��ǹ߻� ���� ����
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
 * ��ǹ߻� ���� ��ȯ
 */
static inline int packet_motion_flag(const unsigned char* pes)
{
	return ((pes[38] & 0x80) != 0);
}

/**
 * ����ҽ��� Progressive ���� ����
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
 * ����ҽ��� Progressive ���� ��ȯ
 * @return (0:Interlaced, 1:Progressive)
 */
static inline int pes_progress_flag(const unsigned char* pes)
{
	return ((pes[38] & 0x40) != 0);
}

/**
 * ���� ȭ��ũ�� ����
 * @warning ������ ��, ���̴� �ݵ�� 16�� ������� �Ѵ�.
 */
static inline void set_pes_frame_resolution(unsigned char* pes, int width, int height)
{
	width >>= 3;	// ������ 8�� ������·� ����
	pes[38] &= 0xF8;
	pes[38] |= ((width >> 7) & 0x07);
	pes[39] = 0x80 | (width & 0x7F);

	height >>= 3;	// ������ 8�� ������·� ����
	pes[38] &= 0xC7;
	pes[38] |= ((height >> 4) & 0x38);
	pes[37] = 0x80 | (height & 0x7F);
}

/**
 * ������ ȭ��ũ�� ��ȯ
 */
static inline void pes_frame_resolution(const unsigned char* pes, int* width, int* height)
{
	// ������ 8�� ������·� ����
	*width = ((pes[39] & 0x7F) | ((pes[38] & 0x07) << 7)) << 3;
	*height= ((pes[37] & 0x7F) | ((pes[38] & 0x38) << 4)) << 3;
}


/****************************************************************************************
 * audio frame only functions
 ****************************************************************************************/

/**
 * audio sampling rate ���
 */
static inline void set_pes_audio_sampling_rate(unsigned char* pes, int rate)
{
	pes[31] &= 0x1F;
	pes[31] |= (rate << 5) & 0xE0;
}

/**
 * audio sampling rate ��ȯ
 */
static inline int pes_audio_sampling_rate(const unsigned char* pes)
{
	return ((pes[31] >> 5) & 0x07);
}

#if 0
/**
 * audio sampling ũ�� (bits) ���
 * (8bit, 16bit, 24bit)
 */
static inline void set_pes_audio_sampling_amplitude(unsigned char* pes, int value)
{
	value >>= 3;	// 8�� ������� ����
	pes[31] &= 0xE7;
	pes[31] |= (value << 3) & 0x18;
}

/**
 * audio sampling rate ��ȯ
 */
static inline int pes_audio_sampling_amplitude(const unsigned char* pes)
{
	// 8�� ���ؼ� ��ȯ
	return (((pes[31] >> 3) & 0x03) << 3);
}
#else
/**
 * audio sampling ũ�� (bits) ���
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
 * audio sampling rate ��ȯ
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
 * �Ϲ��Լ� ������
 ****************************************************************************************/

/**
 *
 */
extern void swap_endian_copy(unsigned char* dst, const unsigned char* src, int size);

/*
 * pes ��� �ʱ�ȭ �Լ���
 * ������ �� �Լ��� ȣ���ϸ� PES �⺻����� �ʱ�ȭ �Ϸ�
 */

/**
 * ����Ʈ �ʵ� �ʱ�ȭ
 * @param pes		�ʱ�ȭ�� �����ּ�
 * @param isAudio	audio frame ���� ����
 * @param ch		���� ä�� id
 */
extern void init_pes_header(unsigned char* pes, int isAudio, int ch);

/**
 * ����Ʈ �ʵ� �ʱ�ȭ
 * @param pes		�ʱ�ȭ�� �����ּ�
 * @param ch		���� ä�� id
 */
#ifdef DEF_META_SUPPORT
extern void init_meta_pes_header(unsigned char* pes, int ch);
#endif

/**
 * frame ������ ũ�� �ʱ�ȭ
 * @param pes		�ʱ�ȭ�� �����ּ�
 * @param length	pes ��� ũ�Ⱑ ���Ե��� ���� ���� �����͸��� ũ��
 */
extern void set_pes_length(unsigned char* pes, int length);

/**
 * time-stamp �ʱ�ȭ
 * @param pes	�ʱ�ȭ�� �����ּ�
 * @param sec	�ʴ��� time stamp
 * @param usec	�鸸���� 1�� ���� time stamp
 */
extern void set_pes_timestamp(unsigned char* pes, int sec, int usec);

/*
 * ���� time-stamp �� 90kHz ����� ���̰ų� pts�� dts �� �ٸ� ��쿡��
 * �ð� ������ ���� set_pes_timestamp() ��� ������ �� �Լ��� ����Ѵ�.
 */
extern void set_pes_pts(unsigned char* pes, unsigned long low, unsigned long high);
extern void set_pes_dts(unsigned char* pes, unsigned long low, unsigned long high);

extern void codec_init(int video_standard, int v_channels, int a_channels, int num_codecs, int enc_cifcaps, int mem_size);

extern pict_type_t is_h264_key_frame(const unsigned char* nal);

#endif /* PES_HEADER_H_ */
