#!/bin/sh

BASEDIR=$(dirname $0)
DBFILE=${BASEDIR}/codegen/types.data
INDIR=${BASEDIR}/codegen
OUTDIR=${BASEDIR}

OP=$1
MODE=$2
T=$3

case ${OP} in
    precision) FILETYPE=precision ;;
    struct) FILETYPE=struct ;;
    *) FILETYPE=opcode ;;
esac

case ${FILETYPE} in
    opcode) ;;
    precision)
        T=${MODE}
        MODE=''
        ;;
    struct)
        OP=${MODE}
        MODE=''
        ;;
esac

case ${FILETYPE} in
    struct) LOCATION=struct ;;
    *) LOCATION=$(sed "/^${T}/!d" ${DBFILE} | tr -s '\t' | cut -f2) ;;
esac
TYPE=$(sed "/^${T}/!d" ${DBFILE} | tr -s '\t' | cut -f3)
MAX=$(sed "/^${T}/!d" ${DBFILE} | tr -s '\t' | cut -f4)
MIN=$(sed "/^${T}/!d" ${DBFILE} | tr -s '\t' | cut -f5)


untemplate() {
    EXT=$1
    case $EXT in
        h)     OUTLOC=include ;;
        inl.h) OUTLOC=include ;;
        c)     OUTLOC=src ;;
        *)     echo "internal error: unknown extension ${EXT} (skipping)"; return ;;
    esac

    INFILE=${INDIR}/${LOCATION}/${OP}${MODE}_@T.${EXT}.in
    OUTFILE=${OUTDIR}/${OUTLOC}/${OP}${MODE}_${T}.${EXT}

    sed "s/@TYPE/${TYPE}/g;s/@MAX/${MAX}/g;s/@MIN/${MIN}/g;s/@T/${T}/g" <${INFILE} >${OUTFILE}
}

case ${FILETYPE} in
    opcode)
        untemplate 'h'
        untemplate 'inl.h'
        untemplate 'c'
        ;;
    precision)
        untemplate 'h'
        untemplate 'inl.h'
        untemplate 'c'
        ;;
    struct)
        untemplate 'h'
        ;;
esac
