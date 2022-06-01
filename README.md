# Snowling
A simple bowling game with a festive twist.

[![A screenshot of the game Snowling](https://dashboard.snapcraft.io/site_media/appmedia/2021/12/Screenshot_2021-12-15_20-36-11.png)](https://www.youtube.com/watch?v=RN6lRq4bKWk "Snowling Game Video")

### How to play

The premise is simple; you must launch the snowball at the pins and knock them down, seems easy right? Well, your snowball won't knock any pins down unless you roll over some ice first to harden it up. There are three obstacles in the game:
* Ice _(color: Aqua)_ - Hardens your snowball to pack a heavier punch on the pins.
* Boost _(color: Purple)_ - Increases the speed of your snowball to blow a heavier punch on the pins.
* Lava _(color: Red)_ - Melts your snowball; instant penalty.

It's best to play with your keyboard but Joystick is also supported.

**Key Bindings:**
* `TAB/SPACE + 0-9` - Select launch speed.
* `0-9` - Launch ball at one of 10 different angles, 5-1 for left-hand launches and 6-0 for right-hand launches.
* `R/LSHIFT` - Launch ball at a random angle and speed.
* `Left, Right, Up, Down` - Launch ball at four quick selection angles and speeds.

**Joypad Bindings:**
* `Stick 1 - Left to Right` - Launch Angle
* `Stick 1 - Up and Down` - Launch Speed
* `Button 1` - Launch
* `Button 2` - Random Launch

I tend to just use `UP, DOWN, LEFT, RIGHT`, and `R` when I play, but if you are competitive you will want to get accustomed to using `SPACE + 0-9` & `0-9`.

---

### Video
https://www.youtube.com/watch?v=RN6lRq4bKWk

---

### Simplified WebGL / Mobile version _(one click/tap random bowl only)_
https://mrbid.github.io/snowling
https://voxdsp.com/snowling

---

### Snapcraft / Software Center
https://snapcraft.io/snowling

---

### AppImage
https://github.com/mrbid/Snowling/raw/main/Snowling-x86_64.AppImage

---

### [x86_64] Linux Binary (Ubuntu 21.10)
https://github.com/mrbid/Snowling/raw/main/snowling

---

### [ARM64] Linux Binary (Raspbian 10)
https://github.com/mrbid/Snowling/raw/main/snowling_arm

---

### Windows Binary
https://github.com/mrbid/Snowling/raw/main/snowling.exe <br>
https://github.com/mrbid/Snowling/raw/main/glfw3.dll

---

### Prerequisites
`sudo apt install libglfw3 libglfw3-dev upx-ucl gcc-mingw-w64-i686-win32`

---

### Compile & Install
```
gcc main.c glad_gl.c -Ofast -lglfw -lm -o snowling
sudo cp snowling /usr/bin/snowling
```

---

### Make & Install
```
make
sudo make install /usr/bin
```

---

### Debug
`clang -fno-omit-frame-pointer -fsanitize=address -g main.c glad_gl.c -Ofast -lglfw -lm -o snowling`

`clang -fno-omit-frame-pointer -fsanitize=undefined -g main.c glad_gl.c -Ofast -lglfw -lm -o snowling`

`valgrind snowling`

`strace snowling`

```
#define LEAK_CHECK
#define LEAK_CHECK_BRUTE
#define AUTOMATE
```

---

## Footnotes

### Attributions
https://unsplash.com/photos/N_MXyBUV5hU<br>
http://www.forrestwalter.com/icons/<br>
