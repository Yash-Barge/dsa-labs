gcc -c master.c
gcc -c count_consonants.c
gcc -o count_consonants_exe master.o count_consonants.o
./count_consonants_exe