#!/bin/sh

BASEDIR=$(dirname $0)
DBFILE=${BASEDIR}/codegen/types.data
INDIR=${BASEDIR}/codegen
OUTDIR=${BASEDIR}

OP=$1

T=$2
LOCATION=$(sed "/^${T}/!d" ${DBFILE} | tr -s '\t' | cut -f2)
TYPE=$(sed "/^${T}/!d" ${DBFILE} | tr -s '\t' | cut -f3)
MAX=$(sed "/^${T}/!d" ${DBFILE} | tr -s '\t' | cut -f4)
MIN=$(sed "/^${T}/!d" ${DBFILE} | tr -s '\t' | cut -f5)

MODE=$3


untemplate() {
    EXT=$1
    case $EXT in
        h)     OUTLOC=include ;;
        inl.h) OUTLOC=include ;;
        c)     OUTLOC=src ;;
        *)     echo "internal error: unknown extension ${EXT} (skipping)"; return ;;
    esac

    INFILE=${INDIR}/${LOCATION}/${OP}_@T${MODE}.${EXT}.in
    OUTFILE=${OUTDIR}/${OUTLOC}/${OP}_${T}${MODE}.${EXT}

    sed "s/@TYPE/${TYPE}/g;s/@MAX/${MAX}/g;s/@MIN/${MIN}/g;s/@T/${T}/g" <${INFILE} >${OUTFILE}
}

untemplate 'h'
untemplate 'inl.h'
untemplate 'c'
