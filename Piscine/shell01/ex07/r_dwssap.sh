#!/bin/sh
cat /etc/passwd | sed '/^#/d' | sed -n 'n;p' | cut -d ":" -f1 | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | sed 'H;1h;$!d;x;y/\n/,/' | sed 's/,/, /g' | sed 's/.*/&./' | tr -d "\n"
