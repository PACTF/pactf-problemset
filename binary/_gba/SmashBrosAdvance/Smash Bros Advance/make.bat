path=C:\devkitadv\bin
gcc -o main.elf main.c -lm
objcopy -O binary main.elf smash.bin
tools\gbafix smash.bin -tSSB_ADVANCE
pause