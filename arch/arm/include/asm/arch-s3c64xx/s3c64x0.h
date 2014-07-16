/*
 * (C) Copyright 2003
 * David MÃŒller ELSOFT AG Switzerland. d.mueller@elsoft.ch
 *
 * (C) Copyright 2008
 * Guennadi Liakhovetki, DENX Software Engineering, <lg@denx.de>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/************************************************
 * NAME	    : S3C64XX.h
 * Version  : 31.3.2003
 *
 * common stuff for SAMSUNG S3C64XX SoC
 ************************************************/

#ifndef __S3C64XX_H__
#define __S3C64XX_H__

#if defined(CONFIG_SYNC_MODE) && defined(CONFIG_S3C6400)
#error CONFIG_SYNC_MODE unavailable on S3C6400, please, fix your configuration!
#endif

#include <asm/types.h>

/* UART (see manual chapter 11) */
typedef struct {
	volatile u32	ULCON;
	volatile u32	UCON;
	volatile u32	UFCON;
	volatile u32	UMCON;
	volatile u32	UTRSTAT;
	volatile u32	UERSTAT;
	volatile u32	UFSTAT;
	volatile u32	UMSTAT;
#ifdef __BIG_ENDIAN
	volatile u8	res1[3];
	volatile u8	UTXH;
	volatile u8	res2[3];
	volatile u8	URXH;
#else /* Little Endian */
	volatile u8	UTXH;
	volatile u8	res1[3];
	volatile u8	URXH;
	volatile u8	res2[3];
#endif
	volatile u32	UBRDIV;
#ifdef __BIG_ENDIAN
	volatile u8	res3[2];
	volatile u16	UDIVSLOT;
#else
	volatile u16	UDIVSLOT;
	volatile u8	res3[2];
#endif
} s3c64xx_uart;

/* PWM TIMER (see manual chapter 10) */
typedef struct {
	volatile u32	TCNTB;
	volatile u32	TCMPB;
	volatile u32	TCNTO;
} s3c64xx_timer;

typedef struct {
	volatile u32	TCFG0;
	volatile u32	TCFG1;
	volatile u32	TCON;
	s3c64xx_timer	ch[4];
	volatile u32	TCNTB4;
	volatile u32	TCNTO4;
} s3c64xx_timers;

typedef struct {
	volatile u32	GPACON;
	volatile u32	GPADAT;
	volatile u32	GPAPUD;
	volatile u32	GPACONSLP;
	volatile u32	GPAPUDSLP;
	volatile u8	res1[12];

	volatile u32	GPBCON;
	volatile u32	GPBDAT;
	volatile u32	GPBPUD;
	volatile u32	GPBCONSLP;
	volatile u32	GPBPUDSLP;
	volatile u8	res2[12];

	volatile u32	GPCCON;
	volatile u32	GPCDAT;
	volatile u32	GPCPUD;
	volatile u32	GPCCONSLP;
	volatile u32	GPCPUDSLP;
	volatile u8	res3[12];

	volatile u32	GPDCON;
	volatile u32	GPDDAT;
	volatile u32	GPDPUD;
	volatile u32	GPDCONSLP;
	volatile u32	GPDPUDSLP;
	volatile u8	res4[12];

	volatile u32	GPECON;
	volatile u32	GPEDAT;
	volatile u32	GPEPUD;
	volatile u32	GPECONSLP;
	volatile u32	GPEPUDSLP;
	volatile u8	res5[12];

	volatile u32	GPFCON;
	volatile u32	GPFDAT;
	volatile u32	GPFPUD;
	volatile u32	GPFCONSLP;
	volatile u32	GPFPUDSLP;
	volatile u8	res6[12];

	volatile u32	GPGCON;
	volatile u32	GPGDAT;
	volatile u32	GPGPUD;
	volatile u32	GPGCONSLP;
	volatile u32	GPGPUDSLP;
	volatile u8	res7[12];

	volatile u32	GPHCON0;
	volatile u32	GPHCON1;
	volatile u32	GPHDAT;
	volatile u32	GPHPUD;
	volatile u32	GPHCONSLP;
	volatile u32	GPHPUDSLP;
	volatile u8	res8[8];

	volatile u32	GPICON;
	volatile u32	GPIDAT;
	volatile u32	GPIPUD;
	volatile u32	GPICONSLP;
	volatile u32	GPIPUDSLP;
	volatile u8	res9[12];

	volatile u32	GPJCON;
	volatile u32	GPJDAT;
	volatile u32	GPJPUD;
	volatile u32	GPJCONSLP;
	volatile u32	GPJPUDSLP;
	volatile u8	res10[12];

	volatile u32	GPOCON;
	volatile u32	GPODAT;
	volatile u32	GPOPUD;
	volatile u32	GPOCONSLP;
	volatile u32	GPOPUDSLP;
	volatile u8	res11[12];

	volatile u32	GPPCON;
	volatile u32	GPPDAT;
	volatile u32	GPPPUD;
	volatile u32	GPPCONSLP;
	volatile u32	GPPPUDSLP;
	volatile u8	res12[12];

	volatile u32	GPQCON;
	volatile u32	GPQDAT;
	volatile u32	GPQPUD;
	volatile u32	GPQCONSLP;
	volatile u32	GPQPUDSLP;
	volatile u8	res13[12];

	volatile u32	SPCON;
	volatile u8	res14[28];

	volatile u32	MEM0CONSLP0;
	volatile u32	MEM0CONSLP1;
	volatile u32	MEM1CONSLP;
	volatile u8	res15[4];

	volatile u32	MEM0DRVCON;
	volatile u32	MEM1DRVCON;
	volatile u8	res16[40];

	volatile u32	EINT12CON;
	volatile u32	EINT34CON;
	volatile u32	EINT56CON;
	volatile u32	EINT78CON;
	volatile u32	EINT9CON;
	volatile u8	res17[12];

	volatile u32	EINT12FLTCON;
	volatile u32	EINT34FLTCON;
	volatile u32	EINT56FLTCON;
	volatile u32	EINT78FLTCON;
	volatile u32	EINT9FLTCON;
	volatile u8	res18[12];

	volatile u32	EINT12MASK;
	volatile u32	EINT34MASK;
	volatile u32	EINT56MASK;
	volatile u32	EINT78MASK;
	volatile u32	EINT9MASK;
	volatile u8	res19[12];

	volatile u32	EINT12PEND;
	volatile u32	EINT34PEND;
	volatile u32	EINT56PEND;
	volatile u32	EINT78PEND;
	volatile u32	EINT9PEND;
	volatile u8	res20[12];

	volatile u32	PRIORITY;
	volatile u32	SERVICE;
	volatile u32	SERVICEPEND;
	volatile u8	res21[1396];

	volatile u32	GPKCON0;
	volatile u32	GPKCON1;
	volatile u32	GPKDAT;
	volatile u32	GPKPUD;

	volatile u32	GPLCON0;
	volatile u32	GPLCON1;
	volatile u32	GPLDAT;
	volatile u32	GPLPUD;

	volatile u32	GPMCON;
	volatile u32	GPMDAT;
	volatile u32	GPMPUD;
	volatile u8	res22[4];

	volatile u32	GPNCON;
	volatile u32	GPNDAT;
	volatile u32	GPNPUD;
	volatile u8	res23[68];

	volatile u32	SPCONSLP;
	volatile u8	res24[124];

	volatile u32	EINT0CON0;
	volatile u32	EINT0CON1;
	volatile u8	res25[8];

	volatile u32	EINT0FLTCON0;
	volatile u32	EINT0FLTCON1;
	volatile u32	EINT0FLTCON2;
	volatile u32	EINT0FLTCON3;

	volatile u32	EINT0MASK;
	volatile u32	EINT0PEND;
	volatile u8	res26[8];

	volatile u32	SLPEN;

} s3c64xx_gpio;

#endif /*__S3C64XX_H__*/
