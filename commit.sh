#!/bin/bash

set -ex

git add .
git commit -m "commit at "`date +%F`
git push origin master
