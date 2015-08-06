/* 
 * copyright (c) Espressif System 2010
 * 
 */

#ifndef __SPI_FLASH_H__
#define __SPI_FLASH_H__

typedef enum {
    SPI_FLASH_RESULT_OK,
    SPI_FLASH_RESULT_ERR,
    SPI_FLASH_RESULT_TIMEOUT
} sdk_SpiFlashOpResult;

#define SPI_FLASH_SEC_SIZE      4096

uint32_t sdk_spi_flash_get_id(void);
sdk_SpiFlashOpResult sdk_spi_flash_read_status(uint32_t *status);
sdk_SpiFlashOpResult sdk_spi_flash_write_status(uint32_t status_value);
sdk_SpiFlashOpResult sdk_spi_flash_erase_sector(uint16_t sec);
sdk_SpiFlashOpResult sdk_spi_flash_write(uint32_t des_addr, uint32_t *src_addr, uint32_t size);
sdk_SpiFlashOpResult sdk_spi_flash_read(uint32_t src_addr, uint32_t *des_addr, uint32_t size);

/* SDK uses this structure internally to account for flash size.

   Based on RE work by @foogod at
   http://esp8266-re.foogod.com/wiki/Flashchip_%28IoT_RTOS_SDK_0.9.9%29

   Note that the only field the SDK actually uses appears to be chip_size
*/
typedef struct {
    uint32_t device_id;
    uint32_t chip_size;   /* in bytes */
    uint32_t block_size;  /* in bytes */
    uint32_t sector_size; /* in bytes */
    uint32_t page_size;   /* in bytes */
    uint32_t status_mask;
} sdk_flashchip_t;

extern sdk_flashchip_t sdk_flashchip;

#endif
