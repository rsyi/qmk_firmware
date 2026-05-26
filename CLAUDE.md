# Notes for Claude — Robert's QMK fork

This is a personal fork of `qmk/qmk_firmware` (remote `git@github.com:rsyi/qmk_firmware.git`,
tracks `qmk/qmk_firmware` master). The only personally-maintained file lives at
`keyboards/planck/keymaps/rsyi/`. Everything else is upstream.

## Target hardware

- **Board:** Planck rev7 (Drop sells it; there is no separate `planck/rev7_drop` folder —
  build target is plain `planck/rev7`).
- **MCU/bootloader:** STM32F303 with `stm32-dfu`. Flash with `dfu-util`. Reset button is
  on the bottom of the PCB; software DFU entry uses the `QK_BOOT` keycode.
- **Layout matrix:** rev6 → rev7 layout is unchanged. `LAYOUT_planck_grid` aliases to
  `LAYOUT_ortho_4x12`, so any rev6-era keymap compiles for rev7 once the keycodes are
  modernized.

## Build / flash commands

```
qmk compile -kb planck/rev7 -km rsyi
qmk flash   -kb planck/rev7 -km rsyi      # auto-waits for DFU device
```

During reflash, `dfu-util` will often print
`dfuERROR / Device's firmware is corrupt. It cannot return to run-time (non-DFU) operations.`
That is expected — the bootloader has no valid firmware to fall back to mid-flash. It
clears status and proceeds normally to erase 100% → download 100% → "File downloaded
successfully". Don't treat it as a failure.

## macOS toolchain install (Apple Silicon, Homebrew)

The Homebrew `qmk` formula pins to versioned compilers from third-party taps and does
not auto-link them. Full install sequence:

```
brew tap osx-cross/arm
brew tap osx-cross/avr
brew install qmk/qmk/qmk
brew link --force arm-none-eabi-gcc@8
brew link --force avr-gcc@8
brew link --force arm-none-eabi-binutils      # provides arm-none-eabi-objcopy
```

If `qmk compile` reports `Could not find module appdirs!`, QMK's bundled Python is
missing its requirements. Fix with (adjust version):

```
/opt/homebrew/Cellar/qmk/<version>/libexec/bin/python -m pip install -r requirements.txt
```

Currently installed: qmk 1.1.8, arm-none-eabi-gcc@8 8.5.0_2, avr-gcc@8 8.5.0_3,
arm-none-eabi-binutils 2.41.

## QMK API rename cheat sheet (≈2019 → current)

The `rsyi` keymap was originally written against an old QMK and required the following
renames. If translating any other old keymap, expect the same set:

| Old                          | New                                                |
|------------------------------|----------------------------------------------------|
| `RESET`                      | `QK_BOOT`                                          |
| `DEBUG`                      | `DB_TOGG`                                          |
| `MUV_DE` / `MUV_IN`          | `AU_PREV` / `AU_NEXT`                              |
| `MU_MOD`                     | `MU_NEXT`                                          |
| `TERM_ON` / `TERM_OFF`       | removed entirely — delete the keys                 |
| `#include "keymap_extras/keymap_dvorak.h"` | `#include "keymap_dvorak.h"`         |

Callback signature changes:

- `void encoder_update_user(bool clockwise)`
  → `bool encoder_update_user(uint8_t index, bool clockwise)` — **must return `false`**
  to override the board default.
- `void dip_switch_update_user(uint8_t index, bool active)`
  → `bool dip_switch_update_user(uint8_t index, bool active)` — **must return `true`**
  to allow further processing.

Tap-hold modernization:

- `#define TAPPING_FORCE_HOLD` is deprecated *and* was a silent no-op in `keymap.c` — it
  has to live in `config.h`. The modern replacement is `#define QUICK_TAP_TERM 0` (also
  in `config.h`). The rsyi keymap uses this to force `MT(MOD_RSFT, KC_ENT)` on the
  bottom-right Enter to always hold-as-mod and never auto-repeat tap.

Muse sequencer:

- The old "muse" mode (`muse_mode`, `muse_counter`, `muse_offset`, `muse_tempo`,
  `matrix_scan_user` ticking notes, `PLOVER_SOUND` globals) was removed. Modern
  `muse.c` is built into `quantum/audio` when `AUDIO_ENABLE=yes`, so a keymap-local
  `SRC += muse.c` in `rules.mk` is wrong and breaks the build. The rsyi `rules.mk` is
  intentionally empty.

## Sanity-check before editing rsyi keymap

- `KC_BRMD` / `KC_BRMU` still exist as legacy aliases (mapped to KC_SCROLL_LOCK /
  KC_PAUSE for macOS brightness keys). Keep them.
- All `DV_*` Dvorak macros are in `quantum/keymap_extras/keymap_dvorak.h` (resolved via
  the modern `#include "keymap_dvorak.h"` form).
- The keymap defines custom layers: `_SDRK`, `_DVORAK`, `_CODE`, `_LOWER`, `_SLOWER`,
  `_RAISE`, `_SRAISE`, `_ADJUST`, `_SADJUST`. Tri-layer (`update_tri_layer_state`) is
  used to derive `_ADJUST` / `_SADJUST` from the respective lower+raise combos.
- Encoder is intentionally simple: clockwise = PGDN (or `KC_MS_WH_DOWN` when mousekeys
  active), counter-clockwise = PGUP / `KC_MS_WH_UP`. No muse tempo, no nav.

## Working with upstream

Upstream merges land via `Merge branch 'qmk:master' into master`. Don't rebase the
personal commits onto upstream — keep the merge-commit history. Personal work always
goes in `keyboards/planck/keymaps/rsyi/` and nowhere else; avoid touching files outside
that directory unless the user explicitly asks.
