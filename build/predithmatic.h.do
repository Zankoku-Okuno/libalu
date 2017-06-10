redo-ifchange ../src/unsigned.in ../src/signed.in

redo-ifchange mk-m4defs.sh
redo-ifchange ../src/h.m4
redo-ifchange ../src/structs.m4 ../src/*_unsigned-portable.m4 ../src/*_signed-portable.m4


cat ../src/predithmatic.h |
    m4 >> $3

for T in `grep -v '^\s*#' ../src/unsigned.in | grep .`; do
    ./mk-m4defs.sh $T |
        cat ../src/h.m4 - ../src/structs.m4 ../src/*_unsigned-portable.m4 |
        m4 >> $3
done;

for T in `grep -v '^\s*#' ../src/signed.in | grep .`; do
    ./mk-m4defs.sh $T |
        cat ../src/h.m4 - ../src/structs.m4 ../src/*_signed-portable.m4 |
        m4 >> $3
done;