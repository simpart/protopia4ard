/**
 * @file serial.cpp
 * @author simpart
 */
#include <Arduino.h>
#include "pia/com.h"

int seri_print (const char *fmt, ...) {
    va_list list;
    char str_buf[128] = {0};
    
    if (NULL == fmt) {
        return PIA_NG;
    }
    
    va_start(list, fmt);
    snprintf(&str_buf[0], sizeof(str_buf), fmt, list);
    Serial.print(&str_buf);
    va_end(list);
    
    return PIA_OK;
}

int seri_println (const char *fmt, ...) {
    va_list list;
    va_start(list, fmt);
    if (PIA_OK != seri_print(fmt, list)) {
        va_end(list);
        return PIA_NG;
    }
    Serial.println("");
    va_end(list);
    return PIA_OK;
}
/* end of file */
