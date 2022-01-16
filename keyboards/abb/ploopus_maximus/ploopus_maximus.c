#include "ploopus_maximus.h"

int8_t mouse_test_x = 0;
int8_t mouse_test_y = 0;

void           pointing_device_driver_init(void) {}
report_mouse_t pointing_device_driver_get_report(report_mouse_t mouse_report)
{
    mouse_report.x = mouse_test_x;
    mouse_report.y = mouse_test_y;
    mouse_test_x = 0;
    mouse_test_y = 0;
    return mouse_report;
}
uint16_t       pointing_device_driver_get_cpi(void) { return 800; }
void           pointing_device_driver_set_cpi(uint16_t cpi) {}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            mouse_test_x =+ 5;
        } else {
            mouse_test_x =- 5;
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            mouse_test_y =+ 5;
        } else {
            mouse_test_y =- 5;
        }
    }
    return false;
}

