#!/bin/sh

set -e

printf "Are you sure uninstall? (y/n) "
read YN

if test "$YN" != "y" ; then
	echo 'abort uninstall'
	exit 0
fi

SCRIPT_NAME=$(basename "$0")
SCRIPT_DIR=$(cd $(dirname "$0") ; pwd)
cd "$SCRIPT_DIR"

rm -rf ../includes/tyctest
rm -f ../libs/libtyctest.a
rm -f ../libs/libtyctest_main.a
rm "$SCRIPT_DIR/$SCRIPT_NAME"
