#include "qmk-vim/src/vim.h"

enum custom_keycodes {
    VIM_LINUX = SAFE_RANGE,
    VIM_MAC,
    MACRO_0,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process case modes
    if (!process_vim_mode(keycode, record)) {
        return false;
    }

    // Regular user keycode case statement
    switch (keycode) {
        case VIM_LINUX:
            if (record->event.pressed) {
                toggle_vim_mode();
            }
            return false;
        case VIM_MAC:
            if (record->event.pressed) {
                toggle_vim_for_mac();
            }
            return false;
        case MACRO_0:
            if (record->event.pressed) {
                SEND_STRING("~/");
            }
            return false;
        default:
            return true;
    }
}
