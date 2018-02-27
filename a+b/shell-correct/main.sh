#!/bin/bash
sed -e '1d' | awk '{print $1+$2;}'
