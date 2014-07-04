/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 * Gary Jennejohn <garyj@denx.de>
 * David Mueller <d.mueller@elsoft.ch>
 *
 * (C) Copyright 2008
 * Guennadi Liakhovetki, DENX Software Engineering, <lg@denx.de>
 *
 * Configuation settings for the SAMSUNG SMDK6400(mDirac-III) board.
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

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_S3C6410		1	/* in a SAMSUNG S3C6400 SoC     */
#define CONFIG_S3C64XX		1	/* in a SAMSUNG S3C64XX Family  */
#define CONFIG_SMDK6410		1	/* on a SAMSUNG SMDK6400 Board  */

#define CONFIG_SKIP_RELOCATE_UBOOT

#define CONFIG_PERIPORT_REMAP
#define CONFIG_PERIPORT_BASE	0x70000000
#define CONFIG_PERIPORT_SIZE	0x13

#define CONFIG_SYS_SDRAM_BASE	0x50000000

/* input clock of PLL: SMDK6400 has 12MHz input clock */
#define CONFIG_SYS_CLK_FREQ	12000000

#if !defined(CONFIG_NAND_SPL) && (TEXT_BASE >= 0xc0000000)
#define CONFIG_ENABLE_MMU
#endif

#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_CMDLINE_TAG
#define CONFIG_INITRD_TAG

/*
 * Architecture magic and machine type
 */
#define MACH_TYPE		2520

#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

/* Boot configuration (define only one of next 3) */
#define CONFIG_BOOT_NAND
//#define CONFIG_BOOT_MOVINAND
/* None of these are currently implemented. Left from the original Samsung
 * version for reference
#define CONFIG_BOOT_NOR
#define CONFIG_BOOT_MOVINAND
#define CONFIG_BOOT_ONENAND
*/

/*
    LCD
*/
//enable LCD display
#if 0
#define CONFIG_CMD_BMP
#define CONFIG_VIDEO
#define CONFIG_VIDEO_S3C64X0
#define CONFIG_VIDEO_LOGO
#define VIDEO_FB_16BPP_WORD_SWAP    //for BMP logo

#define CONFIG_VIDEO_SW_CURSOR
//#define CONFIG_VIDEO_BMP_LOGO
//#define CONFIG_CONSOLE_EXTRA_INFO
//#define CONFIG_CONSOLE_CURSOR
//#define CONFIG_CONSOLE_TIME
#define CONFIG_CFB_CONSOLE
#define CONFIG_SYS_CONSOLE_IS_IN_ENV
//#define CFG_CONSOLE_INFO_QUIET
//#define VIDEO_FB_LITTLE_ENDIAN
#define CONFIG_SPLASH_SCREEN
#define CONFIG_SYS_VIDEO_LOGO_MAX_SIZE         (1024*768+1024+100) /* 100 = slack */
#define CONFIG_VIDEO_BMP_GZIP
#define CONFIG_CMD_UNZIP
#define LCD_VIDEO_ADDR         0x57a00000
#define LCD_VIDEO_BACKGROUND

#if defined(LCD_VIDEO_BACKGROUND)
#define LCD_VIDEO_BACKGROUND_ADDR         	(0x57900000)
#define LCD_VIDEO_BACKGROUND_LOADADDR         	(0x57700000)
#define LCD_VIDEO_BACKGROUND_LOADSIZE         	(0x40000)
#define LCD_VIDEO_BACKGROUND_ALPHA         	(0xa)
#define LCD_VIDEO_BACKGROUND_IN_NAND
#define LCD_VIDEO_BACKGROUND_FLASH_ADDR		(0xa0000)
#endif
#define CONFIG_SYS_VIDEO_VCLOCK_HZ		(133000000)

//RAM_TEXT = 0x57e00000

/*for PC-keyboard*/
#define VIDEO_KBD_INIT_FCT     0
#define VIDEO_TSTC_FCT         serial_tstc
#define VIDEO_GETC_FCT         serial_getc
#endif  /*enable LCD display*/

#define CONFIG_LCD
#ifdef CONFIG_LCD
//#define CONFIG_LCD_LOGO
#endif


//#define virt_to_phys(x)	(x)

/*
 * Size of malloc() pool
 */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 1024 * 1024)
#define CONFIG_SYS_GBL_DATA_SIZE	128	/* size in bytes for initial data */

/*
 * Hardware drivers
 */
#define CONFIG_NET_MULTI
#define CONFIG_CS8900			/* we have a CS8900 on-board	*/
#define CONFIG_CS8900_BASE	  	0x18800300
#define CONFIG_CS8900_BUS16		/* follow the Linux driver	*/


/*Uart*/
#define CONFIG_CLKSRC_CLKUART
#define CONFIG_UART_66	/* default clock value of CLK_UART */
#define CONFIG_SYNC_MODE


/*
 * select serial console configuration
 */
#define CONFIG_SERIAL1          1	/* we use SERIAL 1 on SMDK6400	*/

#define CONFIG_SYS_HUSH_PARSER			/* use "hush" command parser	*/
#ifdef CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#endif

#define CONFIG_CMDLINE_EDITING

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

#define CONFIG_BAUDRATE		115200

/***********************************************************
 * Command definition
 ***********************************************************/
#include <config_cmd_default.h>


#ifndef CONFIG_BOOT_MOVINAND
#define CONFIG_UBI_FIFESYSTEM
#endif

#ifdef CONFIG_UBI_FIFESYSTEM
/*ubi*/
#define CONFIG_CMD_UBIFS
#define CONFIG_CMD_UBI
#define CONFIG_CMD_MTDPARTS
#define CONFIG_MTD_PARTITIONS
#define CONFIG_MTD_DEVICE
#define CONFIG_RBTREE
#define CONFIG_LZO
#define MTDIDS_DEFAULT "nand0=nand0"

#define MTDPARTS_DEFAULT	"mtdparts=nand0:1m(u-boot),"	\
    						"5m(kernel),"	\
	    					"40m(rootfs),"		\
		    				"40m(data)," \
                            "-(reserved)"
#endif

/*usbd*/
#define CONFIG_S3C_USBD
#define USBD_DOWN_ADDR		0x50007fc0
#define CFG_MAX_NAND_DEVICE CONFIG_SYS_MAX_NAND_DEVICE


#if !defined(__ASSEMBLY__)
extern unsigned UsbDownloadChecksumOK, UsbDownloadFileSize;
extern int FriendlyARMGetDataFromUSB (unsigned max_len, unsigned char **data_ptr, unsigned *received_len);
extern int FriendlyARMWriteNand(const unsigned char*data,  unsigned len,unsigned long offset, unsigned MaxNandSize);
extern int FriendlyARMGetDataFromUsbAndWriteNand(unsigned max_len,unsigned long offset, unsigned MaxNandSize, const char *Name);
extern void FriendlyARMMenu(void);
extern unsigned int FriendlyARMGetNandSizeInMB(void);

#endif


#define CONFIG_CMD_CACHE
#define CONFIG_CMD_REGINFO
#define CONFIG_CMD_LOADS
#define CONFIG_CMD_LOADB
#define CONFIG_CMD_SAVEENV
#define CONFIG_CMD_NAND
#if defined(CONFIG_BOOT_ONENAND)
#define CONFIG_CMD_ONENAND
#endif
#define CONFIG_CMD_PING
#define CONFIG_CMD_ELF
#define CONFIG_CMD_FAT
#define CONFIG_CMD_EXT2

#define CONFIG_BOOTDELAY	3
#define CONFIG_CHECKDELAY   2

#define CONFIG_ZERO_BOOTDELAY_CHECK

#if (CONFIG_COMMANDS & CONFIG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE	115200	/* speed to run kgdb serial port */
#define CONFIG_KGDB_SER_INDEX	1	/* which serial port to use	 */
#endif

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP				/* undef to save memory	      */
#define CONFIG_SYS_PROMPT		"SMDK6410 # "	/* Monitor Command Prompt     */
#define CONFIG_SYS_CBSIZE		256		/* Console I/O Buffer Size    */
#define CONFIG_SYS_PBSIZE		384		/* Print Buffer Size          */
#define CONFIG_SYS_MAXARGS		16		/* max number of command args */
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE	/* Boot Argument Buffer Size  */

#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE	/* memtest works on	      */
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_SDRAM_BASE + 0x7e00000) /* 126MB in DRAM */

#define CONFIG_SYS_LOAD_ADDR		CONFIG_SYS_SDRAM_BASE	/* default load address	*/

#define CONFIG_SYS_HZ			1000

/* valid baudrates */
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE	0x40000		/* regular stack 256KB */

/**********************************
 Support Clock Settings
 **********************************
 Setting	SYNC	ASYNC
 ----------------------------------
 667_133_66	 X	  O
 533_133_66	 O	  O
 400_133_66	 X	  O
 400_100_50	 O	  O
 **********************************/

/*#define CONFIG_CLK_667_133_66*/
#define CONFIG_CLK_533_133_66
/*
#define CONFIG_CLK_400_100_50
#define CONFIG_CLK_400_133_66
#define CONFIG_SYNC_MODE
*/

/* SMDK6400 has 2 banks of DRAM, but we use only one in U-Boot */
#define CONFIG_NR_DRAM_BANKS	1
#define PHYS_SDRAM_1		CONFIG_SYS_SDRAM_BASE	/* SDRAM Bank #1	*/
#define PHYS_SDRAM_1_SIZE	0x08000000	/* 128 MB in Bank #1	*/

#define CONFIG_SYS_FLASH_BASE		0x10000000
#define CONFIG_SYS_MONITOR_BASE	0x00000000

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define CONFIG_SYS_MAX_FLASH_BANKS	1	/* max number of memory banks	*/
/* AM29LV160B has 35 sectors, AM29LV800B - 19 */
#define CONFIG_SYS_MAX_FLASH_SECT	40

#define CONFIG_AMD_LV800
#define CONFIG_SYS_FLASH_CFI		1	/* Use CFI parameters (needed?) */
/* Use drivers/cfi_flash.c, even though the flash is not CFI-compliant	*/
#define CONFIG_FLASH_CFI_DRIVER	1
#define CONFIG_SYS_FLASH_CFI_WIDTH	FLASH_CFI_16BIT
#define CONFIG_FLASH_CFI_LEGACY
#define CONFIG_SYS_FLASH_LEGACY_512Kx16

/* timeout values are in ticks */
#define CONFIG_SYS_FLASH_ERASE_TOUT	(5 * CONFIG_SYS_HZ) /* Timeout for Flash Erase	*/
#define CONFIG_SYS_FLASH_WRITE_TOUT	(5 * CONFIG_SYS_HZ) /* Timeout for Flash Write	*/


/*
 * SMDK6400 board specific data
 */

#define CONFIG_IDENT_STRING	" for SMDK6400"

/* base address for uboot */
#define CONFIG_SYS_PHY_UBOOT_BASE	(CONFIG_SYS_SDRAM_BASE + 0x07e00000)
/* total memory available to uboot */
#define CONFIG_SYS_UBOOT_SIZE		(512 * 1024)

/* Put environment copies after the end of U-Boot owned RAM */
#define CONFIG_NAND_ENV_DST	(CONFIG_SYS_UBOOT_BASE + CONFIG_SYS_UBOOT_SIZE)

#ifdef CONFIG_ENABLE_MMU
#define CONFIG_SYS_MAPPED_RAM_BASE	0xc0000000
#define CONFIG_BOOTCOMMAND	"nand read 0x50000000 0x100000 0x300000;" \
				"bootm 0x50000000"
#else
#define CONFIG_SYS_MAPPED_RAM_BASE	CONFIG_SYS_SDRAM_BASE
#define CONFIG_BOOTCOMMAND	"nand read 0x50000000 0x100000 0x300000;" \
				"bootm 0x50000000"
#endif

/* NAND U-Boot load and start address */
#define CONFIG_SYS_UBOOT_BASE		(CONFIG_SYS_MAPPED_RAM_BASE + 0x07e00000)


/*������������512K*/
#define CONFIG_ENV_OFFSET		0x0080000
#define CONFIG_ENV_SIZE		0x80000	/* Total Size of Environment Sector */

/* NAND configuration */
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define CONFIG_SYS_NAND_BASE		0x70200010
#define CONFIG_SYS_S3C_NAND_HWECC

#define CONFIG_SYS_NAND_SKIP_BAD_DOT_I	1  /* ".i" read skips bad blocks	      */
#define CONFIG_SYS_NAND_WP		1
#define CONFIG_SYS_NAND_YAFFS_WRITE	1  /* support yaffs write		      */
#define CONFIG_SYS_NAND_BBT_2NDPAGE	1  /* bad-block markers in 1st and 2nd pages  */

#define CONFIG_SYS_NAND_U_BOOT_DST	CONFIG_SYS_PHY_UBOOT_BASE	/* NUB load-addr      */
#define CONFIG_SYS_NAND_U_BOOT_START	CONFIG_SYS_NAND_U_BOOT_DST	/* NUB start-addr     */

#define CONFIG_SYS_NAND_U_BOOT_OFFS	(4 * 1024)	/* Offset to RAM U-Boot image */
#define CONFIG_SYS_NAND_U_BOOT_SIZE	(400 * 1024)	/* Size of RAM U-Boot image   */

/* NAND chip page size		*/
#define CONFIG_SYS_NAND_PAGE_SIZE	2048
/* NAND chip block size		*/
#define CONFIG_SYS_NAND_BLOCK_SIZE	(128 * 1024)
/* NAND chip page per block count  */
#define CONFIG_SYS_NAND_PAGE_COUNT	64
/* Location of the bad-block label */
#define CONFIG_SYS_NAND_BAD_BLOCK_POS	0
/* Extra address cycle for > 128MiB */
#define CONFIG_SYS_NAND_5_ADDR_CYCLE

/* Size of the block protected by one OOB (Spare Area in Samsung terminology) */
#define CONFIG_SYS_NAND_ECCSIZE	CONFIG_SYS_NAND_PAGE_SIZE
/* Number of ECC bytes per OOB - S3C6400 calculates 4 bytes ECC in 1-bit mode */
#define CONFIG_SYS_NAND_ECCBYTES	4
/* Number of ECC-blocks per NAND page */
#define CONFIG_SYS_NAND_ECCSTEPS	(CONFIG_SYS_NAND_PAGE_SIZE / CONFIG_SYS_NAND_ECCSIZE)
/* Size of a single OOB region */
#define CONFIG_SYS_NAND_OOBSIZE	64
/* Number of ECC bytes per page */
#define CONFIG_SYS_NAND_ECCTOTAL	(CONFIG_SYS_NAND_ECCBYTES * CONFIG_SYS_NAND_ECCSTEPS)
/* ECC byte positions */
#define CONFIG_SYS_NAND_ECCPOS		{40, 41, 42, 43, 44, 45, 46, 47, \
				 48, 49, 50, 51, 52, 53, 54, 55, \
				 56, 57, 58, 59, 60, 61, 62, 63}


#ifdef  CONFIG_BOOT_MOVINAND
#define UART_CLK_CFG
#endif

#define CONFIG_NAND
#define CONFIG_NAND_S3C64XX
/* Unimplemented or unsupported. See comment above.
#define CONFIG_ONENAND
#define CONFIG_MOVINAND
*/

/* Settings as above boot configuration */
#define CONFIG_ENV_IS_IN_NAND
#define CONFIG_BOOTARGS	"ubi.mtd=2 root=ubi0:rootfs-nand rootfstype=ubifs ro console=ttySAC0,115200"
/*����mtd����*/
//#define CONFIG_MTD_DEBUG

#if !defined(CONFIG_ENABLE_MMU)
#define CONFIG_CMD_USB			1
#define CONFIG_USB_S3C64XX
#define CONFIG_USB_OHCI_NEW		1
#define CONFIG_SYS_USB_OHCI_REGS_BASE		0x74300000
#define CONFIG_SYS_USB_OHCI_SLOT_NAME		"s3c6400"
#define CONFIG_SYS_USB_OHCI_MAX_ROOT_PORTS	3
#define CONFIG_SYS_USB_OHCI_CPU_INIT		1

#define CONFIG_USB_STORAGE	1
#endif
#define CONFIG_DOS_PARTITION	1

#if defined(CONFIG_USB_OHCI_NEW) && defined(CONFIG_ENABLE_MMU)
# error "usb_ohci.c is currently broken with MMU enabled."
#endif

#endif	/* __CONFIG_H */
