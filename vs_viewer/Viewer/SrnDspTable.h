/***********************************************************************************
 * Copyright(c) 2014 by Samsung Techwin, Inc.
 *
 * This software is copyrighted by, and is the sole property of Samsung Techwin.
 * All rights, title, ownership, or other interests in the software remain the
 * property of Samsung Techwin. This software may only be used in accordance with
 * the corresponding license agreement. Any unauthorized use, duplication,
 * transmission, distribution, or disclosure of this software is expressly
 * forbidden.
 *
 * This Copyright notice may not be removed or modified without prior written
 * consent of Samsung Techwin.
 *
 * Samsung Techwin reserves the right to modify this software without notice.
 *
 * Samsung Techwin, Inc.
 * KOREA
 * http://www.samsungtechwin.co.kr
 *********************************************************************************/

/**
 * @file SrnDspTable.h
 * @brief 
 * @author: 
 * @date: 
 * @version: 
 */

#ifndef _SRN_DSP_TABLE_H_
#define _SRN_DSP_TABLE_H_

#include <time.h>


/**
 *
 * @enum 
 * @brief 
 */
typedef enum
{
	possible_hold_frame = -3,
	background_frame = -2,
	skip_frame = -1,
	use_frame = 0,
} FRAME_USAGE;


/**
 *
 * @struct 
 * @brief 
 */
typedef struct DSPLineInfo
{
	unsigned long long mLocalTimeMS; //for local time
	unsigned long long mFrameTimeMS;
	unsigned long long mSummaryTime;
	short mX;
	short mY;
	short mWidth;
	short mHeight;
	int	  mEventId;
	FRAME_USAGE mUseage;
} DSPLineInfo;


/**
 *
 * @union 
 * @brief 
 */
typedef union DspTable
{
	DSPLineInfo d;
//	unsigned char uc[80];
} DspTable;


#endif


