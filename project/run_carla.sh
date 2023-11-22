#!/bin/bash

# pgrep -f carla | xargs -r kill -9
SDL_VIDEODRIVER=offscreen /opt/carla-simulator/CarlaUE4.sh -opengl&