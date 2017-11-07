/**
 * @file piacom.h
 * @brief protopia common defined
 * @author simpart
 */
/*** include ***/
#include <stddef.h>
#include <stdint.h>

#ifndef __COMMON_H__
#define __COMMON_H__

/*** define ***/
/**
 * @brief value of function return
 */
#define PIA_OK  0  //! function is successful
#define PIA_NG -1  //! function is failed
/**
 * @brief error value
 */
#define PIA_ERR_NMCH  -10 //! not match
/**
 * @brief common flag
 */
#define PIA_TRUE  1  //! value of true
#define PIA_FALSE 0  //! value of false

#define PIA_RANDOM_8   0x0F
#define PIA_RANDOM_16  0xFF

/*** struct ***/
typedef struct pia_errinf {
    char file[32];
    int  line;
    char detail[128];
} pia_errinf_t;

/*** prototype ***/
int pia_ini t(void);
int pia_err_init (void);
void pia_error (char *, int, char *);
void pia_dump_err (void);
uint16_t pia_htons (uint16_t);
uint16_t pia_ntohs (uint16_t);
uint16_t pia_checksum (uint16_t *, size_t);
uint32_t pia_random (uint32_t);
/* serial */
int seri_print (const char *, ...);

typedef printf seri_print

/*** macro ***/
#define PIA_ERROR(d) pia_error(__FILE__, __LINE__, d);

#endif
/* end of file */
