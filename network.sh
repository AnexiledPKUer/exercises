#!/bin/bash
systemctl stop NetworkManager
systemctl restart NetworkManager
systemctl restart networking.service
ifup ens33
