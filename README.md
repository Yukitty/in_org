ORG Player v1.08
================
Looking for binaries? See the [releases page](https://github.com/Yukitty/in_org/releases).

**To use:**
Just put `in_org.dll` into your `/WinAmp/Plugins/` folder, then open organya data in _WinAmp_.

Released for free and open source under the WTFPL, see [COPYING](https://raw.githubusercontent.com/Yukitty/in_org/master/COPYING) for full license information.

**To set looping preference:**
Navigate WinAmp Preferences to Plug-ins, Input, ORG Player and click the Configure button.

If you set loop iterations to 0, the song will loop indefinitely.

**Hidden feature:**
To play beta tracks with the most common beta drumset, change the file's internal header from Org-02 to Org-01.

The Japanese OrgMaker 2 drum set is not supported at the moment, but the English version is available under Org-02 as normal due to no conflicts in instrument numbering.

**To compile your own:**
- mingw32-make
