# HideyVaulty
HideyVaulty is an open-source file-hiding system for Windows. It is designed for penetration testers and hackers with reverse-shell access to a Windows system, and includes the ability to lock programs away from prying eyes (to be implemented). It can currently save plain-text credentials, stored in the easily accessible "resources" folder (to be fixed).

## Note
Since the last release of HideyVaulty, I decided to start developing HideyVaulty in Linux. I am using VIM and g++, which will make compiling for different Operating Systems easier, so a release for UNIX-based systems may be released during the next few months. I am also planning to make an installer in Qt, which is run on your own computer, and allows you to create a custom version of HideyVaulty. This installer will allow you to select the scripts that are bundled with HideyVaulty, and create a custom folder with them placed in the appropriate locations.

## Prerequisites
**You will need:**

- A working Windows system
- Visual Studio 2015 or later (if you want to compile the code manually)

## Getting started
When HideyVaulty runs for the first time, a basic setup program will run. The program will ask/force you to create an account, 
and create the neccessary files and folders. For more information on HideyVaulty commands and their syntax, type `help` into the
HideyVaulty Shell.

## Changelog
**Coming soon**
- Built-in keylogger
- Task manager and MSCONFIG blocking
- WAY better setup
- Stealth modes
- Hidden folders (finally!)
- Lots more!

**Beta 0.7**
- MBR killing command
- More efficient login code
- Work in progress keylogger (inaccessible)
- A few bug fixes

**Beta 0.6**
- Basic configuration upon first startup
- Disclaimer in "HideyVaulty.cpp"
- "dir" command implemented
- Blank password blocking
- More efficient "quit" function
- A few minor fixes

**Alpha 0.5**
- Redesigned code structure
- Better authentication system
- A ton of bug fixes
- 32-bit version!

**Alpha 0.4**
- "EpicLogin" renamed to "HideyVaulty"
- Totally redesigned CLI
- Cool ASCII art
- Heaps of bug fixes and performance improvements

**Alpha 0.3**
- Minor tweaks

**Alpha 0.2**
- Minor tweaks

**Alpha 0.1**
- Initial alpha build

## Author/s
Jack Williams (HackoTron)
