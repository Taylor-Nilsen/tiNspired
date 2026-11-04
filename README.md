tiNspired
=========

A TI-Nspire CX II CAS emulator for macOS and Windows. It runs the real calculator OS, so what you see is the real thing, with a mouse-driven cursor, keyboard typing, clipboard paste and drag-and-drop file transfer on top.

Based on [Firebird](https://github.com/nspire-emus/firebird), the community TI-Nspire emulator originally created by Goplat. The emulation core is theirs; this fork reworks the desktop experience.

Download
--------

Get the latest build from the [Releases page](https://github.com/Taylor-Nilsen/tiNspired/releases). Builds are made on demand: run the Release workflow from the Actions tab, or push a `v*` tag.

* **macOS:** download the `.dmg` and drag the app to Applications. It is unsigned, so on first launch right-click the app and choose Open.
* **Windows:** download the `.zip`, unzip it and run `tiNspired.exe`.

First launch
------------

The emulator needs the calculator's own firmware, which is TI's and not included. On first launch it asks for:

* **Boot1 (manuf):** has to come from a real CX II.
* **OS:** the CX II CAS OS installer (`.tcc2`) from TI's site.

The model picker defaults to CX II. Touchpad and CX models still work if you have their files.

Using it
--------

* **Mouse = cursor.** Move the mouse over the screen and the calc cursor follows, like a finger sliding on the touchpad. Click to click, hold the button to drag. The touchpad on the on-screen keypad still works too.
* **Just type.** Letters, digits, `+ - * / ^ ( ) = . ,`, Enter, Backspace, Esc, Tab all go straight to the calc. Ctrl is the calc's ctrl key, Shift is shift. Alt+key reaches the rest (Alt+D doc, Alt+M menu, Alt+T trig, Alt+P power, Alt+2 x², Alt+C catalog, Alt+V var).
* **Paste an expression.** Copy text anywhere on your computer, then press Ctrl+Shift+V (Cmd+Shift+V on macOS) in the emulator. It types the text into the calc key by key. Supports letters, digits, the operators above, π, ², × and ÷. Plain Ctrl+V is the calc's own paste.
* **Send files to the calc.** Drag `.tns` files onto the emulator window. They land in the folder picked in the File Transfer dock.
* **Pull files off the calc.** Open the File Transfer dock (Docks menu), right-click any file, Download.

Building from source
--------------------

Install Qt 5.15 and run:

```
mkdir -p build
cd build
qmake ..
make
```

On macOS with Homebrew:

```
brew install qt@5
mkdir -p build && cd build
$(brew --prefix qt@5)/bin/qmake .. && make -j$(sysctl -n hw.ncpu)
open tiNspired.app
```

License
-------
This work (except the icons from the KDE project) is licensed under the GPLv3.
