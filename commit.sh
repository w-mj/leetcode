#!/usr/bin/bash
git add .
git commit -m "'commit at "`data +%F`"'"
git push origin master
