#!/bin/bash

display_message() {
    local color=$1
    local message=$2
    echo -e "${color}${message}${RESET}"
}