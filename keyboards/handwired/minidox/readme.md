# Minidox

A 36 key (3x5+3), split bodied keyboard derived from the [Minidox](/keyboards/handwired/dactyl_manuform/).

* Keyboard Maintainer: [Cedric Bosdonnat](https://github.com/cbosdo)
* Hardware Supported: Pro Micro controller, or clone of
* Hardware Availability: Build Guide to be created 

In order to build the keyboard, run:

    ln -s ~/qmk_userspace/keyboards/handwired/minidox/ ~/qmk_firmware/keyboards/handwired/minidox

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb handwired/minidox -km ergol

Flashing example for this keyboard:

    qmk flash -kb handwired/minidox -km ergol

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
