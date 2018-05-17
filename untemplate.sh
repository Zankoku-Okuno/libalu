#!/bin/sh

CDIR=$(dirname $0)/c-src


T=u8 # FIXME this should be $2, and TYPE,MAX,MIN should be looked up
TYPE=uint8_t
MAX=UINT8_MAX
MIN=UINT8_MIN

SED_T="s/@T/${T}/g"
SED_TYPE="s/@TYPE/${TYPE}/g"
SED_MAX="s/@MAX/${MAX}/g"
SED_MIN="s/@MIN/${MIN}/g"


INFILE=${1}
OUTFILE=$(basename ${INFILE} | sed 's/\.in$//' | sed ${SED_T})

if [ $(echo ${OUTFILE} | grep '.h$') ]
then
    OUTFILE=${CDIR}/include/${OUTFILE}
else
    OUTFILE=${CDIR}/src/${OUTFILE}
fi


sed -e ${SED_TYPE} -e ${SED_T} -e ${SED_MAX} -e ${SED_MIN} <${INFILE} >${OUTFILE}
