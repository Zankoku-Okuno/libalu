#!/bin/sh
T=$1
UP=`echo ${T%_t} | tr '[:lower:]' '[:upper:]'`
DEFT="define(\`TVAR', \`${T}')dnl"
DEFMIN="define(\`MIN', \`${UP}_MIN')dnl"
DEFMAX="define(\`MAX', \`${UP}_MAX')dnl"

/bin/echo -e "$DEFT\n$DEFMIN\n$DEFMAX"