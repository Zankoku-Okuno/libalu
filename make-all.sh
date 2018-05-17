#!/bin/sh

BASEDIR=$(dirname $0)

UARITH="add sub mul divmod align"
UNSIGNED="u8 u16 u32 u64 uF8 uF16 uF32 uF64 uL8 uL16 uL32 uL64 size uptr uM"

ARITH="add sub neg mul divmod quotrem"
SIGNED="i8 i16 i32 i64 iF8 iF16 iF32 iF64 iL8 iL16 iL32 iL64 ptrdiff iptr iM"


for TYPE in $(echo ${UNSIGNED} | tr ' ' '\n'); do
    echo "Generating ${TYPE}"
    for OP in $(echo ${UARITH} | tr ' ' '\n'); do
        ${BASEDIR}/generate.sh ${OP} F ${TYPE}
    done
done

for TYPE in $(echo ${SIGNED} | tr ' ' '\n'); do
    echo "Generating ${TYPE}"
    for OP in $(echo ${ARITH} | tr ' ' '\n'); do
        ${BASEDIR}/generate.sh ${OP} F ${TYPE}
    done
done


# ALWAYS COMPILE AFTER ALL CODE IS GENERATED
# That way, we don't have to care if any of the compilation depends on other generated code.

for TYPE in $(echo ${UNSIGNED} | tr ' ' '\n'); do
    echo "Compiling ${TYPE}"
    for OP in $(echo ${UARITH} | tr ' ' '\n'); do
        ${BASEDIR}/compile.sh ${BASEDIR}/src/${OP}F_${TYPE}.c
    done
done

for TYPE in $(echo ${SIGNED} | tr ' ' '\n'); do
    echo "Compiling ${TYPE}"
    for OP in $(echo ${ARITH} | tr ' ' '\n'); do
        ${BASEDIR}/compile.sh ${BASEDIR}/src/${OP}F_${TYPE}.c
    done
done
