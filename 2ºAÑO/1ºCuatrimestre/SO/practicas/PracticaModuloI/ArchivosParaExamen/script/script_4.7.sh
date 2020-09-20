#!/bin/bash
#Nombre: script_4.7.sh
at -q c -f ./script_4.4.sh now+1 minute
at -q d -f ./script_4.4.sh now+1 minute
at -q e -f ./script_4.4.sh now+1 minute
