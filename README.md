Firebird Emu
==========

This project is currently the community TI-Nspire emulator, originally created by Goplat.  
It supports the emulation of Nspire Touchpad (CAS), CX (CAS) and CX II (-T/CAS) calcs on Android, iOS, Linux, macOS and Windows.

Download
--------

Get the latest build from the [Releases page](https://github.com/taylor-nilsen/tinspired/releases/latest).

* **macOS:** download the `.dmg` and drag the app to Applications. It is unsigned, so on first launch right-click the app and choose Open.
* **Windows:** download the `.zip`, unzip it and run `firebird-emu.exe`.

Using it
--------

* **Mouse = cursor.** Move the mouse over the screen and the calc cursor follows, like a finger sliding on the touchpad. Click to press, right-click to hold. The touchpad on the on-screen keypad still works too.
* **Just type.** Letters, digits, `+ - * / ^ ( ) = . ,`, Enter, Backspace, Esc, Tab all go straight to the calc. Ctrl is the calc's ctrl key, Shift is shift. Alt+key reaches the rest (Alt+D doc, Alt+M menu, Alt+T trig, Alt+P power, Alt+2 x², Alt+C catalog, Alt+V var).
* **Paste an expression.** Copy text anywhere on your computer, then press Ctrl+Shift+V (Cmd+Shift+V on macOS) in the emulator. It types the text into the calc key by key. Supports letters, digits, the operators above, π, ², × and ÷. Plain Ctrl+V is the calc's own paste.
* **Send files to the calc.** Drag `.tns` files onto the emulator window. They land in the folder picked in the File Transfer dock.
* **Pull files off the calc.** Open the File Transfer dock (Docks menu), right-click any file, Download.

Screenshots:
-------------------

_Linux:_

[![](http://i.imgur.com/eGJOMsSl.png)](http://i.imgur.com/eGJOMsS.png)

_Windows:_ | _Android:_
--- | ---
[![](https://i.imgur.com/aibTt9Cl.png)](https://i.imgur.com/aibTt9C.png) | [![](https://i.imgur.com/cLphTgnm.png)](https://i.imgur.com/cLphTgn.png)
_macOS:_ | _iOS:_
[![](https://i.imgur.com/ymDtYsj.png)](https://i.imgur.com/O8R2aSo.png) | [![](https://i.imgur.com/LT1u2bim.png)](https://i.imgur.com/LT1u2bi.png)

Building
--------

First, you need to install Qt5.  
Then, you can either use Qt Creator directly (don't forget to configure your kits/compilers etc.!), or run:

```
mkdir -p build
cd build
qmake ..
make
```
##### A special case: iOS with translation (≈JIT) enabled:

There seems to be a bug in qmake that makes the required .S get ignored when building a JIT-enabled ([`TRANSLATION_ENABLED = true`](https://github.com/nspire-emus/firebird/blob/master/firebird.pro#L4)) binary.  
As a workaround, you'll have to take care of it manually:

1. Hit Build in Qt Creator, on an iOS kit/target. (It'll fail)
2. Open the generated .xcodeproj file (in the build folder) in Xcode
3. Locate `asmcode_arm.S` in the file list, click on it, and in the right sidebar, add it to the Firebird target
4. Adjust any other project settings as you see fit (certs/profiles/team/signings/entitlements/etc. though this should be automatic except the Team choice)
5. Build/Run


License
-------
This work (except the icons from the KDE project) is licensed under the GPLv3.
