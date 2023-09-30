# at_102

![at_102](imgur.com image replace me!)

*DELL AT102 subsituting the COP943C for a Pi Pico*

* Keyboard Maintainer: [Tim Brooks](https://github.com/brookst)
* Hardware Supported: DELL AT102 with Pi Pico

The AT101 and respective W versions (with GUI and menu buttons) likely have a similar matrix.

Make example for this keyboard (after setting up your build environment):

    make at_102:default

To flash, put the RP2040 into bootloader mode and copy the `.uf2` file to the drive.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (2,0) in the matrix (should be the Escape key) and plug in the keyboard
* **Boot select button**: Hold down the `BOOTSEL` button and plug in the keyboard
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is mapped
