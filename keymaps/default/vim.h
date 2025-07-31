#include "qmk-vim/src/vim.h"

enum custom_keycodes {
    TOG_VIM = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process case modes
    if (!process_vim_mode(keycode, record)) {
        return false;
    }

    // Regular user keycode case statement
    switch (keycode) {
        case TOG_VIM:
            if (record->event.pressed) {
                toggle_vim_mode();
            }
            return false;
        default:
            return true;
    }
}
