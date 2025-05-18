## 開発環境

```
$ sudo apt install gcc-avr avr-libc avrdude
```



```
# which avr-gcc
/usr/bin/avr-gcc
# avr-gcc -mmcu=atmega32u4 -v -E - < /dev/null
Using built-in specs.
Reading specs from /usr/lib/gcc/avr/7.3.0/device-specs/specs-atmega32u4
COLLECT_GCC=avr-gcc
Target: avr
Configured with: ../gcc/configure -v --enable-languages=c,c++ --prefix=/usr/lib --infodir=/usr/share/info --mandir=/usr/share/man --bindir=/usr/bin --libexecdir=/usr/lib --libdir=/usr/lib --enable-shared --with-system-zlib --enable-long-long --enable-nls --without-included-gettext --disable-libssp --disable-libcc1 --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=avr --enable-host-pie ASFLAGS= ASFLAGS_FOR_BUILD= CFLAGS='-g -O2 -ffile-prefix-map=/build/gcc-avr-TYLliY/gcc-avr-7.3.0+Atmel3.7.0=. -flto=auto -ffat-lto-objects -fstack-protector-strong -fstack-clash-protection -Wformat  -fcf-protection -fdebug-prefix-map=/build/gcc-avr-TYLliY/gcc-avr-7.3.0+Atmel3.7.0=/usr/src/gcc-avr-1:7.3.0+Atmel3.7.0-1' 'CFLAGS_FOR_BUILD=-g -O2' CPPFLAGS='-Wdate-time -D_FORTIFY_SOURCE=2' CPPFLAGS_FOR_BUILD= CXXFLAGS='-g -O2 -ffile-prefix-map=/build/gcc-avr-TYLliY/gcc-avr-7.3.0+Atmel3.7.0=. -flto=auto -ffat-lto-objects -fstack-protector-strong -fstack-clash-protection -Wformat  -fcf-protection -fdebug-prefix-map=/build/gcc-avr-TYLliY/gcc-avr-7.3.0+Atmel3.7.0=/usr/src/gcc-avr-1:7.3.0+Atmel3.7.0-1' 'CXXFLAGS_FOR_BUILD=-g -O2' DFLAGS=-frelease DFLAGS_FOR_BUILD=-frelease FCFLAGS='-g -O2 -ffile-prefix-map=/build/gcc-avr-TYLliY/gcc-avr-7.3.0+Atmel3.7.0=. -flto=auto -ffat-lto-objects -fstack-protector-strong -fstack-clash-protection -fcf-protection -fdebug-prefix-map=/build/gcc-avr-TYLliY/gcc-avr-7.3.0+Atmel3.7.0=/usr/src/gcc-avr-1:7.3.0+Atmel3.7.0-1' 'FCFLAGS_FOR_BUILD=-g -O2' FFLAGS='-g -O2 -ffile-prefix-map=/build/gcc-avr-TYLliY/gcc-avr-7.3.0+Atmel3.7.0=. -flto=auto -ffat-lto-objects -fstack-protector-strong -fstack-clash-protection -fcf-protection -fdebug-prefix-map=/build/gcc-avr-TYLliY/gcc-avr-7.3.0+Atmel3.7.0=/usr/src/gcc-avr-1:7.3.0+Atmel3.7.0-1' 'FFLAGS_FOR_BUILD=-g -O2' GCJFLAGS=-fdebug-prefix-map=/build/gcc-avr-TYLliY/gcc-avr-7.3.0+Atmel3.7.0=/usr/src/gcc-avr-1:7.3.0+Atmel3.7.0-1 LDFLAGS='-Wl,-Bsymbolic-functions -flto=auto -ffat-lto-objects -Wl,-z,relro' LDFLAGS_FOR_BUILD= OBJCFLAGS='-g -O2 -ffile-prefix-map=/build/gcc-avr-TYLliY/gcc-avr-7.3.0+Atmel3.7.0=. -flto=auto -ffat-lto-objects -fstack-protector-strong -fstack-clash-protection -Wformat  -fcf-protection -fdebug-prefix-map=/build/gcc-avr-TYLliY/gcc-avr-7.3.0+Atmel3.7.0=/usr/src/gcc-avr-1:7.3.0+Atmel3.7.0-1' 'OBJCFLAGS_FOR_BUILD=-g -O2' OBJCXXFLAGS='-g -O2 -ffile-prefix-map=/build/gcc-avr-TYLliY/gcc-avr-7.3.0+Atmel3.7.0=. -flto=auto -ffat-lto-objects -fstack-protector-strong -fstack-clash-protection -Wformat  -fcf-protection -fdebug-prefix-map=/build/gcc-avr-TYLliY/gcc-avr-7.3.0+Atmel3.7.0=/usr/src/gcc-avr-1:7.3.0+Atmel3.7.0-1' 'OBJCXXFLAGS_FOR_BUILD=-g -O2'
Thread model: single
gcc version 7.3.0 (GCC) 
COLLECT_GCC_OPTIONS= '-v' '-E' '-specs=device-specs/specs-atmega32u4' '-mmcu=avr5'
 /usr/lib/gcc/avr/7.3.0/cc1 -E -quiet -v -imultilib avr5 -D__AVR_ATmega32U4__ -D__AVR_DEVICE_NAME__=atmega32u4 - -mn-flash=1 -mno-skip-bug -mmcu=avr5
ignoring nonexistent directory "/usr/lib/gcc/avr/7.3.0/../../../avr/sys-include"
#include "..." search starts here:
#include <...> search starts here:
 /usr/lib/gcc/avr/7.3.0/include
 /usr/lib/gcc/avr/7.3.0/include-fixed
 /usr/lib/gcc/avr/7.3.0/../../../avr/include
End of search list.
# 1 "<stdin>"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "<stdin>"
COMPILER_PATH=/usr/lib/gcc/avr/7.3.0/:/usr/lib/gcc/avr/7.3.0/:/usr/lib/gcc/avr/:/usr/lib/gcc/avr/7.3.0/:/usr/lib/gcc/avr/:/usr/lib/gcc/avr/7.3.0/../../../avr/bin/
LIBRARY_PATH=/usr/lib/gcc/avr/7.3.0/avr5/:/usr/lib/gcc/avr/7.3.0/../../../avr/lib/avr5/:/usr/lib/gcc/avr/7.3.0/:/usr/lib/gcc/avr/7.3.0/../../../avr/lib/
COLLECT_GCC_OPTIONS= '-v' '-E' '-specs=device-specs/specs-atmega32u4' '-mmcu=avr5'
```

#### .vscode/c_cpp_properties.json

```
{
  "configurations": [
    {
      "name": "AVR",
      "includePath": [
        " /usr/lib/gcc/avr/7.3.0/include/**",
        "/usr/lib/gcc/avr/7.3.0/include-fixed/**",
        "/usr/lib/gcc/avr/7.3.0/../../../avr/include/**"
      ],
      "defines": [
        "F_CPU=16000000UL",
        "__AVR_ATmega32U4__",
        "__AVR_DEVICE_NAME__=atmega32u4"
      ],
      "compilerPath": "/usr/bin/avr-gcc",
      "cStandard": "c89"
    }
  ],
  "version": 4
}
```

## ヒューズ値の確認

[ATmega16U4/32U4 - Complete Datasheet](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7766-8-bit-AVR-ATmega16U4-32U4_Datasheet.pdf), P.354-355「28.2 Fuse Bits」より

<figure>
<figcaption>Low</figcaption>

|                     | Hex  | CKDIV8 | CKOUT | SUT1 | SUT0 | CKSEL3 | CKSEL2 | CKSEL1 | CKSEL0 |
| ------------------- | ---- | ------ | ----- | ---- | ---- | ------ | ------ | ------ | ------ |
| ATmega16U4/32U4     | 0x5e | 0      | 1     | 0    | 1    | 1      | 1      | 1      | 0      |
| ATmega16U4RC/32U4RC | 0x52 |        |       |      |      | 0      | 0      |        |        |

<figure>
</figure>
<figcaption>High</figcaption>

|                     | Hex  | OCDEN | JTAGEN | SPIEN | WDTON | EESAVE | BOOTSZ1 | BOOTSZ0 | BOOTRST |
| ------------------- | ---- | ----- | ------ | ----- | ----- | ------ | ------- | ------- | ------- |
| ATmega16U4/32U4     | 0x99 | 1     | 0      | 0     | 1     | 1      | 0       | 0       | 1       |
| ATmega16U4RC/32U4RC |      |       |        |       |       |        |         |         |         |

<figure>
</figure>
<figcaption>Extended</figcaption>

|                     | Hex  | x   | x   | x   | x   | HWBE | BODLEVEL2 | BODLEVEL1 | BODLEVEL0 |
| ------------------- | ---- | --- | --- | --- | --- | ---- | --------- | --------- | --------- |
| ATmega16U4/32U4     | 0xf3 | 1   | 1   | 1   | 1   | 0    | 0         | 1         | 1         |
| ATmega16U4RC/32U4RC | 0xfb |     |     |     |     | 1    |           |           |           |

</figure>

```
$ avrdude -c usbasp -p m32u4 -U lfuse:r:-:h -U hfuse:r:-:h -U efuse:r:-:h

avrdude: AVR device initialized and ready to accept instructions
avrdude: device signature = 0x1e9587 (probably m32u4)
avrdude: reading lfuse memory ...
avrdude: writing output file <stdout>
0x5e
avrdude: reading hfuse memory ...
avrdude: writing output file <stdout>
0x99
avrdude: reading efuse memory ...
avrdude: writing output file <stdout>
0xf3

avrdude done.  Thank you.
```

当然だが今回のATmega32U4はデフォルト通りのようだ。

## ヒューズ値の設定

https://osamuaoki.github.io/jp/2020/03/29/atmega32u4-2/

> CKDIV8は出荷時にプログラムされている(=0)がTeensyの設定でも採用 されています。一見チョット不安になりましたが、実際にはスタート アップコードにCLKPR = 0x80;CLKPR = 0;を置くのがTeensyの標準の ようで分周を1に戻すのでので、これは問題ないとみました。
> 
> まず、5V 16 MHz Crystal使用でBODをするから、以下確定です(P30,P31)。
> 
> - CKSEL0 = 1
> - SUT1..0 = 01
> - CKSEL3..1 = 111

|                     | Hex  | CKDIV8 | CKOUT | SUT1 | SUT0 | CKSEL3 | CKSEL2 | CKSEL1 | CKSEL0 |
| ------------------- | ---- | ------ | ----- | ---- | ---- | ------ | ------ | ------ | ------ |
| ATmega16U4/32U4     | 0x5f | 0      | 1     | 0    | 1    | 1      | 1      | 1      | 1      |

低速スタートアップにしておく必要がないので`CKDIV8=1`か？

|                     | Hex  | CKDIV8 | CKOUT | SUT1 | SUT0 | CKSEL3 | CKSEL2 | CKSEL1 | CKSEL0 |
| ------------------- | ---- | ------ | ----- | ---- | ---- | ------ | ------ | ------ | ------ |
| ATmega16U4/32U4     | 0xdf | 1      | 1     | 0    | 1    | 1      | 1      | 1      | 1      |
