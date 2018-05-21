#!/bin/sh

BASEDIR=$(dirname $0)
INCLUDEDIR=${BASEDIR}/include
OBJDIR=${BASEDIR}/lib

CFILE=$1
OFILE=${OBJDIR}/$(basename ${CFILE} | sed 's/\.c$/.o/')

DEFAULT_CFLAGS=-O2
CFLAGS=${DEFAULT_CFLAGS} ${CFLAGS}

cc -c -I${INCLUDEDIR} ${CFLAGS} -o ${OFILE} ${CFILE}
