# Actions

User action to clear the text area on button press / shortcut
[Link](https://techbase.kde.org/Special:MyLanguage/Development/Tutorials/Using_Actions)

### How to build, install and Run

This projects needs to be installed somewhere, since the ```tutorial3ui.rc``` needs to go somewhere so that KDE can find it.

```bash
mkdir build && cd build
# To tell CMake where to install the program, set the DCMAKE_INSTALL_PREFIX switch
cmake .. -DCMAKE_INSTALL_PREFIX=$HOME
make install
```

To be able to run the program properly, you will need to let the system know where the XMLGUI file is. Since it is installed it in a nonstandard location, it should be mentioned explicitly to do so every time. The following command would suffice:

```bash
XDG_DATA_DIRS=$HOME/share:$XDG_DATA_DIRS $HOME/bin/tutorial3
```
