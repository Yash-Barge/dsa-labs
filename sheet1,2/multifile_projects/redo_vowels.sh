gcc -c master.c
gcc -c count_vowels.c
gcc -o count_vowels_exe master.o count_vowels.o
./count_vowels_exe