#!/bin/env bash

./a.out
[ $? -eq 15 ] && make run
