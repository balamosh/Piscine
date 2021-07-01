#!/bin/sh
ifconfig -a | grep 'ether ' | tr -d " " | cut -c 7-
